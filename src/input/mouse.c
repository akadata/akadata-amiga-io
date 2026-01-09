/*
 * SPDX-License-Identifier: MIT
 * 
 * Amiga Mouse Input Driver for PISTORM
 * Interfaces with Amiga CIA mouse ports to provide Linux input events
 * Works with Musl Libc and standard libc implementations
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <poll.h>

#ifdef __linux__
#include <linux/input.h>
#include <linux/uinput.h>
#else
// For non-Linux systems, define basic input event structures
struct input_event {
    struct timeval time;
    uint16_t type;
    uint16_t code;
    int32_t value;
};

#define EV_KEY 0x01
#define EV_REL 0x02
#define EV_ABS 0x03
#define EV_SYN 0x00
#define SYN_REPORT 0

// Mouse button codes
#define BTN_LEFT        0x110
#define BTN_RIGHT       0x111
#define BTN_MIDDLE      0x112
#define BTN_SIDE        0x113
#define BTN_EXTRA       0x114

// Relative axis codes
#define REL_X           0x00
#define REL_Y           0x01
#define REL_WHEEL       0x08
#define REL_HWHEEL      0x06

#endif

#include "../pistorm-dev/pistorm_dev.h"  // PISTORM device interface
#include "../platforms/amiga/registers/amiga_memory_map.h"

// Mouse constants
#define MOUSE_COUNTER_BITS 8
#define MOUSE_COUNTER_MASK 0xFF
#define MAX_MOUSE_DELTA 127

// CIAA register addresses for mouse
#define CIAA_PRA_ADDR (CIAA_BASE + CIAPRA)    // Port A - mouse 0 (X/Y)
#define CIAA_PRB_ADDR (CIAA_BASE + CIAPRB)    // Port B - mouse 1 (X/Y)
#define CIAA_DDRA_ADDR (CIAA_BASE + CIADDRA)  // Port A direction
#define CIAA_DDRB_ADDR (CIAA_BASE + CIADDRB)  // Port B direction

// CIAA register addresses for mouse buttons
#define CIAA_JOY0DAT_ADDR (CIAA_BASE + CIAPRA) // Joystick/mouse 0 data
#define CIAA_JOY1DAT_ADDR (CIAA_BASE + CIAPRB) // Joystick/mouse 1 data

// Mouse button masks (from CIAA registers)
#define CIAA_GAMEPORT0_FIRE 0x40  // Mouse button 0 (left)
#define CIAA_GAMEPORT1_FIRE 0x80  // Mouse button 1 (right)

// Mouse state structure
typedef struct {
    int32_t x_pos;
    int32_t y_pos;
    uint8_t buttons;
    uint8_t prev_buttons;
    int32_t x_counter;
    int32_t y_counter;
    int32_t prev_x_counter;
    int32_t prev_y_counter;
    int uinput_fd;
    int initialized;
} amiga_mouse_state_t;

static amiga_mouse_state_t mouse_state = {0};

/**
 * @brief Initialize the Amiga mouse interface
 * @return 0 on success, negative on error
 */
int amiga_mouse_init(void) {
    // Initialize mouse state
    memset(&mouse_state, 0, sizeof(mouse_state));
    
    // Configure CIA ports for mouse reading
    // Both ports are inputs for mouse data
    if (pistorm_write_8(CIAA_DDRA_ADDR, 0x00) < 0) {  // Port A as input for mouse 0
        perror("Failed to configure CIAA DDRA for mouse");
        return -1;
    }
    
    if (pistorm_write_8(CIAA_DDRB_ADDR, 0x00) < 0) {  // Port B as input for mouse 1
        perror("Failed to configure CIAA DDRB for mouse");
        return -1;
    }
    
    // Initialize uinput for Linux
#ifdef __linux__
    struct uinput_user_dev uidev;
    memset(&uidev, 0, sizeof(uidev));
    
    snprintf(uidev.name, UINPUT_MAX_NAME_SIZE, "Amiga Mouse via PISTORM");
    uidev.id.bustype = BUS_USB;
    uidev.id.vendor = 0x1234;
    uidev.id.product = 0x5679;
    uidev.id.version = 1;
    
    mouse_state.uinput_fd = open("/dev/uinput", O_WRONLY | O_NONBLOCK);
    if (mouse_state.uinput_fd < 0) {
        mouse_state.uinput_fd = open("/dev/input/uinput0", O_WRONLY | O_NONBLOCK);
    }
    
    if (mouse_state.uinput_fd < 0) {
        perror("Unable to open uinput device");
        return -1;
    }
    
    // Enable relative movement events
    ioctl(mouse_state.uinput_fd, UI_SET_EVBIT, EV_REL);
    ioctl(mouse_state.uinput_fd, UI_SET_RELBIT, REL_X);
    ioctl(mouse_state.uinput_fd, UI_SET_RELBIT, REL_Y);
    ioctl(mouse_state.uinput_fd, UI_SET_RELBIT, REL_WHEEL);
    
    // Enable key events for buttons
    ioctl(mouse_state.uinput_fd, UI_SET_EVBIT, EV_KEY);
    ioctl(mouse_state.uinput_fd, UI_SET_KEYBIT, BTN_LEFT);
    ioctl(mouse_state.uinput_fd, UI_SET_KEYBIT, BTN_RIGHT);
    ioctl(mouse_state.uinput_fd, UI_SET_KEYBIT, BTN_MIDDLE);
    
    // Create the uinput device
    if (write(mouse_state.uinput_fd, &uidev, sizeof(uidev)) < 0) {
        perror("Write user device descriptor failed");
        close(mouse_state.uinput_fd);
        return -1;
    }
    
    if (ioctl(mouse_state.uinput_fd, UI_DEV_CREATE) < 0) {
        perror("Device creation failed");
        close(mouse_state.uinput_fd);
        return -1;
    }
#endif
    
    mouse_state.initialized = 1;
    printf("Amiga mouse interface initialized\n");
    return 0;
}

/**
 * @brief Read mouse counters from CIA registers
 * @param mouse_num Which mouse (0 or 1)
 * @param x_delta Output X delta
 * @param y_delta Output Y delta
 * @return 0 on success, negative on error
 */
int amiga_mouse_read_counters(int mouse_num, int8_t *x_delta, int8_t *y_delta) {
    uint8_t x_data = 0, y_data = 0;
    
    // Select which mouse port to read
    uint32_t port_addr = (mouse_num == 0) ? CIAA_PRA_ADDR : CIAA_PRB_ADDR;
    
    // Read mouse data (X and Y are multiplexed on the same port)
    if (pistorm_read_8(port_addr, &x_data) < 0) {
        return -1;
    }
    
    // For Amiga mouse, X and Y are typically read separately
    // In quadrature mice, we need to decode the quadrature signals
    // This is a simplified approach - real implementation would decode quadrature
    
    // For now, treat the data as raw counter values
    *x_delta = (int8_t)x_data;
    
    // Simulate Y reading (in real implementation, this would come from another read)
    *y_delta = 0; // Placeholder - real implementation would read Y separately
    
    return 0;
}

/**
 * @brief Read mouse button states
 * @param mouse_num Which mouse (0 or 1)
 * @return Button state bitmask
 */
uint8_t amiga_mouse_read_buttons(int mouse_num) {
    uint8_t joy_data = 0;
    uint8_t buttons = 0;
    
    // Read joystick/mouse button data
    uint32_t joy_addr = (mouse_num == 0) ? CIAA_JOY0DAT_ADDR : CIAA_JOY1DAT_ADDR;
    
    if (pistorm_read_8(joy_addr, &joy_data) < 0) {
        return 0;
    }
    
    // Decode buttons from joystick data
    // For mouse 0, fire button is bit 6 (0x40)
    // For mouse 1, fire button is bit 7 (0x80)
    if (mouse_num == 0) {
        buttons |= (joy_data & CIAA_GAMEPORT0_FIRE) ? 0 : 1; // Active low
    } else {
        buttons |= (joy_data & CIAA_GAMEPORT1_FIRE) ? 0 : 2; // Active low
    }
    
    return buttons;
}

/**
 * @brief Process mouse events and send to Linux input subsystem
 */
void amiga_mouse_process_events(void) {
    int8_t x_delta = 0, y_delta = 0;
    
    // Read mouse counters
    if (amiga_mouse_read_counters(0, &x_delta, &y_delta) == 0) {
        // Update internal position
        mouse_state.x_counter += x_delta;
        mouse_state.y_counter += y_delta;
        
        // Calculate relative movement since last update
        int32_t rel_x = mouse_state.x_counter - mouse_state.prev_x_counter;
        int32_t rel_y = mouse_state.y_counter - mouse_state.prev_y_counter;
        
        // Clamp to reasonable values
        if (rel_x > MAX_MOUSE_DELTA) rel_x = MAX_MOUSE_DELTA;
        if (rel_x < -MAX_MOUSE_DELTA) rel_x = -MAX_MOUSE_DELTA;
        if (rel_y > MAX_MOUSE_DELTA) rel_y = MAX_MOUSE_DELTA;
        if (rel_y < -MAX_MOUSE_DELTA) rel_y = -MAX_MOUSE_DELTA;
        
        // Send relative movement events
        if (rel_x != 0 || rel_y != 0) {
#ifdef __linux__
            struct input_event ev;
            memset(&ev, 0, sizeof(ev));
            gettimeofday(&ev.time, NULL);
            
            if (rel_x != 0) {
                ev.type = EV_REL;
                ev.code = REL_X;
                ev.value = rel_x;
                write(mouse_state.uinput_fd, &ev, sizeof(ev));
            }
            
            if (rel_y != 0) {
                ev.type = EV_REL;
                ev.code = REL_Y;
                ev.value = rel_y;
                write(mouse_state.uinput_fd, &ev, sizeof(ev));
            }
            
            // Send sync event
            ev.type = EV_SYN;
            ev.code = SYN_REPORT;
            ev.value = 0;
            write(mouse_state.uinput_fd, &ev, sizeof(ev));
#endif
            
            mouse_state.prev_x_counter = mouse_state.x_counter;
            mouse_state.prev_y_counter = mouse_state.y_counter;
        }
    }
    
    // Read and process mouse buttons
    uint8_t current_buttons = amiga_mouse_read_buttons(0);
    
    if (current_buttons != mouse_state.prev_buttons) {
        // Left button
        if ((current_buttons & 1) != (mouse_state.prev_buttons & 1)) {
#ifdef __linux__
            struct input_event ev;
            memset(&ev, 0, sizeof(ev));
            gettimeofday(&ev.time, NULL);
            
            ev.type = EV_KEY;
            ev.code = BTN_LEFT;
            ev.value = (current_buttons & 1) ? 1 : 0;
            write(mouse_state.uinput_fd, &ev, sizeof(ev));
            
            // Send sync event
            ev.type = EV_SYN;
            ev.code = SYN_REPORT;
            ev.value = 0;
            write(mouse_state.uinput_fd, &ev, sizeof(ev));
#endif
        }
        
        // Right button
        if ((current_buttons & 2) != (mouse_state.prev_buttons & 2)) {
#ifdef __linux__
            struct input_event ev;
            memset(&ev, 0, sizeof(ev));
            gettimeofday(&ev.time, NULL);
            
            ev.type = EV_KEY;
            ev.code = BTN_RIGHT;
            ev.value = (current_buttons & 2) ? 1 : 0;
            write(mouse_state.uinput_fd, &ev, sizeof(ev));
            
            // Send sync event
            ev.type = EV_SYN;
            ev.code = SYN_REPORT;
            ev.value = 0;
            write(mouse_state.uinput_fd, &ev, sizeof(ev));
#endif
        }
        
        mouse_state.prev_buttons = current_buttons;
    }
}

/**
 * @brief Main mouse polling loop
 */
void amiga_mouse_poll(void) {
    amiga_mouse_process_events();
}

/**
 * @brief Cleanup mouse interface
 */
void amiga_mouse_cleanup(void) {
    if (!mouse_state.initialized) return;
    
#ifdef __linux__
    if (mouse_state.uinput_fd >= 0) {
        ioctl(mouse_state.uinput_fd, UI_DEV_DESTROY);
        close(mouse_state.uinput_fd);
        mouse_state.uinput_fd = -1;
    }
#endif
    
    mouse_state.initialized = 0;
}

/**
 * @brief Test function to verify mouse interface
 */
int amiga_mouse_test(void) {
    printf("Testing Amiga mouse interface...\n");
    
    if (amiga_mouse_init() < 0) {
        printf("Mouse initialization failed\n");
        return -1;
    }
    
    // Perform a quick read
    uint8_t buttons = amiga_mouse_read_buttons(0);
    printf("Mouse buttons state: 0x%02X\n", buttons);
    
    amiga_mouse_cleanup();
    return 0;
}
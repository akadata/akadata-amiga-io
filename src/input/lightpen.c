/*
 * SPDX-License-Identifier: MIT
 * 
 * Amiga Lightpen Input Driver for PISTORM
 * Interfaces with Amiga lightpen via beam position registers to provide Linux input events
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
#define EV_ABS 0x03
#define EV_SYN 0x00
#define SYN_REPORT 0

// Absolute axis codes
#define ABS_X           0x00
#define ABS_Y           0x01
#define ABS_PRESSURE    0x18

// Lightpen button codes
#define BTN_TOUCH       0x14a
#define BTN_TOOL_PEN    0x140
#define BTN_STYLUS      0x14b
#define BTN_STYLUS2     0x14c

#endif

#include "../pistorm-dev/pistorm_dev.h"  // PISTORM device interface
#include "../platforms/amiga/registers/amiga_memory_map.h"

// Lightpen constants
#define LIGHTPEN_POLL_INTERVAL_US 1000  // 1ms polling interval
#define LIGHTPEN_THRESHOLD 0x8000       // Threshold for lightpen detection

// AGNUS register addresses for lightpen
#define VPOSR_ADDR (AGNUS_BASE + VPOSR)      // Read vertical MSB + frame flop
#define VHPOSR_ADDR (AGNUS_BASE + VHPOSR)    // Read vertical/horizontal beam position
#define POTGOR_ADDR (AGNUS_BASE + POTINP)    // Pot pin data read (includes lightpen)

// Lightpen state structure
typedef struct {
    int32_t x_pos;
    int32_t y_pos;
    int32_t pressure;
    uint8_t lightpen_detected;
    uint8_t lightpen_button;
    uint8_t prev_lightpen_button;
    int uinput_fd;
    int initialized;
    struct timespec last_poll_time;
} amiga_lightpen_state_t;

static amiga_lightpen_state_t lightpen_state = {0};

/**
 * @brief Initialize the Amiga lightpen interface
 * @return 0 on success, negative on error
 */
int amiga_lightpen_init(void) {
    // Initialize lightpen state
    memset(&lightpen_state, 0, sizeof(lightpen_state));
    
    // Configure CIA for lightpen detection if needed
    // Enable lightpen in BPLCON0 if LPEN bit is available
    uint16_t bplcon0_val = 0;
    if (pistorm_read_16(BPLCON0, &bplcon0_val) == 0) {
        bplcon0_val |= BPLCON0_LPEN;  // Enable lightpen
        if (pistorm_write_16(BPLCON0, bplcon0_val) < 0) {
            printf("Could not enable lightpen in BPLCON0\n");
        }
    }
    
    // Initialize uinput for Linux
#ifdef __linux__
    struct uinput_user_dev uidev;
    memset(&uidev, 0, sizeof(uidev));
    
    snprintf(uidev.name, UINPUT_MAX_NAME_SIZE, "Amiga Lightpen via PISTORM");
    uidev.id.bustype = BUS_USB;
    uidev.id.vendor = 0x1234;
    uidev.id.product = 0x5680;
    uidev.id.version = 1;
    
    // Set up absolute axes for lightpen
    uidev.absmin[ABS_X] = 0;
    uidev.absmax[ABS_X] = 752;  // Amiga standard display width
    uidev.absmin[ABS_Y] = 0;
    uidev.absmax[ABS_Y] = 568;  // Amiga standard display height
    uidev.absmin[ABS_PRESSURE] = 0;
    uidev.absmax[ABS_PRESSURE] = 255;
    
    lightpen_state.uinput_fd = open("/dev/uinput", O_WRONLY | O_NONBLOCK);
    if (lightpen_state.uinput_fd < 0) {
        lightpen_state.uinput_fd = open("/dev/input/uinput0", O_WRONLY | O_NONBLOCK);
    }
    
    if (lightpen_state.uinput_fd < 0) {
        perror("Unable to open uinput device");
        return -1;
    }
    
    // Enable absolute movement events
    ioctl(lightpen_state.uinput_fd, UI_SET_EVBIT, EV_ABS);
    ioctl(lightpen_state.uinput_fd, UI_SET_ABSBIT, ABS_X);
    ioctl(lightpen_state.uinput_fd, UI_SET_ABSBIT, ABS_Y);
    ioctl(lightpen_state.uinput_fd, UI_SET_ABSBIT, ABS_PRESSURE);
    
    // Enable key events for stylus buttons
    ioctl(lightpen_state.uinput_fd, UI_SET_EVBIT, EV_KEY);
    ioctl(lightpen_state.uinput_fd, UI_SET_KEYBIT, BTN_TOUCH);
    ioctl(lightpen_state.uinput_fd, UI_SET_KEYBIT, BTN_TOOL_PEN);
    ioctl(lightpen_state.uinput_fd, UI_SET_KEYBIT, BTN_STYLUS);
    ioctl(lightpen_state.uinput_fd, UI_SET_KEYBIT, BTN_STYLUS2);
    
    // Create the uinput device
    if (write(lightpen_state.uinput_fd, &uidev, sizeof(uidev)) < 0) {
        perror("Write user device descriptor failed");
        close(lightpen_state.uinput_fd);
        return -1;
    }
    
    if (ioctl(lightpen_state.uinput_fd, UI_DEV_CREATE) < 0) {
        perror("Device creation failed");
        close(lightpen_state.uinput_fd);
        return -1;
    }
#endif
    
    lightpen_state.initialized = 1;
    printf("Amiga lightpen interface initialized\n");
    return 0;
}

/**
 * @brief Read lightpen position from beam position registers
 * @param x_pos Output X position
 * @param y_pos Output Y position
 * @return 0 on success, negative on error
 */
int amiga_lightpen_read_position(uint16_t *x_pos, uint16_t *y_pos) {
    uint16_t vhpos_val = 0;
    uint16_t vpos_val = 0;
    
    // Read vertical/horizontal position
    if (pistorm_read_16(VHPOSR_ADDR, &vhpos_val) < 0) {
        return -1;
    }
    
    // Read vertical position (includes frame flop)
    if (pistorm_read_16(VPOSR_ADDR, &vpos_val) < 0) {
        return -1;
    }
    
    // Extract X and Y coordinates from registers
    // VHPOSR contains both vertical and horizontal position
    // Format: V7-V0, H8-H1 (bits 7-0 are V, bits 15-8 are H)
    *y_pos = (vhpos_val & 0x00FF);  // Vertical position (V0-V7)
    *x_pos = ((vhpos_val & 0xFF00) >> 8) << 1;  // Horizontal position (H1-H8, shifted to H2-H9)
    
    // Add vertical MSB from VPOSR
    *y_pos |= ((vpos_val & 0x007F) << 8);  // Add V8-V14 as MSBs
    
    return 0;
}

/**
 * @brief Check if lightpen is detected
 * @return 1 if detected, 0 if not
 */
int amiga_lightpen_detected(void) {
    uint16_t potgor_val = 0;
    
    // Read POTGOR to check for lightpen activity
    if (pistorm_read_16(POTGOR_ADDR, &potgor_val) < 0) {
        return 0;
    }
    
    // Lightpen detection is often indicated by specific bit patterns
    // This is a simplified check - real implementation may vary
    return (potgor_val & LIGHTPEN_THRESHOLD) ? 1 : 0;
}

/**
 * @brief Read lightpen button state
 * @return 1 if pressed, 0 if released
 */
int amiga_lightpen_read_button(void) {
    // Lightpen button is typically the fire button on the lightpen
    // This is usually connected to the same circuit as mouse button 0
    uint16_t joydat_val = 0;
    
    if (pistorm_read_16(JOY0DAT, &joydat_val) < 0) {
        return 0;
    }
    
    // Fire button is typically bit 6 in JOY0DAT (active low)
    return !(joydat_val & 0x40);
}

/**
 * @brief Process lightpen events and send to Linux input subsystem
 */
void amiga_lightpen_process_events(void) {
    uint16_t x_pos = 0, y_pos = 0;
    int lightpen_active = amiga_lightpen_detected();
    
    if (lightpen_active) {
        if (amiga_lightpen_read_position(&x_pos, &y_pos) == 0) {
            // Update internal position
            lightpen_state.x_pos = x_pos;
            lightpen_state.y_pos = y_pos;
            lightpen_state.lightpen_detected = 1;
            
            // Read button state
            lightpen_state.lightpen_button = amiga_lightpen_read_button();
            
#ifdef __linux__
            struct input_event ev;
            memset(&ev, 0, sizeof(ev));
            gettimeofday(&ev.time, NULL);
            
            // Send absolute position events
            ev.type = EV_ABS;
            ev.code = ABS_X;
            ev.value = lightpen_state.x_pos;
            write(lightpen_state.uinput_fd, &ev, sizeof(ev));
            
            ev.code = ABS_Y;
            ev.value = lightpen_state.y_pos;
            write(lightpen_state.uinput_fd, &ev, sizeof(ev));
            
            // Send pressure event (simulated)
            ev.code = ABS_PRESSURE;
            ev.value = lightpen_state.lightpen_button ? 255 : 128;
            write(lightpen_state.uinput_fd, &ev, sizeof(ev));
            
            // Send button events
            if (lightpen_state.lightpen_button != lightpen_state.prev_lightpen_button) {
                ev.type = EV_KEY;
                ev.code = BTN_TOUCH;
                ev.value = lightpen_state.lightpen_button ? 1 : 0;
                write(lightpen_state.uinput_fd, &ev, sizeof(ev));
                
                ev.code = BTN_TOOL_PEN;
                ev.value = lightpen_state.lightpen_button ? 1 : 0;
                write(lightpen_state.uinput_fd, &ev, sizeof(ev));
            }
            
            // Send sync event
            ev.type = EV_SYN;
            ev.code = SYN_REPORT;
            ev.value = 0;
            write(lightpen_state.uinput_fd, &ev, sizeof(ev));
#endif
            
            lightpen_state.prev_lightpen_button = lightpen_state.lightpen_button;
            
            printf("Lightpen at (%d, %d), button: %d\n", x_pos, y_pos, lightpen_state.lightpen_button);
        }
    } else {
        // Lightpen not detected - send release events if previously active
        if (lightpen_state.lightpen_detected) {
#ifdef __linux__
            struct input_event ev;
            memset(&ev, 0, sizeof(ev));
            gettimeofday(&ev.time, NULL);
            
            // Send button release
            ev.type = EV_KEY;
            ev.code = BTN_TOUCH;
            ev.value = 0;
            write(lightpen_state.uinput_fd, &ev, sizeof(ev));
            
            ev.code = BTN_TOOL_PEN;
            ev.value = 0;
            write(lightpen_state.uinput_fd, &ev, sizeof(ev));
            
            // Send sync event
            ev.type = EV_SYN;
            ev.code = SYN_REPORT;
            ev.value = 0;
            write(lightpen_state.uinput_fd, &ev, sizeof(ev));
#endif
            
            lightpen_state.lightpen_detected = 0;
            lightpen_state.lightpen_button = 0;
            lightpen_state.prev_lightpen_button = 0;
        }
    }
}

/**
 * @brief Main lightpen polling loop
 */
void amiga_lightpen_poll(void) {
    struct timespec current_time;
    clock_gettime(CLOCK_MONOTONIC, &current_time);
    
    // Rate limit polling
    long time_diff_us = (current_time.tv_sec - lightpen_state.last_poll_time.tv_sec) * 1000000 +
                       (current_time.tv_nsec - lightpen_state.last_poll_time.tv_nsec) / 1000;
    
    if (time_diff_us >= LIGHTPEN_POLL_INTERVAL_US) {
        amiga_lightpen_process_events();
        lightpen_state.last_poll_time = current_time;
    }
}

/**
 * @brief Cleanup lightpen interface
 */
void amiga_lightpen_cleanup(void) {
    if (!lightpen_state.initialized) return;
    
#ifdef __linux__
    if (lightpen_state.uinput_fd >= 0) {
        ioctl(lightpen_state.uinput_fd, UI_DEV_DESTROY);
        close(lightpen_state.uinput_fd);
        lightpen_state.uinput_fd = -1;
    }
#endif
    
    lightpen_state.initialized = 0;
}

/**
 * @brief Test function to verify lightpen interface
 */
int amiga_lightpen_test(void) {
    printf("Testing Amiga lightpen interface...\n");
    
    if (amiga_lightpen_init() < 0) {
        printf("Lightpen initialization failed\n");
        return -1;
    }
    
    // Perform a quick check
    int detected = amiga_lightpen_detected();
    printf("Lightpen detected: %s\n", detected ? "YES" : "NO");
    
    if (detected) {
        uint16_t x, y;
        if (amiga_lightpen_read_position(&x, &y) == 0) {
            printf("Lightpen position: (%d, %d)\n", x, y);
        }
    }
    
    amiga_lightpen_cleanup();
    return 0;
}
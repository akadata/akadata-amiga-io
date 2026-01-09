/*
 * SPDX-License-Identifier: MIT
 * 
 * Amiga Keyboard Input Driver for PISTORM
 * Interfaces with Amiga CIA keyboard matrix to provide Linux input events
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
#define EV_SYN 0x00
#define SYN_REPORT 0

// Basic key codes mapping (subset)
#define KEY_ESC         1
#define KEY_1           2
#define KEY_2           3
#define KEY_3           4
#define KEY_4           5
#define KEY_5           6
#define KEY_6           7
#define KEY_7           8
#define KEY_8           9
#define KEY_9           10
#define KEY_0           11
#define KEY_MINUS       12
#define KEY_EQUAL       13
#define KEY_BACKSPACE   14
#define KEY_TAB         15
#define KEY_Q           16
#define KEY_W           17
#define KEY_E           18
#define KEY_R           19
#define KEY_T           20
#define KEY_Y           21
#define KEY_U           22
#define KEY_I           23
#define KEY_O           24
#define KEY_P           25
#define KEY_LEFTBRACE   26
#define KEY_RIGHTBRACE  27
#define KEY_ENTER       28
#define KEY_LEFTCTRL    29
#define KEY_A           30
#define KEY_S           31
#define KEY_D           32
#define KEY_F           33
#define KEY_G           34
#define KEY_H           35
#define KEY_J           36
#define KEY_K           37
#define KEY_L           38
#define KEY_SEMICOLON   39
#define KEY_APOSTROPHE  40
#define KEY_GRAVE       41
#define KEY_LEFTSHIFT   42
#define KEY_BACKSLASH   43
#define KEY_Z           44
#define KEY_X           45
#define KEY_C           46
#define KEY_V           47
#define KEY_B           48
#define KEY_N           49
#define KEY_M           50
#define KEY_COMMA       51
#define KEY_DOT         52
#define KEY_SLASH       53
#define KEY_RIGHTSHIFT  54
#define KEY_KPASTERISK  55
#define KEY_LEFTALT     56
#define KEY_SPACE       57
#define KEY_CAPSLOCK    58
#define KEY_F1          59
#define KEY_F2          60
#define KEY_F3          61
#define KEY_F4          62
#define KEY_F5          63
#define KEY_F6          64
#define KEY_F7          65
#define KEY_F8          66
#define KEY_F9          67
#define KEY_F10         68
#define KEY_NUMLOCK     69
#define KEY_SCROLLLOCK  70
#define KEY_KP7         71
#define KEY_KP8         72
#define KEY_KP9         73
#define KEY_KPMINUS     74
#define KEY_KP4         75
#define KEY_KP5         76
#define KEY_KP6         77
#define KEY_KPPLUS      78
#define KEY_KP1         79
#define KEY_KP2         80
#define KEY_KP3         81
#define KEY_KP0         82
#define KEY_KPDOT       83

#endif

#include "../pistorm-dev/pistorm_dev.h"  // PISTORM device interface
#include "../platforms/amiga/registers/amiga_memory_map.h"

// Amiga keyboard matrix dimensions
#define AMIGA_KEYBOARD_ROWS 6
#define AMIGA_KEYBOARD_COLS 9

// CIAA register addresses for keyboard
#define CIAA_PRA_ADDR (CIAA_BASE + CIAPRA)    // Port A - keyboard column select
#define CIAA_PRB_ADDR (CIAA_BASE + CIAPRB)    // Port B - keyboard row sense
#define CIAA_DDRA_ADDR (CIAA_BASE + CIADDRA)  // Port A direction
#define CIAA_DDRB_ADDR (CIAA_BASE + CIADDRB)  // Port B direction

// Amiga keyboard matrix mapping
// This maps Amiga keyboard matrix positions to Linux keycodes
static const uint16_t amiga_keymap[AMIGA_KEYBOARD_ROWS][AMIGA_KEYBOARD_COLS] = {
    // Row 0
    {KEY_F1,    KEY_F2,    KEY_F3,    KEY_F4,    KEY_F5,    KEY_F6,    KEY_F7,    KEY_F8,    KEY_F9},
    // Row 1
    {KEY_1,     KEY_2,     KEY_3,     KEY_4,     KEY_5,     KEY_6,     KEY_7,     KEY_8,     KEY_9},
    // Row 2
    {KEY_Q,     KEY_W,     KEY_E,     KEY_R,     KEY_T,     KEY_Y,     KEY_U,     KEY_I,     KEY_O},
    // Row 3
    {KEY_A,     KEY_S,     KEY_D,     KEY_F,     KEY_G,     KEY_H,     KEY_J,     KEY_K,     KEY_L},
    // Row 4
    {KEY_Z,     KEY_X,     KEY_C,     KEY_V,     KEY_B,     KEY_N,     KEY_M,     KEY_TAB,   KEY_ENTER},
    // Row 5
    {KEY_SPACE, KEY_LEFTSHIFT, KEY_RIGHTSHIFT, KEY_LEFTCTRL, KEY_LEFTALT, KEY_BACKSLASH, KEY_COMMA, KEY_DOT, KEY_SLASH}
};

// State tracking for keyboard
static uint8_t keyboard_matrix[AMIGA_KEYBOARD_ROWS];
static uint8_t previous_matrix[AMIGA_KEYBOARD_ROWS];
static int uinput_fd = -1;

/**
 * @brief Initialize the Amiga keyboard interface
 * @return 0 on success, negative on error
 */
int amiga_keyboard_init(void) {
    // Initialize the keyboard matrix state
    memset(keyboard_matrix, 0xFF, sizeof(keyboard_matrix));
    memset(previous_matrix, 0xFF, sizeof(previous_matrix));
    
    // Configure CIA ports for keyboard scanning
    // Port A: Output (column selection)
    // Port B: Input (row sensing)
    if (pistorm_write_8(CIAA_DDRA_ADDR, 0xFF) < 0) {  // All outputs for column selection
        perror("Failed to configure CIAA DDRA for keyboard");
        return -1;
    }
    
    if (pistorm_write_8(CIAA_DDRB_ADDR, 0x00) < 0) {  // All inputs for row sensing
        perror("Failed to configure CIAA DDRB for keyboard");
        return -1;
    }
    
    // Initialize uinput for Linux
#ifdef __linux__
    struct uinput_user_dev uidev;
    memset(&uidev, 0, sizeof(uidev));
    
    snprintf(uidev.name, UINPUT_MAX_NAME_SIZE, "Amiga Keyboard via PISTORM");
    uidev.id.bustype = BUS_USB;
    uidev.id.vendor = 0x1234;
    uidev.id.product = 0x5678;
    uidev.id.version = 1;
    
    uinput_fd = open("/dev/uinput", O_WRONLY | O_NONBLOCK);
    if (uinput_fd < 0) {
        uinput_fd = open("/dev/input/uinput0", O_WRONLY | O_NONBLOCK);
    }
    
    if (uinput_fd < 0) {
        perror("Unable to open uinput device");
        return -1;
    }
    
    // Enable key events
    ioctl(uinput_fd, UI_SET_EVBIT, EV_KEY);
    ioctl(uinput_fd, UI_SET_EVBIT, EV_SYN);
    
    // Enable all keyboard keys
    for (int i = 0; i < 256; i++) {
        ioctl(uinput_fd, UI_SET_KEYBIT, i);
    }
    
    // Create the uinput device
    if (write(uinput_fd, &uidev, sizeof(uidev)) < 0) {
        perror("Write user device descriptor failed");
        close(uinput_fd);
        return -1;
    }
    
    if (ioctl(uinput_fd, UI_DEV_CREATE) < 0) {
        perror("Device creation failed");
        close(uinput_fd);
        return -1;
    }
#endif
    
    printf("Amiga keyboard interface initialized\n");
    return 0;
}

/**
 * @brief Scan the Amiga keyboard matrix
 * @return 0 on success, negative on error
 */
int amiga_keyboard_scan(void) {
    // Save previous state
    memcpy(previous_matrix, keyboard_matrix, sizeof(keyboard_matrix));
    
    // Scan each column
    for (int col = 0; col < AMIGA_KEYBOARD_COLS; col++) {
        uint8_t col_mask = ~(1 << col);  // Active low
        
        // Select the column by writing to Port A
        if (pistorm_write_8(CIAA_PRA_ADDR, col_mask) < 0) {
            return -1;
        }
        
        // Small delay to let the keyboard matrix settle
        usleep(100);
        
        // Read the row states from Port B
        uint8_t row_data = 0;
        if (pistorm_read_8(CIAA_PRB_ADDR, &row_data) < 0) {
            return -1;
        }
        
        // Store the row data for this column
        keyboard_matrix[col % AMIGA_KEYBOARD_ROWS] = row_data;
    }
    
    return 0;
}

/**
 * @brief Process keyboard events and send to Linux input subsystem
 */
void amiga_keyboard_process_events(void) {
    // Compare current and previous states to detect key changes
    for (int row = 0; row < AMIGA_KEYBOARD_ROWS; row++) {
        for (int col = 0; col < AMIGA_KEYBOARD_COLS; col++) {
            uint8_t prev_bit = (previous_matrix[row] >> col) & 1;
            uint8_t curr_bit = (keyboard_matrix[row] >> col) & 1;
            
            if (prev_bit != curr_bit) {
                // Key state changed
                uint16_t keycode = amiga_keymap[row][col];
                int key_pressed = !curr_bit;  // Active low
                
                // Send key event
#ifdef __linux__
                struct input_event ev;
                memset(&ev, 0, sizeof(ev));
                gettimeofday(&ev.time, NULL);
                
                ev.type = EV_KEY;
                ev.code = keycode;
                ev.value = key_pressed ? 1 : 0;
                
                if (write(uinput_fd, &ev, sizeof(ev)) < 0) {
                    perror("Write key event failed");
                }
                
                // Send sync event
                ev.type = EV_SYN;
                ev.code = SYN_REPORT;
                ev.value = 0;
                write(uinput_fd, &ev, sizeof(ev));
#endif
                
                printf("Key %d,%d: %s\n", row, col, key_pressed ? "pressed" : "released");
            }
        }
    }
}

/**
 * @brief Main keyboard polling loop
 */
void amiga_keyboard_poll(void) {
    if (amiga_keyboard_scan() < 0) {
        fprintf(stderr, "Keyboard scan failed\n");
        return;
    }
    
    amiga_keyboard_process_events();
}

/**
 * @brief Cleanup keyboard interface
 */
void amiga_keyboard_cleanup(void) {
#ifdef __linux__
    if (uinput_fd >= 0) {
        ioctl(uinput_fd, UI_DEV_DESTROY);
        close(uinput_fd);
        uinput_fd = -1;
    }
#endif
}

/**
 * @brief Test function to verify keyboard interface
 */
int amiga_keyboard_test(void) {
    printf("Testing Amiga keyboard interface...\n");
    
    if (amiga_keyboard_init() < 0) {
        printf("Keyboard initialization failed\n");
        return -1;
    }
    
    // Perform a quick scan
    if (amiga_keyboard_scan() < 0) {
        printf("Keyboard scan failed\n");
        amiga_keyboard_cleanup();
        return -1;
    }
    
    printf("Keyboard scan completed successfully\n");
    printf("Current keyboard state:\n");
    for (int i = 0; i < AMIGA_KEYBOARD_ROWS; i++) {
        printf("  Row %d: 0x%02X\n", i, keyboard_matrix[i]);
    }
    
    amiga_keyboard_cleanup();
    return 0;
}
/*
 * SPDX-License-Identifier: MIT
 * 
 * Amiga Input Device Manager for PISTORM
 * Manages keyboard, mouse, and lightpen input devices
 * Works with Musl Libc and standard libc implementations
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <sys/time.h>

#include "keyboard.c"  // Include source files directly for simplicity
#include "mouse.c"
#include "lightpen.c"

// Global variables for input management
static volatile int running = 0;
static pthread_t input_thread;

/**
 * @brief Signal handler for graceful shutdown
 */
void signal_handler(int sig) {
    printf("\nReceived signal %d, shutting down gracefully...\n", sig);
    running = 0;
}

/**
 * @brief Input polling thread function
 */
void* input_polling_thread(void* arg) {
    struct timeval last_poll_time, current_time;
    gettimeofday(&last_poll_time, NULL);
    
    while (running) {
        gettimeofday(&current_time, NULL);
        
        // Poll interval - approximately 60Hz (16.67ms)
        long time_diff_us = (current_time.tv_sec - last_poll_time.tv_sec) * 1000000 +
                           (current_time.tv_usec - last_poll_time.tv_usec);
        
        if (time_diff_us >= 16670) {  // ~60Hz polling
            // Poll all input devices
            amiga_keyboard_poll();
            amiga_mouse_poll();
            amiga_lightpen_poll();
            
            last_poll_time = current_time;
        }
        
        // Small sleep to prevent busy-waiting
        usleep(1000);  // 1ms sleep
    }
    
    return NULL;
}

/**
 * @brief Initialize all Amiga input devices
 * @return 0 on success, negative on error
 */
int amiga_input_init(void) {
    printf("Initializing Amiga input devices...\n");
    
    // Initialize keyboard
    if (amiga_keyboard_init() < 0) {
        fprintf(stderr, "Failed to initialize keyboard\n");
        return -1;
    }
    
    // Initialize mouse
    if (amiga_mouse_init() < 0) {
        fprintf(stderr, "Failed to initialize mouse\n");
        amiga_keyboard_cleanup();
        return -1;
    }
    
    // Initialize lightpen
    if (amiga_lightpen_init() < 0) {
        fprintf(stderr, "Failed to initialize lightpen\n");
        amiga_mouse_cleanup();
        amiga_keyboard_cleanup();
        return -1;
    }
    
    printf("All Amiga input devices initialized successfully\n");
    return 0;
}

/**
 * @brief Start the input polling system
 * @return 0 on success, negative on error
 */
int amiga_input_start(void) {
    // Set up signal handlers for graceful shutdown
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGTERM, &sa, NULL);
    
    running = 1;
    
    // Create input polling thread
    if (pthread_create(&input_thread, NULL, input_polling_thread, NULL) != 0) {
        perror("Failed to create input polling thread");
        return -1;
    }
    
    printf("Input polling started\n");
    return 0;
}

/**
 * @brief Stop the input polling system
 */
void amiga_input_stop(void) {
    running = 0;
    
    // Wait for thread to finish
    if (pthread_join(input_thread, NULL) != 0) {
        perror("Failed to join input polling thread");
    }
    
    printf("Input polling stopped\n");
}

/**
 * @brief Cleanup all Amiga input devices
 */
void amiga_input_cleanup(void) {
    printf("Cleaning up Amiga input devices...\n");
    
    amiga_lightpen_cleanup();
    amiga_mouse_cleanup();
    amiga_keyboard_cleanup();
    
    printf("All Amiga input devices cleaned up\n");
}

/**
 * @brief Main function for the input manager
 */
int main(int argc, char* argv[]) {
    printf("Amiga Input Device Manager for PISTORM\n");
    printf("=====================================\n");
    
    // Parse command line arguments
    int test_mode = 0;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--test") == 0 || strcmp(argv[i], "-t") == 0) {
            test_mode = 1;
        } else if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) {
            printf("Usage: %s [options]\n", argv[0]);
            printf("Options:\n");
            printf("  -t, --test    Run in test mode (initialize and exit)\n");
            printf("  -h, --help    Show this help message\n");
            return 0;
        }
    }
    
    if (test_mode) {
        printf("Running in test mode...\n");
        
        // Test keyboard
        if (amiga_keyboard_test() < 0) {
            printf("Keyboard test failed\n");
        }
        
        // Test mouse
        if (amiga_mouse_test() < 0) {
            printf("Mouse test failed\n");
        }
        
        // Test lightpen
        if (amiga_lightpen_test() < 0) {
            printf("Lightpen test failed\n");
        }
        
        printf("Test mode completed\n");
        return 0;
    }
    
    // Initialize all input devices
    if (amiga_input_init() < 0) {
        fprintf(stderr, "Failed to initialize input devices\n");
        return 1;
    }
    
    // Start input polling
    if (amiga_input_start() < 0) {
        fprintf(stderr, "Failed to start input polling\n");
        amiga_input_cleanup();
        return 1;
    }
    
    printf("Input manager running. Press Ctrl+C to exit.\n");
    
    // Main loop - wait for signal to exit
    while (running) {
        sleep(1);
    }
    
    // Cleanup
    amiga_input_stop();
    amiga_input_cleanup();
    
    printf("Input manager exited cleanly\n");
    return 0;
}
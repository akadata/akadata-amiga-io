/*
 * SPDX-License-Identifier: MIT
 * 
 * Amiga Input Device Headers for PISTORM
 * Defines interfaces for keyboard, mouse, and lightpen input devices
 */

#ifndef AMIGA_INPUT_H
#define AMIGA_INPUT_H

#include <stdint.h>

// Keyboard interface
int amiga_keyboard_init(void);
int amiga_keyboard_scan(void);
void amiga_keyboard_process_events(void);
void amiga_keyboard_poll(void);
void amiga_keyboard_cleanup(void);
int amiga_keyboard_test(void);

// Mouse interface
int amiga_mouse_init(void);
int amiga_mouse_read_counters(int mouse_num, int8_t *x_delta, int8_t *y_delta);
uint8_t amiga_mouse_read_buttons(int mouse_num);
void amiga_mouse_process_events(void);
void amiga_mouse_poll(void);
void amiga_mouse_cleanup(void);
int amiga_mouse_test(void);

// Lightpen interface
int amiga_lightpen_init(void);
int amiga_lightpen_read_position(uint16_t *x_pos, uint16_t *y_pos);
int amiga_lightpen_detected(void);
int amiga_lightpen_read_button(void);
void amiga_lightpen_process_events(void);
void amiga_lightpen_poll(void);
void amiga_lightpen_cleanup(void);
int amiga_lightpen_test(void);

// Input manager interface
int amiga_input_init(void);
int amiga_input_start(void);
void amiga_input_stop(void);
void amiga_input_cleanup(void);

#endif // AMIGA_INPUT_H
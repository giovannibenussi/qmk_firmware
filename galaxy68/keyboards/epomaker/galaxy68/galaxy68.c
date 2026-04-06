/* Copyright 2024 Epomaker
 * Copyright 2024 Epomaker <https://github.com/Epomaker>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "../../lib/rdr_lib/rdr_common.h"

// Forward declaration for keymap-specific key handling
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) __attribute__((weak));
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;  // Default implementation if not defined in keymap
}

void matrix_io_delay(void) {
}

void matrix_output_select_delay(void) {
}

void matrix_output_unselect_delay(uint8_t line, bool key_pressed) {
}

led_config_t g_led_config = { {
    { 0,      NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
    { NO_LED, 1,      2,      3,      4,      5,      6,      7,      8,      9,      10,     11,     12,     13,     14,     15},
    { 16,     17,     18,     19,     20,     21,     22,     23,     24,     25,     26,     27,     28,     29,     30,     31},
    { 32,     33,     34,     35,     36,     37,     38,     39,     40,     41,     42,     43,     NO_LED, 44,     NO_LED, NO_LED},
    { 45,     NO_LED, 46,     47,     48,     49,     50,     51,     52,     53,     54,     55,     NO_LED, 56,     57,     NO_LED},
    { 58,     59,     60,     NO_LED, NO_LED, 61,     NO_LED, NO_LED, NO_LED, 62,     63,     NO_LED, 64,     65,     66,     67}
}, {
    {7, 14}, {21, 14}, {35, 14}, {49, 14}, {63, 14}, {77, 14}, {91, 14}, {105, 14}, {119, 14}, {133, 14}, {147, 14}, {161, 14}, {175, 14}, {189, 14}, {203, 14}, {217, 14},
    {7, 26}, {21, 26}, {35, 26}, {49, 26}, {63, 26}, {77, 26}, {91, 26}, {105, 26}, {119, 26}, {133, 26}, {147, 26}, {161, 26}, {175, 26}, {189, 26}, {203, 26}, {217, 26},
    {7, 38}, {21, 38}, {35, 38}, {49, 38}, {63, 38}, {77, 38}, {91, 38}, {105, 38}, {119, 38}, {133, 38}, {147, 38}, {161, 38},            {189, 38},
    {7, 50},           {35, 50}, {49, 50}, {63, 50}, {77, 50}, {91, 50}, {105, 50}, {119, 50}, {133, 50}, {147, 50}, {161, 50},            {189, 50}, {203, 50},
    {7, 62}, {21, 62}, {35, 62},                     {77, 62},                                 {133, 62}, {147, 62},            {161, 62}, {189, 62}, {203, 62}, {217, 62},

    {225, 65}, {225, 65}, {225, 65}, {225, 65}, {225, 65},
    {225, 65}, {225, 65}, {225, 65}, {225, 65}, {225, 65}, {225, 65}, {225, 65}, {225, 65},
    {225, 65}, {225, 65}, {225, 65}, {225, 65}, {225, 65}, {225, 65}, {225, 65}, {225, 65},
    {225, 65}, {225, 65}, {225, 65}, {225, 65}, {225, 65}, {225, 65}, {225, 65}, {225, 65},
    {225, 65}, {225, 65}, {225, 65}, {225, 65}
}, {
	1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,      1,
    1,      1,  1,  1,  1,  1,  1,  1,  1,  1,  1,      1,  1,
    1,  1,  1,          1,              1,  1,      1,  1,  1,  1,

    0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0
} };

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    User_Led_Show();
    return false;
}

void notify_usb_device_state_change_user(enum usb_device_state usb_device_state)  {
    if (Keyboard_Info.Key_Mode == QMK_USB_MODE) {
        if(usb_device_state == USB_DEVICE_STATE_CONFIGURED) {
            Usb_If_Ok_Led = true;
        } else {
            Usb_If_Ok_Led = false;
        }
    } else {
        Usb_If_Ok_Led = false;
    }
}

void housekeeping_task_user(void) {
    User_Keyboard_Reset();
    es_chibios_user_idle_loop_hook();
}

void board_init(void) {
    User_Keyboard_Init();
}

void keyboard_post_init_user(void) {
    User_Keyboard_Post_Init();
}

// Custom keycodes should be handled in process_record_keymap() in your keymap.c
// This function calls the keymap handler first, then handles USB/power management
bool process_record_user(uint16_t keycode, keyrecord_t *record) {   /*键盘只要有按键按下就会调用此函数*/
    Usb_Change_Mode_Delay = 0;                                      /*只要有按键就不会进入休眠*/
    Usb_Change_Mode_Wakeup = false;

    // Call keymap-specific handler first
    if (!process_record_keymap(keycode, record)) {
        return false;
    }

    return Key_Value_Dispose(keycode, record);
}

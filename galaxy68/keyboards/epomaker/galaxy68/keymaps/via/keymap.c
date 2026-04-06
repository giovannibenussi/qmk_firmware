/* Copyright 2023 Yiancar-Designs
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
#include QMK_KEYBOARD_H
#include "../../lib/rdr_lib/rdr_common.h"

enum layers {
    _BASE,
    _ARROWS,
    _ORIGINAL,
    _CTRL,
    _VIM_TMUX
};

enum custom_keycodes {
    TMUX_PREVIOUS_WINDOW = SAFE_RANGE,
    TMUX_NEXT_WINDOW,
    TMUX_PREVIOUS,
    TMUX_LIST,
    VIM_PREVIOUS_TAB,
    VIM_NEXT_TAB,
    UI_COMBO_A,  // Alternative to combo: custom keycode for U+I → A
    PREVIOUS_TAB,
    NEXT_TAB,
    PREVIOUS_APPLICATION,
    VIM_CLIPBOARD_REGISTER,
};

// Combos are not supported on Epomaker Galaxy68 (causes boot failure)
// Use the alternative tap-dance or custom macro approach instead

// JK combo state tracking
static uint16_t j_press_time = 0;
#define JK_COMBO_TERM 100  // milliseconds - adjust if needed

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_tkl_ansi(
        QK_GESC,         KC_1,         KC_2,         KC_3,              KC_4,          KC_5,        KC_6,        KC_7,                    KC_8,                    KC_9,          KC_0,                     KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  KC_END,  KC_MUTE,
        KC_TAB,          KC_Q,         KC_W,         KC_E,              KC_R,          KC_T,        KC_Y,        KC_U,                    KC_I,                    KC_O,          KC_P,                     KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP, KC_PGDN,
        LT(_CTRL, KC_GRAVE), LCMD_T(KC_A), LCTL_T(KC_S), LOPT_T(KC_D),      LSFT_T(KC_F),  KC_G,        KC_H,        LSFT_T(KC_J),            LOPT_T(KC_K),            LCTL_T(KC_L),  LCMD_T(KC_BACKSPACE),     KC_QUOT,          KC_ENT,
        KC_LSFT,                       KC_Z,         KC_X,              KC_C,          LT(_VIM_TMUX, KC_V), KC_B,        LT(_VIM_TMUX, KC_N),             KC_M,                    KC_COMM,       KC_DOT,                   KC_SLSH,          KC_RSFT, KC_UP,
        KC_LCTL,         KC_LALT,      KC_LGUI,                                        LT(_ARROWS, KC_SPC),                                                      KC_RALT,       MO(_ORIGINAL),                                      KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_ARROWS] = LAYOUT_tkl_ansi(
        KC_GRV,  KC_F1,   KC_F2,                KC_F3,   KC_F4,   KC_F5, KC_F6,    KC_F7,  VIM_CLIPBOARD_REGISTER,   KC_F9,    KC_F10,   KC_F11,   KC_F12,   RGB_RTOG, KC_INS,   KC_DEL,   KC_MUTE,
        KC_TAB,  LCMD(KC_W),    PREVIOUS_APPLICATION, PREVIOUS_TAB, NEXT_TAB, KC_T,  KC_Y, KC_U, KC_I, KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP, KC_PGDN,
        KC_CAPS, KC_A,    KC_S,                 KC_D,    KC_F,    KC_G,  KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,          KC_Z,                 KC_X,    KC_C,    KC_V,  KC_B, KC_N, KC_M, KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,
        MD_BLE1, MD_BLE2, MD_BLE3,                                  KC_SPC,                      MD_24G, MO(3),                      KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_CTRL] = LAYOUT_tkl_ansi(
        KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,      KC_TRNS,       KC_TRNS, KC_TRNS,     KC_TRNS,      KC_TRNS,        KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, C(KC_W),  C(KC_E),      C(KC_R),       C(KC_T), C(KC_Y),     C(KC_U),      KC_LEFT_PAREN,  KC_RIGHT_PAREN, C(KC_P),  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, C(KC_S),  C(KC_D),      LSFT_T(KC_F),  KC_TRNS, C(KC_H),     C(KC_J),      C(KC_K),        KC_QUOTE,       KC_SCLN,  KC_GRAVE,          KC_TRNS,
        KC_TRNS,          KC_TRNS,  C(KC_X),      C(KC_C),       KC_TRNS, KC_TRNS,     KC_ASTERISK,  KC_SLASH,       KC_TRNS,        KC_TRNS,  KC_TRNS,           KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                               KC_ENTER,                                            KC_TRNS,        KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_ORIGINAL] = LAYOUT_tkl_ansi(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,    KC_F6,    KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_F11,   KC_F12,   RGB_RTOG, KC_INS,   KC_DEL,   KC_MUTE,
        KC_TAB,  MD_BLE1, MD_BLE2, MD_BLE3, MD_24G,  KC_T,     SIDE_MOD, TIME_ST, RGB_SAD, RGB_SAI,  KC_P,     KC_LBRC,  KC_RBRC,  RGB_HUI,  KC_HOME,  KC_END,
        KC_CAPS, TO(0),   TO(1),   KC_D,    KC_F,    KC_G,     QK_DEB,   KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_QUOT,            RGB_MOD,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,     QK_BAT,   KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,            LOGO_MOD, RGB_VAI,
        CHAG_K,  QK_WLO,  KC_LGUI,                   EE_CLR,                                KC_RGUI,  KC_NO,              KC_RCTL,  RGB_SPD,  RGB_VAD,  RGB_SPI
    ),
    [_VIM_TMUX] = LAYOUT_tkl_ansi(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,              KC_TRNS,          KC_TRNS,     KC_TRNS,     KC_TRNS,             KC_TRNS,               KC_TRNS,                KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,              KC_TRNS,          KC_TRNS,     KC_TRNS,     KC_LEFT_PAREN,       KC_RIGHT_PAREN,        KC_MINUS,               KC_EQUAL,      KC_TRNS, KC_TRNS, TMUX_LIST, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, VIM_PREVIOUS_TAB,     VIM_NEXT_TAB,     KC_ASTERISK, KC_ASTERISK, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE,  KC_QUOTE,               TMUX_PREVIOUS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, TMUX_PREVIOUS_WINDOW, TMUX_NEXT_WINDOW, KC_TRNS,     KC_QUESTION, KC_SLASH,            KC_LEFT_ANGLE_BRACKET, KC_RIGHT_ANGLE_BRACKET, KC_TRNS,       KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                                 KC_ENTER,                                                                                         KC_TRNS,                   KC_TRNS,                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
};

// IMPORTANT: This MUST be named process_record_keymap(), NOT process_record_user()
// The base galaxy68.c file already defines process_record_user() and calls this function
// Using process_record_user() here will cause a "multiple definition" linker error
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    // JK combo detection - let keys process normally, fix up afterward
    if (keycode == LSFT_T(KC_J) && record->event.pressed) {
        j_press_time = timer_read();
        return true;  // Let J process normally
    }

    if (keycode == LOPT_T(KC_K) && record->event.pressed) {
        if (j_press_time > 0 && timer_elapsed(j_press_time) < JK_COMBO_TERM) {
            // Combo detected! Wait for J to be sent, then fix it
            wait_ms(20);  // Give J time to be fully processed
            tap_code(KC_BSPC);  // Delete J
            tap_code(KC_ENT);   // Send Enter
            j_press_time = 0;
            return false;  // Block K from being sent
        }
    }

    // Reset timer on other keys
    if (record->event.pressed && keycode != LSFT_T(KC_J) && keycode != LOPT_T(KC_K)) {
        j_press_time = 0;
    }

    // Handle custom keycodes
    if (record->event.pressed) {
        switch (keycode) {
            case TMUX_PREVIOUS_WINDOW:
                SEND_STRING(SS_LCTL("s") "p");
                return false;
            case TMUX_NEXT_WINDOW:
                SEND_STRING(SS_LCTL("s") "n");
                return false;
            case TMUX_PREVIOUS:
                SEND_STRING(SS_LCTL("s") "L");
                return false;
            case TMUX_LIST:
                SEND_STRING(SS_LCTL("s") "s");
                return false;
            case VIM_PREVIOUS_TAB:
                SEND_STRING("gT");
                return false;
            case VIM_NEXT_TAB:
                SEND_STRING("gt");
                return false;
            case PREVIOUS_TAB:
                SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LSFT) SS_TAP(X_TAB) SS_UP(X_LSFT) SS_UP(X_LCTL));
                return false;
            case NEXT_TAB:
                SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_TAB) SS_UP(X_LCTL));
                return false;
            case PREVIOUS_APPLICATION:
                SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_TAB) SS_UP(X_LGUI));
                return false;
            case VIM_CLIPBOARD_REGISTER:
                SEND_STRING("\"*");
                return false;
        }
    }
    return true;
};


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE]     = { ENCODER_CCW_CW(KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP) },
    [_ARROWS]   = { ENCODER_CCW_CW(KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP) },
    [_CTRL]     = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [_ORIGINAL] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [_VIM_TMUX] = { ENCODER_CCW_CW(KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP) }
};
#endif



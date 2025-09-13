/* Copyright 2022 Gondolindrim
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

enum custom_keycodes {
    TMUX_PREVIOUS_WINDOW = SAFE_RANGE,
    TMUX_NEXT_WINDOW,
    TMUX_CREATE_WINDOW,
    TMUX_CLOSE_WINDOW,
    TMUX_LIST,
    TMUX_PREVIOUS,
    TMUX_SCROLL,
    TMUX_SCROLL_AND_SEARCH,
    TMUX_ZOOM,
    PREVIOUS_TAB,
    NEXT_TAB,
    PREVIOUS_APPLICATION,
    VIM_CLIPBOARD_REGISTER,
    VIM_SAVE,
    VIM_SAVE_AND_FOCUS_TMUX,
    VIM_PREVIOUS_TAB,
    VIM_NEXT_TAB,
    VIM_CLOSE_TAB
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_65_ansi_blocker( /* Base */
    QK_GRAVE_ESCAPE,       KC_1   ,      KC_2,         KC_3   ,         KC_4  ,       KC_5    , KC_6   , KC_7   ,      KC_8   ,      KC_9   ,      KC_0   ,         KC_MINS, KC_EQL , KC_BSPC, LT(1, KC_DEL),
    LT(3, KC_TAB), KC_Q   ,      KC_W        , KC_E   ,         KC_R  ,       KC_T    , KC_Y   , KC_U   ,      KC_I   ,      KC_O   ,      KC_P,            KC_LBRC, KC_RBRC, KC_BSLS, KC_AUDIO_VOL_UP,
    LT(2, KC_GRAVE),       LCMD_T(KC_A), LCTL_T(KC_S), LOPT_T(KC_D),    LSFT_T(KC_F), KC_G,     KC_H,    LSFT_T(KC_J), LOPT_T(KC_K), LCTL_T(KC_L), LCMD_T(KC_BACKSPACE), KC_SEMICOLON, KC_ENT,           KC_AUDIO_VOL_DOWN,
    KC_LEFT_SHIFT, LT(9, KC_Z),         KC_X,         KC_C,            LT(4, KC_V)  ,       KC_B    , LT(8, KC_N), LT(8, KC_M),      KC_COMM,      KC_DOT ,      KC_SLSH,         KC_RSFT         , KC_UP  , KC_MEDIA_PLAY_PAUSE,
    KC_LCTL,       KC_LALT,      KC_LGUI,                            LT(3, KC_SPACE),                    KC_MEH,      MO(1)  ,      KC_LEFT,      KC_DOWN,         KC_RGHT
),
[1] = LAYOUT_65_ansi_blocker(
    QK_BOOT, KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP, KC_MISSION_CONTROL, KC_LAUNCHPAD, KC_MEDIA_PREV_TRACK, KC_MPLY, KC_MEDIA_NEXT_TRACK, KC_MUTE, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_F11, KC_F12, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLU,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                   KC_TRNS, KC_TRNS, KC_MEDIA_PREV_TRACK, KC_MPLY, KC_MEDIA_NEXT_TRACK
),
[2] = LAYOUT_65_ansi_blocker(
    KC_GRAVE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, C(KC_W), C(KC_E), C(KC_R), C(KC_T), C(KC_Y), C(KC_U), KC_LEFT_PAREN, KC_RIGHT_PAREN, C(KC_P), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, C(KC_S), C(KC_D), LSFT_T(KC_F), KC_TRNS, C(KC_H), C(KC_J), C(KC_K), KC_QUOTE, KC_SCLN, KC_GRAVE, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, C(KC_X), C(KC_C), KC_TRNS, KC_TRNS, KC_ASTERISK, KC_SLASH, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,          KC_ENTER,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
// Space Layer
[3] = LAYOUT_65_ansi_blocker(
    QK_BOOT, KC_F1  , TMUX_PREVIOUS_WINDOW, TMUX_NEXT_WINDOW, KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_TRNS, KC_MUTE,
    LCMD(KC_TAB), VIM_CLOSE_TAB, LCMD(KC_W), VIM_NEXT_TAB, LCMD(KC_R), LCMD(KC_T), KC_TRNS, KC_U, KC_TRNS, KC_TRNS, TMUX_PREVIOUS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLU,
    KC_TRNS, LCMD_T(KC_A), LCTL_T(KC_S), LOPT_T(KC_D),    LSFT_T(KC_F), KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, TMUX_LIST, KC_TRNS, KC_TRNS, KC_VOLD,
    KC_TRNS, KC_TRNS, KC_TRNS,          KC_C,              KC_TRNS, KC_TRNS, KC_ASTERISK, KC_SLASH, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
    KC_TRNS, KC_TRNS, KC_TRNS,          KC_ENTER,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[4] = LAYOUT_65_ansi_blocker(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_MINUS, KC_EQUAL, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LT(7, KC_ASTERISK), KC_TRNS, KC_ASTERISK, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, KC_QUOTE, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_QUESTION, KC_SLASH, KC_LEFT_ANGLE_BRACKET, KC_RIGHT_ANGLE_BRACKET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,          KC_ENTER,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[5] = LAYOUT_65_ansi_blocker(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,          KC_ENTER,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
// F-Row
[6] = LAYOUT_65_ansi_blocker(
    QK_BOOT, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_TRNS, KC_MUTE,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLU,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                   KC_TRNS, KC_TRNS, KC_MEDIA_PREV_TRACK, KC_MPLY, KC_MEDIA_NEXT_TRACK
),
[7] = LAYOUT_65_ansi_blocker(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT_BRACKET, KC_RIGHT_BRACKET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,          KC_ENTER,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[8] = LAYOUT_65_ansi_blocker(
    QK_BOOT, KC_F1  , KC_TRNS, KC_TRNS, KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_TRNS, KC_MUTE,
    KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLU,
    KC_TRNS, KC_TRNS, KC_TRNS, VIM_PREVIOUS_TAB, VIM_NEXT_TAB, KC_TRNS, KC_TRNS, KC_TRNS, TMUX_SCROLL_AND_SEARCH, TMUX_SCROLL, TMUX_PREVIOUS, KC_TRNS, KC_TRNS, KC_VOLD,
    KC_TRNS, TMUX_ZOOM, TMUX_CREATE_WINDOW, TMUX_PREVIOUS_WINDOW, TMUX_NEXT_WINDOW, KC_TRNS, KC_TRNS, TMUX_LIST, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
    TMUX_CLOSE_WINDOW, KC_TRNS, KC_TRNS,          KC_ENTER,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[9] = LAYOUT_65_ansi_blocker(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TMUX_PREVIOUS_WINDOW, TMUX_NEXT_WINDOW, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TMUX_PREVIOUS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, VIM_PREVIOUS_TAB, VIM_NEXT_TAB, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TMUX_LIST, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,          KC_ENTER,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
// [3] = LAYOUT_65_ansi_blocker(
//     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//     KC_TRNS, KC_TRNS, KC_TRNS,          KC_ENTER,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
// ),
};

enum combos {
    AB_ESC,
    PREVIOUS_TAB_COMBO,
    NEXT_TAB_COMBO,
    PREVIOUS_APPLICATION_COMBO,
    VIM_CLIPBOARD_REGISTER_COMBO,
    VIM_SAVE_COMBO,
    VIM_SAVE_AND_FOCUS_TMUX_COMBO,
    JK_TAB,
    QW_SFT,
    SD_LAYER,
    SEND_ENTER
};

// LCMD_T(KC_A), LCTL_T(KC_S), LOPT_T(KC_D), LSFT_T(KC_F),
const uint16_t PROGMEM previous_tab_combo[] = {LCTL_T(KC_S), LOPT_T(KC_D), COMBO_END};
const uint16_t PROGMEM next_tab_combo[] = {LOPT_T(KC_D), LSFT_T(KC_F), COMBO_END};
const uint16_t PROGMEM previous_application_combo[] = {LCTL_T(KC_S), LOPT_T(KC_D), LSFT_T(KC_F), COMBO_END};
const uint16_t PROGMEM vim_save_combo[] = {LCTL_T(KC_S), LSFT_T(KC_F), COMBO_END};
const uint16_t PROGMEM vim_save_combo_and_focus_tmux_combo[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM send_enter_combo[] = {LSFT_T(KC_J), LOPT_T(KC_K), COMBO_END};
const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM vim_clipboard_register_combo[] = {KC_U, KC_I, COMBO_END};

combo_t key_combos[] = {
    [PREVIOUS_TAB_COMBO] = COMBO(previous_tab_combo, PREVIOUS_TAB),
    [NEXT_TAB_COMBO] = COMBO(next_tab_combo, NEXT_TAB),
    [VIM_CLIPBOARD_REGISTER_COMBO] = COMBO(vim_clipboard_register_combo, VIM_CLIPBOARD_REGISTER),
    [VIM_SAVE_COMBO] = COMBO(vim_save_combo, VIM_SAVE),
    [VIM_SAVE_AND_FOCUS_TMUX_COMBO] = COMBO(vim_save_combo_and_focus_tmux_combo, VIM_SAVE_AND_FOCUS_TMUX),
    [PREVIOUS_APPLICATION_COMBO] = COMBO(previous_application_combo, PREVIOUS_APPLICATION),
    [SEND_ENTER] = COMBO(send_enter_combo, KC_ENTER),
    [QW_SFT] = COMBO(qw_combo, KC_LSFT),
};

bool get_combo_must_tap(uint16_t combo_index, combo_t *combo) {
    switch (combo_index) {
        case SEND_ENTER:
            return true;  // Only trigger this combo if both keys are tapped
        default:
            return false; // Other combos can behave normally
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case TMUX_PREVIOUS_WINDOW:
                SEND_STRING(SS_LCTL("s") "p");
                return false;
            case TMUX_NEXT_WINDOW:
                SEND_STRING(SS_LCTL("s") "n");
                return false;
            case TMUX_CREATE_WINDOW:
                SEND_STRING(SS_LCTL("s") "c");
                return false;
            case TMUX_CLOSE_WINDOW:
                SEND_STRING(SS_LCTL("s") "xy");
                return false;
            case TMUX_LIST:
                SEND_STRING(SS_LCTL("s") "s");
                return false;
            case TMUX_PREVIOUS:
                SEND_STRING(SS_LCTL("s") "L");
                return false;
            case TMUX_SCROLL:
                SEND_STRING(SS_LCTL("s") "[");
                return false;
            case TMUX_SCROLL_AND_SEARCH:
                SEND_STRING(SS_LCTL("s") "[?");
                return false;
            case TMUX_ZOOM:
                SEND_STRING(SS_LCTL("s") "z");
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
            case VIM_PREVIOUS_TAB:
                SEND_STRING("gT");
                return false;
            case VIM_NEXT_TAB:
                SEND_STRING("gt");
                return false;
            case VIM_CLOSE_TAB:
                SEND_STRING(SS_TAP(X_ESC) " q");
                return false;
            case VIM_SAVE:
                SEND_STRING(SS_TAP(X_ESC) " w");
                return false;
            case VIM_SAVE_AND_FOCUS_TMUX:
                SEND_STRING(SS_TAP(X_ESC) " w fr");
                return false;
        }
    }
    return true;
};

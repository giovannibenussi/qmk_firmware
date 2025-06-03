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
    TMUX_LIST,
    PREVIOUS_TAB,
    NEXT_TAB,
    PREVIOUS_APPLICATION,
    VIM_CLIPBOARD_REGISTER,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_65_ansi_blocker( /* Base */
    KC_ESC ,       KC_1   ,      KC_2,         KC_3   ,         KC_4  ,       KC_5    , KC_6   , KC_7   ,      KC_8   ,      KC_9   ,      KC_0   ,         KC_MINS, KC_EQL , KC_BSPC, LT(2, KC_DEL),
    LT(2, KC_TAB) , KC_Q   ,      KC_W        , KC_E   ,         KC_R  ,       KC_T    , KC_Y   , KC_U   ,      KC_I   ,      KC_O   ,      KC_P,            KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
    MO(3),       LCMD_T(KC_A), LCTL_T(KC_S), LOPT_T(KC_D),    LSFT_T(KC_F), KC_G,     KC_H,    LSFT_T(KC_J), LOPT_T(KC_K), LCTL_T(KC_L), LCMD_T(KC_SCLN), KC_QUOT, KC_ENT,           KC_PGDN,
    KC_LEFT_SHIFT, KC_Z,         KC_X,         KC_C,            KC_V  ,       KC_B    , KC_N   , KC_M   ,      KC_COMM,      KC_DOT ,      KC_SLSH,         KC_RSFT         , KC_UP  , KC_END ,
    KC_LCTL,       KC_LALT,      KC_LGUI,                            KC_SPC ,                    KC_RALT,      MO(1)  ,      KC_LEFT,      KC_DOWN,         KC_RGHT
),
[1] = LAYOUT_65_ansi_blocker(
    QK_BOOT, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_TRNS, KC_MUTE,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLU,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
    KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[2] = LAYOUT_65_ansi_blocker(
    QK_BOOT, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_TRNS, KC_MUTE,
    KC_TRNS, KC_TRNS, TMUX_PREVIOUS_WINDOW, TMUX_NEXT_WINDOW, KC_R, KC_TRNS, KC_TRNS, KC_U, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLU,
    KC_TRNS, KC_TRNS, KC_TRNS,          KC_D,              KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, TMUX_LIST, KC_TRNS, KC_TRNS, KC_VOLD,
    KC_TRNS, KC_TRNS, KC_TRNS,          KC_C,              KC_TRNS, KC_TRNS, KC_ASTERISK, KC_SLASH, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
    KC_TRNS, KC_TRNS, KC_TRNS,          KC_ENTER,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[3] = LAYOUT_65_ansi_blocker(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, C(KC_E), KC_TRNS, KC_TRNS, C(KC_Y), C(KC_U), KC_TRNS, KC_TRNS, C(KC_P), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, C(KC_S), C(KC_D), KC_TRNS, KC_TRNS, C(KC_H), C(KC_J), C(KC_K), C(KC_L), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, C(KC_C), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,          KC_ENTER,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)
// [3] = LAYOUT_65_ansi_blocker(
//     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//     KC_TRNS, KC_TRNS, KC_TRNS,          KC_ENTER,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
// )
};

enum combos {
    AB_ESC,
    PREVIOUS_TAB_COMBO,
    NEXT_TAB_COMBO,
    PREVIOUS_APPLICATION_COMBO,
    VIM_CLIPBOARD_REGISTER_COMBO,
    JK_TAB,
    QW_SFT,
    SD_LAYER
};

const uint16_t PROGMEM ab_combo[] = {LCMD_T(KC_A), KC_B, COMBO_END};
const uint16_t PROGMEM previous_tab_combo[] = {LCMD_T(KC_A), LCTL_T(KC_S), COMBO_END};
const uint16_t PROGMEM next_tab_combo[] = {LCTL_T(KC_S), LOPT_T(KC_D), COMBO_END};
const uint16_t PROGMEM previous_application_combo[] = {LCMD_T(KC_A), LCTL_T(KC_S), LOPT_T(KC_D), COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM vim_clipboard_register_combo[] = {KC_U, KC_I, COMBO_END};

combo_t key_combos[] = {
    [AB_ESC] = COMBO(ab_combo, KC_ESC),
    [PREVIOUS_TAB_COMBO] = COMBO(previous_tab_combo, PREVIOUS_TAB),
    [NEXT_TAB_COMBO] = COMBO(next_tab_combo, NEXT_TAB),
    [VIM_CLIPBOARD_REGISTER_COMBO] = COMBO(vim_clipboard_register_combo, VIM_CLIPBOARD_REGISTER),
    [PREVIOUS_APPLICATION_COMBO] = COMBO(previous_application_combo, PREVIOUS_APPLICATION),
    [JK_TAB] = COMBO(jk_combo, KC_TAB),
    [QW_SFT] = COMBO(qw_combo, KC_LSFT),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case TMUX_PREVIOUS_WINDOW:
                SEND_STRING(SS_LCTL("s") "p");
                return false;
            case TMUX_NEXT_WINDOW:
                SEND_STRING(SS_LCTL("s") "n");
                return false;
            case TMUX_LIST:
                SEND_STRING(SS_LCTL("s") "s");
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

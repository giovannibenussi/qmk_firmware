/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
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
#include "version.h"

enum layers {
    BASE,
    SYMBOLS,
    SYMBOLS_ALT,
    NUMBERS,
    VIM_TMUX,
    NUMPAD,
    RGB_LAYER,
};

enum custom_keycodes {
    VRSN = ML_SAFE_RANGE,
    TYPE_EMAIL,
    SAVE_VIM,
    VIM_TAB_PREV,
    VIM_TAB_NEXT,
    TMUX_PREVIOUS_WINDOW,
    TMUX_NEXT_WINDOW,
    TMUX_PREVIOUS_SESSION,
    TMUX_ZOOM,
    TMUX_SCROLL,
    TMUX_ZOOM_SCROLL,
    SONG_1,
    SONG_2,
    SONG_3,
    SONG_4,
    SONG_5,
    SONG_6,
    SONG_7,
    SONG_8,
    SONG_9,
    SONG_0,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_moonlander(
    _______,         _______,               _______,      _______,      _______,      _______, _______,           _______,             _______,            _______,      _______,      _______,         _______,           _______,
    KC_GRAVE,        KC_Q,                  KC_W,         KC_E,         KC_R,         KC_T,    _______,           _______,             KC_Y,               KC_U,         KC_I,         KC_O,            KC_P,              KC_SCOLON,
    LCTL_T(KC_TAB),  LCMD_T(KC_A),          LCTL_T(KC_S), LOPT_T(KC_D), LSFT_T(KC_F), KC_G,    KC_NO,             KC_NO,               KC_H,               LSFT_T(KC_J), LOPT_T(KC_K), LCTL_T(KC_L),    LCMD_T(KC_BSPC),   KC_QUOT,
    LSFT_T(KC_CAPS), LT(VIM_TMUX, KC_Z),    KC_X,         KC_C,         KC_V,         KC_B,                                            KC_N,               KC_M,         KC_COMM,      KC_DOT,          RCTL_T(KC_SLSH),   KC_RSFT,
    _______,         _______,               _______,     _______,      _______,      _______,                                         _______,             KC_LEAD,      TT(NUMPAD),      _______,         _______,           _______,
                                                               LT(SYMBOLS, KC_ENT),       LT(VIM_TMUX, KC_ESC),  KC_LGUI,           LT(RGB_LAYER, KC_ESC), KC_BSPC, LT(NUMBERS, KC_SPC)
  ),

  [SYMBOLS] = LAYOUT_moonlander(
      _______, _______,    _______,  _______, _______,                         _______,     _______,           _______, _______,      _______,               _______,                _______,     _______,  _______,
      _______, KC_EXCLAIM, KC_AT,    KC_HASH, KC_DOLLAR,                       KC_PERCENT,  _______,           _______, KC_AMPERSAND, KC_LEFT_PAREN,         KC_RIGHT_PAREN,         KC_MINUS,    KC_EQUAL, _______,
      _______, _______,    SAVE_VIM, _______, LT(SYMBOLS_ALT, KC_KP_ASTERISK), KC_QUESTION, _______,           _______, _______,      KC_LEFT_CURLY_BRACE,   KC_RIGHT_CURLY_BRACE,   KC_QUOTE,       _______, _______,
      _______, _______,    _______,  _______, _______,                         KC_SLASH,                                _______,      KC_LEFT_ANGLE_BRACKET, KC_RIGHT_ANGLE_BRACKET, KC_SLASH,    _______,  _______,
      _______, _______,    _______,  _______, _______,                         _______,                        _______, _______,      _______,               _______,                TYPE_EMAIL,  _______,
                                              _______,                         _______,     _______,           _______, _______,      _______
  ),

    [SYMBOLS_ALT] = LAYOUT_moonlander(
      _______, _______,    _______,  _______, _______,     _______,  _______,           _______, _______, _______,               _______,                _______,  _______,     _______,
      _______, _______,    _______,  _______, _______,     _______,  _______,           _______, _______, _______,               _______,                KC_UNDERSCORE,  KC_PLUS,     _______,
      _______, _______,    _______, _______, _______, _______,  _______,           _______, _______, KC_LBRACKET,           KC_RBRACKET,            KC_DOUBLE_QUOTE,    _______,    _______,
      _______, _______,    _______,  _______, _______,     _______,                             _______, _______, _______, _______, _______,     _______,
      _______, _______,    _______,  _______, _______,               _______,           _______,          _______,               _______,                _______,  _______,  _______,
                                              _______,      _______,  _______,           _______, _______,      _______
    ),


    [NUMBERS] = LAYOUT_moonlander(
        _______, SONG_1,  SONG_2,  SONG_3,  _______, _______, _______,           _______, _______, _______, _______, _______,  _______, _______,
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,           _______, KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_BSLASH,
        _______, _______, _______, _______, _______, _______, _______,           _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,
        _______, _______, _______, _______, _______,      _______,                        _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______,  _______, _______,
                                            _______, _______, _______, _______,_______, _______
    ),

    [VIM_TMUX] = LAYOUT_moonlander(
        _______, _______, _______,   _______,              _______,          _______,               _______,           _______, _______,  _______,   _______, _______, _______,  _______,
        _______, _______, _______,   TMUX_PREVIOUS_WINDOW, TMUX_NEXT_WINDOW, TMUX_PREVIOUS_SESSION, _______,           _______, _______,  _______,   _______, _______, _______,  _______,
        _______, _______, TMUX_ZOOM, VIM_TAB_PREV,         VIM_TAB_NEXT, TMUX_ZOOM_SCROLL,      _______,           _______, _______,  _______,   _______, _______, _______,  _______,
        _______, _______, _______,   _______,              _______,          _______,                                  _______, _______,  _______,   _______, _______, _______,
        _______, _______, _______,   TMUX_SCROLL,          _______,          _______,               _______,           _______, _______,  _______,   _______, _______,
                                            _______, _______, _______, _______,_______, _______
    ),

    [NUMPAD] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, KC_7,    KC_8,    KC_9,    _______, _______,
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, KC_4,    KC_5,    KC_6,    _______, _______,
        _______, _______, _______, _______, _______, _______,                            _______, KC_1,    KC_2,    KC_3,    _______, _______,
        _______, _______, _______, _______, _______,          _______, _______,          _______, KC_0,    _______, _______, _______,
                                            _______, _______, _______, _______, _______, KC_ENT
    ),

    [RGB_LAYER] = LAYOUT_moonlander(
        _______, _______,        _______,          _______,          _______,        _______, _______,          _______, _______, _______, _______, _______, _______, _______,
        _______, RGB_MODE_PLAIN, RGB_MODE_BREATHE, RGB_MODE_RAINBOW, RGB_MODE_SWIRL, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
        _______, _______,        _______,          _______,          RGB_TOG,        _______, _______,          _______, _______, _______, _______, _______, _______, _______,
        _______, _______,        _______,          _______,          _______,        _______,                            _______, _______, _______, _______, _______, _______,
        _______, _______,        _______,          _______,          _______,                 _______, _______,          _______, _______, _______, _______, _______,
                                                                     _______,        _______, _______, _______, _______, KC_ENT
    ),

    /*[LAYOUT_NAME] = LAYOUT_moonlander(*/
        /*_______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,*/
        /*_______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,*/
        /*_______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,*/
        /*_______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,*/
        /*_______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______,*/
                                            /*_______, _______, _______, _______, _______, _______*/
    /*),*/
};

float mario_theme[][2] = SONG(MARIO_THEME);
float mario_gameover_theme[][2] = SONG(MARIO_GAMEOVER);
float mario_mushroom_theme[][2] = SONG(MARIO_MUSHROOM);
float my_song[][2] = SONG(QWERTY_SOUND);
float rick_roll_theme[][2] = SONG(RICK_ROLL);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        case TYPE_EMAIL:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        case SAVE_VIM:
            SEND_STRING(SS_TAP(X_ESC) " w");
            return false;
        case VIM_TAB_NEXT:
            SEND_STRING(SS_TAP(X_ESC) "gt");
            return false;
        case VIM_TAB_PREV:
            SEND_STRING(SS_TAP(X_ESC) "gT");
            return false;
        case TMUX_PREVIOUS_WINDOW:
            SEND_STRING(SS_LCTL("s") "p");
            return false;
        case TMUX_NEXT_WINDOW:
            SEND_STRING(SS_LCTL("s") "n");
            return false;
        case TMUX_PREVIOUS_SESSION:
            SEND_STRING(SS_LCTL("s") SS_LSFT("l"));
            return false;
        case TMUX_ZOOM:
            SEND_STRING(SS_LCTL("s") "z");
            return false;
        case TMUX_SCROLL:
            SEND_STRING(SS_LCTL("s") SS_TAP(X_LBRACKET)); 
            return false;
        case TMUX_ZOOM_SCROLL:
            SEND_STRING(SS_LCTL("s") "z");
            SEND_STRING(SS_LCTL("s") SS_TAP(X_LBRACKET)); 
            return false;
        case SONG_1:
            PLAY_SONG(mario_theme);
            return false;
        case SONG_2:
            PLAY_SONG(mario_mushroom_theme);
            return false;
        case SONG_3:
            PLAY_SONG(mario_gameover_theme);
            return false;
        }
    }
    return true;
}

enum combo_events {
  PREVIOUS_TAB_COMBO,
  NEXT_TAB_COMBO,
  SWITCH_APP_COMBO,
  VIM_SAVE,
  VIM_CLIPBOARD_REGISTER,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM previous_tab[] = {LCTL_T(KC_S), LOPT_T(KC_D), COMBO_END};
const uint16_t PROGMEM next_tab[] = {LCTL_T(KC_S), LSFT_T(KC_F), COMBO_END};
const uint16_t PROGMEM switch_app[] = {LCTL_T(KC_S), LOPT_T(KC_D), LSFT_T(KC_F), COMBO_END};
const uint16_t PROGMEM vim_save[] = {LOPT_T(KC_D), LSFT_T(KC_F), COMBO_END};
const uint16_t PROGMEM vim_clipboard_register[] = {KC_U, KC_O, COMBO_END};

combo_t key_combos[] = {
  [PREVIOUS_TAB_COMBO] = COMBO_ACTION(previous_tab),
  [NEXT_TAB_COMBO] = COMBO_ACTION(next_tab),
  [SWITCH_APP_COMBO] = COMBO_ACTION(switch_app),
  [VIM_SAVE] = COMBO_ACTION(vim_save),
  [VIM_CLIPBOARD_REGISTER] = COMBO_ACTION(vim_clipboard_register),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case PREVIOUS_TAB_COMBO:
      if (pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LSFT) SS_TAP(X_TAB) SS_UP(X_LSFT) SS_UP(X_LCTL)); 
      }
      break;
    case NEXT_TAB_COMBO:
      if (pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_TAB) SS_UP(X_LCTL)); 
      }
      break;
    case SWITCH_APP_COMBO:
      if (pressed) {
        SEND_STRING(SS_DOWN(X_LCMD) SS_TAP(X_TAB) SS_UP(X_LCMD)); 
      }
      break;
    case VIM_SAVE:
      if (pressed) {
        SEND_STRING(SS_TAP(X_ESC) " w");
      }
      break;
    case VIM_CLIPBOARD_REGISTER:
      if (pressed) {
        SEND_STRING("\"*");
      }
      break;
  }
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_F) {
      // Anything you can do in a macro.
      SEND_STRING("QMK is awesome.");
    };
    SEQ_TWO_KEYS(KC_D, KC_D) {
      SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
    };
    SEQ_THREE_KEYS(KC_O, KC_P, KC_R) {
        SEND_STRING(SS_DOWN(X_LOPT) SS_DOWN(X_LSFT) "v" SS_UP(X_LSFT) SS_UP(X_LOPT)); 
        SEND_STRING(SS_DELAY(1000) SS_LCMD("l")); 
        SEND_STRING("https://github.com/PropertySimple/crm-public\n");
        SEND_STRING(SS_TAP(X_ENTER)); 
    };
    SEQ_TWO_KEYS(KC_A, KC_S) {
      register_code(KC_LGUI);
      register_code(KC_S);
      unregister_code(KC_S);
      unregister_code(KC_LGUI);
    };
  }
}

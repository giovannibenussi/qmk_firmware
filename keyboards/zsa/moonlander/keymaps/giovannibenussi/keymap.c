#include QMK_KEYBOARD_H
#include "version.h"
#include "colors.h"

bool ledEnabled = true;

enum layers {
    BASE,
    SYMBOLS,
    SYMBOLS_ALT,
    NUMBERS,
    VIM_TMUX,
    NUMPAD,
    RGB_LAYER,
    MACROS,
    MOUSE_AND_SOUND_LAYER,
    APPS_LAYER,
    F_LAYER,
    SYMBOLS_N,
    SYMBOLS_V,
    BRACKETS_FV,
    SPACE_LAYER,
    CAPS_LAYER
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
    TYPE_EMAIL,
    CHROME_PREV_PANE,
    CHROME_NEXT_PANE,
    SAVE_VIM,
    VIM_COPY_LINE_TO_CURSOR,
    VIM_PASTE_LINE_FROM_CURSOR,
    VIM_TAB_PREV,
    VIM_TAB_NEXT,
    VIM_SEARCH,
    VIM_SEARCH_JS,
    VIM_SPLIT_HORIZONTALLY,
    VIM_SPLIT_VERTICALLY,
    TMUX_PREVIOUS_WINDOW,
    TMUX_NEXT_WINDOW,
    TMUX_PREVIOUS_SESSION,
    TMUX_ZOOM,
    TMUX_KILL,
    TMUX_CREATE,
    TMUX_SCROLL,
    TMUX_SCROLL_AND_SEARCH,
    TMUX_DETACH,
    TMUX_FIND,
    TMUX_ZOOM_SCROLL,
    TMUX_NEW_VERTICAL_PANE,
    TMUX_NEW_HORIZONTAL_PANE,
    TMUX_MOVE_LEFT,
    TMUX_MOVE_RIGHT,
    TMUX_LIST,
    OPEN_APPLICATION_Q,
    OPEN_APPLICATION_W,
    OPEN_APPLICATION_E,
    OPEN_APPLICATION_R,
    OPEN_APPLICATION_A,
    OPEN_APPLICATION_S,
    OPEN_APPLICATION_D,
    OPEN_APPLICATION_F,
    OPEN_APPLICATION_G,
    OPEN_APPLICATION_I,
    OPEN_APPLICATION_Z,
    OPEN_APPLICATION_X,
    OPEN_APPLICATION_C,
    OPEN_APPLICATION_V,
    OPEN_APPLICATION_B,
    OPEN_APPLICATION_L,
    OPEN_APPLICATION_N,
    OPEN_PREVIOUS_APPLICATION,
    ANIMATE_KEY_PRESS,
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
    TOGGLE_LEDS
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_moonlander(
    QK_GRAVE_ESCAPE, KC_1,                  KC_2,         KC_3,         KC_4,          KC_5,    _______,          _______,            KC_6,              KC_7,                KC_8,               KC_9,         KC_0,         LT(F_LAYER, KC_DEL),
    KC_TAB,        KC_Q,                  KC_W,         KC_E,         KC_R,          KC_T,    _______,           _______,             KC_Y,               KC_U,         KC_I,         KC_O,            KC_P,              KC_BSLS,
    LT(CAPS_LAYER, KC_GRAVE),  LCMD_T(KC_A),          LCTL_T(KC_S), LOPT_T(KC_D), LSFT_T(KC_F),  KC_G,    KC_NO,             KC_NO,               KC_H,               LSFT_T(KC_J), LOPT_T(KC_K), LCTL_T(KC_L),    LCMD_T(KC_BSPC),   KC_SEMICOLON,
    LT(CAPS_LAYER, KC_GRAVE), LT(VIM_TMUX, KC_Z),    KC_X,         KC_C,         LT(SYMBOLS_V, KC_V), KC_B,                                            LT(SYMBOLS_N, KC_N), LT(SYMBOLS_N, KC_M),               KC_COMM,      KC_DOT,          RCTL_T(KC_SLSH),   KC_RSFT,
    _______,         _______,               KC_LCTL,     KC_LALT,       KC_LGUI,       _______,                                         _______,            QK_LEADER,    TT(NUMPAD),   _______,         _______,           _______,
                                                               LT(SYMBOLS, KC_ENT),       LT(APPS_LAYER, KC_ESC), KC_LGUI,               LT(RGB_LAYER, KC_ESC), LT(MOUSE_AND_SOUND_LAYER, KC_BSPC), LT(SPACE_LAYER, KC_SPC)
  ),

  [SYMBOLS] = LAYOUT_moonlander(
      QK_BOOT, _______,    _______,  _______, _______,                         _______,     _______,           _______, _______,      _______,               _______,                _______,     _______,  _______,
      _______, KC_EXCLAIM, KC_AT,    KC_HASH, KC_DOLLAR,                       KC_PERCENT,  _______,           _______, KC_AMPERSAND, KC_LEFT_PAREN,         KC_RIGHT_PAREN,         KC_MINUS,    KC_EQUAL, _______,
      _______, _______,    SAVE_VIM, _______, LT(SYMBOLS_ALT, KC_KP_ASTERISK), KC_QUESTION, _______,           _______, _______,      KC_LEFT_CURLY_BRACE,   KC_RIGHT_CURLY_BRACE,   KC_QUOTE,       _______, _______,
      _______, _______,    _______,  _______, _______,                         KC_SLASH,                                KC_PIPE,      KC_LEFT_ANGLE_BRACKET, KC_RIGHT_ANGLE_BRACKET, KC_SLASH,    _______,  _______,
      _______, _______,    _______,  _______, _______,                         _______,                        _______, _______,      _______,               _______,                TYPE_EMAIL,  _______,
                                              _______,                         _______,     _______,           _______, _______,      _______
  ),

    [SYMBOLS_ALT] = LAYOUT_moonlander(
      _______, _______,    _______,  _______, _______,     _______,  _______,           _______, _______, _______,               _______,                _______,  _______,     _______,
      _______, _______,    _______,  _______, _______,     _______,  _______,           _______, _______, _______,               _______,                KC_UNDERSCORE,  KC_PLUS,     _______,
      _______, _______,    _______, _______, _______, _______,  _______,           _______, _______, KC_LEFT_BRACKET,       KC_RIGHT_BRACKET,       KC_DOUBLE_QUOTE,        _______,    _______,
      _______, _______,    _______,  _______, _______,     _______,                             _______, _______, _______, _______, _______,     _______,
      _______, _______,    _______,  _______, _______,               _______,           _______,          _______,               _______,                _______,  _______,  _______,
                                              _______,      _______,  _______,           _______, _______,      _______
    ),

    [NUMBERS] = LAYOUT_moonlander(
        _______, SONG_1,  SONG_2,  SONG_3,  _______,        _______, _______,           _______, _______, _______, _______, _______,  _______, _______,
        _______, KC_1,    KC_2,    KC_3,    KC_4,           KC_5,    _______,           _______, KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_BACKSLASH,
        _______, _______, _______, _______, KC_KP_ASTERISK, _______, _______,           _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, VIM_SEARCH_JS,
        _______, _______, _______, _______, _______,        KC_SLASH,                    _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______,                 _______,          _______,           _______,          _______, _______, _______,  _______, _______,
                                                            _______, _______, _______, _______,  _______, _______
    ),

    [VIM_TMUX] = LAYOUT_moonlander(
        _______, _______,   _______,     _______,              _______,          _______,               _______,            _______, _______, _______,  _______,                            _______, _______,  _______,
        _______, TMUX_KILL, _______,     TMUX_PREVIOUS_WINDOW, TMUX_NEXT_WINDOW, TMUX_PREVIOUS_SESSION, _______,            _______, VIM_SPLIT_HORIZONTALLY, CHROME_PREV_PANE,  CHROME_NEXT_PANE, _______, _______,  TMUX_NEW_VERTICAL_PANE,
        _______, _______,   TMUX_ZOOM,   VIM_TAB_PREV,         VIM_TAB_NEXT,     TMUX_ZOOM_SCROLL,      _______,            _______, VIM_SPLIT_VERTICALLY, TMUX_MOVE_LEFT,   TMUX_MOVE_RIGHT, TMUX_LIST, _______, TMUX_NEW_HORIZONTAL_PANE,
        _______, _______,   TMUX_CREATE, TMUX_SCROLL,          TMUX_DETACH,      _______,                                   _______, _______,  _______,          _______,          RESET,   _______,
        _______, _______,   _______,     _______,              _______,          _______,               _______,            _______, _______, _______,  _______, _______,
                                                               TMUX_ZOOM,        TMUX_SCROLL,           _______, TMUX_FIND, _______, _______
    ),

    [NUMPAD] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______,         _______,          _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, QK_DYNAMIC_MACRO_RECORD_START_1, QK_DYNAMIC_MACRO_RECORD_START_2, _______, _______,          _______, _______, KC_7,    KC_8,    KC_9,    _______, _______,
        _______, _______, _______, QK_DYNAMIC_MACRO_PLAY_1, QK_DYNAMIC_MACRO_PLAY_2, _______, _______,          _______, _______, KC_4,    KC_5,    KC_6,    _______, _______,
        _______, _______, _______, _______, QK_DYNAMIC_MACRO_RECORD_STOP, _______,                            _______, KC_1,    KC_2,    KC_3,    _______, _______,
        _______, _______, _______, _______,          _______,         _______,  _______,          KC_0,    _______,    _______ , _______, _______,
                                                     _______, _______, _______, _______, _______, KC_ENT
    ),

    [MOUSE_AND_SOUND_LAYER] = LAYOUT_moonlander(
        _______, _______,        _______,             _______,             _______,             _______, _______,          _______, _______, _______,          _______,     _______, _______, _______,
        _______, _______,        _______,             _______,             _______,             _______, _______,          _______, _______,    _______,       KC_MS_BTN1,     KC_MS_BTN2, _______, _______,
        _______, _______,        KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, _______, _______,          _______, KC_MS_LEFT, KC_MS_DOWN,    KC_MS_UP,    KC_MS_RIGHT, _______, _______,
        _______, _______,        _______,             KC_AUDIO_VOL_DOWN,   KC_AUDIO_VOL_UP,     _______,                            _______,    KC_MS_WH_DOWN, KC_MS_WH_UP, _______, _______, _______,
        _______, _______,        _______,             _______,             _______,             _______, _______,          _______,          _______,       _______,        _______, _______,
                                                                           _______,             _______, _______, _______, _______, _______
    ),
    [RGB_LAYER] = LAYOUT_moonlander(
        _______, SONG_1,             SONG_2,              SONG_3,             _______,             _______, _______,          _______,                    _______, _______, _______, _______, _______, TOGGLE_LEDS,
        _______, RGB_MODE_PLAIN,     RGB_MODE_BREATHE,    RGB_MODE_RAINBOW,    RGB_MODE_SWIRL,      RGB_TOG, _______,          _______, ANIMATE_KEY_PRESS, _______, _______, _______, _______, _______,
        _______, _______,            KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, _______, _______,          _______, RGB_HUD,           RGB_HUI, RGB_SAD, RGB_SAI, _______, _______,
        _______, KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP,    KC_AUDIO_VOL_DOWN,   KC_AUDIO_VOL_UP,     _______,                            RGB_VAI,           RGB_VAD, _______, _______, _______, _______,
        _______, _______,        _______,             _______,             _______,             _______, _______,          _______,           _______, _______, _______, _______,
                                                                           _______,             _______, _______, _______, _______, _______
    ),

    [MACROS] = LAYOUT_moonlander(
        _______, _______, _______, _______,          _______,         _______,      _______,          _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, QK_DYNAMIC_MACRO_RECORD_START_2, QK_DYNAMIC_MACRO_RECORD_START_1, _______, _______,          _______, VIM_COPY_LINE_TO_CURSOR, _______, _______, _______, VIM_PASTE_LINE_FROM_CURSOR, _______,
        _______, _______, _______, QK_DYNAMIC_MACRO_PLAY_2, QK_DYNAMIC_MACRO_PLAY_1, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, QK_DYNAMIC_MACRO_RECORD_STOP, _______,                                 _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,          _______,         _______,      _______,          _______, _______, _______, _______, _______,
                                                     _______,         _______,      _______, _______, _______, _______
    ),

    [APPS_LAYER] = LAYOUT_moonlander(
        _______,                   _______,             _______,            _______,            _______,            _______,            _______,          _______, _______, _______, _______, _______, _______, _______,
        _______,                   OPEN_APPLICATION_Q,  OPEN_APPLICATION_W, OPEN_APPLICATION_E, OPEN_APPLICATION_R, _______,            _______,          _______, _______, _______, OPEN_APPLICATION_I, _______, _______, _______,
        OPEN_PREVIOUS_APPLICATION, OPEN_APPLICATION_A,  OPEN_APPLICATION_S, OPEN_APPLICATION_D, OPEN_APPLICATION_F, OPEN_APPLICATION_G,            _______,          _______, _______, _______, _______, OPEN_APPLICATION_L, _______, _______,
        KC_MEDIA_PLAY_PAUSE,       OPEN_APPLICATION_Z,  OPEN_APPLICATION_X, OPEN_APPLICATION_C, OPEN_APPLICATION_V, OPEN_APPLICATION_B,                            OPEN_APPLICATION_N, _______, _______, _______, _______, _______,
        KC_MEDIA_PREV_TRACK,       KC_MEDIA_NEXT_TRACK, KC_AUDIO_VOL_DOWN,  KC_AUDIO_VOL_UP,                              _______  ,          _______, _______,          _______, _______, _______, _______, _______,
                                                                                                _______,            _______,            _______, _______, _______, _______
    ),

    [SYMBOLS_N] = LAYOUT_moonlander(
        RESET,   KC_F1,     KC_F2,     KC_F3,              KC_F4,             KC_F5,   KC_F6,                        KC_F7,   KC_F8,     KC_F9,    KC_F10,                  KC_F11,               KC_F12,                KC_MUTE,
        _______,   KC_1,      KC_2,      KC_3,               KC_4,              KC_5,    _______,                      _______, KC_6,      KC_7,     KC_8,                    KC_9,                 KC_0,                  KC_AUDIO_VOL_UP,
        _______,   _______,   _______,   VIM_TAB_PREV,       VIM_TAB_NEXT,      _______, _______,                      _______, _______,   KC_LEFT_BRACKET,  TMUX_SCROLL_AND_SEARCH,  TMUX_SCROLL,          TMUX_PREVIOUS_SESSION, VIM_SEARCH_JS,
        _______,   TMUX_ZOOM, TMUX_CREATE, TMUX_PREVIOUS_WINDOW, TMUX_NEXT_WINDOW, _______,                                       _______, TMUX_LIST, _______,  _______,                 _______,              _______,
        TMUX_KILL, _______,   _______,   _______,            _______,           _______,                      _______,          _______, _______,   _______,  _______,                 _______,
                                                             _______,           _______, _______,          _______, _______, _______
    ),

    [SYMBOLS_V] = LAYOUT_moonlander(
        _______, _______,   _______,   _______,   _______,   _______, _______,                      _______, _______,     _______,               _______,                 _______,   _______, _______,
        _______, _______,   _______,   _______,   _______,   _______, _______,                      _______, _______,     KC_LEFT_PAREN,         KC_RIGHT_PAREN,          KC_MINUS,  KC_EQUAL, _______,
        _______, _______,   _______,   _______,   _______,   KC_ASTERISK, _______,                  _______, KC_ASTERISK, KC_LEFT_CURLY_BRACE,   KC_RIGHT_CURLY_BRACE,    KC_QUOTE,  _______, _______,
        _______, _______,   _______,   _______,   _______,   _______,                                        KC_QUESTION,           KC_SLASH,                _______,     KC_LEFT_ANGLE_BRACKET, KC_RIGHT_ANGLE_BRACKET, _______,
        _______, _______,   _______,   _______,   _______,            _______,                     _______,          _______,     _______,               _______,                 _______,   _______,
                                                             _______,   _______, _______,          _______, _______, _______
    ),

    [BRACKETS_FV] = LAYOUT_moonlander(
        _______, _______,   _______,   _______,   _______,   _______, _______,                      _______, _______,     _______,               _______,                 _______,   _______, _______,
        _______, _______,   _______,   _______,   _______,   _______, _______,                      _______, _______,     _______,               _______,                 _______,   _______, _______,
        _______, _______,   _______,   _______,   _______,   _______, _______,                      _______, _______,     KC_LEFT_BRACKET,       KC_RIGHT_BRACKET,        _______,   _______, _______,
        _______, _______,   _______,   _______,   _______,   _______,                                        _______,     _______,               _______,                 _______,   _______, _______,
        _______, _______,   _______,   _______,   _______,            _______,                     _______,          _______,     _______,               _______,                 _______,   _______,
                                                             _______,   _______, _______,          _______, _______, _______
    ),

    [SPACE_LAYER] = LAYOUT_moonlander(
        RESET,       KC_F1,            TMUX_PREVIOUS_WINDOW, TMUX_NEXT_WINDOW, KC_F4,        KC_F5,    KC_F6,             KC_F7,       KC_F8,        KC_F9,    KC_F10,   KC_F11,               KC_F12,   KC_MUTE,
        LCMD(KC_TAB), VIM_TAB_PREV,     LCMD(KC_W),          VIM_TAB_NEXT,     LCMD(KC_R),   LCMD(KC_T), _______,          _______,     KC_U,         _______,  _______,  TMUX_PREVIOUS_SESSION, _______,  KC_AUDIO_VOL_UP,
        _______,     LCMD_T(KC_A),     LCTL_T(KC_S),        LOPT_T(KC_D),     LSFT_T(KC_F), _______,  _______,           _______,     KC_LEFT,      KC_DOWN,  KC_UP,    KC_RIGHT,             TMUX_LIST, KC_AUDIO_VOL_DOWN,
        _______,     _______,          _______,             KC_C,             _______,      _______,                                   _______,      KC_ASTERISK, KC_SLASH, _______,           _______,  KC_MEDIA_PLAY_PAUSE,
        _______,     _______,          _______,             _______,          _______,               _______,          _______,          _______,      _______,  _______,  _______,           _______,
                                                                              KC_ENT,       _______,   _______,          _______, _______, _______
    ),

    [CAPS_LAYER] = LAYOUT_moonlander(
        KC_GRAVE,    _______,          _______,             _______,          _______,      _______,  _______,           _______,     _______,      _______,  _______,  _______,               _______,  _______,
        _______,     _______,          C(KC_W),             C(KC_E),          C(KC_R),      C(KC_T),  _______,           _______,     C(KC_Y),      C(KC_U),  KC_LEFT_PAREN, KC_RIGHT_PAREN,   C(KC_P),  _______,
        _______,     _______,          C(KC_S),             C(KC_D),          LSFT_T(KC_F), _______,  _______,           _______,     C(KC_H),      C(KC_J),  C(KC_K),  KC_COLN,              KC_SEMICOLON, KC_GRAVE,
        _______,     _______,          C(KC_X),             C(KC_C),          _______,      _______,                                  _______,      KC_ASTERISK, KC_SLASH, _______,           _______,  _______,
        _______,     _______,          _______,             _______,          _______,               _______,          _______,          _______,      _______,  _______,  _______,           _______,
                                                                              KC_ENTER,     _______,   _______,          _______, _______, _______
    ),

    [F_LAYER] = LAYOUT_moonlander(
        QK_BOOT, _______,          _______,              _______,              _______,              _______, _______,          _______, _______, _______, _______, _______, _______, _______,
        _______, _______,          _______,              KC_AUDIO_VOL_DOWN,    KC_AUDIO_VOL_UP,      _______, _______,          _______, _______, _______, _______, _______, _______, _______,
        _______, _______,          _______,              _______,              KC_MEDIA_PLAY_PAUSE,  _______, _______,          _______, _______, _______, _______, _______, _______, _______,
        _______, _______,          _______,              KC_MEDIA_PREV_TRACK,  KC_MEDIA_NEXT_TRACK,  _______,                            _______, _______, _______, _______, _______, _______,
        _______, _______,          _______,              _______,              _______,                       _______,          _______, _______, _______, _______, _______, _______,
                                                                               _______,              _______, _______,          _______, _______, _______
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

void open_application(char key[]) {
  SEND_STRING(SS_DOWN(X_LALT));
  SEND_STRING(SS_DOWN(X_LSFT));
  SEND_STRING(key);
  SEND_STRING(SS_UP(X_LSFT));
  SEND_STRING(SS_UP(X_LALT));
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        case TYPE_EMAIL:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        case CHROME_PREV_PANE:
            SEND_STRING(SS_LCTL("`") SS_LCMD("["));
            return false;
        case CHROME_NEXT_PANE:
            SEND_STRING(SS_LCTL("`") SS_LCMD("]"));
            return false;
        case SAVE_VIM:
            SEND_STRING(SS_TAP(X_ESC) " w");
            return false;
        case VIM_TAB_NEXT:
            SEND_STRING(SS_TAP(X_ESC) "gt");
            return false;
        case VIM_COPY_LINE_TO_CURSOR:
            SEND_STRING(SS_TAP(X_ESC) "\"*yy");
            return false;
        case VIM_PASTE_LINE_FROM_CURSOR:
            SEND_STRING(SS_TAP(X_ESC) "\"*p");
            return false;
        case VIM_TAB_PREV:
            SEND_STRING(SS_TAP(X_ESC) "gT");
            return false;
        case VIM_SEARCH:
            SEND_STRING(SS_TAP(X_ESC) ":Ag \"\"" SS_TAP(X_LEFT));
            return false;
        case VIM_SEARCH_JS:
            SEND_STRING(SS_TAP(X_ESC) ":Ack --js \"\"" SS_TAP(X_LEFT));
            return false;
        case VIM_SPLIT_HORIZONTALLY:
            SEND_STRING(SS_LCTL("w") "s");
            return false;
        case VIM_SPLIT_VERTICALLY:
            SEND_STRING(SS_LCTL("w") "v");
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
        case TMUX_KILL:
            SEND_STRING(SS_LCTL("s") "xy");
            return false;
        case TMUX_CREATE:
            SEND_STRING(SS_LCTL("s") "c");
            return false;
        case TMUX_SCROLL:
            SEND_STRING(SS_LCTL("s") SS_TAP(X_LEFT_BRACKET));
            return false;
        case TMUX_SCROLL_AND_SEARCH:
            SEND_STRING(SS_LCTL("s") SS_TAP(X_LEFT_BRACKET) "?");
            return false;
        case TMUX_DETACH:
            SEND_STRING(SS_LCTL("s") "d");
            return false;
        case TMUX_FIND:
            SEND_STRING(SS_LCTL("s") SS_TAP(X_LEFT_BRACKET) "?");
            return false;
        case TMUX_ZOOM_SCROLL:
            SEND_STRING(SS_LCTL("s") "z");
            SEND_STRING(SS_LCTL("s") SS_TAP(X_LEFT_BRACKET));
            return false;
        case TMUX_NEW_VERTICAL_PANE:
            SEND_STRING(SS_LCTL("s") SS_LSFT("5"));
            return false;
        case TMUX_NEW_HORIZONTAL_PANE:
            SEND_STRING(SS_LCTL("s") "-");
            return false;
        case TMUX_MOVE_LEFT:
            SEND_STRING(SS_LCTL("s") "{");
            return false;
        case TMUX_MOVE_RIGHT:
            SEND_STRING(SS_LCTL("s") "}");
            return false;
        case TMUX_LIST:
            SEND_STRING(SS_LCTL("s") "s");
            return false;
        case OPEN_APPLICATION_Q:
            open_application("q");
            return false;
        case OPEN_APPLICATION_W:
            open_application("w");
            return false;
        case OPEN_APPLICATION_E:
            open_application("e");
            return false;
        case OPEN_APPLICATION_R:
            open_application("r");
            return false;
        case OPEN_APPLICATION_A:
            open_application("a");
            return false;
        case OPEN_APPLICATION_S:
            open_application("s");
            return false;
        case OPEN_APPLICATION_D:
            open_application("d");
            return false;
        case OPEN_APPLICATION_F:
            open_application("f");
            return false;
        case OPEN_APPLICATION_G:
            open_application("g");
            return false;
        case OPEN_APPLICATION_I:
            open_application("i");
            return false;
        case OPEN_APPLICATION_Z:
            open_application("z");
            return false;
        case OPEN_APPLICATION_X:
            open_application("x");
            return false;
        case OPEN_APPLICATION_C:
            open_application("c");
            return false;
        case OPEN_APPLICATION_V:
            open_application("v");
            return false;
        case OPEN_APPLICATION_B:
            open_application("b");
            return false;
        case OPEN_APPLICATION_L:
            open_application("l");
            return false;
        case OPEN_APPLICATION_N:
            open_application("n");
            return false;
        case OPEN_PREVIOUS_APPLICATION:
            SEND_STRING(SS_DOWN(X_LCMD));
            SEND_STRING(SS_TAP(X_TAB));
            SEND_STRING(SS_UP(X_LCMD));
            return false;
        case ANIMATE_KEY_PRESS:
            rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_SIMPLE);
            rgb_matrix_set_color(0, 249, 115, 22);
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
        case TOGGLE_LEDS:
            ledEnabled = !ledEnabled;
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
  FV_BRACKETS_COMBO,
  RESET_COMBO,
  SD_PREVIOUS_TAB,
  DF_NEXT_TAB,
  SEND_ENTER,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM previous_tab[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM next_tab[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM switch_app[] = {LCTL_T(KC_S), LOPT_T(KC_D), LSFT_T(KC_F), COMBO_END};
const uint16_t PROGMEM vim_save[] = {LCTL_T(KC_S), LSFT_T(KC_F), COMBO_END};
const uint16_t PROGMEM vim_clipboard_register[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM fv_brackets[] = {LSFT_T(KC_F), LT(SYMBOLS_V, KC_V), COMBO_END};
const uint16_t PROGMEM reset_combo[] = {QK_GRAVE_ESCAPE, KC_BSPC, COMBO_END};
const uint16_t PROGMEM sd_previous_tab[] = {LCTL_T(KC_S), LOPT_T(KC_D), COMBO_END};
const uint16_t PROGMEM df_next_tab[] = {LOPT_T(KC_D), LSFT_T(KC_F), COMBO_END};
const uint16_t PROGMEM send_enter[] = {LSFT_T(KC_J), LOPT_T(KC_K), COMBO_END};

combo_t key_combos[] = {
  [PREVIOUS_TAB_COMBO] = COMBO_ACTION(previous_tab),
  [NEXT_TAB_COMBO] = COMBO_ACTION(next_tab),
  [SWITCH_APP_COMBO] = COMBO_ACTION(switch_app),
  [VIM_SAVE] = COMBO_ACTION(vim_save),
  [VIM_CLIPBOARD_REGISTER] = COMBO_ACTION(vim_clipboard_register),
  [FV_BRACKETS_COMBO] = COMBO_ACTION(fv_brackets),
  [RESET_COMBO] = COMBO_ACTION(reset_combo),
  [SD_PREVIOUS_TAB] = COMBO_ACTION(sd_previous_tab),
  [DF_NEXT_TAB] = COMBO_ACTION(df_next_tab),
  [SEND_ENTER] = COMBO_ACTION(send_enter),
};

void set_home_row_color(uint8_t red, uint8_t green, uint8_t blue) {
  rgb_matrix_set_color(7, red, green, blue);
  rgb_matrix_set_color(12, red, green, blue);
  rgb_matrix_set_color(17, red, green, blue);
  rgb_matrix_set_color(22, red, green, blue);
  rgb_matrix_set_color(43, red, green, blue);
  rgb_matrix_set_color(48, red, green, blue);
  rgb_matrix_set_color(53, red, green, blue);
  rgb_matrix_set_color(58, red, green, blue);
}

void set_number_row_color(uint8_t red, uint8_t green, uint8_t blue) {
  rgb_matrix_set_color(6, red, green, blue);
  rgb_matrix_set_color(11, red, green, blue);
  rgb_matrix_set_color(16, red, green, blue);
  rgb_matrix_set_color(21, red, green, blue);
  rgb_matrix_set_color(26, red, green, blue);
  rgb_matrix_set_color(30, red, green, blue);
  rgb_matrix_set_color(35, red, green, blue);
  rgb_matrix_set_color(36, red, green, blue);
  rgb_matrix_set_color(42, red, green, blue);
  rgb_matrix_set_color(47, red, green, blue);
  rgb_matrix_set_color(52, red, green, blue);
  rgb_matrix_set_color(57, red, green, blue);
  rgb_matrix_set_color(62, red, green, blue);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if(!ledEnabled) {
      rgb_matrix_set_color_all(RGB_NONE);
      return false;
    }

    switch(get_highest_layer(layer_state|default_layer_state)) {
        case BASE:
            rgb_matrix_set_color_all(RGB_TAILWIND_PURPLE_800);
            set_home_row_color(RGB_TAILWIND_ROSE_500);
            break;
        case SYMBOLS:
            rgb_matrix_set_color_all(RGB_TAILWIND_PURPLE_800);
            set_number_row_color(RGB_TAILWIND_CYAN_500);
            break;
        case NUMBERS:
            rgb_matrix_set_color_all(RGB_TAILWIND_PURPLE_900);
            set_number_row_color(RGB_TAILWIND_ORANGE_500);
            rgb_matrix_set_color(48, RGB_TAILWIND_CYAN_500);
            rgb_matrix_set_color(53, RGB_TAILWIND_CYAN_500);
            rgb_matrix_set_color(58, RGB_TAILWIND_CYAN_500);
            rgb_matrix_set_color(63, RGB_TAILWIND_CYAN_500);
            break;
        case NUMPAD:
            rgb_matrix_set_color_all(RGB_TAILWIND_PURPLE_900);
            rgb_matrix_set_color(42, RGB_TAILWIND_GREEN_500);
            rgb_matrix_set_color(43, RGB_TAILWIND_GREEN_500);
            rgb_matrix_set_color(44, RGB_TAILWIND_GREEN_500);
            rgb_matrix_set_color(47, RGB_TAILWIND_GREEN_500);
            rgb_matrix_set_color(48, RGB_TAILWIND_GREEN_500);
            rgb_matrix_set_color(49, RGB_TAILWIND_GREEN_500);
            rgb_matrix_set_color(52, RGB_TAILWIND_GREEN_500);
            rgb_matrix_set_color(53, RGB_TAILWIND_GREEN_500);
            rgb_matrix_set_color(54, RGB_TAILWIND_GREEN_500);
            rgb_matrix_set_color(57, RGB_TAILWIND_GREEN_500);
            rgb_matrix_set_color(58, RGB_TAILWIND_GREEN_500);
            rgb_matrix_set_color(59, RGB_TAILWIND_GREEN_500);
            rgb_matrix_set_color(60, RGB_TAILWIND_LIME_500);
            break;
        case VIM_TMUX:
            rgb_matrix_set_color_all(RGB_TAILWIND_ROSE_600);
            rgb_matrix_set_color(12, RGB_TAILWIND_TEAL_500);
            rgb_matrix_set_color(16, RGB_TAILWIND_PURPLE_800);
            rgb_matrix_set_color(17, RGB_TAILWIND_TEAL_500);
            rgb_matrix_set_color(18, RGB_TAILWIND_GREEN_500);
            rgb_matrix_set_color(21, RGB_TAILWIND_PURPLE_800);
            rgb_matrix_set_color(22, RGB_TAILWIND_TEAL_500);
            rgb_matrix_set_color(26, RGB_TAILWIND_PURPLE_800);
            rgb_matrix_set_color(27, RGB_TAILWIND_TEAL_500);
            rgb_matrix_set_color(44, RGB_TAILWIND_TEAL_500);
            rgb_matrix_set_color(37, RGB_TAILWIND_CYAN_500);
            rgb_matrix_set_color(38, RGB_TAILWIND_CYAN_500);
            rgb_matrix_set_color(62, RGB_TAILWIND_CYAN_500);
            rgb_matrix_set_color(63, RGB_TAILWIND_CYAN_500);
            break;
        case RGB_LAYER:
            rgb_matrix_set_color_all(RGB_TAILWIND_ROSE_600);
            rgb_matrix_set_color(12, RGB_TAILWIND_TEAL_500);
            rgb_matrix_set_color(17, RGB_TAILWIND_PURPLE_500);
            rgb_matrix_set_color(18, RGB_TAILWIND_GREEN_500);
            rgb_matrix_set_color(22, RGB_TAILWIND_TEAL_500);
            rgb_matrix_set_color(23, RGB_TAILWIND_GREEN_500);
            break;
        default:
            break;
    }
    return false;
}

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
        rgb_matrix_set_color(0, RGB_RED);
        rgb_matrix_set_color(1, RGB_RED);
        rgb_matrix_set_color(2, RGB_RED);
        rgb_matrix_set_color(3, RGB_RED);
        rgb_matrix_set_color(4, RGB_RED);
        rgb_matrix_set_color(5, RGB_RED);
        rgb_matrix_set_color(6, RGB_RED);
        rgb_matrix_set_color(7, RGB_RED);
        rgb_matrix_set_color(8, RGB_RED);
        rgb_matrix_set_color(9, RGB_RED);
        rgb_matrix_set_color(10, RGB_RED);
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
    case FV_BRACKETS_COMBO:
      if (pressed) {
        layer_on(BRACKETS_FV);
      } else {
        layer_off(BRACKETS_FV);
      }
      break;
    case RESET_COMBO:
      if (pressed) {
        reset_keyboard();
      }
      break;
    case SD_PREVIOUS_TAB:
      if (pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LSFT) SS_TAP(X_TAB) SS_UP(X_LSFT) SS_UP(X_LCTL));
      }
      break;
    case DF_NEXT_TAB:
      if (pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_TAB) SS_UP(X_LCTL));
      }
      break;
    case SEND_ENTER:
      if (pressed) {
        SEND_STRING(SS_TAP(X_ENT));
      }
      break;
  }
}

bool get_combo_must_tap(uint16_t combo_index, combo_t *combo) {
    switch (combo_index) {
        case SEND_ENTER:
            return true;  // Only trigger this combo if both keys are tapped
        default:
            return false; // Other combos can behave normally
    }
}

void leader_end_user(void) {
    if (leader_sequence_two_keys(KC_E, KC_M)) {
        SEND_STRING("giovanni.benussi@usach.cl");
    }
    if (leader_sequence_three_keys(KC_R, KC_U, KC_T)) {
        SEND_STRING("17.565.817-3");
    }
    if (leader_sequence_two_keys(KC_R, KC_U)) {
        SEND_STRING("175658173");
    }
    if (leader_sequence_three_keys(KC_O, KC_P, KC_R)) {
        SEND_STRING(SS_DOWN(X_LOPT) SS_DOWN(X_LSFT) "v" SS_UP(X_LSFT) SS_UP(X_LOPT));
        SEND_STRING(SS_DELAY(1000) SS_LCMD("l"));
        SEND_STRING("https://github.com/PropertySimple/crm-public\n");
        SEND_STRING(SS_TAP(X_ENTER));
    }
    if (leader_sequence_two_keys(KC_A, KC_S)) {
        register_code(KC_LGUI);
        register_code(KC_S);
        unregister_code(KC_S);
        unregister_code(KC_LGUI);
    }
    if (leader_sequence_two_keys(KC_Y, KC_W)) {
        SEND_STRING(SS_TAP(X_ESC) "\"*yw");
    }
    if (leader_sequence_two_keys(KC_Y, KC_Y)) {
        SEND_STRING(SS_TAP(X_ESC) "\"*yy");
    }
    if (leader_sequence_one_key(KC_P)) {
        SEND_STRING(SS_TAP(X_ESC) "\"*p");
    }
    if (leader_sequence_two_keys(KC_D, KC_D)) {
        SEND_STRING(SS_TAP(X_ESC) "\"*dd");
    }
    if (leader_sequence_one_key(KC_L)) {
        SEND_STRING(SS_TAP(X_ESC) "ysiw'");
    }
    if (leader_sequence_one_key(KC_K)) {
        SEND_STRING(SS_TAP(X_ESC) "ysiw\"");
    }
}

#include QMK_KEYBOARD_H

enum user_keycodes {
    TMUX_PREVIOUS_WINDOW = QK_USER_0,
    TMUX_NEXT_WINDOW,
    TMUX_CREATE_WINDOW,
    TMUX_CLOSE_WINDOW,
    TMUX_LIST,
    TMUX_PREVIOUS,
    TMUX_SCROLL,
    TMUX_SCROLL_AND_SEARCH,
    TMUX_ZOOM,
    VIM_PREVIOUS_TAB,
    VIM_NEXT_TAB,
    VIM_CLOSE_TAB,
    PREVIOUS_TAB,
    NEXT_TAB,
    PREVIOUS_APPLICATION,
    TMUX_CLOSE_PANE,
    VIM_CLIPBOARD_REGISTER,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// layer0 Mac
[0] = LAYOUT(
	KC_ESC, 	KC_1,   	KC_2,   	KC_3,  		KC_4,   	KC_5,   	KC_6,   	KC_7,   	KC_8,   	KC_9,  		KC_0,   	KC_MINS,	KC_EQL, 	KC_BSPC,	            KC_INS,
	KC_TAB, 	KC_Q,   	KC_W,   	KC_E,  		KC_R,   	KC_T,   	KC_Y,   	KC_U,   	KC_I,   	KC_O,  		KC_P,   	KC_LBRC,	KC_RBRC,	KC_BSLS,	            KC_DEL,
	LCTL_T(KC_GRV),	LCMD_T(KC_A),	LCTL_T(KC_S),	LOPT_T(KC_D),	LSFT_T(KC_F),	KC_G,	KC_H,	LSFT_T(KC_J),	LOPT_T(KC_K),	LCTL_T(KC_L),	LCMD_T(KC_BSPC),	KC_SCLN, 	KC_ENT,                             KC_PGUP,
	LSFT_T(KC_CAPS),				KC_Z,   	KC_X,   	KC_C,  		LT(7,KC_V),   	KC_B,   	LT(8,KC_N),   	LT(8,KC_M),   	KC_COMM,	KC_DOT,		KC_SLSH,	KC_RSFT,	            KC_UP,      KC_PGDN,
	KC_LCTL,	KC_LOPT,	KC_LCMD,										LT(9,KC_SPC), 							            KC_RCMD,	MO(1),   				KC_LEFT,	KC_DOWN,    KC_RIGHT),

// layer1 Mac Fn1
[1] = LAYOUT(
	KC_GRV, 	KC_BRID,   	KC_BRIU,  	MAC_TASK, 	MAC_SEARCH, MAC_VOICE,  MAC_DND,  	KC_MPRV,  	KC_MPLY,  	KC_MNXT, 	KC_MUTE, 	KC_VOLD, 	KC_VOLU,	_______,                _______,	
	_______, 	LNK_BLE1,  	LNK_BLE2,  	LNK_BLE3,  	LNK_RF,    	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	DEV_RESET,	SLEEP_MODE, BAT_SHOW,	            _______,	
	_______,	_______,   	_______,   	_______,  	_______,   	_______,   	_______,	_______,   	_______,   	_______,  	_______,	_______, 	_______,                            KC_HOME,
	MO(2),				    _______,   	_______,   	_______,  	_______,    _______,   	_______,	MO(6), 		RGB_SPD,	RGB_SPI,	_______,	MO(2),	                RGB_VAI,    KC_END, 
	_______,	_______,	_______,										_______, 							            _______,	MO(1),		            RGB_MOD,    RGB_VAD,	RGB_HUI),

// layer2 Mac FN2
[2] = LAYOUT(
	S(KC_GRV), 	KC_F1,  	KC_F2,  	KC_F3, 		KC_F4,  	KC_F5,  	KC_F6,  	KC_F7,  	KC_F8,  	KC_F9, 		KC_F10, 	KC_F11, 	KC_F12,  	_______,                _______,	
	_______, 	_______,  	_______,  	_______,  	_______,    _______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______,    _______,	            _______,	
	_______,	_______,   	_______,   	_______,  	_______,   	_______,   	_______,	_______,   	_______,   	_______,  	_______,	_______, 	_______,                            _______,
	_______,				_______,   	_______,   	_______,  	_______,    _______,   	_______,	_______, 	_______,	_______,	_______,	_______,	            _______,    _______, 
	_______,	_______,	_______,										_______, 							            _______,	_______,		        _______,    _______,	_______),

// layer3 win
[3] = LAYOUT(
	KC_ESC, 	KC_1,   	KC_2,   	KC_3,  		KC_4,   	KC_5,   	KC_6,   	KC_7,   	KC_8,   	KC_9,  		KC_0,   	KC_MINS,	KC_EQL, 	KC_BSPC,	            KC_INS,
	KC_TAB, 	KC_Q,   	KC_W,   	KC_E,  		KC_R,   	KC_T,   	KC_Y,   	KC_U,   	KC_I,   	KC_O,  		KC_P,   	KC_LBRC,	KC_RBRC,	KC_BSLS,	            KC_DEL,
	LCTL_T(KC_GRV),	LWIN_T(KC_A),	LCTL_T(KC_S),	LALT_T(KC_D),	LSFT_T(KC_F),	KC_G,	KC_H,	LSFT_T(KC_J),	LALT_T(KC_K),	LCTL_T(KC_L),	LWIN_T(KC_BSPC),	KC_SCLN, 	KC_ENT,                             KC_PGUP,
	LSFT_T(KC_CAPS),				KC_Z,   	KC_X,   	KC_C,  		LT(7,KC_V),   	KC_B,   	LT(8,KC_N),   	LT(8,KC_M),   	KC_COMM,	KC_DOT,		KC_SLSH,	KC_RSFT,	            KC_UP,      KC_PGDN,
	KC_LCTL,	KC_LWIN,	KC_LALT,										LT(9,KC_SPC), 							            KC_RALT,	MO(4),	                KC_LEFT,   	KC_DOWN,	KC_RIGHT),

// layer4 win Fn1
[4] = LAYOUT(
	KC_GRV, 	KC_F1,  	KC_F2,  	KC_F3, 		KC_F4,  	KC_F5,  	KC_F6,  	KC_F7,  	KC_F8,  	KC_F9, 		KC_F10, 	KC_F11, 	KC_F12,  	_______,                _______,	
	_______, 	LNK_BLE1,  	LNK_BLE2,  	LNK_BLE3,  	LNK_RF,    	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	DEV_RESET,	SLEEP_MODE, BAT_SHOW,	            _______,	
	_______,	_______,   	_______,   	_______,  	_______,   	_______,   	_______,	_______,   	_______,   	_______,  	_______,	_______, 	_______,                            KC_HOME,
	MO(5),				    _______,   	_______,   	_______,  	_______,    _______,   	_______,	MO(6), 		RGB_SPD,	RGB_SPI,	_______,	MO(5),	                RGB_VAI,    KC_END, 
	_______,	_______,	_______,										_______, 							            _______,	MO(4),		            RGB_MOD,    RGB_VAD,	RGB_HUI),

// layer5 win FN2
[5] = LAYOUT(
	S(KC_GRV), 	KC_BRID,   	KC_BRIU,  	KC_F3, 		KC_F4,  	KC_F5,  	KC_F6,  	KC_MPRV,  	KC_MPLY,  	KC_MNXT, 	KC_MUTE, 	KC_VOLD, 	KC_VOLU,  	_______,                _______,	
	_______, 	_______,  	_______,  	_______,  	_______,    _______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______,    _______,	            _______,	
	_______,	_______,   	_______,   	_______,  	_______,   	_______,   	_______,	_______,   	_______,   	_______,  	_______,	_______, 	_______,                            _______,
	_______,				_______,   	_______,   	_______,  	_______,    _______,   	_______,	_______, 	_______,	_______,	_______,	_______,	            _______,    _______, 
	_______,	_______,	_______,										_______, 							            _______,	_______,		        _______,    _______,	_______),
// layer 6
[6] = LAYOUT(
	_______, 	_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______, 	_______,	            _______,
	_______, 	_______,  	_______,  	_______,  	_______,    _______,    _______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______, 	_______,	            _______,
	_______,	_______,   	_______,   	_______,  	_______,   	_______,   	_______,	_______,   	_______,   	_______,  	_______,	_______, 	_______,                            _______,
	_______,				_______,   	_______,   	_______,  	_______,   	_______,   	_______,	_______, 	SIDE_SPD,	SIDE_SPI,	SIDE_MOD_B,	_______,	            SIDE_VAI,   _______,
	_______,	_______,	_______,										_______, 							_______,	_______,   	        	            SIDE_MOD_A, SIDE_VAD,	SIDE_HUI),

// layer7 Symbols (V hold)
[7] = LAYOUT(
	_______, 	_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______, 	_______,	            _______,
	_______, 	_______,  	_______,  	_______,  	_______,    _______,    _______,   	KC_LPRN,   	KC_RPRN,   	KC_MINS,  	KC_EQL,   	_______,	_______, 	_______,	            _______,
	_______,	_______,   	_______,   	_______,  	_______,   	_______,   	KC_ASTR,	KC_LCBR,   	KC_RCBR,   	KC_QUOT,  	_______,	_______, 	_______,                            _______,
	_______,				_______,   	_______,   	_______,  	_______,   	_______,   	KC_QUES,	KC_SLSH, 	KC_LABK,	KC_RABK,	_______,	_______,	            _______,    _______,
	_______,	_______,	_______,										KC_ENT, 							_______,	_______,   	        	            _______,    _______,	_______),

// layer8 Numbers + Tmux/Vim (N/M hold)
[8] = LAYOUT(
	TMUX_CLOSE_PANE, 	_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______, 	_______,	            _______,
	_______, 	KC_1,  		KC_2,  		KC_3,  		KC_4,    	KC_5,    	KC_6,   	KC_7,   	KC_8,   	KC_9,  		KC_0,   	_______,	_______, 	_______,	            _______,
	KC_GRV,	_______,   	_______,   	VIM_PREVIOUS_TAB,  	VIM_NEXT_TAB,   	_______,   	_______,	_______,   	TMUX_SCROLL_AND_SEARCH,   	TMUX_SCROLL,  	TMUX_PREVIOUS,	_______, 	_______,                            _______,
	_______,				TMUX_ZOOM,   	TMUX_CREATE_WINDOW,   	TMUX_PREVIOUS_WINDOW,  	TMUX_NEXT_WINDOW,   	_______,   	_______,	TMUX_LIST, 	_______,	_______,	_______,	_______,	            _______,    _______,
	TMUX_CREATE_WINDOW,	_______,	_______,										KC_ENT, 							_______,	_______,   	        	            _______,    _______,	_______),

// layer9 Navigation (Space hold)
[9] = LAYOUT(
	_______, 	KC_F1,   	KC_F2,   	KC_F3,  	KC_F4,   	KC_F5,   	KC_F6,   	KC_F7,   	KC_F8,   	KC_F9,  	KC_F10,   	KC_F11,	KC_F12, 	_______,	            _______,
	LCMD(KC_TAB), 	VIM_CLOSE_TAB,  LCMD(KC_W),  VIM_NEXT_TAB,  	LCMD(KC_R),    	LCMD(KC_T),    	_______,   	_______,   	_______,   	_______,  	TMUX_PREVIOUS,   	_______,	_______, 	_______,	            _______,
	_______,	_______,   	_______,   	_______,  	_______,   	_______,   	KC_LEFT,	KC_DOWN,   	KC_UP,   	KC_RIGHT,  	TMUX_LIST,	KC_QUOT, 	_______,                            _______,
	_______,				_______,   	_______,   	_______,  	_______,   	_______,   	KC_ASTR,	KC_SLSH, 	_______,	_______,	_______,	_______,	            _______,    _______,
	_______,	_______,	_______,										KC_ENT, 							_______,	_______,   	        	            _______,    _______,	_______),
};

enum combos {
    PREVIOUS_TAB_COMBO,
    NEXT_TAB_COMBO,
    PREVIOUS_APPLICATION_COMBO,
    JK_ENTER_COMBO,
    VIM_CLIPBOARD_REGISTER_COMBO,
};

const uint16_t PROGMEM previous_tab_combo[] = {LCTL_T(KC_S), LOPT_T(KC_D), COMBO_END};
const uint16_t PROGMEM next_tab_combo[] = {LOPT_T(KC_D), LSFT_T(KC_F), COMBO_END};
const uint16_t PROGMEM previous_application_combo[] = {LCTL_T(KC_S), LOPT_T(KC_D), LSFT_T(KC_F), COMBO_END};
const uint16_t PROGMEM jk_enter_combo[] = {LSFT_T(KC_J), LOPT_T(KC_K), COMBO_END};
const uint16_t PROGMEM vim_clipboard_register_combo[] = {KC_U, KC_I, COMBO_END};

combo_t key_combos[] = {
    [PREVIOUS_TAB_COMBO] = COMBO(previous_tab_combo, PREVIOUS_TAB),
    [NEXT_TAB_COMBO] = COMBO(next_tab_combo, NEXT_TAB),
    [PREVIOUS_APPLICATION_COMBO] = COMBO(previous_application_combo, PREVIOUS_APPLICATION),
    [JK_ENTER_COMBO] = COMBO(jk_enter_combo, KC_ENT),
    [VIM_CLIPBOARD_REGISTER_COMBO] = COMBO(vim_clipboard_register_combo, VIM_CLIPBOARD_REGISTER),
};

bool get_combo_must_tap(uint16_t combo_index, combo_t *combo) {
    switch (combo_index) {
        case JK_ENTER_COMBO:
            return true;
        default:
            return false;
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
            case VIM_PREVIOUS_TAB:
                SEND_STRING("gT");
                return false;
            case VIM_NEXT_TAB:
                SEND_STRING("gt");
                return false;
            case VIM_CLOSE_TAB:
                SEND_STRING(SS_TAP(X_ESC) " q");
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
            case TMUX_CLOSE_PANE:
                SEND_STRING(SS_LCTL("s") "x");
                return false;
            case VIM_CLIPBOARD_REGISTER:
                SEND_STRING("\"*");
                return false;
        }
    }
    return true;
}

const is31_led PROGMEM g_is31_leds[RGB_MATRIX_LED_COUNT] = {
    //Main RGB
    {0, D_1,    E_1,    F_1},       // "ESC`"   
    {0, D_2,    E_2,    F_2},       // "!1"
    {0, D_3,    E_3,    F_3},       // "@2"
    {0, D_4,    E_4,    F_4},       // "#3"
    {0, A_6,    B_6,    C_6},       // "4"   
    {0, A_7,    B_7,    C_7},       // "5"
    {0, A_8,    B_8,    C_8},       // "6"
    {0, A_9,    B_9,    C_9},       // "7"
    {0, A_10,   B_10,   C_10},      // "8"
    {1, A_1,    B_1,    C_1},       // "(9"
    {1, A_2,    B_2,    C_2},       // ")0"
    {1, A_3,    B_3,    C_3},       // "_-"
    {1, A_4,    B_4,    C_4},       // "+="
    {1, A_5,    B_5,    C_5},       // "Backsp"
    {1, A_6,    B_6,    C_6},       // "ins"   

    {0, D_5,    E_5,    F_5},       // "Tab"  
    {0, D_6,    E_6,    F_6},       // "Q"
    {0, D_7,    E_7,    F_7},       // "W"
    {0, D_8,    E_8,    F_8},       // "E"
    {0, D_9,    E_9,    F_9},       // "R"
    {0, D_10,   E_10,   F_10},      // "T"
    {1, D_1,    E_1,    F_1},       // "Y"
    {1, D_2,    E_2,    F_2},       // "U"
    {1, D_3,    E_3,    F_3},       // "I"
    {1, D_4,    E_4,    F_4},       // "O"
    {1, D_5,    E_5,    F_5},       // "P"
    {1, A_7,    B_7,    C_7},       // "{["
    {1, A_8,    B_8,    C_8},       // "}]"
    {1, A_9,    B_9,    C_9},       // "|\\"
    {1, A_10,   B_10,   C_10},      // "del"   

    {0, G_1,    H_1,    I_1},       // "Caps"   
    {0, G_2,    H_2,    I_2},       // "A"
    {0, G_3,    H_3,    I_3},       // "S"
    {0, G_4,    H_4,    I_4},       // "D"
    {0, G_5,    H_5,    I_5},       // "F"
    {0, G_6,    H_6,    I_6},       // "G"
    {0, G_7,    H_7,    I_7},       // "H"
    {0, G_8,    H_8,    I_8},       // "J"
    {1, G_1,    H_1,    I_1},       // "K"
    {1, G_2,    H_2,    I_2},       // "L"
    {1, G_3,    H_3,    I_3},       // ":"
    {1, G_4,    H_4,    I_4},       // "\""
    {1, G_5,    H_5,    I_5},       // "Enter"
    {1, G_10,   H_10,   I_10},      // "PGUP"  

    {0, J_1,    K_1,    L_1},       // "Shift"   
    {0, J_3,    K_3,    L_3},       // "Z"
    {0, J_4,    K_4,    L_4},       // "X"
    {0, J_5,    K_5,    L_5},       // "C"
    {0, J_6,    K_6,    L_6},       // "V"
    {0, J_7,    K_7,    L_7},       // "B"
    {0, J_8,    K_8,    L_8},       // "N"
    {0, J_9,    K_9,    L_9},       // "M"
    {0, J_10,   K_10,   L_10},      // "<,"
    {1, D_6,    E_6,    F_6},       // ">."
    {1, D_7,    E_7,    F_7},       // "?/"
    {1, D_8,    E_8,    F_8},       // "Shift"
    {1, D_9,    E_9,    F_9},       // "UP"
    {1, D_10,   E_10,   F_10},      // "PGDN"   

    {0, G_9,    H_9,    I_9},       // "Ctrl"   
    {0, G_10,   H_10,   I_10},      // "Opt"
    {0, J_2,    K_2,    L_2},       // "Cmd"
    {1, J_3,    K_3,    L_3},       // "Space"
    {1, J_4,    K_4,    L_4},       // "Cmd"
    {1, J_5,    K_5,    L_5},       // "Fn"
    {1, G_7,    H_7,    I_7},       // "LEFT"
    {1, G_8,    H_8,    I_8},       // "DOWN"
    {1, G_9,    H_9,    I_9},       // "RIGHT"   

    //Side RGB
    {0, A_1,    B_1,    C_1},       
    {0, A_2,    B_2,    C_2},       
    {0, A_3,    B_3,    C_3},       
    {0, A_4,    B_4,    C_4},       
    {0, A_5,    B_5,    C_5},       
    {1, J_6,    K_6,    L_6},      
    {1, J_7,    K_7,    L_7},
    {1, J_8,    K_8,    L_8},
    {1, J_9,    K_9,    L_9},
    {1, J_10,   K_10,   L_10},
    {0, A_12,   B_12,   C_12},       
    {0, A_13,   B_13,   C_13},       
    {0, A_14,   B_14,   C_14},       
    {0, A_15,   B_15,   C_15},       
    {0, A_16,   B_16,   C_16},       
    {0, D_16,   E_16,   F_16},       
    {0, D_15,   E_15,   F_15},       
    {0, D_14,   E_14,   F_14},       
    {0, D_13,   E_13,   F_13},       
    {0, D_12,   E_12,   F_12},       
    {0, G_12,   H_12,   I_12},       
    {0, G_13,   H_13,   I_13},       
    {0, G_14,   H_14,   I_14},       
    {0, G_15,   H_15,   I_15},       
    {0, G_16,   H_16,   I_16},       
    {0, J_16,   K_16,   L_16},       
    {0, J_15,   K_15,   L_15},       
    {0, J_14,   K_14,   L_14},       
    {0, J_13,   K_13,   L_13},        
    {0, J_12,   K_12,   L_12},       
    {1, A_12,   B_12,   C_12},      
    {1, A_13,   B_13,   C_13},      
    {1, A_14,   B_14,   C_14},      
    {1, A_15,   B_15,   C_15},      
    {1, A_16,   B_16,   C_16},      
    {1, D_16,   E_16,   F_16},      
    {1, D_15,   E_15,   F_15},      
    {1, D_14,   E_14,   F_14},      
    {1, D_13,   E_13,   F_13},      
    {1, D_12,   E_12,   F_12},      
    {1, G_12,   H_12,   I_12},      
    {1, G_13,   H_13,   I_13},      
    {1, G_14,   H_14,   I_14},      
    {1, G_15,   H_15,   I_15},      
    {1, G_16,   H_16,   I_16},      
    {1, J_16,   K_16,   L_16},      
    {1, J_15,   K_15,   L_15},      
    {1, J_14,   K_14,   L_14},      
    {1, J_13,   K_13,   L_13},      
    {1, J_12,   K_12,   L_12},       
};

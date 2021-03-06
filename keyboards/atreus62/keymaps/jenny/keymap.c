#include QMK_KEYBOARD_H

// keys
#define _SCREEN_SHOT LCTL(LGUI(LSFT(KC_4)))
#define _DUXO LCTL(LSFT(KC_D))
#define _ACTION LGUI(LSFT(KC_A))
#define _FRAGMENT LCTL(LSFT(KC_F))
#define _VIEW_STATE LCTL(LSFT(KC_V))
#define _GT_LAYOUT LCTL(LSFT(KC_L))
#define _IMPORT LALT(LCTL(KC_O))
#define _FORMAT LALT(LGUI(KC_L))
#define _RENAME LSFT(KC_F6)
#define _REFACTOR LCTL(KC_T)
#define _AUTOSHIFT KC_ASTG
#define _INPUT_M LCTL(LALT(KC_SPC))

#define _MOVE_CURSOR_AHEAD LCTL(KC_A)
#define _MOVE_CURSOR_END LCTL(KC_E)

// layers
#define _DEFAULT 0
#define _FN 1
#define _ANDROID 2
#define _NUMPAD 3
#define _MEDIA 4
#define _MOUSE 5
#define _NAV 6

#define TO_DEFAULT TO(_DEFAULT)
#define FN MO(_FN)
#define MO_MEDIA MO(_MEDIA)
#define TG_MOUSE TG(_MOUSE)
#define MO_NUMPAD MO(_NUMPAD)
#define OSL_ANDROID OSL(_ANDROID)
#define MO_NAV MO(_NAV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[_DEFAULT] = LAYOUT(KC_ESCAPE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, MO_NAV, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_BSLS, KC_LCTL, MO_MEDIA, MO_NUMPAD, KC_LALT, KC_LGUI, KC_SPC, FN, KC_ENT, KC_SPC, OSL_ANDROID, KC_EQL, KC_MINS, KC_LBRC, KC_RBRC),
                                                              [_FN]      = LAYOUT(KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_NO, KC_UNDERSCORE, KC_KP_PLUS, KC_MINS, KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR, KC_NO, KC_NO, KC_F12, _______, KC_NO, KC_KP_SLASH, KC_KP_ASTERISK, KC_PEQL, KC_LBRACKET, KC_LEFT_ANGLE_BRACKET, KC_RIGHT_ANGLE_BRACKET, KC_RBRACKET, KC_NO, KC_NO, KC_NO, KC_NO, _______, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, _______, _______, _______, _______, _______, _______, _______, _______, KC_NO, KC_NO, KC_UP, KC_DOWN, KC_LEFT, KC_RIGHT),
                                                              [_ANDROID] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, _IMPORT, _FORMAT, KC_NO, KC_NO, _ACTION, _SCREEN_SHOT, _DUXO, _FRAGMENT, KC_NO, KC_NO, KC_NO, KC_NO, _GT_LAYOUT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, _VIEW_STATE, KC_NO, KC_NO, KC_NO, KC_NO, _RENAME, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO_DEFAULT, KC_NO, _REFACTOR, KC_NO, KC_NO),
                                                              [_NUMPAD]  = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, _______, KC_1, KC_2, KC_3, KC_4, KC_5, KC_KP_PLUS, KC_KP_MINUS, KC_KP_ASTERISK, KC_KP_SLASH, KC_NO, _______, _______, KC_6, KC_7, KC_8, KC_9, KC_0, KC_PCMM, KC_PEQL, KC_PDOT, KC_NO, KC_NO, KC_NO, _______, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_NO, KC_NO, KC_NO, KC_NO),
                                                              [_MEDIA]   = LAYOUT(_INPUT_M, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_VOLU, KC_NO, KC_NO, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, KC_NO, KC_NO, KC_NO, KC_MRWD, KC_VOLD, KC_MFFD, KC_NO, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, KC_NO, _______, _______, _______, _______, _______, _______, KC_MPLY, RGB_TOG, RGB_M_X, RGB_M_G, RGB_M_K, KC_NO, KC_NO, KC_NO),
                                                              [_MOUSE]   = LAYOUT(KC_NO, KC_ACL0, KC_ACL1, KC_ACL2, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_D, KC_NO, KC_NO, KC_NO, KC_NO, KC_MS_U, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_R, KC_WH_U, KC_WH_L, KC_NO, KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, _______, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BTN2, KC_BTN1, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
 [6] = LAYOUT(_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,LCTL(KC_Q),LCTL(KC_W),_MOVE_CURSOR_END,LCTL(KC_E),LCTL(KC_R),LCTL(KC_Y),LCTL(KC_U),LCTL(KC_I),LCTL(KC_O),KC_UP,LCTL(KC_BSPACE),_______,_MOVE_CURSOR_AHEAD,LCTL(KC_X),KC_DELETE,KC_RIGHT,LCTL(KC_G),LCTL(KC_H),LCTL(KC_J),LCTL(KC_K),LCTL(KC_O),LCTL(KC_SCOLON),LCTL(KC_COMMA),_______,LCTL(KC_Z),LCTL(KC_X),LCTL(KC_C),LCTL(KC_V),KC_LEFT,KC_DOWN,LCTL(KC_M),LCTL(KC_COMMA),LCTL(KC_DOT),LCTL(KC_SLASH),LCTL(KC_BSLS),_______,_______,_______,_______,_______,LCTL(KC_SPC),_______,LCTL(KC_ENT),LCTL(KC_SPC),_______,LCTL(KC_EQL),LCTL(KC_MINS),LCTL(KC_LBRC),LCTL(KC_RBRC))};

uint8_t  prev = _DEFAULT;
uint32_t check;
uint32_t desired = RGBLIGHT_MODE_BREATHING;

void matrix_init_user() { rgblight_mode(desired); }

uint32_t layer_state_set_user(uint32_t state) {
    uint8_t layer = biton32(state);
    if (prev != _MEDIA) {
        switch (layer) {
            case _DEFAULT:
                rgblight_mode(desired);
                break;

            case _FN:
                rgblight_mode(RGBLIGHT_MODE_KNIGHT);
                break;

            case _ANDROID:
                rgblight_mode(RGBLIGHT_MODE_ALTERNATING);
                break;
            case _NUMPAD:
                rgblight_mode(RGBLIGHT_MODE_TWINKLE);
            case _MOUSE:
                rgblight_mode(RGBLIGHT_MODE_KNIGHT + 1);
            case _MEDIA:
                break;
        }
    } else {
        desired = rgblight_get_mode();
    }
    prev = layer;
    return state;
}

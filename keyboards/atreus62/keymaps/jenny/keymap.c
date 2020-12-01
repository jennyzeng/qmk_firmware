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
#define _____ KC_TRNS

// layers
#define _DEFAULT 0
#define _FN 1
#define _ANDROID 2
#define _NUMPAD 3
#define _MEDIA 4

#define TO_DEFAULT TO(0)
#define FN MO(1)
#define MO_MEDIA MO(4)
#define TG_NUMPAD TG(3)
#define OSL_ANDROID OSL(2)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[_DEFAULT] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_BSLS, _SCREEN_SHOT, TG_NUMPAD, MO_MEDIA, KC_LALT, KC_LGUI, KC_SPC, FN, KC_ENT, KC_SPC, OSL_ANDROID, KC_EQL, KC_MINS, KC_LBRC, KC_RBRC),
                                                              [_FN]      = LAYOUT(KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_KP_ASTERISK, KC_KP_PLUS, KC_MINS, KC_UP, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_NO, KC_NO, KC_F12, _____, KC_KP_SLASH, KC_PEQL, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_LBRC, KC_RBRC, KC_NO, KC_NO, KC_NO, KC_NO, _____, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET, _____, _____, _____, _____, _____, _____, _____, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
                                                              [_ANDROID] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, _IMPORT, _FORMAT, KC_NO, KC_NO, _ACTION, _SCREEN_SHOT, _DUXO, _FRAGMENT, KC_NO, KC_NO, KC_NO, KC_NO, _GT_LAYOUT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, _VIEW_STATE, KC_NO, KC_NO, KC_NO, KC_NO, _RENAME, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO_DEFAULT, KC_NO, _REFACTOR, KC_NO, KC_NO),
                                                              [_NUMPAD]  = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PSLS, KC_PAST, KC_PMNS, KC_NO, KC_NO, _____, KC_NO, KC_NO, KC_UP, KC_NO, KC_NO, KC_P7, KC_P8, KC_P9, KC_PPLS, KC_NO, _____, _____, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_P4, KC_P5, KC_P6, KC_PCMM, KC_NO, KC_NO, _____, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P1, KC_P2, KC_P3, KC_PEQL, KC_NO, KC_NO, KC_NO, _____, _____, _____, _____, _____, _____, _____, _____, KC_P0, KC_PDOT, KC_PENT, KC_NO, KC_NO),
                                                              [_MEDIA]   = LAYOUT(KC_NO, _AUTOSHIFT, _INPUT_M, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_VOLU, KC_NO, KC_NO, KC_NO, RGB_MOD, RGB_HUI, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, KC_NO, KC_MRWD, KC_VOLD, KC_MFFD, KC_NO, KC_NO, RGB_RMOD, RGB_HUD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, KC_NO, _____, _____, _____, _____, _____, KC_MPLY, RGB_TOG, RGB_M_X, RGB_M_G, KC_NO, KC_NO, KC_NO, KC_NO)};


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

            case _MEDIA:
                break;
        }
    } else {
        desired = rgblight_get_mode();
    }
    prev = layer;
    return state;
}

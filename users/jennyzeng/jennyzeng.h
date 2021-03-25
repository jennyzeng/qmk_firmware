#include "quantum.h"


/* Shortcuts */
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
#define _ZOOM_IN LGUI(KC_PLUS)
#define _ZOOM_OUT LGUI(KC_MINS)

// navigation
#define _MISSION_CONTROL LCTL(KC_UP)
#define _ALFRED LALT(KC_SPACE)
#define _TOGGLE_DOCK LGUI((LALT(KC_D)))
#define _DESKTOP LCTL(KC_DOWN)
#define _LEFT_SPACE LCTL(KC_LEFT)
#define _RIGHT_SPACE LCTL(KC_RIGHT)
#define _LEFT_TAB SCMD(KC_LBRC)
#define _RIGHT_TAB SCMD(KC_RBRC)
#define _BROWSER_BACK LGUI(KC_LBRC)
#define _BROWSER_FORWARD LGUI(KC_RBRC)
#define _LEFT_WORD LALT(KC_LEFT)
#define _RIGHT_WORD LALT(KC_RIGHT)

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _FN,
};



/* Wrappers */
#define LAYOUT_crkbd_wrapper(...)   LAYOUT_split_3x6_3(__VA_ARGS__)
#define LAYOUT_kyria_wrapper(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_atreus62_grid_wrapper(...)  LAYOUT(__VA_ARGS__)

/* Qwerty Layer */
#define QWERTY_L0   KC_ESC,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define QWERTY_L1   KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define QWERTY_L2   KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define QWERTY_L3   KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define QWERTY_R0                                                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_GRV
#define QWERTY_R1                                                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC
#define QWERTY_R2                                                           KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT
#define QWERTY_R3                                                           KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_ESC

/* Lower Layer */
#define LOWER_L1    KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define LOWER_L2    KC_LCTL,  _LEFT_SPACE, _RIGHT_SPACE,  _LEFT_TAB, _RIGHT_TAB, _ZOOM_IN
#define LOWER_L3    KC_LSFT, KC_PGUP, KC_PGDOWN, _BROWSER_BACK, _BROWSER_FORWARD, _ZOOM_OUT

#define LOWER_R1                                                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC
#define LOWER_R2                                                            KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_HOME, KC_END
#define LOWER_R3                                                            _LEFT_WORD, _RIGHT_WORD, _MISSION_CONTROL, _TOGGLE_DOCK, _DESKTOP, XXXXXXX

/* Raise Layer */
#define RAISE_L1    KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC
#define RAISE_L2    KC_LCTL, KC_F2, _REFACTOR, _RENAME, _FORMAT, _IMPORT
#define RAISE_L3    KC_LSFT,  _SCREEN_SHOT, _DUXO, _FRAGMENT, _VIEW_STATE, _GT_LAYOUT

#define RAISE_R1                                                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC
#define RAISE_R2                                                            KC_MINS,  KC_EQL, KC_LCBR, KC_RCBR, KC_BSLS,  KC_GRV
#define RAISE_R3                                                            KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_PIPE, KC_TILD

/* adjust Layer */
#define ADJUST_L1    RGB_TOG, RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ADJUST_L2    RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX
#define ADJUST_L3    RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX

#define ADJUST_R1                                                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ADJUST_R2                                                            KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, XXXXXXX
#define ADJUST_R3                                                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

/** fn Layer */
#define FN_L    _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5
#define FN_R    KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, _______

/** transparent row */
#define TRANS_5  _______, _______ , _______, _______, _______
#define TRANS_6  TRANS_5, _______
#define TRANS_7  TRANS_6, _______
#define TRANS_12   TRANS_6, TRANS_6
#define TRANS_14 TRANS_7, TRANS_7

#define QWERTY_0_12 QWERTY_L0, QWERTY_R0
#define QWERTY_1_12 QWERTY_L1, QWERTY_R1
#define QWERTY_2_12 QWERTY_L2, QWERTY_R2
#define QWERTY_3_12 QWERTY_L3, QWERTY_R3

#define LOWER_1_12 LOWER_L1, LOWER_R1
#define LOWER_2_12 LOWER_L2, LOWER_R2
#define LOWER_3_12 LOWER_L3, LOWER_R3

#define RAISE_1_12 RAISE_L1, RAISE_R1
#define RAISE_2_12 RAISE_L2, RAISE_R2
#define RAISE_3_12 RAISE_L3, RAISE_R3

#define ADJUST_1_12 ADJUST_L1, ADJUST_R1
#define ADJUST_2_12 ADJUST_L2, ADJUST_R2
#define ADJUST_3_12 ADJUST_L3, ADJUST_R3

#define FN_12 FN_L, FN_R

#define QWERTY_L4_CORNE                                    KC_LGUI,   MO(_LOWER),  KC_SPC
#define QWERTY_R4_CORNE                                    KC_ENT,   MO(_RAISE), KC_RALT
#define QWERTY_4_CORNE_12 QWERTY_L4_CORNE, QWERTY_R4_CORNE

#define LOWER_L4_CORNE                                      KC_LGUI, _______,  KC_SPC
#define LOWER_R4_CORNE                                      KC_ENT,   MO(_ADJUST), KC_RALT
#define LOWER_4_CORNE_12 LOWER_L4_CORNE, LOWER_R4_CORNE

#define RAISE_L4_CORNE                                      KC_LGUI,   MO(_ADJUST),  KC_SPC
#define RAISE_R4_CORNE                                      KC_ENT, _______, KC_RALT
#define RAISE_4_CORNE_12 RAISE_L4_CORNE, RAISE_R4_CORNE

#define ADJUST_L4_CORNE                                      KC_LGUI, _______,  KC_SPC
#define ADJUST_R4_CORNE                                      KC_ENT, _______, KC_RALT
#define ADJUST_4_CORNE_12 ADJUST_L4_CORNE, ADJUST_R4_CORNE


#define QWERTY_L3_KYRIA                                    QWERTY_L3, XXXXXXX,   KC_LCBR
#define QWERTY_R3_KYRIA                                                                         KC_RCBR, XXXXXXX, QWERTY_R3
#define QWERTY_3_KYRIA_12 QWERTY_L3_KYRIA, QWERTY_R3_KYRIA

#define QWERTY_L4_KYRIA                                    _ALFRED, QWERTY_L4_CORNE, KC_LALT
#define QWERTY_R4_KYRIA                                                                         KC_DEL, QWERTY_R4_CORNE, KC_MPLY
#define QWERTY_4_KYRIA_12 QWERTY_L4_KYRIA, QWERTY_R4_KYRIA

#define LOWER_L3_KYRIA                                      LOWER_L3, XXXXXXX,   _______
#define LOWER_R3_KYRIA                                      _______, XXXXXXX, LOWER_R3
#define LOWER_3_KYRIA_12 LOWER_L3_KYRIA, LOWER_R3_KYRIA

#define LOWER_L4_KYRIA                                      TRANS_5
#define LOWER_R4_KYRIA                                      _______, LOWER_R4_CORNE, _______
#define LOWER_4_KYRIA_12 LOWER_L4_KYRIA, LOWER_R4_KYRIA

#define RAISE_L3_KYRIA                                      RAISE_L3, XXXXXXX,   _______
#define RAISE_R3_KYRIA                                      _______, XXXXXXX, RAISE_R3
#define RAISE_3_KYRIA_12 RAISE_L3_KYRIA, RAISE_R3_KYRIA

#define RAISE_L4_KYRIA                                      _______, RAISE_L4_CORNE, _______
#define RAISE_R4_KYRIA                                      TRANS_5
#define RAISE_4_KYRIA_12 RAISE_L4_KYRIA, RAISE_R4_KYRIA

#define ADJUST_L3_KYRIA                                      ADJUST_L3, XXXXXXX,   _______
#define ADJUST_R3_KYRIA                                      _______, XXXXXXX, ADJUST_R3
#define ADJUST_3_KYRIA_12 ADJUST_L3_KYRIA, ADJUST_R3_KYRIA


#define QWERTY_L4_ATREUS62                                    KC_LBRC, KC_RBRC, MO(_FN), KC_LALT, KC_LGUI,   MO(_LOWER),  KC_SPC
#define QWERTY_R4_ATREUS62                                    KC_ENT,   MO(_RAISE), KC_RALT, KC_LEFT, KC_DOWN , KC_UP, KC_RIGHT
#define QWERTY_4_ATREUS62_14 QWERTY_L4_ATREUS62, QWERTY_R4_ATREUS62

#define LOWER_R4_ATREUS62                                      _______, MO(_ADJUST), TRANS_5
#define LOWER_4_ATREUS62_14 TRANS_7, LOWER_R4_ATREUS62

#define RAISE_L4_ATREUS62                                      TRANS_5, MO(_ADJUST),  _______
#define RAISE_4_ATREUS62_14 RAISE_L4_ATREUS62, TRANS_7


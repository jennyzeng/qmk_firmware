/* Copyright 2020 Team Mechlovin
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

enum layers {
    _DEFAULT,
    _FN,
    _NAV,
    _ANDROID,
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*default
    * ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐         ┌───┬───┬───┬───┬───┬───┬───────┐
    * │Ply│ │`~ │! 1│@ 2│# 3│$ 4│% 5│^ 6│         │& 7│* 8│( 9│) 0│_ -│+ =│ Bspc  │
    * ├───┤ ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘       ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
    * │PRV│ │Tab  │ Q │ W │ E │ R │ T │         │ Y │ U │ I │ O │ P │{ [│} ]│ \|  │
    * ├───┤ ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐        └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
    * │NXT│ │NAV   │ A │ S │ D │ F │ G │         │ H │ J │ K │ L │: ;│" '│   Enter│
    * └───┘ ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐     ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
    *       │LShift  │ Z │ X │ C │ V │ B │     │ B │ N │ M │< ,│> .│? /│ Shft │Fn │
    *       ├─────┬──┴──┬┴───┴┬──┴───┴┬──┴─┐   ├───┴───┴──┬┴───┴┬──┴───┴────┬─┴───┤
    *       │Andro│     │Cmd  │Spc    │Alt │   │   Spc    │ Del │           │ Ctrl│
    *       └─────┘     └─────┴───────┴────┘   └──────────┴─────┘           └─────┘
    */
    [_DEFAULT] = LAYOUT_all(
    KC_MPLY,  KC_GRAVE, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  XXXXXXX,
    KC_MPRV, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    KC_MNXT, MO(_NAV), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
             KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_B,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, OSL(_FN),
             OSL(_ANDROID),          KC_LGUI, KC_SPC,  KC_LALT,                          KC_SPC,           KC_DEL,          KC_RCTL
  ),
    /*Fn
    * ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐         ┌───┬───┬───┬───┬───┬───┬───────┐
    * │FND│ │Esc│F1 │F2 │F3 │F4 │F5 │F6 │         │F7 │F8 │F9 │F10│F11│F12│ Del   │
    * ├───┤ ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘       ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
    * │   │ │     │   │ up│   │   │   │         │MOD│SAI│HUI│VAI│INC│   │   │     │
    * ├───┤ ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐        └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
    * │   │ │      │ lt│dwn│rht│   │   │         │ROD│SAD│HUD│VAD│DEC│   │        │
    * └───┘ ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐     ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
    *       │        │   │   │   │   │   │     │tog│   │   │   │   │   │      │   │
    *       ├─────┬──┴──┬┴───┴┬──┴───┴┬──┴─┐   ├───┴───┴──┬┴───┴┬──┴───┴────┬─┴───┤
    *       │     │     │     │       │    │   │          │     │           │RESET│
    *       └─────┘     └─────┴───────┴────┘   └──────────┴─────┘           └─────┘
    */
    [_FN] = LAYOUT_all(
    LGUI(KC_F),  KC_ESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  XXXXXXX,
    _______,  _______,  _______, KC_UP,  _______, _______, _______,          RGB_MOD, RGB_SAI, RGB_HUI, RGB_VAI, BL_INC, _______, _______, _______,
    _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,          RGB_RMOD, RGB_SAD, RGB_HUD, RGB_VAD, BL_DEC, _______,          _______,
              _______, _______,  _______,  _______, _______, _______,          RGB_TOG, _______, _______, _______, _______, _______, _______, TO(_DEFAULT),
              _______,          _______, _______, _______,                            _______,          _______,          RESET
  ),
    /* Nav
    * ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐         ┌───┬───┬───┬───┬───┬───┬───────┐
    * │DSK│ │   │   │   │   │   │   │   │         │   │   │   │   │   │   │       │
    * ├───┤ ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘       ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
    * │MUP│ │     │   │   │END│   │   │         │   │   │   │   │Up │   │   │     │
    * ├───┤ ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐        └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
    * │MDN│ │      │HED│   │   │RHT│   │         │   │   │   │   │   │   │        │
    * └───┘ ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐     ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
    *       │        │   │   │   │   │BCK│     │BCK│DWN│   │   │   │   │      │   │
    *       ├─────┬──┴──┬┴───┴┬──┴───┴┬──┴─┐   ├───┴───┴──┬┴───┴┬──┴───┴────┬─┴───┤
    *       │     │     │     │       │    │   │          │     │           │     │
    *       └─────┘     └─────┴───────┴────┘   └──────────┴─────┘           └─────┘
    */
    [_NAV] = LAYOUT_all(
    KC_F11,  	LCTL(KC_GRAVE), LCTL(KC_1),    LCTL(KC_2),    LCTL(KC_3),    LCTL(KC_4),    LCTL(KC_5),    LCTL(KC_6),    LCTL(KC_7),   LCTL(KC_8),    LCTL(KC_9),    LCTL(KC_0), LCTL(KC_MINS), (KC_EQL),  LCTL(KC_BSPC),  XXXXXXX,
    LCTL(KC_UP),  	LCTL(KC_TAB),  LCTL(KC_Q),    LCTL(KC_W),    LCTL(KC_E),    LCTL(KC_R),    LCTL(KC_T),      LCTL(KC_Y),   LCTL(KC_U),    LCTL(KC_I),    LCTL(KC_O),    KC_UP,    LCTL(KC_LBRC), LCTL(KC_RBRC), LCTL(KC_BSLS),
    LCTL(KC_DOWN), 	_______, LCTL(KC_A),    LCTL(KC_S),    LCTL(KC_D),    KC_RIGHT,    LCTL(KC_G),             LCTL(KC_H),   LCTL(KC_J),    LCTL(KC_K),    LCTL(KC_L),    LCTL(KC_SCLN), LCTL(KC_QUOT),          LCTL(KC_ENT),
				_______, LCTL(KC_Z),    LCTL(KC_X),    LCTL(KC_C),    LCTL(KC_V),    LCTL(KC_B),             LCTL(KC_B),   KC_DOWN,    LCTL(KC_M),    LCTL(KC_COMM), LCTL(KC_DOT),  LCTL(KC_SLSH), LCTL(KC_RSFT), _______,
				_______,          _______, LCTL(KC_SPC), _______,                            LCTL(KC_SPC),          LCTL(KC_DEL),          _______
  ),
    /* Android
    * ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐         ┌───┬───┬───┬───┬───┬───┬───────┐
    * │CLS│ │   │   │   │   │   │   │   │         │   │   │   │   │   │   │       │
    * ├───┤ ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘       ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
    * │   │ │     │   │   │   │   │   │         │   │   │   │   │   │   │   │     │
    * ├───┤ ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐        └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
    * │   │ │      │   │   │   │   │   │         │   │   │   │   │   │   │        │
    * └───┘ ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐     ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
    *       │        │   │   │   │   │   │     │   │   │   │   │   │   │      │   │
    *       ├─────┬──┴──┬┴───┴┬──┴───┴┬──┴─┐   ├───┴───┴──┬┴───┴┬──┴───┴────┬─┴───┤
    *       │     │     │     │       │    │   │          │     │           │     │
    *       └─────┘     └─────┴───────┴────┘   └──────────┴─────┘           └─────┘
    */
    [_ANDROID] = LAYOUT_all(
    LGUI(KC_W),  	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX,
    _______,  	_______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______,
    _______, 	_______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,          _______,
				_______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______,
				TO(_DEFAULT),          _______, _______, _______,                            _______,          _______,          _______
  ),
    /* Layout
    * ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐         ┌───┬───┬───┬───┬───┬───┬───────┐
    * │   │ │   │   │   │   │   │   │   │         │   │   │   │   │   │   │       │
    * ├───┤ ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘       ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
    * │   │ │     │   │   │   │   │   │         │   │   │   │   │   │   │   │     │
    * ├───┤ ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐        └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
    * │   │ │      │   │   │   │   │   │         │   │   │   │   │   │   │        │
    * └───┘ ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐     ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
    *       │        │   │   │   │   │   │     │   │   │   │   │   │   │      │   │
    *       ├─────┬──┴──┬┴───┴┬──┴───┴┬──┴─┐   ├───┴───┴──┬┴───┴┬──┴───┴────┬─┴───┤
    *       │     │     │     │       │    │   │          │     │           │     │
    *       └─────┘     └─────┴───────┴────┘   └──────────┴─────┘           └─────┘
    */
    /*
    [_BLANK] = LAYOUT_all( \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                _______,          _______,     _______,      _______,          _______,          _______,                   _______ \

    )
    */
};

#ifdef USE_LEDS_FOR_LAYERS
/*
* layer/ led   0   1   2   3   4   5   6
* 0           *    -   -   *   *   -   *
* 1           -    *   -   *   -   *   *
* 2           -    -   *   -   *   *   *
*/
bool led_update_keymap(led_t led_state) {
    writePin(TOP_LED, LED_ON(IS_LAYER_ON(0) || IS_LAYER_ON(3) || IS_LAYER_ON(4) || IS_LAYER_ON(6)));
    writePin(MIDDLE_LED, LED_ON(IS_LAYER_ON(1) || IS_LAYER_ON(3) || IS_LAYER_ON(5) || IS_LAYER_ON(6)));
    writePin(BOTTOM_LED, LED_ON(IS_LAYER_ON(2) || IS_LAYER_ON(4) || IS_LAYER_ON(5) || IS_LAYER_ON(6)));
    return false; // Override default set by KB
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    switch (get_highest_layer(layer_state)) {
        case _FN:
            // change hue
            if (clockwise) {
            tap_code16(RGB_HUI);
            } else {
            tap_code16(S(RGB_HUD));
            }
            break;
        case _NAV:
            // Switch tabs
            if (clockwise) {
                tap_code16(C(KC_TAB));
            } else {
                tap_code16(S(C(KC_TAB)));
            }
            break;
       case _ANDROID:
            // switch window
            if (clockwise) {
                tap_code16(LCTL(KC_LEFT));
            } else {
                tap_code16(LCTL(KC_RIGHT));
            }
            break;
       default:
            // Volume control
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
            break;
    }
}

  #endif

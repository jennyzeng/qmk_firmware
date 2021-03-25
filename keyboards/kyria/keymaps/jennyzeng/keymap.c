/* Copyright 2020 Fredrik Salomonsson <plattfot@gmail.com>
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
#include "jennyzeng.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_kyria_wrapper(
        QWERTY_1_12,
        QWERTY_2_12,
        QWERTY_3_KYRIA_12,
        QWERTY_4_KYRIA_12
    ),
    [_LOWER] = LAYOUT_kyria_wrapper(
        LOWER_1_12,
        LOWER_2_12,
        LOWER_3_KYRIA_12,
        LOWER_4_KYRIA_12
    ),
    [_RAISE] = LAYOUT_kyria_wrapper(
        RAISE_1_12,
        RAISE_2_12,
        RAISE_3_KYRIA_12,
        RAISE_4_KYRIA_12
    ),
    [_ADJUST] = LAYOUT_kyria_wrapper(
        ADJUST_1_12,
        ADJUST_2_12,
        ADJUST_3_KYRIA_12,
        TRANS_5, TRANS_5
    ),
};

// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// /*
//  * Base Layer: Default
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |   Tab  |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |   Esc |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |  LCtrl |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |  ' "   |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * | LShift |   Z  |   X  |   C  |   V  |   B  |      |adjust|  |android|      |   N  |   M  | ,  < | . >  | /  ? | \|    |
//  * `----------------------+------+------+------+      +------|  |------+      +------+------+------+----------------------'
//  *                        | MPlay| lower| GUI  | Space|      |  |del    |Enter|BSpace|raise |mission|
//  *                        |      |      |      |      | LALT |  |      |      |      |      |control|
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_DEFAULT] = LAYOUT(
//       KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_ESC,
//       KC_LCTL,  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
//       KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,    XXXXXXX,   MO(_ADJUST),       MO(_ANDROID), XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
//                              KC_MPLY, MO(_LOWER), KC_LGUI, KC_SPACE, KC_LALT,               KC_DEL, KC_ENT, KC_BSPC, TT(_RAISE), LCTL(KC_UP)
//     ),
//     /*
//  * Layer symbol
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |   !  |   @  |  #   |  $   |   %  |                              |  ^   |   &   |  *   |  (   |  )  |  `     |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |  -   |  =   |  {   |  }  | "|"   |  "      |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |    |      |      |  |      |        |   _  |   +  |  [   |   ]  |  \   |   ~    |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LOWER] = LAYOUT(
//       _______, KC_EXLM, KC_AT, KC_HASH, KC_DOLLAR, KC_PERC,                                         KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_GRAVE,
//       _______, _______, _______, _______, _______, _______,                                     KC_MINUS, KC_EQUAL, KC_LCBR, KC_RCBR, KC_PIPE, KC_DQUO,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, KC_TILDE,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
// /*
//  * Raise Layer: num keys
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |  1   |   2  |   3  |   4  |   5  |                              |  6   |  7   |  8   |  9   | 0    | ~      |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              | left |  up  |  down| right |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |       |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |default|      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_RAISE] = LAYOUT(
//       _______, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                                       KC_6,   KC_7,   KC_8,   KC_9,   KC_0,  KC_TILDE,
//       _______, _______, _______, _______, _______, _______,                                    KC_LEFT,  KC_UP, KC_DOWN, KC_RIGHT, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, TO(_DEFAULT), _______

//     ),
// /*
//  * Adjust Layer: RGB
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        | TOG  | SAI  | HUI  | VAI  | MOD  |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      | SAD  | HUD  | VAD  | RMOD |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_ADJUST] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),

//     /*
//  * Layer Android
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |  F2   |      | rename   |      |                              |      |      |      |import|format|        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        | action|screenshot|duxo|fragment|      |                         |      |      |      |layout|       |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |viewstate |      |      |      |  |      |      |      |      |      |rename|refactor |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_ANDROID] = LAYOUT(
//       _______, _______, KC_F2, _______, LSFT(KC_F6), _______,                                     _______, _______, _______, _IMPORT, _FORMAT, _______,
//       _______, _ACTION, _SCREEN_SHOT, _DUXO, _FRAGMENT, _______,                                     _______, _______, _______, _GT_LAYOUT, _______, _______,
//       _______, _______, _______, _______, _VIEW_STATE, _______, _______, _______, _______, _______, _______, _______, _______, _RENAME, _REFACTOR, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
// // /*
// //  * Layer template
// //  *
// //  * ,-------------------------------------------.                              ,-------------------------------------------.
// //  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
// //  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
// //  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
// //  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
// //  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
// //  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
// //  *                        |      |      |      |      |      |  |      |      |      |      |      |
// //  *                        |      |      |      |      |      |  |      |      |      |      |      |
// //  *                        `----------------------------------'  `----------------------------------'
// //  */
// //     [_LAYERINDEX] = LAYOUT(
// //       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
// //       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
// //       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
// //                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
// //     ),
// };

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

// clang-format off
static void render_jenny_logo(void) {
    static const char PROGMEM jenny_logo[] = {
// 'T0252AY77-UQ8PNQ5QF-ac22dc57ff96-512', 128x64px
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0x7f, 0x7f, 0x3f, 0x3f, 0x1f, 0x1f, 0x1f, 0x1f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x1f, 0x1f, 0x1f, 0x3f, 0x3f, 0x3f, 0x7f, 0x7f, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x03,
0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x80, 0xe0, 0xf0, 0xfc, 0xfe, 0xfe, 0xfc, 0xfc, 0xfc, 0xfc,
0xfc, 0xfc, 0xfe, 0xfc, 0xf8, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xff, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0xfc, 0xfe, 0xd6, 0xb6, 0xc5, 0x8d, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xed, 0xed,
0xed, 0x8d, 0x8d, 0x8f, 0xff, 0xff, 0xfc, 0xe0, 0xe0, 0x20, 0x40, 0xe8, 0xf0, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0xe0, 0xf0, 0xf8, 0xf8, 0xf8, 0xf0, 0xc0, 0x00, 0x00,
0x00, 0x00, 0x01, 0x1f, 0x7f, 0xff, 0xff, 0xbf, 0x13, 0x5c, 0x5f, 0x7f, 0x6f, 0xef, 0xaf, 0xcf,
0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x1f, 0x07, 0x03, 0x03, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xff, 0xff, 0xff,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xe0, 0xc1, 0x63, 0x63, 0x73, 0xf1, 0x80, 0x80, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x06, 0x07, 0x07, 0xf7, 0xff,
0xfb, 0xfb, 0xfd, 0xfe, 0x7e, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xf0, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1e, 0x8c, 0xe8, 0xc0, 0xd0, 0xd0,
0xc0, 0xc0, 0xe0, 0x80, 0x10, 0x00, 0x20, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x06, 0x07, 0x07,
0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xfa, 0xf5, 0xef, 0xf7,
0xf7, 0xf7, 0xff, 0xf1, 0xee, 0xdf, 0xbf, 0xbf, 0xff, 0xfe, 0xf0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
0xc0, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xf0, 0xf8,
0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    oled_write_raw_P(jenny_logo, sizeof(jenny_logo));
}

// static void render_qmk_logo(void) {
//     static const char PROGMEM qmk_logo[] = {
//         0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
//         0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
//         0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

//     oled_write_P(qmk_logo, false);
// }
// clang-format on

static void render_status(void) {
    // // QMK Logo and version information
    // render_qmk_logo();
    // oled_write_P(PSTR("Kyria rev1.0\n"), false);
    // oled_write_P(PSTR("v" QMK_VERSION "\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: \n"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Jenny Zeng\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("lower\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("raise\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("adjust\n"), false);
            break;
        default:
            oled_write_P(PSTR("undefined\n"), false);
    }

    oled_write_P(PSTR("Encoder 0: \n"), false);
    switch (get_highest_layer(layer_state)) {
        case _RAISE:
            oled_write_P(PSTR("Switch tabs\n"), false);
            break;
        default:
            oled_write_P(PSTR("Page up/down\n"), false);
            break;
        }

    oled_write_P(PSTR("Encoder 1: \n"), false);
    switch (get_highest_layer(layer_state)) {
        case _LOWER:
            oled_write_P(PSTR("Skip/Prev song\n"), false);
            break;
        default:
            oled_write_P(PSTR("Volume control\n"), false);
            break;
        }

}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_jenny_logo();
    }
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (get_highest_layer(layer_state)) {
            case _RAISE:
                // Zoom
                if (clockwise) {
                    tap_code16(_ZOOM_IN);
                    clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
                } else {
                    tap_code16(_ZOOM_OUT);
                    clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
                }
            default:
                // Page up/down
                if (clockwise) {
                    tap_code(KC_PGDN);
                    clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
                } else {
                    tap_code(KC_PGUP);
                    clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
                }
                break;
        }
    } else if (index == 1) {
        switch (get_highest_layer(layer_state)) {
            case _LOWER:
               // Skip/Prev song
                if (clockwise) {
                    tap_code(KC_MNXT);
                    clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
                } else {
                    tap_code(KC_MPRV);
                    clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
                }
                break;
            default:
                // Volume control
                if (clockwise) {
                    tap_code(KC_VOLU);
                    clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
                } else {
                    tap_code(KC_VOLD);
                    clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
                }
                break;
        }
    }
}
#endif

#ifdef LEADER_ENABLE
LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();
        // Sway navigation
        SEQ_ONE_KEY(KC_Q) {  // Jump to workspace 1
            SEND_STRING(SS_LGUI("1"));
        }
        SEQ_ONE_KEY(KC_W) {  // Jump to workspace 2
            SEND_STRING(SS_LGUI("2"));
        }
        SEQ_ONE_KEY(KC_E) {  // Jump to workspace 3
            SEND_STRING(SS_LGUI("3"));
        }
        SEQ_ONE_KEY(KC_R) {  // Jump to workspace 4
            SEND_STRING(SS_LGUI("4"));
        }
        SEQ_ONE_KEY(KC_T) {  // Jump to workspace 5
            SEND_STRING(SS_LGUI("5"));
        }

        SEQ_ONE_KEY(KC_Y) {  // Jump to workspace 6
            SEND_STRING(SS_LGUI("6"));
        }
        SEQ_ONE_KEY(KC_U) {  // Jump to workspace 7
            SEND_STRING(SS_LGUI("7"));
        }
        SEQ_ONE_KEY(KC_I) {  // Jump to workspace 8
            SEND_STRING(SS_LGUI("8"));
        }
        SEQ_ONE_KEY(KC_O) {  // Jump to workspace 9
            SEND_STRING(SS_LGUI("9"));
        }
        SEQ_ONE_KEY(KC_P) {  // Jump to workspace 0
            SEND_STRING(SS_LGUI("0"));
        }
        SEQ_ONE_KEY(KC_G) {  // View scratch pad
            SEND_STRING(SS_LGUI("-"));
        }

        // Sway move window
        SEQ_TWO_KEYS(KC_M, KC_Q) {  // Move to workspace 1
            SEND_STRING(SS_LSFT(SS_LGUI("1")));
        }
        SEQ_TWO_KEYS(KC_M, KC_W) {  // Move to workspace 2
            SEND_STRING(SS_LSFT(SS_LGUI("2")));
        }
        SEQ_TWO_KEYS(KC_M, KC_E) {  // Move to workspace 3
            SEND_STRING(SS_LSFT(SS_LGUI("3")));
        }
        SEQ_TWO_KEYS(KC_M, KC_R) {  // Move to workspace 4
            SEND_STRING(SS_LSFT(SS_LGUI("4")));
        }
        SEQ_TWO_KEYS(KC_M, KC_T) {  // Move to workspace 5
            SEND_STRING(SS_LSFT(SS_LGUI("5")));
        }

        SEQ_TWO_KEYS(KC_M, KC_Y) {  // Move to workspace 6
            SEND_STRING(SS_LSFT(SS_LGUI("6")));
        }
        SEQ_TWO_KEYS(KC_M, KC_U) {  // Move to workspace 7
            SEND_STRING(SS_LSFT(SS_LGUI("7")));
        }
        SEQ_TWO_KEYS(KC_M, KC_I) {  // Move to workspace 8
            SEND_STRING(SS_LSFT(SS_LGUI("8")));
        }
        SEQ_TWO_KEYS(KC_M, KC_O) {  // Move to workspace 9
            SEND_STRING(SS_LSFT(SS_LGUI("9")));
        }
        SEQ_TWO_KEYS(KC_M, KC_P) {  // Move to workspace 0
            SEND_STRING(SS_LSFT(SS_LGUI("0")));
        }
        SEQ_TWO_KEYS(KC_M, KC_G) {  // Move to scratch pad
            SEND_STRING(SS_LSFT(SS_LGUI("-")));
        }
    }
}
#endif

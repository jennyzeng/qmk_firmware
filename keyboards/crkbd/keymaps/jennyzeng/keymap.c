/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "jennyzeng.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_crkbd_wrapper(
        QWERTY_1_12,
        QWERTY_2_12,
        QWERTY_3_12,
        QWERTY_4_CORNE_12
    ),
    [_LOWER] = LAYOUT_crkbd_wrapper(
        LOWER_1_12,
        LOWER_2_12,
        LOWER_3_12,
        LOWER_4_CORNE_12
    ),
    [_RAISE] = LAYOUT_crkbd_wrapper(
        RAISE_1_12,
        RAISE_2_12,
        RAISE_3_12,
        RAISE_4_CORNE_12
    ),
    [_ADJUST] = LAYOUT_crkbd_wrapper(
        ADJUST_1_12,
        ADJUST_2_12,
        ADJUST_3_12,
        ADJUST_4_CORNE_12
    ),
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_master) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Jenny Zeng"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Unknown"), false);
            break;
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0
        };
    oled_write_P(crkbd_logo, false);
    // oled_write_raw_P(my_logo, sizeof(my_logo));
}

void oled_task_user(void) {
    if (is_master) {
        oled_render_layer_state();
        // oled_render_keylog();
    } else {
        oled_render_logo();
    }
}
#endif // OLED_DRIVER_ENABLE

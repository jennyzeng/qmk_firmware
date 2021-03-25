// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include "jennyzeng.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_atreus62_grid_wrapper(QWERTY_0_12, QWERTY_1_12, QWERTY_2_12, QWERTY_3_12, QWERTY_4_ATREUS62_14),
    [_LOWER] = LAYOUT_atreus62_grid_wrapper(TRANS_12, LOWER_1_12 , LOWER_2_12 , LOWER_3_12 , LOWER_4_ATREUS62_14),
    [_RAISE] = LAYOUT_atreus62_grid_wrapper(TRANS_12, RAISE_1_12   , RAISE_2_12, RAISE_3_12, RAISE_4_ATREUS62_14),
    [_ADJUST] = LAYOUT_atreus62_grid_wrapper(TRANS_12, ADJUST_1_12, ADJUST_2_12, ADJUST_3_12, TRANS_14),
    [_FN] = LAYOUT_atreus62_grid_wrapper(FN_12, TRANS_12 , TRANS_12 , TRANS_12 , TRANS_14)
};

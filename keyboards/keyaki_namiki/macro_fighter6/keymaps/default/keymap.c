/* Copyright 2021 keyaki-namiki
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
#include "keymap_prefs.h"

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    NONE
};

const uint16_t PROGMEM keymaps[4][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        TO(0),   TO(1),   KC_NO,   TO(3),   RGB_MOD, RGB_TOG,
        KC_CAPS, KC_NLCK, KC_NO,   KC_NO,   KC_DEL,  KC_BSPC,
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
        KC_LCTL, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,
        KC_LSFT, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,
        KC_LALT, KC_NO,   KC_NO,   KC_NO,   KC_LGUI, KC_SPC
    ),
    [_NUMPAD] = LAYOUT( 
        _______, _______, _______, _______, KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_ESC,  KC_PSLS, KC_PAST, KC_PMNS,
        KC_NO,   KC_NO,   KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_NO,   KC_QUOT, KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_NO,   KC_TAB,  KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_NO,   KC_NO,   KC_P0,   KC_P0,   KC_PDOT, LT(2,KC_PENT)
    ),
    [_NUMPAD_SHIFT] = LAYOUT(
        _______, _______, _______, _______, _______, KC_NO,
        KC_NO,   KC_NO,   KC_NLCK, _______, _______, _______,
        KC_NO,   KC_NO,   KC_HOME, KC_UP,   KC_END,  _______,
        KC_NO, S(KC_QUOT),KC_LEFT ,KC_NO,   KC_RGHT ,_______,
        KC_NO, S(KC_TAB), KC_BSPC, KC_DOWN, KC_DEL,  _______,
        KC_NO, S(KC_SPC), KC_SPC,  KC_EQL,  KC_COMM, _______
    ),
    [_FN] = LAYOUT(
        _______, _______, _______, _______, KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
    )
};

const uint16_t PROGMEM keymaps_global[4][MATRIX_ROWS][MATRIX_COLS] = {};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NONE:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
            } else {
                // when keycode QMKBEST is released
            }
            break;
    }
    return true;
}

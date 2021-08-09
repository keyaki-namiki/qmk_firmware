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

//#define NONE XXXXXXX

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    IF_CAPS,
    NONE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        TO(0),   TO(1),   NONE,    TO(3),   RGB_MOD, RGB_TOG,
        IF_CAPS, KC_NLCK, NONE,    NONE,    KC_DEL,  KC_BSPC,
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
        KC_LCTL, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,
        KC_LSFT, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  NONE,
        KC_LALT, NONE,    NONE,    NONE,    KC_LGUI, KC_SPC
    ),
    [_NUMPAD] = LAYOUT( 
        TO(0),   TO(1),   NONE,   TO(3),    NONE,    NONE,
        _______, _______, KC_ESC,  KC_PSLS, KC_PAST, KC_PMNS,
        NONE,    NONE,    KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        NONE,    KC_QUOT, KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        NONE,    KC_TAB,  KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        NONE,    NONE,    KC_P0,   KC_P0,   KC_PDOT, LT(2,KC_PENT)
    ),
    [_NUMPAD_SHIFT] = LAYOUT(
        TO(0),   TO(1),   NONE,    TO(3),   NONE,    NONE,
        _______, _______, KC_NLCK, _______, _______, _______,
        NONE,    NONE,    KC_HOME, KC_UP,   KC_END,  _______,
        NONE,  S(KC_QUOT),KC_LEFT ,NONE,    KC_RGHT, _______,
        NONE,  S(KC_TAB), KC_BSPC, KC_DOWN, KC_DEL,  _______,
        NONE,  S(KC_SPC), KC_SPC,  KC_EQL,  KC_COMM, _______
    ),
    [_FN] = LAYOUT(
        TO(0),   TO(1),   NONE,    TO(3),   RESET,   EEP_RST,
        NONE,    NONE,    NONE,    NONE,    NONE,    NONE,
        NONE,    NONE,    NONE,    NONE,    NONE,    NONE,
        NONE,    NONE,    NONE,    NONE,    NONE,    NONE,
        NONE,    NONE,    NONE,    NONE,    NONE,    NONE,
        NONE,    NONE,    NONE,    NONE,    NONE,    NONE
    )
};

static bool caps_state = false;
static bool if_caps_on = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case IF_CAPS: // check if your on-board keyboard caps swapped with LCTL, and submit this key as capslock
            if (record->event.pressed) {
                // when your custom keycode is pressed
                if_caps_on = true;
                caps_state = host_keyboard_led_state().caps_lock;
                register_code(KC_CAPS);
            } else {
                // when your custom keycode is released
                unregister_code(KC_CAPS);
                if(if_caps_on == true) { 
                    if(caps_state == host_keyboard_led_state().caps_lock) {
                    tap_code(KC_LCTL);
                    }
                }
                if_caps_on = false;
            }
            break;
        case NONE:
            if (record->event.pressed) {
                // when your custom keycode is pressed
            } else {
                // when your custom keycode is released
            }
            break;
    }
    return true;
}

void keyboard_post_init_user(void) {
  // Call the post init code.
    rgb_matrix_mode(RGB_MATRIX_CUSTOM_macro_fighter6_matrix);
}

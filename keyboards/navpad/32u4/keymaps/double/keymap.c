/* Copyright 2019 keyaki-namiki
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

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes { QMKBEST = SAFE_RANGE, QMKURL };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] =LAYOUT (\
	KC_ESC, KC_SLCK, KC_PAUS,                  KC_1,   KC_2,	KC_ESC, KC_SLCK, KC_PAUS,                  KC_1,   KC_2,\
	KC_INS,  KC_HOME, KC_PGUP, KC_NLCK,KC_PSLS, KC_PAST, KC_PMNS,	KC_INS,  KC_HOME, KC_PGUP, KC_NLCK,KC_PSLS, KC_PAST, KC_PMNS,\
	KC_DEL,  KC_END,  KC_PGDN, KC_P7,  KC_P8,   KC_P9,   KC_PPLS,	KC_DEL,  KC_END,  KC_PGDN, KC_P7,  KC_P8,   KC_P9,   KC_PPLS,\
                               KC_P4,  KC_P5,   KC_P6,   KC_PPLS,                               KC_P4,  KC_P5,   KC_P6,   KC_PPLS,\
	S(KC_TAB), KC_UP,   KC_TAB, KC_P1,  KC_P2,   KC_P3,   LT(1,KC_PENT),	S(KC_TAB), KC_UP,   KC_TAB, KC_P1,  KC_P2,   KC_P3,   LT(1,KC_PENT),\
	KC_LEFT, KC_DOWN, KC_RGHT, KC_P0,  KC_P0,   KC_PDOT, LT(1,KC_PENT),	KC_LEFT, KC_DOWN, KC_RGHT, KC_P0,  KC_P0,   KC_PDOT, LT(1,KC_PENT) \
    ),
    [1] =LAYOUT (\
	KC_NO,  KC_NO,  RESET,                KC_NO, KC_NO,	KC_NO,  KC_NO,  RESET,                KC_NO, KC_NO,\
	KC_NO,  KC_NO,  KC_NO, BL_STEP,KC_NO, KC_NO, KC_NO,	KC_NO,  KC_NO,  KC_NO, BL_STEP,KC_NO, KC_NO, KC_NO,\
	KC_NO,  KC_NO,  KC_NO, KC_NO,  KC_UP, KC_NO, KC_NO,	KC_NO,  KC_NO,  KC_NO, KC_NO,  KC_UP, KC_NO, KC_NO,\
                         KC_LEFT,KC_NO, KC_RGHT,KC_NO,                         KC_LEFT,KC_NO, KC_RGHT,KC_NO,\
	KC_NO,KC_NO,S(KC_TAB), KC_BSPC,  KC_DOWN, KC_DEL, KC_TRNS,	KC_NO,KC_NO,S(KC_TAB), KC_BSPC,  KC_DOWN, KC_DEL, KC_TRNS,\
	KC_NO, KC_NO,KC_TAB, KC_PEQL,KC_PEQL,KC_NO, KC_TRNS,KC_NO, KC_NO,KC_TAB, KC_PEQL,KC_PEQL,KC_NO, KC_TRNS \
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  } else if (index == 1) { /* Second encoder */  
    if (clockwise) {
      tap_code(KC_WH_D);
    } else {
      tap_code(KC_WH_U);
    }
  }
}
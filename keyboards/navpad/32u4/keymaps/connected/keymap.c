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

enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes { 
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(\
	KC_ESC, KC_SLCK, KC_PAUS,                  KC_1,   KC_2,    KC_ESC,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,          KC_Y,   KC_U,   KC_I,   KC_O,   KC_P, BL_TOGG, KC_BSPC,\
	KC_INS,  KC_HOME, KC_PGUP, KC_NLCK,KC_PSLS, KC_PAST, KC_PMNS,     MT(MOD_LCTL,KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,   KC_ENT,\
	KC_DEL,  KC_END,  KC_PGDN, KC_P7,  KC_P8,   KC_P9,   KC_PPLS,          KC_LSFT,   KC_Z,   KC_X,   KC_C,   KC_V,    KC_B,   KC_N,   KC_M,   KC_COMM,  KC_DOT,   KC_SLSH, ADJUST,\
                               KC_P4,  KC_P5,   KC_P6,   KC_PPLS,                        LOWER,KC_LGUI, LT(_LOWER,KC_SPC),LT(_RAISE,KC_ENT),KC_RALT,RAISE \
	S(KC_TAB), KC_UP,   KC_TAB, KC_P1,  KC_P2,   KC_P3,   LT(1,KC_PENT),\
	KC_LEFT, KC_DOWN, KC_RGHT, KC_P0,  KC_P0,   KC_PDOT, LT(1,KC_PENT), \
    ),
  [_LOWER] = LAYOUT( \
	KC_NO,  KC_NO,  RESET,                KC_NO, KC_NO,      KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11, KC_DEL,\
	KC_NO,  KC_NO,  KC_NO, BL_STEP,KC_NO, KC_NO, KC_NO,       _______, XXXXXXX, KC_INS, KC_DEL, KC_BTN3,  KC_F11, KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT, XXXXXXX, XXXXXXX,\
	KC_NO,  KC_NO,  KC_NO, KC_NO,  KC_UP, KC_NO, KC_NO,            _______, XXXXXXX, KC_BSPC, XXXXXXX, KC_ENT, KC_F12,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,\
                         KC_LEFT,KC_NO, KC_RGHT,KC_NO,                                 LOWER,_______, XXXXXXX, KC_TAB, _______,RAISE\
	KC_NO,KC_NO,S(KC_TAB), KC_BSPC,  KC_DOWN, KC_DEL, KC_TRNS,\
	KC_NO, KC_NO,KC_TAB, KC_PEQL,KC_PEQL,KC_NO, KC_TRNS, \
    ),
  [_RAISE] = LAYOUT( \
	KC_ESC, KC_SLCK, KC_PAUS,                  KC_1,   KC_2,    KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX, KC_GRV,\
	KC_INS,  KC_HOME, KC_PGUP, KC_NLCK,KC_PSLS, KC_PAST, KC_PMNS,      _______,  KC_4,    KC_5,    KC_6,    KC_DOT, XXXXXXX, KC_LBRC, KC_MINS, KC_EQL, KC_BSLS, KC_LPRN,   KC_QUOT,\
	KC_DEL,  KC_END,  KC_PGDN, KC_P7,  KC_P8,   KC_P9,   KC_PPLS,          _______, KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, KC_RBRC, KC_SLSH,S(KC_COMM),S(KC_DOT),KC_RPRN,_______,\
                               KC_P4,  KC_P5,   KC_P6,   KC_PPLS,                                     LOWER,_______, KC_TAB, XXXXXXX, _______,RAISE\
	S(KC_TAB), KC_UP,   KC_TAB, KC_P1,  KC_P2,   KC_P3,   LT(1,KC_PENT),\
	KC_LEFT, KC_DOWN, KC_RGHT, KC_P0,  KC_P0,   KC_PDOT, LT(1,KC_PENT), \
  ),
  [_ADJUST] = LAYOUT( \
	KC_ESC, KC_SLCK, KC_PAUS,                  KC_1,   KC_2,     RESET, DF(_QWERTY),XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, KC_PSCR, KC_UP, XXXXXXX, XXXXXXX, XXXXXXX,\
	KC_INS,  KC_HOME, KC_PGUP, KC_NLCK,KC_PSLS, KC_PAST, KC_PMNS,        KC_CAPS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,BL_STEP, BL_INC, XXXXXXX, KC_LEFT, KC_RGHT, XXXXXXX,\
	KC_DEL,  KC_END,  KC_PGDN, KC_P7,  KC_P8,   KC_P9,   KC_PPLS,            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BL_TOGG, BL_BRTG, BL_DEC, XXXXXXX, KC_DOWN, XXXXXXX, _______,\
                               KC_P4,  KC_P5,   KC_P6,   KC_PPLS,                                    LOWER,_______, XXXXXXX, XXXXXXX, _______,RAISE\
	S(KC_TAB), KC_UP,   KC_TAB, KC_P1,  KC_P2,   KC_P3,   LT(1,KC_PENT),\
	KC_LEFT, KC_DOWN, KC_RGHT, KC_P0,  KC_P0,   KC_PDOT, LT(1,KC_PENT), \
  )
};

void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
	if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
		layer_on(layer3);
	} else {
		layer_off(layer3);
	}
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
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
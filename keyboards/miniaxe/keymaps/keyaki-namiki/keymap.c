/* Copyright 2018 ENDO Katsuhiro <ka2hiro@curlybracket.co.jp>
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
/*
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};
 */

enum layer_number {
    _QWERTY = 0,
    _GAME,
    _LOWER,
    _RAISE,
    _GAME_RAISE,
    _ADJUST
};

#define QWERTY DF(_QWERTY)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT( \
  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,           KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,    \
  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,           KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN, \
  KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,           KC_N,   KC_M,   KC_COMM,KC_DOT, LT(_RAISE,KC_SLSH), \
  MT(MOD_LSFT,KC_TAB),LT(_LOWER,KC_ESC),MT(MOD_LCTL,KC_SPC),MT(MOD_LSFT,KC_BSPC),RAISE,MT(MOD_LALT,KC_ENT)  \
),

[_RAISE] = LAYOUT( \
  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,           KC_6,   KC_7,   KC_8,   KC_9,   KC_0, \
  KC_4,   KC_5,   KC_6,   KC_DOT, KC_GRV,         KC_LBRC,KC_MINS,KC_EQL, KC_BSLS,KC_QUOT, \
  KC_7,   KC_8,   KC_9,   KC_0,   XXXXXXX,        KC_RBRC,KC_SLSH,S(KC_COMM),S(KC_DOT),S(KC_SLSH), \
                  _______,ADJUST, _______,         _______,_______,_______\
),
[_LOWER] = LAYOUT( \
  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,          KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,\
  LCTL(KC_SPC),KC_INS, KC_DEL, KC_BTN3,KC_F11,         KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,XXXXXXX, \
  XXXXXXX,KC_BSPC,XXXXXXX,KC_ENT, KC_F12,         KC_HOME,KC_PGDN,KC_PGUP,KC_END, KC_QUOT, \
                  _______,_______,_______,        _______,ADJUST, _______                    \
),
[_ADJUST] =  LAYOUT( \
  QWERTY, XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,        XXXXXXX,XXXXXXX,KC_PSCR,XXXXXXX,XXXXXXX, \
  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, \
  RESET,  _______,_______,_______,_______,        KC_MPRV,KC_MNXT,KC_VOLD,KC_VOLU,KC_MPLY, \
                  _______,_______,_______,        _______,_______,_______                   \
)
};
/* 
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        // persistant_default_layer_set(1UL<<_QWERTY);
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
*/
void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

void led_set_user(uint8_t usb_led) {
}

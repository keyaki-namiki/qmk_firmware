/* Copyright 2019 yynmt
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


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    MO(1),KC_B,KC_V,KC_C,KC_X,KC_Z,\
    KC_ESC,KC_D,KC_R,KC_E,KC_W,KC_Q
  ),
  [1] = LAYOUT(
    KC_TRNS,XXXXXXX,MT(MOD_LCTL,KC_TAB),KC_ENT ,KC_Q   ,KC_S,\
    KC_LSFT,KC_LGUI,KC_LCTL,KC_DEL ,KC_BTN3,KC_ESC
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

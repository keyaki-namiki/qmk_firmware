/* Copyright 2019 'Naoto Takai'
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

enum layer_names {
    _QWERTY = 0,
    _GAME,
    _LOWER,
    _RAISE,
    _GAME_RAISE,
    _ADJUST
};

#define QWERTY DF(_QWERTY)
#define GAME DF(_GAME)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define GAME_R MO(_GAME_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
    MT(MOD_LCTL,KC_TAB),   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L, KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSFT,   KC_Z,   KC_X,   KC_C,   KC_V,    KC_B,   KC_N,   KC_M,   KC_COMM,  KC_DOT,   KC_SLSH, LT(_RAISE,KC_SLSH), LOWER,
    LOWER,  KC_LGUI, LT(_LOWER,KC_SPC), LT(_RAISE,KC_ENT), KC_LALT, RAISE
  ),
  [_GAME] = LAYOUT(
    KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
    KC_LCTL,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L, KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSFT,   KC_Z,   KC_X,   KC_C,   KC_V,    KC_B,   KC_N,   KC_M,   KC_COMM,  KC_DOT,   KC_SLSH, LT(_RAISE,KC_SLSH), LOWER,
    LT(_LOWER,KC_LGUI),  KC_LSFT, KC_SPC, KC_ENT, KC_LALT, GAME_R
  ),
  [_LOWER] = LAYOUT(
    KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11, KC_F12, KC_DEL,
    _______,  XXXXXXX, KC_INS,  KC_DEL,  KC_BTN3,  KC_F11, KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT, _______, _______, _______,
    _______, XXXXXXX, KC_BSPC, XXXXXXX, KC_ENT, KC_F12,  KC_HOME, KC_PGDN, KC_PGUP, KC_END, _______, _______, _______,
    LOWER, _______, _______, _______, _______, ADJUST
  ),
  [_RAISE] = LAYOUT(
    KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_GRV,
    _______, KC_4,    KC_5,    KC_6,    KC_DOT, XXXXXXX, KC_LBRC, KC_MINS, KC_EQL, KC_BSLS, _______, _______, _______,
    _______, KC_7,    KC_8,    KC_9,    KC_0,    KC_RBRC, KC_SLSH, XXXXXXX,S(KC_COMM),S(KC_DOT), _______, _______, _______,
    ADJUST, _______, MT(MOD_LSFT,KC_TAB), _______, _______, RAISE
  ),
  [_GAME_RAISE] = LAYOUT(
    KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_GRV,
    _______, KC_4,    KC_5,    KC_6,    KC_DOT, XXXXXXX, KC_LBRC, KC_MINS, KC_EQL, KC_BSLS, _______, _______, _______,
    _______, KC_7,    KC_8,    KC_9,    KC_0,    KC_RBRC, KC_SLSH, XXXXXXX,S(KC_COMM),S(KC_DOT), _______, _______, _______,
    ADJUST, _______, KC_TAB, _______, _______, RAISE
  ),
  [_ADJUST] = LAYOUT(
    RESET, DF(_QWERTY),XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(_GAME), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    LOWER, _______, _______, _______, _______, RAISE
  ),
};

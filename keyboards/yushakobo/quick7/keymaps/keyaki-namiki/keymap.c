/* Copyright 2020 yushakobo
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

#define FAVORITE_COLOR HSV_PINK
//#define CAPS_COLOR HSV_TEAL

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FUNC1
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    YUSHAURL = SAFE_RANGE,
    B_MO_FUNC1
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_ESC,    KC_E,    LCTL(KC_S),
        LCTL(KC_H),KC_R,    KC_F,
        KC_X,      KC_V,    B_MO_FUNC1
    ),
    [_FUNC1] = LAYOUT(
        LALT(KC_3),KC_BTN3,     RGB_TOG,
        KC_DEL,    KC_INS,      KC_D,
        KC_W,      KC_BSPC,     KC_TRNS
    )
};

static bool _key_b_pressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case YUSHAURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://yushakobo.jp/\n");
            } else {
                // when keycode QMKURL is released
            }
            return false;
        case B_MO_FUNC1:
            if(record->event.pressed){
                _key_b_pressed = true;
                layer_on(_FUNC1);
            } else {
                layer_off(_FUNC1);
                if(_key_b_pressed){
                    register_code(KC_B);
                    unregister_code(KC_B);
                }
                _key_b_pressed = false;
            }
            return false;
        default:
            if(record->event.pressed){
                _key_b_pressed = false;
            }

    }
    return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { // Left encoder
        if (clockwise) {
            rgblight_decrease_hue_noeeprom();
        } else {
            rgblight_increase_hue_noeeprom();
        }
    }
    else if (index == 1) { // Right encoder
        if (clockwise) {
            tap_code16(S(KC_LBRC));
        } else {
            tap_code16(S(KC_RBRC));
        }
    }
}

const rgblight_segment_t PROGMEM quick7_capslock[] = RGBLIGHT_LAYER_SEGMENTS(
    {9,1,FAVORITE_COLOR},
    {12,1,FAVORITE_COLOR}
);
const rgblight_segment_t PROGMEM quick7_numlock[] = RGBLIGHT_LAYER_SEGMENTS(
    {10,1,FAVORITE_COLOR},
    {11,1,FAVORITE_COLOR}
);

const rgblight_segment_t* const PROGMEM quick7_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    quick7_capslock,
    quick7_numlock
);

void keyboard_post_init_user(void){
    rgblight_layers = quick7_rgb_layers;
    rgblight_sethsv(HSV_WHITE);
}

bool led_update_user(led_t led_state){
    rgblight_set_layer_state(0, led_state.caps_lock);
    rgblight_set_layer_state(1, led_state.num_lock);
    return true;
}
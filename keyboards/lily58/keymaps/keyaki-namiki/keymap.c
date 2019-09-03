#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif


extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

enum layer_names {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST
};

#define QWERTY DF(_QWERTY)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_QWERTY] = LAYOUT( \
  KC_F1,                KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,                                 KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12, \
  KC_ESC,               KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,                                  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC, \
  MT(MOD_LCTL,KC_TAB),  KC_A,     KC_S,    KC_D,    KC_F,    KC_G,                                  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT, \
  KC_LSFT,              KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,  KC_LBRC,              KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, \
                                           KC_LGUI, KC_LALT, LOWER, LT(_LOWER,KC_SPC),    LT(_RAISE,KC_ENT), RAISE,   KC_BSPC, KC_RGUI \
),
[_LOWER] = LAYOUT( \
  _______,  _______, _______, _______, _______, _______,                    _______, _______, _______,_______, _______, _______,\
  _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL, \
  _______,  XXXXXXX,  KC_INS,  KC_DEL,  KC_BTN3,  KC_F11,                   KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT,  KC_LPRN, KC_RPRN, \
  _______,  XXXXXXX,  KC_BSPC, XXXXXXX, KC_ENT,   KC_F12, _______, _______, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
                              _______, _______, LOWER, _______, _______,  ADJUST, _______, _______\
),
[_RAISE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______, \
  _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,     KC_7,    KC_8,    KC_9,       KC_0,    KC_GRV, \
  _______,    KC_4,    KC_5,    KC_6,    KC_DOT,  XXXXXXX,                     KC_LBRC,  KC_MINS, KC_EQL,  KC_BSLS,    KC_RGHT, XXXXXXX, \
  _______,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,  _______, _______,  KC_RBRC,  KC_SLSH, S(KC_COMM),S(KC_DOT), _______, _______, \
                                _______, _______, ADJUST,  MT(MOD_LSFT,KC_TAB), _______,  RAISE, _______, _______ \
),
  [_ADJUST] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  RESET,   QWERTY,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,\
                             _______, _______, LOWER, _______, _______,  RAISE, _______, _______ \
  )
};

//int RGB_current_mode;
//
//// Setting ADJUST layer RGB back to default
//void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
//  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
//    layer_on(layer3);
//  } else {
//    layer_off(layer3);
//  }
//}
//
//void matrix_init_user(void) {
//    #ifdef RGBLIGHT_ENABLE
//      RGB_current_mode = rgblight_config.mode;
//    #endif
//}

//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//  if (record->event.pressed) {
//    // set_timelog();
//  }
//
//  switch (keycode) {
//    case QWERTY:
//      if (record->event.pressed) {
//        set_single_persistent_default_layer(_QWERTY);
//      }
//      return false;
//      break;
//    case LOWER:
//      if (record->event.pressed) {
//        layer_on(_LOWER);
//        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
//      } else {
//        layer_off(_LOWER);
//        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
//      }
//      return false;
//      break;
//    case RAISE:
//      if (record->event.pressed) {
//        layer_on(_RAISE);
//        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
//      } else {
//        layer_off(_RAISE);
//        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
//      }
//      return false;
//      break;
//    case ADJUST:
//        if (record->event.pressed) {
//          layer_on(_ADJUST);
//        } else {
//          layer_off(_ADJUST);
//        }
//        return false;
//        break;
//  }
//  return true;
//}

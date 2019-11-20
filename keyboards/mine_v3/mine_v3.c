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
#include "mine_v3.h"

// Optional override functions below.
// You can leave any or all of these undefined.
// These are only required if you want to perform custom actions.

// Call led_toggle to set LEDs easily
// LED IDs:
// 
// (LEFT) 0 1 2   |   3 4 5 (RIGHT)

void led_toggle(int id, bool on) {
    switch(id) {
        case 0:
            // B5
            if (on)
                writePinHigh(B5);
            else
                writePinLow(B5);
            break;
        case 1:
            // C7
            if (on)
                writePinHigh(C7);
            else
                writePinLow(C7);
            break;
        default:
            break;
  }
}

// Set all LEDs at once using an array of 6 booleans
// LED IDs:
// 
// (LEFT) 0 1 2   |   3 4 5 (RIGHT)
// 
// Ex. set_all_leds({ false, false, false, true, true, true }) would turn off left hand, turn on right hand

void set_all_leds(bool leds[2]) {
	for (int i = 0; i < 6; i++) {
		led_toggle(i, leds[i]);
	}
}

void set_layer_indicators(uint8_t layer) {

  switch (layer)
	{
		case 0:
			led_toggle(0, false);
			led_toggle(1, false);
			break;
		case 1:
			led_toggle(0, true);
			led_toggle(1, true);
			break;
		case 2:
			led_toggle(0, true);
			led_toggle(1, false);
			break;
		case 3:
			led_toggle(0, false);
			led_toggle(1, true);
			break;
        case 4:
			led_toggle(0, false);
			led_toggle(1, true);
            break;
        case 5:
            led_toggle(0, true);
            led_toggle(1, true);
            break;
		default:
			led_toggle(0, false);
			led_toggle(1, false);
			break;
	}
	
}

void matrix_init_kb(void) {
    // put your keyboard start-up code here
    // runs once when the firmware starts up

    setPinOutput(B6);
    setPinOutput(B5);
    setPinOutput(C7);
    writePinLow(B6);
    writePinLow(B5);
    writePinLow(C7);

    matrix_init_user();
}

void matrix_scan_kb(void) {
    // put your looping keyboard code here
    // runs every cycle (a lot)

    matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    // put your per-action keyboard code here
    // runs for every action, just before processing by the firmware

    return process_record_user(keycode, record);
}

void led_set_kb(uint8_t usb_led) {
  // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here
    if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
        writePinHigh(B6);
    } else {
        writePinLow(B6);
    }

  led_set_user(usb_led);
}

uint32_t layer_state_set_kb(uint32_t state) {

    set_layer_indicators(biton32(state));
  
	// NOTE: Do not set slave LEDs here.
	// This is not called on slave
	
	return layer_state_set_user(state);
}


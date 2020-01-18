#include "smd_indicator.h"

void led_set_kb(uint8_t usb_led) {
  // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here
    if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
        writePinHigh(C7);
    } else {
        writePinLow(C7);
    }
    if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
        writePinHigh(C6);
    } else {
        writePinLow(C6);
    }

  led_set_user(usb_led);
}

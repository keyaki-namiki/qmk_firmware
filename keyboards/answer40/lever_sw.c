#include "lever_sw.h"

#ifndef LEVER_SW_RESOLUTION
  #define LEVER_SW_RESOLUTION 2
#endif

#ifndef NUMBER_OF_LEVER_SW
  #error "Number of lever switches not defined by NUMBER_OF_ENCODERS"
#endif

#if !defined(LEVER_SW_PAD_1) || !defined(LEVER_SW_PAD_2) || !defined(LEVER_SW_PAD_3) || !defined(LEVER_SW_PAD_4) || !defined(LEVER_SW_PAD_T)
  #error "No pads defined for lever switch"
#endif

static pin_t lever_sw_pad_1[NUMBER_OF_LEVER_SW] = LEVER_SW_PAD_1;
static pin_t lever_sw_pad_2[NUMBER_OF_LEVER_SW] = LEVER_SW_PAD_2;
static pin_t lever_sw_pad_3[NUMBER_OF_LEVER_SW] = LEVER_SW_PAD_3;
static pin_t lever_sw_pad_4[NUMBER_OF_LEVER_SW] = LEVER_SW_PAD_4;
static pin_t lever_sw_pad_T[NUMBER_OF_LEVER_SW] = LEVER_SW_PAD_T;

//uint8_t lever_sw_state[NUMBER_OF_LEVER_SW] = {0};
/*
  0: not slided and pushed
  1: left level 1
  2: left level 2
  3: right level 2
  4: right level 1
  5: pushed
 */

//uint8_t lever_sw_value[NUMBER_OF_LEVER_SW] = {0};

__attribute__ ((weak))
void lever_sw_update_user(int8_t index,int8_t lever_sw_state){ }

__attribute__ ((weak))
void lever_sw_update_kb(int8_t index,int8_t lever_sw_state){
  lever_sw_update_user(index, lever_sw_state);
}

void lever_sw_init(void){
  for (int i = 0 ; i < NUMBER_OF_LEVER_SW; i++) {
    setPinInputHigh(lever_sw_pad_1[i]);
    setPinInputHigh(lever_sw_pad_2[i]);
    setPinInputHigh(lever_sw_pad_3[i]);
    setPinInputHigh(lever_sw_pad_4[i]);
    setPinInputHigh(lever_sw_pad_T[i]);
  }
}

void lever_sw_read(void){
  for (int i = 0 ;i < NUMBER_OF_LEVER_SW ;i++) {
    int lever_sw_state = 0;
    if(readPin(lever_sw_pad_2[i]) == 0) lever_sw_state=2;
    if(readPin(lever_sw_pad_3[i]) == 0) lever_sw_state=3;
    if(lever_sw_state != 2 && readPin(lever_sw_pad_1[i])==0) lever_sw_state=1;
    if(lever_sw_state != 3 && readPin(lever_sw_pad_4[i])==0) lever_sw_state=4;
    if(readPin(lever_sw_pad_T[i]) == 0) lever_sw_state=5;
    lever_sw_update_kb(i, lever_sw_state);
  }
}
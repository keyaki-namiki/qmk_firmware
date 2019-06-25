#pragma once

#include "quantum.h"

void lever_sw_init(void);
void lever_sw_read(void);

void lever_sw_update_kb(int8_t index,int8_t lever_sw_state);
void lever_sw_update_user(int8_t index,int8_t lever_sw_state);

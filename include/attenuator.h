#pragma once

#include <stdint.h>


#define ATT_CH1 0x00    
#define ATT_CH2 0x01    
#define ATT_CH3 0x02  


void att_tx(uint16_t data);
void init_attenuator();
void att_mute();
void att_set_volume(uint8_t channel, uint8_t attenuate_value);
void att_pulse_clock();


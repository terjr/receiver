#pragma once

#include <stdint.h>

#define ATT_CH1 0x00
#define ATT_CH2 0x01
// TODO: Figure out what channel 3 is used to
#define ATT_CH3 0x02

#define ATT_LEFT ATT_CH1
#define ATT_RIGHT ATT_CH2


void init_attenuator();
void att_set_value(const uint8_t channel, const uint8_t attenuate_value);
void att_set_volume(uint8_t volume);
void att_mute();
void att_tx(uint16_t data);
void att_pulse_clock();


#include "attenuator.h"

#include <avr/io.h>
#include <util/delay.h>

#define CLOCK PA1
#define LOAD_SHIFT PA2
#define DATA_IN PA3

#define ATT_CH1 0x00
#define ATT_CH2 0x01
#define ATT_CH3 0x02


void init_attenuator() {
    DDRA  |= (1 << PA1) | (1 << PA2) | (1 << PA3);
    PORTA |= (1 << LOAD_SHIFT);
    PORTA &= ~(1 << CLOCK);
}

// Mute channel 1 and 2
void att_mute() {
    uint16_t att_data;

    att_data = (ATT_CH1 << 8) | 0xff;
    att_tx(att_data);

    att_data = (ATT_CH2 << 8) | 0xff;
    att_tx(att_data);
}

void att_set_volume(uint8_t channel, uint8_t attenuate_value)
{
    att_tx( (channel << 8) | attenuate_value);
}


void att_tx(uint16_t data) {
    // Set Load/Shift low to start data transfer
    PORTA &= ~(1 << LOAD_SHIFT);

    for (int i = 0; i < 16; ++i) {
        if (data & 0x8000) {
            PORTA |= (1 << DATA_IN);
        } else {
            PORTA &= ~(1 << DATA_IN);
        }

        att_pulse_clock();

        data <<= 1;
    }
    PORTA |= (1 << LOAD_SHIFT);
}

void att_pulse_clock() {
    PORTA |= (1 << CLOCK);
    // TODO: Delay here?
    _delay_ms(1);
    PORTA &= ~(1 << CLOCK);
}


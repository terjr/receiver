#include "attenuator.h"

#include <avr/io.h>
#include <util/delay.h>

#define CLOCK PA1
#define LOAD_SHIFT PA2
#define DATA_IN PA3

void init_attenuator() {
    DDRA  |= (1 << DDA1) | (1 << DDA2) | (1 << DDA3);
    PORTA |= (1 << LOAD_SHIFT);
    PORTA &= ~(1 << CLOCK);

    // TODO: For now, start unmuted
    att_set_mute(ATT_LEFT, 0);
    att_set_mute(ATT_RIGHT, 0);
}

void att_mute() {
    uint16_t att_data;

    att_data = (ATT_LEFT << 8) | 0xff;
    att_tx(att_data);

    att_data = (ATT_RIGHT << 8) | 0xff;
    att_tx(att_data);
}

void att_set_mute(uint8_t channel, uint8_t attenuate_value) {
    att_tx((channel << 8) | attenuate_value);
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
    _delay_ms(1);
    PORTA &= ~(1 << CLOCK);
}


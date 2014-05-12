#include "attenuator.h"

#include <avr/io.h>

#define CLOCK PA1
#define LOAD_SHIFT PA2
#define DATA_IN PA3


void init_attenuator() {
    PORTA |= (1 << PA1) | (1 << PA2) | (1 << PA3);
    PORTA |= (1 << LOAD_SHIFT);
    PORTA &= ~(1 << CLOCK);
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

        pulse_clock();

        data <<= 1;
    }
    PORTA |= (1 << LOAD_SHIFT);
}

void pulse_clock() {
    PORTA |= (1 << CLOCK);
    // TODO: Delay here?
    PORTA &= ~(1 << CLOCK);
}


#include "attenuator.h"

#include <avr/io.h>
#include <util/delay.h>

#define CLOCK PA1
#define LOAD_SHIFT PA2
#define DATA_IN PA3

#define MAX_VOLUME 79
#define LM1972_STEP_CHANGE 48

void init_attenuator() {
    DDRA  |= (1 << DDA1) | (1 << DDA2) | (1 << DDA3);
    PORTA |= (1 << LOAD_SHIFT);
    PORTA &= ~(1 << CLOCK);

    att_set_volume(MAX_VOLUME);
}

void att_set_value(const uint8_t channel, const uint8_t attenuate_value) {
    att_tx((channel << 8) | attenuate_value);
}

// 0 = mute, 79 = full volume
void att_set_volume(uint8_t volume) {
    if (volume > MAX_VOLUME) volume = MAX_VOLUME;
    uint8_t db = MAX_VOLUME - (0x7f & volume);
    uint8_t output_volume = (db <= LM1972_STEP_CHANGE) ? 2 * db : LM1972_STEP_CHANGE + db;

    att_set_value(ATT_LEFT, output_volume);
    att_set_value(ATT_RIGHT, output_volume);
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


#include "muxctrl.h"

#include <avr/io.h>

#define MUX_A0 _BV(PB2)
#define MUX_A1 _BV(PB1)
#define ANALOG_EN _BV(PB0)


void init_muxes() {
    // ADG1/ADG2 address pins
    DDRB |= (1 << DDB2);
    DDRB |= (1 << DDB1);
    // ADG2 enable pin AND ADG3 control pin
    DDRB |= (1 << DDB0);
}

void mux_set_channel(const uint8_t mode, const uint8_t channel) {
    // Enable ADG2 (this in turn configures ADG3 correctly, see schematics)
    if (ANALOG == mode) {
        PORTB |= ANALOG_EN;
    } else if (DIGITAL == mode) {
        PORTB &= ~ANALOG_EN;
    } else {
        return;
    }

    // Set appropriate address pins on ADG1/ADG2
    switch (channel) {
        case CH_1:
            PORTB &= ~(MUX_A0);
            PORTB &= ~(MUX_A1);
            break;
        case CH_2:
            PORTB |= MUX_A0;
            PORTB &= ~(MUX_A1);
            break;
        case CH_3:
            PORTB &= ~(MUX_A0);
            PORTB |= MUX_A1;
            break;
        case CH_4:
            PORTB |= MUX_A0;
            PORTB |= MUX_A1;
            break;
    }
}

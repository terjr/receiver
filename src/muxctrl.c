#include "muxctrl.h"

#include <avr/io.h>

#define ADG2_A0 _BV(PB2)
#define ADG2_A1 _BV(PB1)


void init_muxes() {
    // ADG2 address pins
    DDRB |= (1 << DDB2);
    DDRB |= (1 << DDB1);
    // ADG3 control pin
    DDRB |= (1 << DDB0);
}

void mux_set_analog_channel(const uint8_t channel) {
    switch (channel) {
        case A_CH_1:
            PORTB &= ~(ADG2_A0);
            PORTB &= ~(ADG2_A1);
            break;
        case A_CH_2:
            PORTB |= ADG2_A0;
            PORTB &= ~(ADG2_A1);
            break;
        case A_CH_3:
            PORTB &= ~(ADG2_A0);
            PORTB |= ADG2_A1;
            break;
        case A_CH_4:
            PORTB |= ADG2_A0;
            PORTB |= ADG2_A1;
            break;
    }
}

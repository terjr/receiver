#include "led.h"

#include <avr/io.h>

void init_leds() {
    // Set as outputs.
    DDRD |= (1 << DDD3) | (1 << DDD4) | (1 << DDD5);
}

void led_toggle(const uint8_t n) {
    switch (n) {
        case LED1:
            PORTD ^= _BV(PD3);
            break;
        case LED2:
            PORTD ^= _BV(PD4);
            break;
        case LED3:
            PORTD ^= _BV(PD5);
            break;
    }
}


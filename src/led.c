#include "led.h"

#include <avr/io.h>

void init_leds() {
    // Set as outputs.
    DDRD |= (1 << DDD3) | (1 << DDD4) | (1 << DDD5);
}

void led_toggle(const uint8_t n) {
    switch (n) {
        case LED1:
            PORTD ^= _BV(DDD3);
            break;
        case LED2:
            PORTD ^= _BV(DDD4);
            break;
        case LED3:
            PORTD ^= _BV(DDD5);
            break;
    }
}


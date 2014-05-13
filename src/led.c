#include "led.h"

#include <avr/io.h>

void init_leds() {
    // Set as outputs.
    DDRD |= (1 << DDD3) | (1 << DDD4) | (1 << DDD5) | (1 << DDD6);
}

void led_set(const uint8_t n, const uint8_t value) {
    if (value) {
        PORTD |= (1 << n);
    } else {
        PORTD &= ~(1 << n);
    }
}

void led_set_number(const uint8_t value) {
    led_set(LED1, value & 1);
    led_set(LED2, value & 2);
    led_set(LED3, value & 4);
}

void led_toggle(const uint8_t n) {
    PORTD ^= _BV(n);
}


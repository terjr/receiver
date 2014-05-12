#include "led.h"

#include <avr/io.h>

void init_leds() {
    // Set as outputs.
    DDRD |= (1 << DDD3) | (1 << DDD4) | (1 << DDD5);
}

void set_value(const uint8_t pin, const uint8_t value) {
    if (value) {
        PORTD |= (1 << pin);
    } else {
        PORTD &= ~(1 << pin);
   }
}

void set_led(const uint8_t n, const uint8_t value) {
     switch (n) {
        case LED1:
            set_value(DDD3, value);
            break;
        case LED2:
            set_value(DDD4, value);
            break;
        case LED3:
            set_value(DDD5, value);
            break;
    }
}

void set_leds_bin(const uint8_t value) {
    set_led(LED1, value & 1);
    set_led(LED2, value & 2);
    set_led(LED3, value & 4);
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


#pragma once

#define LED1 DDD3
#define LED2 DDD4
#define LED3 DDD5
#define LED4 DDD6

#include <stdint.h>


void init_leds();
void set_led(const uint8_t n, const uint8_t value);
void set_leds_bin(const uint8_t value);
void led_toggle(const uint8_t n);

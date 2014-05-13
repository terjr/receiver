#pragma once

#define LED1 PD3
#define LED2 PD4
#define LED3 PD5

#include <stdint.h>


void init_leds();
void led_set(const uint8_t n, const uint8_t value);
void led_set_number(const uint8_t value);
void led_toggle(const uint8_t n);

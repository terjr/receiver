#pragma once

#define LED1 DDD3
#define LED2 DDD4
#define LED3 DDD5

#include <stdint.h>


void init_leds();
void led_toggle(const uint8_t n);

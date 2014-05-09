#include "receiver.h"

#include <avr/io.h>
#include <util/delay.h>
#include "led.h"

int main() {

    init_leds();

    led_toggle(LED1);
    _delay_ms(500);
    led_toggle(LED1);
    _delay_ms(500);
    led_toggle(LED2);
    _delay_ms(500);
    led_toggle(LED2);
    _delay_ms(500);
    led_toggle(LED3);
    _delay_ms(500);
    led_toggle(LED3);
    _delay_ms(500);
    while (1);
    return 0;
}

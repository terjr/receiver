#include "receiver.h"

#include <avr/io.h>
#include <util/delay.h>
#include "muxctrl.h"
#include "led.h"
#include "attenuator.h"

int main() {

    init_leds();
    init_muxes();
    init_attenuator();

    mux_set_analog_channel(A_CH_1);
/*
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
    */
    while (1) {
        led_set_number(0);
        for (uint8_t value = 0; value < 127; ++value) {
            att_set_volume(ATT_CH1, value);
            _delay_ms(10);
        }
        led_set_number(1);
        for (uint8_t value = 127; value > 0; --value) {
            att_set_volume(ATT_CH1, value);
            _delay_ms(10);
        }
        led_set_number(2);
        for (uint8_t value = 0; value < 127; ++value) {
            att_set_volume(ATT_CH2, value);
            _delay_ms(10);
        }
        led_set_number(3);
        for (uint8_t value = 127; value > 0; --value) {
            att_set_volume(ATT_CH2, value);
            _delay_ms(10);
        }
        led_set_number(4);
        for (uint8_t value = 0; value < 127; ++value) {
            att_set_volume(ATT_CH3, value);
            _delay_ms(10);
        }
        led_set_number(5);
        for (uint8_t value = 127; value > 0; --value) {
            att_set_volume(ATT_CH3, value);
            _delay_ms(10);
        }
    }
    return 0;
}

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

    while (1);
    return 0;
}

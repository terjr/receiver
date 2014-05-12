#include <stdint.h>

#define A_CH_1 1
#define A_CH_2 2
#define A_CH_3 3
#define A_CH_4 4

void init_muxes();

void mux_set_analog_channel(const uint8_t channel);

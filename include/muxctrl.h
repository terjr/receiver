#include <stdint.h>

#define ANALOG 0
#define DIGITAL 1

#define CH_1 0
#define CH_2 1
#define CH_3 2
#define CH_4 3


void init_muxes();

void mux_set_channel(const uint8_t mode, const uint8_t channel);

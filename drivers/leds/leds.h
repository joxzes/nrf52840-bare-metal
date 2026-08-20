#ifndef LEDS_H
#define LEDS_H

#include "nrf52840.h"

void leds_init(void);
void leds_on(enum leds led);
void leds_off(enum leds led);
void leds_process(void);

#endif
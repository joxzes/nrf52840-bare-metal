#ifndef LEDS_H
#define LEDS_H

#include "nrf52840.h"

void LEDS_init(void);
void LEDS_on(led_t led);
void LEDS_off(led_t led);

#endif
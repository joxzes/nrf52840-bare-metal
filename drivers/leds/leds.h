#ifndef LEDS_H
#define LEDS_H

#include "nrf52840.h"

enum leds {
	LED1,
	LED2,
	LED3,
	LED4,
	LED_COUNT,
};

void leds_init(void);
void leds_on(enum leds led);
void leds_off(enum leds led);
void leds_process(void);

#endif
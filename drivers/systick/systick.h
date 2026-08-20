#ifndef SYSTICK_H
#define SYSTICK_H

#include "nrf52840.h"

void systick_init(void);
uint32_t millis(void);
void delay(uint32_t ms);

#endif
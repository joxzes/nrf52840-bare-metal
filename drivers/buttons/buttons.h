#ifndef BUTTON_H
#define BUTTON_H

#include "nrf52840.h"

void BTNS_init(void);
uint8_t BTNS_read(button_t btn);

#endif
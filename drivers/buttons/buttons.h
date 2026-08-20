#ifndef BUTTON_H
#define BUTTON_H

#include "nrf52840.h"

enum buttons {
	BTN1,
	BTN2,
	BTN3,
	BTN4,
	BTN_COUNT,
};

void btns_init(void);
uint8_t btns_read(enum buttons btn);
void btns_process(void);

#endif
#ifndef APP_H
#define APP_H

#include "leds.h"
#include "buttons.h"
#include "systick.h"

void button_led_control(void);
void blink(void);
void state_machine(void);
void blink_speed_control(void);
void check_password(void);


#endif
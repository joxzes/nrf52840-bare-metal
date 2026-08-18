#include "leds.h"

void LEDS_init(void) {
    P0->PIN_CNF[LED1] = 0x3u;
    P0->PIN_CNF[LED2] = 0x3u;
    P0->PIN_CNF[LED3] = 0x3u;
    P0->PIN_CNF[LED4] = 0x3u;

    P0->OUTSET = (1 << LED1) | (1 << LED2) | (1 << LED3) | (1 << LED4);
}

void LEDS_on(led_t led) {
    if (led < LED1 || led > LED4)
        return;

    P0->OUTCLR = (1 << led);
}

void LEDS_off(led_t led) {
    if (led < LED1 || led > LED4)
        return;

    P0->OUTSET = (1 << led);
}
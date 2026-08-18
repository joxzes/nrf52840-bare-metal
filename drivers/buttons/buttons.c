#include "buttons.h"

void BTNS_init(void) {
    P0->PIN_CNF[BTN1] = GPIO_PIN_CNF_DIR_Input | GPIO_PIN_CNF_INPUT_Connect | GPIO_PIN_CNF_PULL_Pullup;
    P0->PIN_CNF[BTN2] = GPIO_PIN_CNF_DIR_Input | GPIO_PIN_CNF_INPUT_Connect | GPIO_PIN_CNF_PULL_Pullup;
    P0->PIN_CNF[BTN3] = GPIO_PIN_CNF_DIR_Input | GPIO_PIN_CNF_INPUT_Connect | GPIO_PIN_CNF_PULL_Pullup;
    P0->PIN_CNF[BTN4] = GPIO_PIN_CNF_DIR_Input | GPIO_PIN_CNF_INPUT_Connect | GPIO_PIN_CNF_PULL_Pullup;
}

uint8_t BTNS_read(button_t btn) {
    if (btn != BTN1 && btn != BTN2 && btn != BTN3 && btn != BTN4)
        return 0u;

    return ((P0->IN >> btn) & 1u);
}

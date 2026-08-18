#include "systick.h"

static volatile uint32_t ticks = 0u;

void SYST_init(void) {
    SYST->SYST_CSR &= ~1u;

    SYST->SYST_RVR = 63999u;
    SYST->SYST_CVR = 0u;

    SYST->SYST_CSR = (1u << 2) | (1u << 1) | 1u;
    
}

void SysTick_Handler(void) {
    ticks++;
}

uint32_t millis(void) {
    return ticks;
}

void delay(uint32_t ms) {
    uint32_t start = ticks;

    while ((ticks - start) < ms) {
        
    }
}
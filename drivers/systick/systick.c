#include "systick.h"

static volatile uint32_t ticks;

void systick_init(void)
{
	SYSTICK->syst_csr &= ~1U;

	SYSTICK->syst_rvr = 63999U;
	SYSTICK->syst_cvr = 0U;

	SYSTICK->syst_csr = (1U << 2) | (1U << 1) | 1U;
}

void SysTick_Handler(void)
{
	ticks++;
}

uint32_t millis(void)
{
	return ticks;
}

void delay(uint32_t ms)
{
	uint32_t start = ticks;

	while (ticks - start < ms)
		;
}
#include <stdint.h>

extern uint32_t _estack;
extern uint32_t _sidata;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

int main(void);
void Default_Handler(void);

void Reset_Handler(void);
void NMI_Handler(void)	__attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void)	__attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void)	__attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void)	__attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void)	__attribute__((weak, alias("Default_Handler")));
void SVC_Handler(void)	__attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler(void)	__attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void)	__attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void)	__attribute__((weak, alias("Default_Handler")));

void CLOCK_POWER_IRQHandler(void)
	__attribute__((weak, alias("Default_Handler")));
void RADIO_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void UART0_UARTE0_IRQHandler(void)
	__attribute__((weak, alias("Default_Handler")));

void SPI0_SPIM0_SPIS0_TWI0_TWIM0_TWIS0_IRQHandler(void)
	__attribute__((weak, alias("Default_Handler")));
void SPI1_SPIM1_SPIS1_TWI1_TWIM1_TWIS1_IRQHandler(void)
	__attribute__((weak, alias("Default_Handler")));

void NFCT_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void GPIOTE_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void SAADC_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));

void TIMER0_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void TIMER1_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void TIMER2_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));

void RTC0_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void TEMP_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void RNG_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void ECB_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void AAR_CCM_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));

void WDT_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void RTC1_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void QDEC_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void COMP_LPCOMP_IRQHandler(void)
	__attribute__((weak, alias("Default_Handler")));

void EGU0_SWI0_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void EGU1_SWI1_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void EGU2_SWI2_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void EGU3_SWI3_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void EGU4_SWI4_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void EGU5_SWI5_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));

void TIMER3_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void TIMER4_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));

void PWM0_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void PDM_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));

void MWU_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void PWM1_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void PWM2_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));

void SPI2_SPIM2_SPIS2_IRQHandler(void)
	__attribute__((weak, alias("Default_Handler")));
void RTC2_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void I2S_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void FPU_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void USBD_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void UARTE1_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void QSPI_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void CRYPTOCELL_IRQHandler(void)
	__attribute__((weak, alias("Default_Handler")));

void PWM3_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));
void SPIM3_IRQHandler(void)	__attribute__((weak, alias("Default_Handler")));

__attribute__((section(".isr_vector"), used))
const uintptr_t vector_table[] = {
	(uintptr_t)&_estack,
	(uintptr_t)Reset_Handler,

	(uintptr_t)NMI_Handler,
	(uintptr_t)HardFault_Handler,
	(uintptr_t)MemManage_Handler,
	(uintptr_t)BusFault_Handler,
	(uintptr_t)UsageFault_Handler,

	(uintptr_t)0,
	(uintptr_t)0,
	(uintptr_t)0,
	(uintptr_t)0,

	(uintptr_t)SVC_Handler,
	(uintptr_t)DebugMon_Handler,

	(uintptr_t)0,

	(uintptr_t)PendSV_Handler,
	(uintptr_t)SysTick_Handler,

	(uintptr_t)CLOCK_POWER_IRQHandler,	/* IRQ0: CLOCK / POWER */
	(uintptr_t)RADIO_IRQHandler,		/* IRQ1: RADIO */
	(uintptr_t)UART0_UARTE0_IRQHandler,	/* IRQ2: UART0 / UARTE0 */

	(uintptr_t)SPI0_SPIM0_SPIS0_TWI0_TWIM0_TWIS0_IRQHandler,
	/* IRQ3: SPI0 / SPIM0 / SPIS0 / TWI0 / TWIM0 / TWIS0 */

	(uintptr_t)SPI1_SPIM1_SPIS1_TWI1_TWIM1_TWIS1_IRQHandler,
	/* IRQ4: SPI1 / SPIM1 / SPIS1 / TWI1 / TWIM1 / TWIS1 */

	(uintptr_t)NFCT_IRQHandler,		/* IRQ5: NFCT */
	(uintptr_t)GPIOTE_IRQHandler,		/* IRQ6: GPIOTE */
	(uintptr_t)SAADC_IRQHandler,		/* IRQ7: SAADC */

	(uintptr_t)TIMER0_IRQHandler,		/* IRQ8: TIMER0 */
	(uintptr_t)TIMER1_IRQHandler,		/* IRQ9: TIMER1 */
	(uintptr_t)TIMER2_IRQHandler,		/* IRQ10: TIMER2 */

	(uintptr_t)RTC0_IRQHandler,		/* IRQ11: RTC0 */
	(uintptr_t)TEMP_IRQHandler,		/* IRQ12: TEMP */
	(uintptr_t)RNG_IRQHandler,		/* IRQ13: RNG */
	(uintptr_t)ECB_IRQHandler,		/* IRQ14: ECB */
	(uintptr_t)AAR_CCM_IRQHandler,		/* IRQ15: AAR / CCM */

	(uintptr_t)WDT_IRQHandler,		/* IRQ16: WDT */
	(uintptr_t)RTC1_IRQHandler,		/* IRQ17: RTC1 */
	(uintptr_t)QDEC_IRQHandler,		/* IRQ18: QDEC */
	(uintptr_t)COMP_LPCOMP_IRQHandler,	/* IRQ19: COMP / LPCOMP */

	(uintptr_t)EGU0_SWI0_IRQHandler,	/* IRQ20: EGU0 / SWI0 */
	(uintptr_t)EGU1_SWI1_IRQHandler,	/* IRQ21: EGU1 / SWI1 */
	(uintptr_t)EGU2_SWI2_IRQHandler,	/* IRQ22: EGU2 / SWI2 */
	(uintptr_t)EGU3_SWI3_IRQHandler,	/* IRQ23: EGU3 / SWI3 */
	(uintptr_t)EGU4_SWI4_IRQHandler,	/* IRQ24: EGU4 / SWI4 */
	(uintptr_t)EGU5_SWI5_IRQHandler,	/* IRQ25: EGU5 / SWI5 */

	(uintptr_t)TIMER3_IRQHandler,		/* IRQ26: TIMER3 */
	(uintptr_t)TIMER4_IRQHandler,		/* IRQ27: TIMER4 */

	(uintptr_t)PWM0_IRQHandler,		/* IRQ28: PWM0 */
	(uintptr_t)PDM_IRQHandler,		/* IRQ29: PDM */

	(uintptr_t)0,				/* IRQ30: Reserved */
	(uintptr_t)0,				/* IRQ31: Reserved */

	(uintptr_t)MWU_IRQHandler,		/* IRQ32: MWU */
	(uintptr_t)PWM1_IRQHandler,		/* IRQ33: PWM1 */
	(uintptr_t)PWM2_IRQHandler,		/* IRQ34: PWM2 */

	(uintptr_t)SPI2_SPIM2_SPIS2_IRQHandler,	/* IRQ35: SPI2 / SPIM2 / SPIS2 */
	(uintptr_t)RTC2_IRQHandler,		/* IRQ36: RTC2 */
	(uintptr_t)I2S_IRQHandler,		/* IRQ37: I2S */
	(uintptr_t)FPU_IRQHandler,		/* IRQ38: FPU */
	(uintptr_t)USBD_IRQHandler,		/* IRQ39: USB device */
	(uintptr_t)UARTE1_IRQHandler,		/* IRQ40: UARTE1 */
	(uintptr_t)QSPI_IRQHandler,		/* IRQ41: QSPI */
	(uintptr_t)CRYPTOCELL_IRQHandler,	/* IRQ42: CryptoCell */

	(uintptr_t)0,				/* IRQ43: Reserved */
	(uintptr_t)0,				/* IRQ44: Reserved */

	(uintptr_t)PWM3_IRQHandler,		/* IRQ45: PWM3 */

	(uintptr_t)0,				/* IRQ46: Reserved */

	(uintptr_t)SPIM3_IRQHandler,		/* IRQ47: SPIM3 */
};

void Reset_Handler(void)
{
	uint32_t *source = &_sidata;
	uint32_t *destination = &_sdata;

	while (destination < &_edata) {
		*destination = *source;
		destination++;
		source++;
	}

	destination = &_sbss;

	while (destination < &_ebss) {
		*destination = 0;
		destination++;
	}

	main();

	for (;;)
		;
}

void Default_Handler(void)
{
	for (;;)
		;
}
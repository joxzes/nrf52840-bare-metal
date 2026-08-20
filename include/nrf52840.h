#ifndef NRF52840_H
#define NRF52840_H

#include <stdint.h>

struct systick {
	volatile uint32_t syst_csr;
	volatile uint32_t syst_rvr;
	volatile uint32_t syst_cvr;
	volatile uint32_t syst_calib;
};

struct clock {
	volatile uint32_t tasks_hfclkstart;	/* 0x000 */
	volatile uint32_t tasks_hfclkstop;	/* 0x004 */
	volatile uint32_t tasks_lfclkstart;	/* 0x008 */
	volatile uint32_t tasks_lfclkstop;	/* 0x00c */
	volatile uint32_t tasks_cal;		/* 0x010 */
	volatile uint32_t tasks_ctstart;		/* 0x014 */
	volatile uint32_t tasks_ctstop;		/* 0x018 */

	uint32_t reserved0[57];			/* 0x01c - 0x0fc */

	volatile uint32_t events_hfclkstarted;	/* 0x100 */
	volatile uint32_t events_lfclkstarted;	/* 0x104 */

	uint32_t reserved1[1];			/* 0x108 */

	volatile uint32_t events_done;		/* 0x10c */
	volatile uint32_t events_ctto;		/* 0x110 */

	uint32_t reserved2[5];			/* 0x114 - 0x124 */

	volatile uint32_t events_ctstarted;	/* 0x128 */
	volatile uint32_t events_ctstopped;	/* 0x12c */

	uint32_t reserved3[117];			/* 0x130 - 0x300 */

	volatile uint32_t intenset;		/* 0x304 */
	volatile uint32_t intenclr;		/* 0x308 */

	uint32_t reserved4[63];			/* 0x30c - 0x404 */

	volatile uint32_t hfclkrun;		/* 0x408 */
	volatile uint32_t hfclkstat;		/* 0x40c */

	uint32_t reserved5[1];			/* 0x410 */

	volatile uint32_t lfclkrun;		/* 0x414 */
	volatile uint32_t lfclkstat;		/* 0x418 */
	volatile uint32_t lfclksrccopy;		/* 0x41c */

	uint32_t reserved6[62];			/* 0x420 - 0x514 */

	volatile uint32_t lfclksrc;		/* 0x518 */

	uint32_t reserved7[3];			/* 0x51c - 0x524 */

	volatile uint32_t hfxodebounce;		/* 0x528 */

	uint32_t reserved8[3];			/* 0x52c - 0x534 */

	volatile uint32_t ctiv;			/* 0x538 */

	uint32_t reserved9[8];			/* 0x53c - 0x558 */

	volatile uint32_t traceconfig;		/* 0x55c */

	uint32_t reserved10[21];			/* 0x560 - 0x5b0 */

	volatile uint32_t lfrcmode;		/* 0x5b4 */
};

struct gpio {
	uint32_t reserved0[321];		/* 0x000 - 0x500 */

	volatile uint32_t out;		/* 0x504 */
	volatile uint32_t outset;	/* 0x508 */
	volatile uint32_t outclr;	/* 0x50c */
	volatile uint32_t in;		/* 0x510 */
	volatile uint32_t dir;		/* 0x514 */
	volatile uint32_t dirset;	/* 0x518 */
	volatile uint32_t dirclr;	/* 0x51c */
	volatile uint32_t latch;		/* 0x520 */
	volatile uint32_t detectmode;	/* 0x524 */

	uint32_t reserved1[118];		/* 0x528 - 0x6fc */

	volatile uint32_t pin_cnf[32];	/* 0x700 - 0x77c */
};

#define SYSTICK	((struct systick *)0xE000E010U)
#define CLOCK	((struct clock *)0x40000000U)

#define P0	((struct gpio *)0x50000000U)
#define P1	((struct gpio *)0x50000300U)

#define CLEAR(x, y)	((x) &= ~(1U << (y)))

#define GPIO_PIN_CNF_DIR_OUTPUT	1U
#define GPIO_PIN_CNF_DIR_INPUT	0U

#define GPIO_PIN_CNF_INPUT_CONNECT	0U
#define GPIO_PIN_CNF_INPUT_DISCONNECT	(1U << 1)

#define GPIO_PIN_CNF_PULL_DISABLE	0U
#define GPIO_PIN_CNF_PULL_PULLDOWN	(1U << 2)
#define GPIO_PIN_CNF_PULL_PULLUP	(3U << 2)

#endif
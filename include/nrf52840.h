#ifndef NRF52840_H
#define NRF52840_H

#include <stdint.h>

typedef struct {
    volatile uint32_t SYST_CSR;
    volatile uint32_t SYST_RVR;
    volatile uint32_t SYST_CVR;
    volatile uint32_t SYST_CALIB;
} SYST_TypeDef;

typedef struct
{
    volatile uint32_t TASKS_HFCLKSTART;      // 0x000
    volatile uint32_t TASKS_HFCLKSTOP;       // 0x004
    volatile uint32_t TASKS_LFCLKSTART;      // 0x008
    volatile uint32_t TASKS_LFCLKSTOP;       // 0x00C
    volatile uint32_t TASKS_CAL;             // 0x010
    volatile uint32_t TASKS_CTSTART;         // 0x014
    volatile uint32_t TASKS_CTSTOP;          // 0x018

    uint32_t RESERVED0[57];                  // 0x01C - 0x0FC

    volatile uint32_t EVENTS_HFCLKSTARTED;   // 0x100
    volatile uint32_t EVENTS_LFCLKSTARTED;   // 0x104

    uint32_t RESERVED1[1];                   // 0x108

    volatile uint32_t EVENTS_DONE;           // 0x10C
    volatile uint32_t EVENTS_CTTO;           // 0x110

    uint32_t RESERVED2[5];                   // 0x114 - 0x124

    volatile uint32_t EVENTS_CTSTARTED;      // 0x128
    volatile uint32_t EVENTS_CTSTOPPED;      // 0x12C

    uint32_t RESERVED3[117];                 // 0x130 - 0x300

    volatile uint32_t INTENSET;              // 0x304
    volatile uint32_t INTENCLR;              // 0x308

    uint32_t RESERVED4[63];                  // 0x30C - 0x404

    volatile uint32_t HFCLKRUN;               // 0x408
    volatile uint32_t HFCLKSTAT;              // 0x40C

    uint32_t RESERVED5[1];                   // 0x410

    volatile uint32_t LFCLKRUN;               // 0x414
    volatile uint32_t LFCLKSTAT;              // 0x418
    volatile uint32_t LFCLKSRCCOPY;           // 0x41C

    uint32_t RESERVED6[62];                  // 0x420 - 0x514

    volatile uint32_t LFCLKSRC;               // 0x518

    uint32_t RESERVED7[3];                   // 0x51C - 0x524

    volatile uint32_t HFXODEBOUNCE;           // 0x528

    uint32_t RESERVED8[3];                   // 0x52C - 0x534

    volatile uint32_t CTIV;                   // 0x538

    uint32_t RESERVED9[8];                   // 0x53C - 0x558

    volatile uint32_t TRACECONFIG;            // 0x55C

    uint32_t RESERVED10[21];                 // 0x560 - 0x5B0

    volatile uint32_t LFRCMODE;               // 0x5B4

} CLOCK_TypeDef;

typedef struct
{
    uint32_t RESERVED0[321];          // 0x000 - 0x500

    volatile uint32_t OUT;            // 0x504
    volatile uint32_t OUTSET;         // 0x508
    volatile uint32_t OUTCLR;         // 0x50C
    volatile uint32_t IN;             // 0x510
    volatile uint32_t DIR;            // 0x514
    volatile uint32_t DIRSET;         // 0x518
    volatile uint32_t DIRCLR;         // 0x51C
    volatile uint32_t LATCH;          // 0x520
    volatile uint32_t DETECTMODE;     // 0x524

    uint32_t RESERVED1[118];          // 0x528 - 0x6FC

    volatile uint32_t PIN_CNF[32];    // 0x700 - 0x77C

} GPIO_TypeDef;

typedef enum {
    LED1 = 13,
    LED2,
    LED3,
    LED4
} led_t;

typedef enum {
    BTN1 = 11,
    BTN2,
    BTN3 = 24,
    BTN4
} button_t;

#define SYST ((SYST_TypeDef *)0xE000E010u)
#define CLOCK ((CLOCK_TypeDef *)0x40000000u)
#define P0 ((GPIO_TypeDef *)0x50000000u)
#define P1 ((GPIO_TypeDef *)0x50000300u)

#define CLEAR(X, Y) ((X) &= ~(1U << (Y)))

#define GPIO_PIN_CNF_DIR_Output 1u
#define GPIO_PIN_CNF_DIR_Input 0u
#define GPIO_PIN_CNF_INPUT_Connect 0u
#define GPIO_PIN_CNF_INPUT_Disconnect (1u << 1)
#define GPIO_PIN_CNF_PULL_Disable 0u
#define GPIO_PIN_CNF_PULL_Pulldown (1u << 2)
#define GPIO_PIN_CNF_PULL_Pullup (3u << 2)

#endif
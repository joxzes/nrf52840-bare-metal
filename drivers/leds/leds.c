#include "leds.h"
#include "queue.h"
#include "systick.h"

enum led_state {
	LED_STATE_IDLE,
	LED_STATE_ON
};

static const uint8_t led_pin[LED_COUNT] = {13, 14, 15, 16};

static enum led_state state = LED_STATE_IDLE;
static uint8_t current_led;
static uint32_t start_time;

#define LED_DELAY 2000U

void leds_init(void)
{
	P0->pin_cnf[13] = 0x3U;
	P0->pin_cnf[14] = 0x3U;
	P0->pin_cnf[15] = 0x3U;
	P0->pin_cnf[16] = 0x3U;

	P0->outset = (1U << 13) | (1U << 14) |
		     (1U << 15) | (1U << 16);
}

void leds_on(enum leds led)
{
	if (led >= LED_COUNT)
		return;

	P0->outclr = 1U << led_pin[led];
}

void leds_off(enum leds led)
{
	if (led >= LED_COUNT)
		return;

	P0->outset = 1U << led_pin[led];
}

void leds_process(void)
{
	switch (state) {
	case LED_STATE_IDLE:
		if (fifo_pop(&event_fifo, &current_led))
			break;

		leds_on(current_led);
		start_time = millis();
		state = LED_STATE_ON;
		break;

	case LED_STATE_ON:
		if (millis() - start_time >= LED_DELAY) {
			leds_off(current_led);
			state = LED_STATE_IDLE;
		}
		break;
	}
}
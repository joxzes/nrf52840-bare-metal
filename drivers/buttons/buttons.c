#include "buttons.h"
#include "queue.h"

enum button_state {
	BTN_RELEASED,
	BTN_PRESSED,
};

static const uint8_t btn_pin[BTN_COUNT] = { 11, 12, 24, 25 };
static const uint8_t led_sequence[BTN_COUNT] = { 1, 3, 0, 2 };

static enum button_state btn_state[BTN_COUNT];

void btns_init(void)
{
	P0->pin_cnf[11] = GPIO_PIN_CNF_DIR_INPUT |
					GPIO_PIN_CNF_INPUT_CONNECT |
					GPIO_PIN_CNF_PULL_PULLUP;

	P0->pin_cnf[12] = GPIO_PIN_CNF_DIR_INPUT |
					GPIO_PIN_CNF_INPUT_CONNECT |
					GPIO_PIN_CNF_PULL_PULLUP;

	P0->pin_cnf[24] = GPIO_PIN_CNF_DIR_INPUT |
					GPIO_PIN_CNF_INPUT_CONNECT |
					GPIO_PIN_CNF_PULL_PULLUP;

	P0->pin_cnf[25] = GPIO_PIN_CNF_DIR_INPUT |
					GPIO_PIN_CNF_INPUT_CONNECT |
					GPIO_PIN_CNF_PULL_PULLUP;
}

uint8_t btns_read(enum buttons btn)
{
	if (btn >= BTN_COUNT)
		return 0U;

	return (P0->in >> btn_pin[btn]) & 1U;
}

void btns_process(void)
{
	for (int i = 0; i < BTN_COUNT; i++) {
		uint8_t pressed = !btns_read(i);

		switch (btn_state[i]) {
		case BTN_RELEASED:
			if (!pressed)
				break;

			fifo_push(&event_fifo, led_sequence[i]);
			btn_state[i] = BTN_PRESSED;
			break;

		case BTN_PRESSED:
			if (!pressed)
				btn_state[i] = BTN_RELEASED;
			break;
		}
	}
}
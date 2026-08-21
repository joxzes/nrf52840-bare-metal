#include "app.h"

void button_led_control(void)
{
	if (btns_read(BTN1)) {
		leds_off(LED1);
	} else {
		leds_on(LED1);
	}

	if (btns_read(BTN2)) {
		leds_off(LED2);
	} else {
		leds_on(LED2);
	}

	if (btns_read(BTN3)) {
		leds_off(LED3);
	} else {
		leds_on(LED3);
	}

	if (btns_read(BTN4)) {
		leds_off(LED4);
	} else {
		leds_on(LED4);
	}
}

void blink(void)
{
	leds_on(LED1);
	leds_on(LED2);
	leds_on(LED3);
	leds_on(LED4);

	delay(250U);

	leds_off(LED1);
	leds_off(LED2);
	leds_off(LED3);
	leds_off(LED4);

	delay(250U);
}

void state_machine(void)
{
	btns_process();
	leds_process();
}

void blink_speed_control(void)
{
	static uint8_t btn_state[2];

	static uint8_t status;
	static uint32_t speed = 1000U;
	static uint32_t previous;
	uint32_t now = millis();

	if ((now - previous) >= speed) {
		previous = now;

		if (status) {
			leds_off(LED1);
			status = !status;
		} else {
			leds_on(LED1);
			status = !status;
		}
	}

	for (int i = 0; i < 2; i++) {
		uint8_t pressed = !btns_read(i);

		if (pressed && !btn_state[i]) {
			btn_state[i] = 1U;

			if ((i == 0 && speed > 100U) ||
    				(i == 1 && speed < 2000U))
				speed += (2U * i - 1U) * 100U;

		} else if (!pressed && btn_state[i]) {
			btn_state[i] = 0U;
		}
	}
}

void check_password(void)
{
	const uint8_t password[4] = { BTN3, BTN1, BTN4, BTN2};
	static uint8_t code[4];
	static uint8_t state[4];
	static uint8_t count;

	for (int i = 0; i < 4; i++) {
		uint8_t pressed = !btns_read(i);

		if (pressed && !state[i]) {
			state[i] = 1U;

			if (count < 4) {
				code[count] = i;
				count++;
			}

		} else if (!pressed && state[i]) {
			state[i] = 0U;
		}
	}

	if (count == 4U) {
		uint8_t equal = 1U;
		count = 0;

		for (int i = 0; i < 4; i++) {
			if (password[i] != code[i]) {
				equal = 0U;
				leds_on(LED1);
				break;
			}
		}

		if (equal) {
			for (int i = 0; i < 4; i++) {
				leds_on(i);
			}
		}

		for (int i = 0; i < 4; i++) {
			code[i] = 0U;
		}

		for (;;) {
			uint8_t pressed = !btns_read(BTN1);

			if (pressed && !state[0]) {
				state[0] = 1U;

				for (int i = 0; i < 4; i++) {
					leds_off(i);
				}

				break;
			}

			if (!pressed)
				state[0] = 0U;
		}
	}
}
#include "app.h"

int main(void)
{
	systick_init();
	leds_init();
	btns_init();

	for (;;) {
		blink_speed_control();
	}
}
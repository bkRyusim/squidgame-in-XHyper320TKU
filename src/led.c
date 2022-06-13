//-------| src/led.c |-------//
#include "led.h"

static short *led;

void init_led(short *address)
{
	led = address;
}

void led_clear()
{
	*led = (short)~0;
}

void led_all()
{
	*led = (short)~0xFF;
}

void led_print_chance(int chance)
{
	int i;
	int tmp = chance;
	short result = 0;

	for (i = 0; i < 8; i++)
	{
		if (tmp > 0)
		{
			result++;
			tmp--;
		}
		if (i != 7)
			result = result << 1;
	}
	*led = (short)~result;
}

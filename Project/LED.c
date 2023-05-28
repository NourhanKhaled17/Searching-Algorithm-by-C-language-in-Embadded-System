#include "LED.h"


void led_init(void)
{
	SET_BIT(led_ddr,led_green);
	SET_BIT(led_ddr,led_blue);
	SET_BIT(led_ddr,led_yellow);
	SET_BIT(red_ddr,led_red);
}
void clr_led(void)
{
	CLR_BIT(PORTA,4);
	CLR_BIT(PORTA,5);
	CLR_BIT(PORTA,6);
	CLR_BIT(PORTB,7);
	
}

void led_on(unsigned char led)
{
	if (led==led_red)
	{
			SET_BIT(PORTB,led);
	}
	else
	SET_BIT(PORTA,led);
	
}

void led_off(unsigned char led)
{
	CLR_BIT(DDRA,led);
	
}
void led_toggle(unsigned char led)
{
	if (led==led_red)
	{
		TOGGLE_BIT(PORTB,led);
	}
	else
	TOGGLE_BIT(PORTA,led);
}
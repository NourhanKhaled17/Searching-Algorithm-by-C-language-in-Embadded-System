
#ifndef LED_H_
#define LED_H_
#include "ATmega32_Rrgiosters.h"
#include "BIT_MATH.h"
#include "std_types.h"

#define led_ddr DDRA
#define red_ddr  DDRB
#define led_green  4
#define led_blue  5
#define led_yellow 6
#define led_red   7  
void led_init(void);
void led_on(unsigned char led);
void led_off(unsigned char led);
void led_toggle(unsigned char led);
#endif /* LED_H_ */
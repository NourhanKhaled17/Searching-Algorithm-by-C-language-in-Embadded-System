#ifndef LCD_H_
#define LCD_H_

#define F_CPU 16000000UL

#include "BIT_MATH.h"
#include "ATmega32_Rrgiosters.h"
#include <util/delay.h>

#define LCD_data_DDR DDRB
#define LCD_command_DDR DDRA

#define LCD_data_PORT PORTB
#define LCD_command_PORT PORTA

#define RS 3
#define E 2

void LCD_init(void);
void LCD_command(unsigned char cmd);
void LCD_write_char(unsigned char chr);
void LCD_write_string(unsigned char* str);
void LCD_clear(void);
void clr_led(void);


#endif /* LCD_H_ */
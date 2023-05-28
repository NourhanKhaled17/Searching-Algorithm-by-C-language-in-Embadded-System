
#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "BIT_MATH.h"
#include "ATmega32_Rrgiosters.h"
#include "LCD.h"
#define F_CPU 16000000UL

#include <util/delay.h>

#define INVALID_KEYPAD_PRESS (0xff)

void keypad_init();
unsigned char keypad_get_value(void);
int keypad_write();
#endif /* KEYPAD_H_ */


#ifndef EXTERNALINT_H_
#define EXTERNALINT_H_

#include "BIT_MATH.h"
#include "ATmega32_Rrgiosters.h"
#include "std_types.h"
#include <avr/interrupt.h>
#define  I_BIT (7)
#define F_CPU (16000000UL)
#include <util/delay.h>


void init_int(void);
void INT1_SetCallBack(void(*a_Ptr)(void));


#endif /* EXTERNALINT_H_ */
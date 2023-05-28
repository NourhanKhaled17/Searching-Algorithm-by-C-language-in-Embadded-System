#include "Timer.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include "BIT_MATH.h"
#include "ATmega32_Rrgiosters.h"
#define F_CPU 16000000UL
#define I_BIT 7
void(*g_callback_ptr)(void)=NULL_PTR;

ISR(TIMER0_OVF_vect)
{
	if(g_callback_ptr != NULL_PTR)
	{
		(*g_callback_ptr)();
	}
	
}

void timer0_init(void)
{
	TCNT0=0;
	SET_BIT(TIMSK,TOIE0);//ENABLE TIMER OVERFLOE FLAG
	TCCR0=(1<<FOC0)|(1<<CS02)|(1<<CS00);//chose timer0 normall mode
	SET_BIT(SREG,I_BIT);//ENABLE GLOBAL INT
}
void timer0_setCallBack(void(*a_ptr)(void))
{
	g_callback_ptr = a_ptr;
}

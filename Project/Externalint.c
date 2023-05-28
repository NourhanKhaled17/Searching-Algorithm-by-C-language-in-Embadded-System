#include "Externalint.h"
#define I_BIT (7)
void(*g_callBackPtr)(void)=NULL_PTR;
#define SREG *(volatile unsigned char *)(0x5f)

ISR(INT1_vect)
{
	if (g_callBackPtr!= NULL_PTR)
	{
		(*g_callBackPtr)();
	}
}

void init_int(void)
{
	CLR_BIT(SREG,I_BIT);
	CLR_BIT(DDRD,PD3);
	SET_BIT(PORTD,PD3);
	SET_BIT(GICR,INT1);
	SET_BIT(MCUCR,ISC11);
	CLR_BIT(MCUCR,ISC10);
	SET_BIT(SREG,I_BIT);
}

void INT1_SetCallBack(void(*a_Ptr)(void))
{
	
	g_callBackPtr =  a_Ptr;
}


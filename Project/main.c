#include <avr/io.h>
#include "Externalint.h"
#include "LCD.h"
#include "KEYPAD.h"
#include "std_types.h"
#include "BIT_MATH.h"
#include "LED.h"
#include "Seven_Segment.h"
#include "timer.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <util/delay.h>
#define F_CPU (16000000UL)
int key;
int i=0;
int listt[100];
int g_tick=-1;
int binary[4];
void displayP(void)
{
	g_tick++;
	if (g_tick==0)
	{
		while(i<16)
		{
			if(listt[i]==key)
			{
				CLEAR_SEV_SEG();
				display_number(i);
				CLEAR_SEV_SEG();
				toggle_led(i);
				
				break;
				
			}
			i++;
		}
		
		
	}
	if (g_tick==62&&i<16)
	{
		g_tick=-1;
		i++;
		clr_led();
		CLEAR_SEV_SEG();
		
	}
	if (i>=16)
	{
		i=0;
		timer0_setCallBack(NULL_PTR);
		listt[0]='/0';
		
	}
	
	
}
void toggle_led(int n)
{
	
	int i=0;
	while(n>0)
	{
		binary[i]=n%2;
		n=n/2;
		i++;
	}
	for(int i=0;i<4;i++)
	{
		if (binary[3]==1)
		{
			SET_BIT(PORTB,7);
		}
		if (binary[2]==1)            //0 0 1 1
		{                             //3 2 1 0
			SET_BIT(PORTA,6);
		}
		if (binary[1]==1)
		{
			SET_BIT(PORTA,5);
		}
		if (binary[0]==1)
		{
			SET_BIT(PORTA,4);
		}
		
	}
	
}
int main(void)
{
	int pos;
	keypad_init();
	led_init();
	LCD_init();
	timer0_init();
	int i=0;
	int Temp=0;
	LCD_write_string("instructions...");
	LCD_clear();
	LCD_write_string("+ : config digit,   = : config List, ");
	LCD_clear();
	LCD_write_string( "- : config key for  search ");
	LCD_clear();
	LCD_write_string( "enter the list and  key for search");
	LCD_clear();
	LCD_write_string( "list: ");
	while (1)
	{
		
		int val=keypad_write();
		
		//1= 13=      45   +        13-               1 13 45
		if(val!=INVALID_KEYPAD_PRESS)
		{
			if(val<9 && val>0)
			{                                          //12+14+77+22+69=77-
				Temp*=10;
				Temp+=val;
				
			}
			else if(val==10)
			{
				listt[i++]=Temp;
				Temp=0;
			}
			else if(val==11)
			{
				listt[i++]=Temp;
				Temp=0;
			}
			else if(val==12)
			{
				key=Temp;
				LCD_clear();
				LCD_write_string( "loading....");
				LCD_clear();
				SEVEN_SEG_INIT();
				timer0_setCallBack(displayP);
			}
			
		}
	}
}


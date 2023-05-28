#include "KEYPAD.h"

const unsigned char arr[4][4]= {{0,1,2,3},
								{4,5,6,7},
								{8,9,10,11},
								{12,13,14,15}
								};
void keypad_init(){
	
	CLR_BIT(DDRD,PIN3);
	CLR_BIT(DDRD,PIN5);
	CLR_BIT(DDRD,PIN6);
	CLR_BIT(DDRD,PIN7); //set column as input
	
	SET_BIT(PORTD,PIN3);
	SET_BIT(PORTD,PIN5);
	SET_BIT(PORTD,PIN6);
	SET_BIT(PORTD,PIN7); //set column pull up
	
	SET_BIT(DDRC,PIN2);
	SET_BIT(DDRC,PIN3);
	SET_BIT(DDRC,PIN4);
	SET_BIT(DDRC,PIN5); //set rows as output
	
	_delay_ms(5);
}
unsigned char keypad_get_value(void)
{
		unsigned char col,row,ans = INVALID_KEYPAD_PRESS;
		for (row=5;row>=2;row--)
		{
			PORTC |= 0b00111100; //write high on all rows
			CLR_BIT(PORTC,row); //write low on one row
			for (col=7;col>=3;col--)
			{
				if (col==4)
				{
					col--;
				}
				if (GET_BIT(PIND,col)==0)
				{
					_delay_ms(120); 
					if (GET_BIT(PIND,col)==0)
					{
						if (col==3)
						{
							ans=arr[5-row][7-col-1];
							break;							
						}
						else
						{
							ans=arr[5-row][7-col];
							break;
						}
						
					}
				}
			}
		}
		return ans;
}
// 0 1 2 3           7 8 9 %
// 4 5 6 7           4 5 6 *
// 8 9 10 11         1 2 3 -
// 12 13 14 15       c 0 = +
int keypad_write()
{
	unsigned char x=INVALID_KEYPAD_PRESS;
	unsigned char value;
	value=keypad_get_value();
	if (value!=INVALID_KEYPAD_PRESS)
	{
		if (value==0)
		{
			LCD_write_char('7');
			x=7;
		}
	 else if (value==1)
		{
			LCD_write_char('8');
			x=8;
		}
		else if (value==2)
		{
			LCD_write_char('9');
			x=9;
		}
		else if (value==3)
		{
			LCD_write_char('%');   //%=13
			x=13;
		}
		else if (value==4)
		{
			LCD_write_char('4');
			x=4;
		}
		else if (value==5)
		{
			LCD_write_char('5');
			x=5;
		}
		else if (value==6)
		{
			LCD_write_char('6');
			x=6;
		}
		else if (value==7)
		{
			LCD_write_char('X');   //*=14
			x=14;
		}
		else if (value==8)
		{
			LCD_write_char('1');
			x=1;
		}
		else if (value==9)
		{
			LCD_write_char('2');
			x=2;
		}
		else if (value==10)
		{
			LCD_write_char('3');
			x=3;
		}
		else if (value==11)
		{
			LCD_write_char(' ');
			x=12;							//-=12
		}
		else if (value==12)
		{
			LCD_clear();
		}
		else if (value==13)
		{
			LCD_write_char('0');
			x=0;
		}
		else if (value==14)
		{
			LCD_write_string(" Num for search : ");
			x=11;															//'=' = 11
		}
		else if (value==15)
		{
			LCD_write_char(',');
			x=10;															//'+' = 10
		}
	}
	return x;
}
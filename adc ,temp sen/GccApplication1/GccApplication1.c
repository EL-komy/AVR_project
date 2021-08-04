/*
 * GccApplication1.c
 *
 * Created: 07-May-20 12:19:45 AM
 *  Author: Mohamed_ELkomy
 */ 


#include <avr/io.h>
#include "ADC.h"
#include "LCD.h"

 

int main(void)
{
	LCD_Init();
	ADC_init();
	LCD_send_string("temp=");

	short t,r,m;
	
	while(1)
	{
		m = ADC_Read(0)*.25;
		EEPROM_write(1,m);
		
		r= ADC_Read(2)*.25;
		EEPROM_write(3,r);
		
		t=(m-r);
		
		if (t>=0)
		{
			if (t<10)
			{
				LCD_movecursor(1,6);
				LCD_send_char(48);
				LCD_send_char(t+48);
				LCD_send_char(0);
			}
			else if(t>=10)
			{
				LCD_movecursor(1,6);
				LCD_send_char((t/10)+48);
				LCD_send_char((t%10)+48);
			}

		}

		if (t<0)
		{
			if (t>-10)
			{
				LCD_movecursor(1,6);
				LCD_send_char(0x2d);
				LCD_send_char(48);
				LCD_send_char(-t+48);
			}
			else if(t<=-10)
			{
				LCD_movecursor(1,6);
				LCD_send_char(0x2d);
				LCD_send_char((-t/10)+48);
				LCD_send_char((-t%10)+48);
			}
		}
	}
}
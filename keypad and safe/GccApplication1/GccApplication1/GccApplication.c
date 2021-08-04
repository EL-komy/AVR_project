/*
 * GccApplication1.c
 *
 * Created: 28-Mar-20 10:50:34 PM
 *  Author: Mohamed_ELkomy
 */ 


#include <avr/io.h>
#include "keypad.h"
#include "LCD.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "EEPROM.h"
int main(void)
{
	LCD_Init();
	keypad_Init();
	//EEPROM_write(0x1,0xff);  //  ?????? ?? ????? ??   
mk: if(EEPROM_read(0x1)==0xff)
	{
		LCD_send_string(" Enter new password");
		LCD_movecursor(2,1);
		char i,x=10,r[4],n[4],f=0;
		for (i=10;i<14;i++)
		{
			while(x==10 || x==NOTPRESSED)
			{
			   x=keypad_check_press();
			}			   
			_delay_ms(300);
			EEPROM_write(i,x);
			LCD_send_char('*');
			x=10;
		}
		LCD_send_string("  Done");
		_delay_ms(1000);
		LCD_clearscreen();
		LCD_send_string("  again");
		LCD_movecursor(2,1);
		
		for (i=0;i<4;i++)
		{
			while(x==10 || x==NOTPRESSED)
			{
				x=keypad_check_press();
			}
			_delay_ms(300);
			r[i]=x;
			LCD_send_char('*');
			x=10;
		}
		
		
		if (r[0]==EEPROM_read(10) && r[1]==EEPROM_read(11)&& r[2]==EEPROM_read(12) && r[3]==EEPROM_read(13) )
		{
			LCD_send_string("  ok");
			_delay_ms(1000);
			EEPROM_write(0x1,5);
		}
		else
		{
			LCD_send_string("  not ok");
			_delay_ms(1000);
			LCD_clearscreen();
			goto mk;
		}
		
		while(f!=2)
		{
			LCD_clearscreen();
			LCD_send_string("  password");
			LCD_movecursor(2,1);
			
			for (i=0;i<4;i++)
			{
				while(x==10 || x==NOTPRESSED)
				{
					x=keypad_check_press();
				}
				_delay_ms(300);
				n[i]=x;
				LCD_send_char('*');
				x=10;
			}
			
			
			if (n[0]==EEPROM_read(10) && n[1]==EEPROM_read(11)&& n[2]==EEPROM_read(12) && n[3]==EEPROM_read(13) )
			{
				LCD_send_string("  RIGHT");
				break;
			}
			else
			{
				LCD_send_string("  wrong try again");
				_delay_ms(1000);
				f++;
			}
			if (f==2)
			{
				LCD_clearscreen();
				LCD_send_string("  thief");
			}
		}
	}
	
	else 
	{
		char i,x=10,r[4],n[4],f=0;
		while(f!=2)
		{
			LCD_clearscreen();
			LCD_send_string("  password");
			LCD_movecursor(2,1);
			
			for (i=0;i<4;i++)
			{
				while(x==10 || x==NOTPRESSED)
				{
					x=keypad_check_press();
				}
				_delay_ms(300);
				n[i]=x;
				LCD_send_char('*');
				x=10;
			}
			
			
			if (n[0]==EEPROM_read(10) && n[1]==EEPROM_read(11)&& n[2]==EEPROM_read(12) && n[3]==EEPROM_read(13) )
			{
				LCD_send_string("  RIGHT");
				break;
			}
			else
			{
				LCD_send_string(" wrong try again");
				_delay_ms(1000);
				f++;
			}
			if (f==2)
			{
				LCD_clearscreen();
				LCD_send_string("  thief");
			}
		}
	}
	
	
	
}
/*
 * GccApplication1.c
 *
 * Created: 29-Mar-20 8:25:20 PM
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
    while(1)
    {
        char i,x=10,r[6],a,s,d,b,c;
		short z=0;
        for (i=0;i<6;i++)
        {
	        while(x==10 || x==NOTPRESSED)
	        {
		        x=keypad_check_press();
	        }
	        _delay_ms(300);
	        if (x=='A')
	        {
				LCD_clearscreen();
				i=0;
	        }
			else
			{
				r[i]=x;
				LCD_send_char(x);
				if(x=='=')
				{
					goto mk;
				}
			}
	        x=10;
        }
		
		mk: i=0;
		while(1)
   		{
			if (i<2)
			{
				if(r[i]!='+'&& r[i]!='-' && r[i]!='*' && r[i]!='/' )
				{
					if(r[i+1]!='+'&& r[i+1]!='-' && r[i+1]!='*' && r[i+1]!='/' )
					{
						a=((((r[i])-48)*10)+(r[i+1]-48));
						EEPROM_write(5,a);
						i=i+2;
					}
					else
					{
						a=r[i]-48;
						EEPROM_write(5,a);
						i++;
					}
				}
				if(r[i]=='+'|| r[i]=='-' || r[i]=='*' || r[i]=='/' )
				{
					s=r[i];
					i++;
				}
			}
			if((i>=2))
			{
				if(r[i]!='+'|| r[i]!='-' || r[i]!='*' || r[i]!='/' )
				{
					if(r[i+1]!='+'&& r[i+1]!='-' && r[i+1]!='*' && r[i+1]!='/' && r[i+1]!='=')
					{
						d=((((r[i])-48)*10)+(r[i+1]-48));
						EEPROM_write(6,d);
						i=i+2;
					}
					else
					{
						d=r[i]-48;
						EEPROM_write(6,d);
						i++;
					}
				}
			}
			if(r[i]=='=')
			{
				if (s=='+')
				{
					z=a+d;
					EEPROM_write(7,z);
					if (z<10)
					{
						LCD_send_char(z+48);
					}
					else if (z>=10 && z<=99)
					{
						LCD_send_char((z/10)+48);
						LCD_send_char((z%10)+48);
					}
					else if (z>99)
					{
						LCD_send_char((z/100)+48);
						LCD_send_char(((z-(z/100)*100)/10)+48);
						LCD_send_char((z%10)+48);
					}
					
				}
				else if (s=='-')
				{
					z=a-d;
					if (z<10)
					{
						LCD_send_char(z+48);
					}
					else if (z>=10 && z<=99)
					{
						LCD_send_char((z/10)+48);
						LCD_send_char((z%10)+48);
					}
				}
				else if (s=='*')
				{
					z=a*d;
					if (z<10)
					{
						LCD_send_char(z+48);
					}
					else if (z>=10 && z<=99)
					{
						LCD_send_char((z/10)+48);
						LCD_send_char((z%10)+48);
					}
					else if (z>99 && z<=999)
					{
						LCD_send_char((z/100)+48);
						LCD_send_char(((z-(z/100)*100)/10)+48);
						LCD_send_char((z%10)+48);
					}
					else if (z>999)
					{
						LCD_send_char((z/1000)+48);
						LCD_send_char(((z-(z/1000)*1000)/100)+48);
						LCD_send_char(((z-(z/100)*100)/10)+48);
						LCD_send_char((z%10)+48);
					}
					
				}
				else if (s=='/')
				{
					z=a/d;
					if (z<10)
					{
						LCD_send_char(z+48);
					}
					else if (z>=10 && z<=99)
					{
						LCD_send_char((z/10)+48);
						LCD_send_char((z%10)+48);
					}
				}
				
				//EEPROM_write(7,z);
				//LCD_send_char(z);
				_delay_ms(2000);
				LCD_clearscreen();
				break;
			}
		}
	}
	
}
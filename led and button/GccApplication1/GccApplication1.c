/*
 * GccApplication1.c
 *
 * Created: 9/2/2019 12:18:27 PM
 *  Author: Mohamed_ELkomy
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "std_macros.h"
#include "DIO.h"
#include "led.h"
#include "button.h"

int main(void)
{
	button_init('b',0);
	led_init('a',0);
	char x;
	button_pullupchar('b',0);
	while(1)
	{
		x=button_read('b',0);
	 m:   if (x==0)
		{
			x=button_read('b',0);
			_delay_ms(50);
			if(x==0)
			{
				goto m	;	
			}
			else 
			{
				_delay_ms(25);
				toggle_pin('a',0);
			}
		}
					
	}
	
  return 0;
}
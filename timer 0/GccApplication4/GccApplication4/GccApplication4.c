/*
 * GccApplication4.c
 *
 * Created: 10-Mar-20 10:14:47 PM
 *  Author: Mohamed_ELkomy
 */ 


#include <avr/io.h>
#include "led.h"
#include "button.h"
int main(void)
{
	led_init('a',1);
	button_init('b',1);
	led_on('a',1);
	while(1)
	{
		char x;
		led_tog('a',1);
		for(x=0;x<30;x++)
		{
			TCNT0=0;
			TCCR0=5;
			while((TIFR&(1<<TOV0))==0);
			TCCR0=0;
			TIFR=1;
			
		}		
	}
}	
/*
 * counter_0.c
 *
 * Created: 15-Mar-20 6:55:14 PM
 *  Author: Mohamed_ELkomy
 */ 


#include <avr/io.h>

int main(void)
{
	button_init('b',0);
	set_port('a',0xff);
	button_pullup('b',0);
	TCCR0=6;
	TCNT0=0;
    while(1)
    {
		/*
		while (TIFR&(1<<TOV0)==0)
		{
			write_port('a',TCNT0);
		}
		*/
		do 
		{
			write_port('a',TCNT0);
		} while (TIFR&(1<<TOV0)==0);
		
		
		TIFR=1;	
		
		
    }
}
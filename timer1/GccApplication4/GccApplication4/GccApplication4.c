/*
 * GccApplication4.c
 *
 * Created: 15-Mar-20 1:57:11 PM
 *  Author: Mohamed_ELkomy
 */ 


#include <avr/io.h>  
void del ();

                                 

int main(void)
{
	led_init('a',1);
	led_off('a',1);
	
    while(1)
    {
		 led_tog('a',1);
		  TCNT1H=0x85;
		  TCNT1L=0xEE;
		  TCCR1A= 0x0;
		  TCCR1B=0x4;
		  while(TIFR&(1<<TOV1)==0);
		  TIFR=(1<<TOV1);
    }
}
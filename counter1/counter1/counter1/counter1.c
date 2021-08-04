/*
 * counter1.c
 *
 * Created: 15-Mar-20 9:08:23 PM
 *  Author: Mohamed_ELkomy
 */ 


#include <avr/io.h>

int main(void)
{
	led_init('a',1);
	led_off('a',1);
	button_init('b',1);
	button_pullup('b',1);
	TCCR1A=0;
	TCCR1B=0xe;
	OCR1AH=0;
	OCR1AL=0x4;
	TCNT1L=0;
    TCNT1H=0;
    while(1)
    {
          while ((TIFR&(1<<OCF1A))==0);
		  led_tog('a',1);		  
		  TIFR=1<<OCF1A;
              
    }
}
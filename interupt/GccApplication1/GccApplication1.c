/*
 * GccApplication1.c
 *
 * Created: 16-Mar-20 2:57:18 PM
 *  Author: Mohamed_ELkomy
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>


int main(void)
{
	led_init('a',1);
	button_init('d',2);
	button_pullup('d',2);
	GICR=(1<<INT0);
	
	sei();
	
    while(1)
    {
		
    }
}
ISR(INT0_vect)
{
	sei();
	_delay_ms(1000);
	led_tog('A',1);
	_delay_ms(1000);
}
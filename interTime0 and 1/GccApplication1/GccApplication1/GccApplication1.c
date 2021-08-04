/*
 * GccApplication1.c
 *
 * Created: 16-Mar-20 1:02:15 PM
 *  Author: Mohamed_ELkomy
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include "led.h"
#include "DIO.h"
#include "button.h"
int main(void)
{
	led_init('b',1);
	led_off('b',1);
	button_init('b',0);
	button_pullup('b',0);
	TCCR0=6;
	TCNT0=-3;
	TCNT1=0x85ee;
	TCCR1A=0;
	TCCR1B=4;
	sei();
	TIMSK=(1<<TOIE0)|(1<<TOIE1);
	set_port('d',0xff);	
	set_port('a',0xff);
    while(1)
    {
        write_port('d',55);
    }
}

ISR (TIMER0_OVF_vect)
{
	TCNT0=-3;
	led_tog('b',1);
}

ISR (TIMER1_OVF_vect)
{
	write_port('a',(read_port('a')+1));
}
/*
 * project.c
 *
 * Created: 31-May-20 10:50:01 PM
 *  Author: Mohamed_ELkomy
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
	DDRA|=(1<<0);          //make pin output(led)
	DDRB&=(~(1<<0));       //make pin input(button)
	char x;
	char m=0;
	PORTB|=(1<<0);        //pull up the button
	
    while(1)
    {
       x=((PINB&(1<<0))>>0);    
	   if (x==0 && m==0)          //if the button pressed
	   {
		    PORTA^=(1<<0);        //toggle the led
			m=1;
	   }
	   else if (x==1)
	   {
		   m=0;
	   }
	   _delay_ms(50);
    }
}
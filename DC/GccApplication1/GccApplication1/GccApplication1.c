/*
 * GccApplication1.c
 *
 * Created: 24-Jun-20 2:07:31 PM
 *  Author: Mohamed_ELkomy
 */ 


#include <avr/io.h>
#include "DIO.h"
#include "button.h"

int main(void)
{
	set_pin('b',3,1);
    set_pin('b',4,1);
    set_pin('b',5,1);
	write_pin('b',5,1);
	button_init('a',7);
	button_pullup('a',7);
	TCCR0=0x61;
	
    while(1)
    {
		if(button_read('a',7)==1)
		{
			OCR0=0;
		}
		else
		{
			OCR0=255;
		}
       
    }
}
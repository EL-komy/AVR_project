/*
 * GccApplication2.c
 *
 * Created: 9/17/2019 2:46:54 PM
 *  Author: Mohamed_ELkomy
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "seven segment.h"
#include "button.h"

void main(void)
{
	char i=0;
	seven_init('d');
	button_init('b',0);
	 DDRC=0XFF;
	 PORTC=0XAA;
    while(1)
    {
		m:	if(i<10)
			{
			 if(button_read('b',0)==1)
			 {
				 _delay_ms(500);
				 if(button_read('b',0)==1){
					  _delay_ms(500);
					   seven_write('d',i);
					  goto m ;
				 }
				
				 seven_write('d',i);
				 i++;
			 }
			}			 
			 else				 
				 i=0;
			}
			
	}							 
/*
 * GccApplication1.c
 *
 * Created: 06-May-20 12:44:15 PM
 *  Author: Mohamed_ELkomy
 */ 


#include <avr/io.h>
#include "ADC.h"
#include "led.h"

int main(void)
{
	ADC_init();
	led_init('c',0);
	led_init('c',1);
	led_init('c',2);
	led_init('c',3);
	led_init('c',4);
	led_init('c',5);
	led_init('c',6);
	led_init('c',7);

    while(1)
    {
        PORTC=ADC_Read();
    }
}
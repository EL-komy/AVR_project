/*
 * GccApplication1.c
 *
 * Created: 25-Jun-20 11:05:32 PM
 *  Author: Mohamed_ELkomy
 */ 


#include <avr/io.h>
#include "USART.h"
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
	UART_init(9600);
	_delay_ms(300);
	UART_sendString("MOHAMMED");
    while(1)
    {
       
    }
}
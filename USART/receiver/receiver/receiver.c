/*
 * receiver.c
 *
 * Created: 26-Jun-20 12:23:14 AM
 *  Author: Mohamed_ELkomy
 */ 


#include <avr/io.h>
#include "USART.h"
#include "LCD.h"
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
	UART_init(9600);
	LCD_Init();
	char x;
    while(1)
    {
        x=UART_receiveData();
        LCD_send_char(x);
    }
}
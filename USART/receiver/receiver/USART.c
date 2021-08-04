/*
 * USART.c
 *
 * Created: 25-Jun-20 11:10:28 PM
 *  Author: Mohamed_ELkomy
 */ 
#include <avr/io.h>
#include "std_macros.h"
#define F_CPU 8000000UL
#include <util/delay.h>

void UART_init(unsigned long baud)
{
	unsigned short UBRR ;
	UBRR =(F_CPU/(16*baud))-1;
	UBRRH = (unsigned char)(UBRR>>8);
	UBRRL = (unsigned char)UBRR;
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
	UCSRC= (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
}

void UART_sendData (char data)
{
	while(READ_BIT(UCSRA,UDRE)==0);
	UDR=data;
}

char UART_receiveData ()
{
	while(READ_BIT(UCSRA,RXC)==0);
	return UDR;
}

void UART_sendString (char *ptr)
{
	while(*ptr!=0)
	{
		UART_sendData(*ptr);
		ptr++;
		_delay_ms(100);
	}
}

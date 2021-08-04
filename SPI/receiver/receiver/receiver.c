/*
 * receiver.c
 *
 * Created: 27-Jun-20 6:20:18 PM
 *  Author: Mohamed_ELkomy
 */ 


#include <avr/io.h>
#include "SPI.h"
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
	SPI_SlaveInit();
	LCD_Init();
	unsigned char x=0x30;
	unsigned char z=0;
    while(z<10)
    {
       x=SPI_SlaveReceiveChar(x);
	   LCD_send_char(x);
	   z++;
    }
}
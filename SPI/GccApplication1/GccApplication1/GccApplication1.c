/*
 * GccApplication1.c
 *
 * Created: 27-Jun-20 7:15:02 AM
 *  Author: Mohamed_ELkomy
 */ 


#include <avr/io.h>
#include "SPI.h"
#define F_CPU 8000000UL
#include <util/delay.h>
int main(void)
{
	SPI_MasterInit();
	unsigned char c =0;
    while(c<10)
    {
        SPI_MasterTransChar(c+48);
		_delay_ms(300);
		c++;
    }
}
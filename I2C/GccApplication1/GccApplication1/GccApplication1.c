/*
 * GccApplication1.c
 *
 * Created: 29-Jun-20 6:05:56 PM
 *  Author: Mohamed_ELkomy
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "I2C.h"

int main(void)
{
	I2C_Master_init(50000);
	unsigned char c=0;
	
    while(c<10)
    {
        _delay_ms(500);
		I2C_start();
		I2C_Write_Address(0B11100000);
		I2C_Write_Data(c+48);
		I2C_stop();
		c++;
    }
}
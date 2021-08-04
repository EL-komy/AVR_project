/*
 * receiver.c
 *
 * Created: 30-Jun-20 2:30:59 AM
 *  Author: Mohamed_ELkomy
 */ 


#include <avr/io.h>
#include "LCD.h"
#include "I2C.h"

int main(void)
{
	I2C_Slave_init(0b11100000);
	LCD_Init();
	unsigned char x;
    while(1)
    {
        x=I2C_Slave_read();
		LCD_send_char(x);
    }
}
/*
 * GccApplication1.c
 *
 * Created: 28-Mar-20 1:09:30 PM
 *  Author: Mohamed_ELkomy
 */ 


#include <avr/io.h>
#define  F_CPU 8000000UL
#include <util/delay.h>
#include "LCD.h"


int main(void)
{
	LCD_Init();
	LCD_send_string("mohamed");
    while(1)
    {
        
    }
}
/*
 * LCD.c
 *
 * Created: 28-Mar-20 1:13:08 PM
 *  Author: Mohamed_ELkomy
 */ 

#include "LCD.h"
#define  F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>

void LCD_Init(void)
{
	_delay_ms(200);
	#if defined eight_bits_mode
	
	set_port('b',0xff);
	write_pin('b',RW,0);
	
	LCD_send_cmd(EIGHT_BITS); //8 bit mode
	_delay_ms(1);
	LCD_send_cmd(CURSOR_ON_DISPLAN_ON);//display on cursor on
	_delay_ms(1);
	LCD_send_cmd(CLR_SCREEN);//clear the screen
	_delay_ms(10);
	LCD_send_cmd(ENTRY_MODE); //entry mode
	_delay_ms(1);
	
	#elif defined four_bits_mode
	set_port('b',0xff);
	write_pin('b',RW,0);
	 LCD_send_cmd(RETURN_HOME); //return home
	 _delay_ms(10);
	 //LCD_send_cmd(0x33);
	 //LCD_send_cmd(0x32);  
	 LCD_send_cmd(FOUR_BITS); //4bit mode
	 _delay_ms(1);
	 LCD_send_cmd(CURSOR_ON_DISPLAN_ON);//display on cursor on
	 _delay_ms(1);
	 LCD_send_cmd(CLR_SCREEN);//clear the screen
	 _delay_ms(10);
	 LCD_send_cmd(ENTRY_MODE); //entry mode
	 _delay_ms(1);
	 #endif
 }

static void send_falling_edge(void)
{
	write_pin('b',EN,1);
	_delay_ms(2);
	write_pin('b',EN,0);
	_delay_ms(2);
}

void LCD_send_cmd(char cmd)
{
	#if defined eight_bits_mode
	write_port('b',cmd);
	write_pin('b',RS,0);
	send_falling_edge();

	#elif defined four_bits_mode
	write_port('b',(PORTA & 0x0f)|(cmd&0xf0));
	write_pin('b',RS,0);
	send_falling_edge();
	write_port('b',(PORTA & 0x0f)|(cmd<<4));
	write_pin('b',RS,0);
	send_falling_edge();
	_delay_ms(1);
	#endif
}


void LCD_send_char(char data)
{
	#if defined eight_bits_mode
	write_port('b',data);
	write_pin('b',RS,1);
	send_falling_edge();

	#elif defined four_bits_mode
	write_port('b',(PORTA & 0x0f)|(data&0xf0));
	write_pin('b',RS,1);
	send_falling_edge();
	write_port('b',(PORTA & 0x0f)|(data<<4));
	write_pin('b',RS,1);
	send_falling_edge();
	_delay_ms(1);
	#endif
}

void LCD_send_string(char *data)
{
	while((*data)!='\0')
	{
		LCD_send_char(*data);
		data++;
	}
}
void LCD_clearscreen()
{
	LCD_send_cmd(CLR_SCREEN);
	_delay_ms(10);
}


void LCD_movecursor(char row,char coloumn)
{
	char data ;
	if(row>2||row<1||coloumn>16||coloumn<1)
	{
		data=0x80;
	}
	else if(row==1)
	{
		data=0x80+coloumn-1 ;
	}
	else if (row==2)
	{
		data=0xc0+coloumn-1;
	}
	LCD_send_cmd(data);
	_delay_ms(1);
}

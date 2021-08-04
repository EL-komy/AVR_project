/*
 * button.c
 *
 * Created: 9/14/2019 3:23:41 PM
 *  Author: Mohamed_ELkomy
 */ 

#include "DIO.h"

void button_init(char port_name,char pin_number)
{
	set_pin(port_name,pin_number,0);
}
char button_read (char port_name,char pin_number)
{
	char x;
	x=read_pin(port_name,pin_number);
	return x;
}

void button_pullup(char port_name,char pin_number)
{
	write_pin(port_name,pin_number,1);
}
/*
 * _7_segment.c
 *
 * Created: 9/17/2019 2:49:23 PM
 *  Author: Mohamed_ELkomy
 */ 

#include "DIO.h"

void seven_init (char port_name)
{
	set_pin(port_name,0,1);
	set_pin(port_name,1,1);
	set_pin(port_name,2,1);
	set_pin(port_name,3,1);
}

void seven_write(char port_name,char val)
{
		write_low_nibble(port_name,val);
}
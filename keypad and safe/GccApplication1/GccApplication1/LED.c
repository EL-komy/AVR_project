/*
 * LED.c
 *
 * Created: 9/10/2019 2:18:26 PM
 *  Author: Mohamed_ELkomy
 */ 

#include "DIO.h"

void led_init (char port_name,char pin_number)
{
	set_pin(port_name, pin_number,1);
}
void led_on (char port_name,char pin_number)
{
	write_pin( port_name, pin_number,1);
}
void led_off (char port_name,char pin_number)
{
	write_pin( port_name, pin_number,0);
}
void led_tog (char port_name,char pin_number)
{
	toggle_pin( port_name, pin_number);
}
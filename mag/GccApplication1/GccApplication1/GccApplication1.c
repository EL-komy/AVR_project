/*
 * GccApplication1.c
 *
 * Created: 07-Jul-20 9:49:18 PM
 *  Author: Mohamed_ELkomy
 */ 


#include <avr/io.h>
#include "DIO.h"

int main(void)
{
	set_port('a',1);
	while(1)
	{
		write_pin('a',0,1);
		write_pin('a',1,0);
	}
}
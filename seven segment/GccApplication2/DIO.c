/*
 * DIO.c
 *
 * Created: 9/5/2019 2:14:30 PM
 *  Author: Mohamed_ELkomy
 */ 

#include <avr/io.h>
#include "std_macros.h"

void set_pin(char port_name,char pin_number,char direction)
{
	switch(port_name)
	{
		case 'A':
		case 'a':
		if (direction==1)
		{
			SET_BIT(DDRA,pin_number);
		}
		else
		{
			CLR_BIT(DDRA,pin_number);
		}			
		break;
		
		case 'B':
		case 'b':
		if (direction==1)
		{
			SET_BIT(DDRB,pin_number);
		}
		else
		{
			CLR_BIT(DDRB,pin_number);
		}
		break;
		case 'C':
		case 'c':
		if (direction==1)
		{
			SET_BIT(DDRC,pin_number);
		}
		else
		{
			CLR_BIT(DDRC,pin_number);
		}
		break;
		
		case 'D':
		case 'd':
		if (direction==1)
		{
			SET_BIT(DDRD,pin_number);
		}
		else
		{
			CLR_BIT(DDRD,pin_number);
		}
		break;
		default:
		break;
	}
}

void write_pin(char port_name,char pin_number,char val)
{
	switch(port_name)
	{
		case 'A':
		case 'a':
		if (val==1)
		{
			SET_BIT(PORTA,pin_number);
		}
		else
		{
			CLR_BIT(PORTA,pin_number);
		}
		break;
		
		case 'B':
		case 'b':
		if (val==1)
		{
			SET_BIT(PORTB,pin_number);
		}
		else
		{
			CLR_BIT(PORTB,pin_number);
		}
		break;
		
		case 'C':
		case 'c':
		if (val==1)
		{
			SET_BIT(PORTC,pin_number);
		}
		else
		{
			CLR_BIT(PORTC,pin_number);
		}
		break;
		
		case 'D':
		case 'd':
		if (val==1)
		{
			SET_BIT(PORTD,pin_number);
		}
		else
		{
			CLR_BIT(PORTD,pin_number);
		}
		break;
		default:
		break;
	}		
}

char read_pin(char port_name,char pin_number)
{
	char val;
	switch(port_name)
	{
		case 'A':
		case 'a':
		val= READ_BIT(PINA,pin_number);
		break;
		
		case 'B':
		case 'b':
		val=  READ_BIT(PINB,pin_number);
		break;
		
		case 'C':
		case 'c':
		val=  READ_BIT(PINC,pin_number);
		break;
		
		case 'D':
		case 'd':
		val=  READ_BIT(PIND,pin_number);
		break;
		default:
		break;
	}
	 return val;
}			

void toggle_pin(char port_name,char pin_number)
{
	switch(port_name)
	{
		case 'A':
		case 'a':
		TOG_BIT(PORTA,pin_number);
		break;
		
		case 'B':
		case 'b':
		TOG_BIT(PORTB,pin_number);
		break;
		case 'C':
		case 'c':
		TOG_BIT(PORTC,pin_number);
		break;
		case 'D':
		case 'd':
		TOG_BIT(PORTD,pin_number);
		break;
		default:
		break;
					
	}		
}

void set_port (char port_name,char direction)
{
	switch(port_name)
	{
		case 'A':
		case 'a':
		DDRA=direction;
		break;
		case 'B':
		case 'b':
		DDRB=direction;
		break;
		case 'C':
		case 'c':
		DDRC=direction;
		break;
		case 'D':
		case 'd':
		DDRD=direction;
		break;
		default:
		break;
	}			
}
void write_port (char port_name,char val)
{
	switch(port_name)
	{
		case 'A':
		case 'a':
		PORTA=val;
		break;
		case 'B':
		case 'b':
		PORTB=val;
		break;
		case 'C':
		case 'c':
		PORTC=val;
		break;
		case 'D':
		case 'd':
		PORTD=val;
		break;
		default:
		break;
	}		
}

char read_port(char port_name)
{
	unsigned char val;
	
	switch(port_name)
	{
		case 'A':
		case 'a':
		val=PINA;
		break;
		case 'B':
		case 'b':
		val=PINB;
		break;
		case 'C':
		case 'c':
		val=PINC;
		break;
		case 'D':
		case 'd':
		val=PIND;
		break;
		default:
		break;
	}		
} 

void write_high_nibble(char port_name,char val)
{
	switch(port_name)
	{
		 case 'A':
		 case 'a':
		 PORTA&=0x0f;
		 PORTA|=val;
		 break;
		 case 'B':
		 case 'b':
		 PORTB&=0x0f;
		 PORTB|=val;
		 break;
		 case 'C':
		 case 'c':
		 PORTC&=0x0f;
		 PORTC|=val;
		 break;
		 case 'D':
		 case 'd':
		 PORTD&=0x0f;
		 PORTD|=val;
		 break;
		 default:
		 break;
	}		 
}
void write_low_nibble(char port_name,char val)
{
	switch(port_name)
	{
		case 'A':
		case 'a':
		PORTA&=0xf0;
		PORTA|=val;
		break;
		case 'B':
		case 'b':
		PORTB&=0xf0;
		PORTB|=val;
		break;
		case 'C':
		case 'c':
		PORTC&=0xf0;
		PORTC|=val;
		break;
		case 'D':
		case 'd':
		PORTD&=0xf0;
		PORTD|=val;
		break;
		default:
		break;
	}
}
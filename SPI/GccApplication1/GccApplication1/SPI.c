/*
 * SPI.c
 *
 * Created: 27-Jun-20 7:19:15 AM
 *  Author: Mohamed_ELkomy
 */ 

#include "std_macros.h"
#include "DIO.h"
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

void SPI_MasterInit()
{
	set_pin('b',4,1);
	set_pin('b',5,1);
	set_pin('b',7,1);
	SET_BIT(SPCR,MSTR);
	SET_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPE);
	write_pin('B',4,1);
}

void SPI_SlaveInit()
{
	SET_BIT(SPCR,SPE);
	set_pin('b',6,1);
}

unsigned char SPI_MasterTransChar(unsigned char Data)
{
	write_pin('b',4,0);
	SPDR=Data;
	while(READ_BIT(SPSR,SPIF)==0);
	return SPDR;
}

unsigned char SPI_SlaveReceiveChar(unsigned char Data)
{

	SPDR=Data;
	while(READ_BIT(SPSR,SPIF)==0);
	return SPDR;
}

void SPI_MasterTransString(unsigned char *ptr)
{
	while((*ptr)!=0)
	{
		SPI_SlaveReceiveChar(*ptr);
		_delay_ms(300);
		ptr++;
	}
}
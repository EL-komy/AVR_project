/*
 * I2C.c
 *
 * Created: 29-Jun-20 6:07:48 PM
 *  Author: Mohamed_ELkomy
 */ 

#include <avr/io.h>
#include "std_macros.h"
#define F_CPU 8000000UL
#define  prescalar 1

void I2C_Master_init(unsigned long scl)
{
	TWBR= (unsigned char) (((F_CPU/scl)-16)/(2*prescalar));
	if (prescalar==1)
	{
		TWSR=0;
	}
	else if (prescalar==4)
	{
		TWSR=1;
	}
	else if (prescalar==16)
	{
		TWSR=2;
	}
	else if (prescalar==64)
	{
		TWSR=3;
	}		
}

void I2C_start()
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
	while(READ_BIT(TWCR,TWINT)==0);
	
}

void I2C_stop()
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}

void I2C_Write_Address(unsigned char adr)
{
	TWDR=adr;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(READ_BIT(TWCR,TWINT)==0);
}

void I2C_Write_Data(unsigned char data)
{
	TWDR=data;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(READ_BIT(TWCR,TWINT)==0);
}

void I2C_Slave_init(unsigned char addr)
{
	TWAR=addr;
}

unsigned char I2C_Slave_read()
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while(READ_BIT(TWCR,TWINT)==0);
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while(READ_BIT(TWCR,TWINT)==0);
	
	return TWDR;
}

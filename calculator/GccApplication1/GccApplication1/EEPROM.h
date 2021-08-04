/*
 * EEPROM.h
 *
 * Created: 29-Mar-20 1:02:04 PM
 *  Author: Mohamed_ELkomy
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

void EEPROM_write(unsigned short address, unsigned char data );
unsigned char EEPROM_read( unsigned short address );

#endif /* EEPROM_H_ */
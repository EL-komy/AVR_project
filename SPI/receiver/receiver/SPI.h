/*
 * SPI.h
 *
 * Created: 27-Jun-20 7:46:06 AM
 *  Author: Mohamed_ELkomy
 */ 


#ifndef SPI_H_
#define SPI_H_

void SPI_MasterInit();
void SPI_SlaveInit();
unsigned char SPI_MasterTransChar(unsigned char Data);
unsigned char SPI_SlaveReceiveChar(unsigned char Data);
void SPI_MasterTransString(unsigned char *ptr);




#endif /* SPI_H_ */
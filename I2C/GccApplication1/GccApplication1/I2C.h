/*
 * I2C.h
 *
 * Created: 29-Jun-20 6:07:17 PM
 *  Author: Mohamed_ELkomy
 */ 


#ifndef I2C_H_
#define I2C_H_

void I2C_Master_init(unsigned long scl);
void I2C_start();
void I2C_stop();
void I2C_Write_Address(unsigned char adr);
void I2C_Write_Data(unsigned char data);
void I2C_Slave_init(unsigned char addr);
unsigned char I2C_Slave_read();

#endif /* I2C_H_ */
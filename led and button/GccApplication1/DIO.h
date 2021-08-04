/*
 * DIO.h
 *
 * Created: 9/5/2019 2:13:37 PM
 *  Author: Mohamed_ELkomy
 */ 


#ifndef DIO_H_
#define DIO_H_

void set_pin(char port_name,char pin_number,char direction);
void write_pin(char port_name,char pin_number,char val);
char read_pin(char port_name,char pin_number);
void toggle_pin(char port_name,char pin_number);
void set_port (char port_name,char direction);
void write_port (char port_name,char val);
char read_port(char port_name);




#endif /* DIO_H_ */
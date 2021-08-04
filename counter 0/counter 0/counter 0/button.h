
/*
 * button.h
 *
 * Created: 9/14/2019 4:44:27 PM
 *  Author: Mohamed_ELkomy
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

void button_init(char port_name,char pin_number);
char button_read (char port_name,char pin_number);
void button_pullup(char port_name,char pin_number);

#endif /* BUTTON_H_ */
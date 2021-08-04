/*
 * keypad.h
 *
 * Created: 28-Mar-20 10:52:01 PM
 *  Author: Mohamed_ELkomy
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#define NOTPRESSED  0xff
#include "DIO.h"
void keypad_Init();
char keypad_check_press();

#endif /* KEYPAD_H_ */
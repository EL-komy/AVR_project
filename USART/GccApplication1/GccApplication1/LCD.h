/*
 * LCD.h
 *
 * Created: 28-Mar-20 1:13:55 PM
 *  Author: Mohamed_ELkomy
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "DIO.h"
#define   four_bits_mode
#define CLR_SCREEN 0x01
#define CURSOR_ON_DISPLAN_ON 0x0e
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06
#define EN 0
#define RS 1
#define RW 2

#if defined four_bits_mode
#define FOUR_BITS 0x28

#elif defined eight_bits_mode
#define EIGHT_BITS 0x38
#endif

void LCD_Init(void);
static void send_falling_edge(void);
void LCD_send_cmd(char cmd);
void LCD_send_char(char data);
void LCD_send_string(char *data);
void LCD_clearscreen();
void LCD_movecursor(char row,char coloumn);

#endif /* LCD_H_ */
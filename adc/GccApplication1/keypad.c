/*
 * keypad.c
 *
 * Created: 28-Mar-20 10:52:31 PM
 *  Author: Mohamed_ELkomy
 */ 

#include "keypad.h"
#include "DIO.h"
void keypad_Init()
{
	set_pin('D',0,1);
	set_pin('D',1,1);
	set_pin('D',2,1);
	set_pin('D',3,1);
	set_pin('D',4,0);
	set_pin('D',5,0);
	set_pin('D',6,0);
	set_pin('D',7,0);
	write_pin('D',4,1);
	write_pin('D',5,1);
	write_pin('D',6,1);
	write_pin('D',7,1);
}

char  keypad_check_press()
{
char arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{1,'2','3','-'},{'A','0','=','+'}};
char row,coloumn,x;
char returnval=NOTPRESSED;
for(row=0;row<4;row++)
{
	write_pin('D',0,1);
	write_pin('D',1,1);
	write_pin('D',2,1);
	write_pin('D',3,1);
	write_pin('D',row,0);
	for(coloumn=0;coloumn<4;coloumn++)
	{
		x=read_pin('D',(coloumn+4));
		if(x==0)
		{
			returnval=arr[row][coloumn];
			break;
		}
	}
	if(x==0)
	{
		break;
	}
}
return returnval ;
 }


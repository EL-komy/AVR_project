/*
 * USART.h
 *
 * Created: 25-Jun-20 11:10:16 PM
 *  Author: Mohamed_ELkomy
 */ 


#ifndef USART_H_
#define USART_H_

void UART_init(unsigned long baud);	
void UART_sendData (char data);
char UART_receiveData ();
void UART_sendString (char *ptr);

#endif /* USART_H_ */
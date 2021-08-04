/*
 * led.h
 *
 * Created: 9/10/2019 2:26:13 PM
 *  Author: Mohamed_ELkomy
 */ 


#ifndef LED_H_
#define LED_H_

void led_init (char port_name,char pin_number);
void led_on (char port_name,char pin_number);
void led_off (char port_name,char pin_number);
void led_tog (char port_name,char pin_number);

#endif /* LED_H_ */
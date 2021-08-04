/*
 * std_macros.h
 *
 * Created: 9/2/2019 12:21:01 PM
 *  Author: Mohamed_ELkomy
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_

#define REGISTER_SIZE 8
#define SET_BIT(reg,bit)  reg|=(1<<bit)
#define CLR_BIT(reg,bit)  reg&=(~(1<<bit))
#define TOG_BIT(reg,bit)  reg^=(1<<bit)
#define READ_BIT(reg,bit)  ((reg&(1<<bit))>>bit)

#endif /* STD_MACROS_H_ */
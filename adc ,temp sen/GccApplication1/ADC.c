/*
 * ADC.c
 *
 * Created: 06-May-20 12:46:12 PM
 *  Author: Mohamed_ELkomy
 */

#include <avr/io.h>
#include "std_macros.h"
void ADC_init(void)
{
	//SET_BIT(ADMUX,REFS0); //configure VREF
	//SET_BIT(ADMUX,REFS1);
	SET_BIT(ADMUX,ADLAR);
	
	SET_BIT(ADCSRA,ADEN); // enable ADC
	/* adjust ADC clock*/
	SET_BIT(ADCSRA,ADPS2);
	SET_BIT(ADCSRA,ADPS1);
	//SET_BIT(ADCSRA,ADPS0);
}


short ADC_Read(char n)
{
	short read_val;
	ADMUX = ((1<<REFS0) |(1<<REFS1) | n);

	SET_BIT(ADCSRA,ADSC);
	while((ADCSRA & (1<<ADIF))==0);//stay in your position till ADIF become 1
	SET_BIT(ADCSRA,ADIF); // clear ADIF
	read_val=(ADCL);
	read_val|=(ADCH<<8);
	return read_val ;
}
 

/*
 * ADC.c
 *
 *  Created on: Jan 13, 2018
 *      Author: Mohamed
 */
#include "adc.h"
void ADC_Init(){
	DDRA = 0x00;	        /* Make ADC port as input */
	ADCSRA = 0x87;          /* Enable ADC, with freq/128  */
	ADMUX = 0x40;           /* Vref: Avcc, ADC channel: 0 */
}

//void ADC_Init()
//{
//	ADCSRA |= (1<<ADEN)|(1<<ADPS0)|(1<<ADPS1);
//	ADMUX = 0;
//}

uint16 ADC_read(uint8 num_pin)
{
	ADMUX |= (num_pin & 0x1F);
	Set_Bit(ADCSRA,ADSC);
	while(Bit_Is_Clear(ADCSRA,ADIF));
	Set_Bit(ADCSRA,ADIF);
return ADC;}

int ADC_Read(char channel)
{
	ADMUX = 0x40 | (channel & 0x07);   /* set input channel to read */
	ADCSRA |= (1<<ADSC);               /* Start ADC conversion */
	while (!(ADCSRA & (1<<ADIF)));     /* Wait until end of conversion by polling ADC interrupt flag */
	ADCSRA |= (1<<ADIF);               /* Clear interrupt flag */
	_delay_ms(1);                      /* Wait a little bit */
	return ADCW;                       /* Return ADC word */
}

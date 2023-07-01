/*
 * LCD_EX_2.c
 *
 *  Created on: Mar 17, 2023
 *      Author:
 */
//9600
#include <avr/io.h>
#include <util/delay.h>
#include "gpio.h"
#include "lcd.h"
#include "std_types.h"
#include "uart.h"
#include "DCmotor.h"
#include "adc.h"
#define degree_sysmbol 0xdf

int main()
{
UART_init(9600);
DcMotor_Init();
ADC_Init();
GPIO_setupPinDirection(2,0,1);

int temp1=0;
int celsius=0;
while(1){temp1=ADC_read(0);
			celsius = (ADC_Read(0)*4.88);
			celsius = (celsius/10.00);
    	UART_sendByte(celsius);
        if(celsius>30) {
        	DcMotor_Rotate(DcMotor_CW,100);
        }
        if(celsius<20) {
        	DcMotor_Rotate(DcMotor_STOP,0);
        }

           }

    return 0;
}

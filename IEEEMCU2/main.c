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
#include "motor.h"
int main()
{
UART_init(9600);
GPIO_setupPinDirection(0,2,1);
    while(1){

    	if (UART_recieveByte()>60){
    		GPIO_writePin(0,2,1);
    	}
    }

    return 0;
}

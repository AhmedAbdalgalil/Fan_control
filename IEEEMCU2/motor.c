/******************************************************************************
*  File name:		motor.c
*  Author:			Oct 5, 2022

*******************************************************************************/

/*******************************************************************************
*                        		Inclusions                                     *
*******************************************************************************/

#include "motor.h"
#include <util/delay.h> /* For the delay functions */
#include "common_macros.h"
#include "gpio.h"

#include "avr/io.h"


void DcMotor_Init(void)
{
	/* setting the direction of the motor pins */
	GPIO_setupPinDirection(DCMOTOR_PORT_ID, DCMOTOR_PIN_N1, output); /* Input1 */
	GPIO_setupPinDirection(DCMOTOR_PORT_ID, DCMOTOR_PIN_N2, output);

}

void DcMotor_Rotate()
{
	/* clearing the motor so we can change it state */
	GPIO_writePin(DCMOTOR_PORT_ID, DCMOTOR_PIN_N1,1);
	GPIO_writePin(DCMOTOR_PORT_ID, DCMOTOR_PIN_N2, 0);


}
void DcMotor_Stop(){

	GPIO_writePin(DCMOTOR_PORT_ID, DCMOTOR_PIN_N1,0);
	GPIO_writePin(DCMOTOR_PORT_ID, DCMOTOR_PIN_N2, 0);

}

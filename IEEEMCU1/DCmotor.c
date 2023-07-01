/******************************************************************************
*  File name:		motor.c
*  Author:			Oct 5, 2022
*  Author:			Ahmed Tarek
*******************************************************************************/

/*******************************************************************************
*                        		Inclusions                                     *
*******************************************************************************/

#include "DCmotor.h"



void DcMotor_Init(void)
{
	/* setting the direction of the motor pins */
	GPIO_setupPinDirection(DCMOTOR_PORT_ID, DCMOTOR_PIN_IN1, 1); /* Input1 */
	GPIO_setupPinDirection(DCMOTOR_PORT_ID, DCMOTOR_PIN_IN2, 1); /* Inupt2 */
	GPIO_setupPinDirection(PORTB_ID, PIN3_ID, output);
	/* Stop the motor */
	GPIO_writePin(DCMOTOR_PORT_ID, DCMOTOR_PIN_IN1, Low);
	GPIO_writePin(DCMOTOR_PORT_ID, DCMOTOR_PIN_IN2, Low);
}

void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	/* clearing the motor so we can change it state */

	GPIO_writePin(DCMOTOR_PORT_ID, DCMOTOR_PIN_IN1, GET_BIT(state,0));
	GPIO_writePin(DCMOTOR_PORT_ID, DCMOTOR_PIN_IN2, GET_BIT(state,1));
	GPIO_writePin(DCMOTOR_PORT_ID, DCMOTOR_PIN_E, 1);
	//PWM_Timer0_Start(speed);
}

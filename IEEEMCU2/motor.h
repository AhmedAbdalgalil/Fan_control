/******************************************************************************
*  File name:		motor.h
*  Author:			Oct 5, 2022
*******************************************************************************/

#ifndef MOTOR_H_
#define MOTOR_H_

/*******************************************************************************
*                        		Inclusions                                     *
*******************************************************************************/

#include "gpio.h"
#include "avr/io.h"
#include "std_types.h"
/*******************************************************************************
*                        		Definitions                                    *
*******************************************************************************/

#define DCMOTOR_PORT_ID			PORTB_ID
#define	DCMOTOR_PIN_N1			PIN2_ID
#define	DCMOTOR_PIN_N2           PIN3_ID
/*******************************************************************************
*                         Types Declaration                                   *
*******************************************************************************/

/*******************************************************************************
* Name: DcMotor_State
* Type: Enumeration
* Description: Data type to represent the different states of the motor
********************************************************************************/


/*******************************************************************************
*                      Functions Prototypes                                   *
*******************************************************************************/

/*******************************************************************************
* Function Name:		DcMotor_Init
* Description:			Function to initialize the motor
* Parameters (in):    	None
* Parameters (out):   	None
* Return value:      	void
********************************************************************************/

void DcMotor_Init(void);

/*******************************************************************************
* Function Name:		DcMotor_Rotate
* Description:			Function to control the motor direction and its speed
* Parameters (in):    	Required direction and speed
* Parameters (out):   	None
* Return value:      	void
********************************************************************************/

void DcMotor_Rotate();
void DcMotor_Stop();
void DcMotor_Commn();

#endif /* MOTOR_H_ */

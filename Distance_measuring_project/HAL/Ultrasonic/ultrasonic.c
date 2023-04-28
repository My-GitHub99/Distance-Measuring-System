/*
 * ultrasonic.c
 *
 *  Created on: Apr 23, 2023
 *      Author: Ahmed bahaa
 */

#include "../../MCAL/GPIO/gpio.h"
#include "../../MCAL/ICU/icu.h"
#define F_CPU        8000000UL       /*to use the delay function*/
#include <util/delay.h> /* For the delay functions */
#include <math.h>
#include "ultrasonic.h"


const Icu_ConfigType sensorInstance1 ={F_CPU_8,RISING};
 uint8 g_edgeCount =0;

 uint16 g_timeHigh = 0;

void Ultrasonic_init(void)
{
	Icu_init(&sensorInstance1);
	GPIO_setupPinDirection(TRIGGER_PORT_ID,TRIGGER_PIN_ID,PIN_OUTPUT);
	Icu_setCallBack(Ultrasonic_edgeProcessing);
}

void Ultrasonic_Trigger(void)
{

	 GPIO_writePin(TRIGGER_PORT_ID,TRIGGER_PIN_ID,LOGIC_HIGH);
	 _delay_us(15);
	 GPIO_writePin(TRIGGER_PORT_ID,TRIGGER_PIN_ID,LOGIC_LOW);





}

uint16 Ultrasonic_readDistance(void)
{
	Ultrasonic_Trigger();
	return (g_timeHigh/57);
}

void Ultrasonic_edgeProcessing(void)
{
	g_edgeCount++;
	if(g_edgeCount==1)
	{

				/* Detect falling edge */
				Icu_setEdgeDetectionType(FALLING);
				/* Clear the timer counter register to start measurements from the
				 * first detected rising edge
				 */
				Icu_clearTimerValue();
	}

	else if(g_edgeCount==2)
	{
		/* Store the Period time value + High time value */
	           	g_timeHigh = Icu_getInputCaptureValue();

				/* Detect rising edge */
				Icu_setEdgeDetectionType(RISING);
				Icu_clearTimerValue();

	}
}

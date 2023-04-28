/*
 * ultrasonic.h
 *
 *  Created on: Apr 23, 2023
 *      Author: Ahmed Bahaa
 */

#ifndef HAL_ULTRASONIC_ULTRASONIC_H_
#define HAL_ULTRASONIC_ULTRASONIC_H_


#define TRIGGER_PORT_ID PORTB_ID
#define TRIGGER_PIN_ID PIN5_ID

extern uint8 g_edgeCount;
void Ultrasonic_init(void);
void Ultrasonic_Trigger(void);
uint16 Ultrasonic_readDistance(void);
void Ultrasonic_edgeProcessing(void);


#endif /* HAL_ULTRASONIC_ULTRASONIC_H_ */

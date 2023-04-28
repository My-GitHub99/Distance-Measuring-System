/*
 * app.c
 *
 *  Created on: Apr 23, 2023
 *      Author: Ahmed Bahaa
 */

#include "../HAL/LCD/lcd.h"
#include "../HAL/Ultrasonic/ultrasonic.h"
#include "app.h"
#include <avr/interrupt.h>
#include <util/delay.h> /* For the delay functions */

uint8 g_edgeCount;
uint16 required_distance=0;
void appInit(void)
{
	SREG |= (1<<7); /*enable global intrrupt*/
	LCD_init();
	Ultrasonic_init();

}

void appPrintTemperature(void)
{
	if(g_edgeCount==2)
	{    /*to measure the time between rising and falling*/
		g_edgeCount=0;
		LCD_moveCursor(0,10);    /*to display the distance in this location*/
		LCD_intgerToString((uint32)required_distance);
		required_distance=Ultrasonic_readDistance();
	}
	if(required_distance<10)
	{
		LCD_moveCursor(0,11);
		LCD_displayCharacter(' ');   /*to remove this number in this location*/
	}
	if(required_distance<100)
	{
	LCD_moveCursor(0,12);
	LCD_displayCharacter(' ');          /*to remove this number in this location*/
	}
}

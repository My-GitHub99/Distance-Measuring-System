/*
 * main.c
 *
 *  Created on: Apr 25, 2023
 *      Author: Ahmed Bahaa
 */


#include "./Application/app.h"
#include "./HAL/Ultrasonic/ultrasonic.h"
#include "./HAL/LCD/lcd.h"

uint16 required_distance;
int main()
{
	appInit();
	LCD_displayString("Distance=    cm");
	Ultrasonic_Trigger();
		while(1)
		{
		  appPrintTemperature();
		}


}

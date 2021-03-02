/*
 * helper_gpio.h
 *
 *  Created on: Feb 8, 2021
 *      Author: bmcmahon
 */

#ifndef HELPER_GPIO_H_
#define HELPER_GPIO_H_


#include "gpio.h"

/*
 * user led macros
 */
#define GREEN_LED 		12
#define ORANGE_LED 		13
#define RED_LED 		14
#define BLUE_LED 		15

#define BUTTON_PRESSED	1
#define ENABLE			1
void Delay(void);

void ToggleUserLED(int LEDNumber);
void ToggleAllUserLED();

void PushBtnLed(int LEDNumber);
void PushBtnInterruptLed(int LEDNumber,int IT_MODE);
#endif /* HELPER_GPIO_H_ */

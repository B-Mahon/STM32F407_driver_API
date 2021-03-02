/*
 * helper_gpio.c
 *
 *  Created on: Feb 8, 2021
 *      Author: bmcmahon
 */
#include "helper_gpio.h"

void Delay(void)
{
	for (int i = 0; i < 50000; i++);
}


void ToggleUserLED(int LEDNumber)
{
	GPIO_Handle_t GPIOLed;

	//init peripheral clock
	GPIO_PeriClockControl(GPIOD, ENABLE);

	//configure orange led in output mode
	if (LEDNumber == ORANGE_LED)
	{
		GPIOLed.pGPIOx = GPIOD;
		GPIOLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
		GPIOLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
		GPIOLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
		GPIOLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
		GPIOLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
		GPIO_Init(&GPIOLed);
	}
	//configure green led in output mode
	else if (LEDNumber == GREEN_LED)
	{
		GPIOLed.pGPIOx = GPIOD;
		GPIOLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
		GPIOLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
		GPIOLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
		GPIOLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
		GPIOLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
		GPIO_Init(&GPIOLed);
	}
	//configure red led in output mode
	else if (LEDNumber == RED_LED)
	{
		GPIOLed.pGPIOx = GPIOD;
		GPIOLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
		GPIOLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
		GPIOLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
		GPIOLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
		GPIOLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
		GPIO_Init(&GPIOLed);
	}
	//configure blue led in output mode
	else if (LEDNumber == BLUE_LED)
	{
		GPIOLed.pGPIOx = GPIOD;
		GPIOLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;
		GPIOLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
		GPIOLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
		GPIOLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
		GPIOLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
		GPIO_Init(&GPIOLed);
	}

	while (1)
	{
		Delay();
		GPIO_ToggleOutputPin(GPIOD,GPIOLed.GPIO_PinConfig.GPIO_PinNumber);
	}
}

void ToggleAllUserLED(void)
{
	GPIO_Handle_t GPIOOrangeLed;
	GPIO_Handle_t GPIOGreenLed;
	GPIO_Handle_t GPIORedLed;
	GPIO_Handle_t GPIOBlueLed;

	//init peripheral clock
	GPIO_PeriClockControl(GPIOD, ENABLE);

	//configure orange led in output mode
	GPIOOrangeLed.pGPIOx = GPIOD;
	GPIOOrangeLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	GPIOOrangeLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GPIOOrangeLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	GPIOOrangeLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIOOrangeLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIO_Init(&GPIOOrangeLed);

	//configure green led in output mode
	GPIOGreenLed.pGPIOx = GPIOD;
	GPIOGreenLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GPIOGreenLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GPIOGreenLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	GPIOGreenLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIOGreenLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIO_Init(&GPIOGreenLed);

	//configure red led in output mode
	GPIORedLed.pGPIOx = GPIOD;
	GPIORedLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
	GPIORedLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GPIORedLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	GPIORedLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIORedLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIO_Init(&GPIORedLed);

	//configure blue led in output mode
	GPIOBlueLed.pGPIOx = GPIOD;
	GPIOBlueLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;
	GPIOBlueLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GPIOBlueLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	GPIOBlueLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIOBlueLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIO_Init(&GPIOBlueLed);

	while (1)
	{
		Delay();
		GPIO_ToggleOutputPin(GPIOD,GPIOOrangeLed.GPIO_PinConfig.GPIO_PinNumber);
		GPIO_ToggleOutputPin(GPIOD,GPIOGreenLed.GPIO_PinConfig.GPIO_PinNumber);
		GPIO_ToggleOutputPin(GPIOD,GPIORedLed.GPIO_PinConfig.GPIO_PinNumber);
		GPIO_ToggleOutputPin(GPIOD,GPIOBlueLed.GPIO_PinConfig.GPIO_PinNumber);
	}
}


void PushBtnLed(int LEDNumber)
{
	GPIO_Handle_t GPIOLed;
	GPIO_Handle_t GPIOBtn;
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_PeriClockControl(GPIOA, ENABLE);

	//configure button in input mode
	GPIOBtn.pGPIOx = GPIOA;
	GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	GPIOBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIO_Init(&GPIOBtn);


	//configure orange led in output mode
	if (LEDNumber == ORANGE_LED)
	{
		GPIOLed.pGPIOx = GPIOD;
		GPIOLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
		GPIOLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
		GPIOLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
		GPIOLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
		GPIOLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
		GPIO_Init(&GPIOLed);
	}
	//configure green led in output mode
	else if (LEDNumber == GREEN_LED)
	{
		GPIOLed.pGPIOx = GPIOD;
		GPIOLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
		GPIOLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
		GPIOLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
		GPIOLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
		GPIOLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
		GPIO_Init(&GPIOLed);
	}
	//configure red led in output mode
	else if (LEDNumber == RED_LED)
	{
		GPIOLed.pGPIOx = GPIOD;
		GPIOLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
		GPIOLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
		GPIOLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
		GPIOLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
		GPIOLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
		GPIO_Init(&GPIOLed);
	}
	//configure blue led in output mode
	else if (LEDNumber == BLUE_LED)
	{
		GPIOLed.pGPIOx = GPIOD;
		GPIOLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;
		GPIOLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
		GPIOLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
		GPIOLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
		GPIOLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
		GPIO_Init(&GPIOLed);
	}
		while (1)
		{
			if(GPIO_ReadFromInputPin(GPIOA,0) == BUTTON_PRESSED)
			{
				Delay();
				GPIO_ToggleOutputPin(GPIOD,GPIOLed.GPIO_PinConfig.GPIO_PinNumber);
			}
		}
}



void PushBtnInterruptLed(int LEDNumber, int IT_MODE )
{
GPIO_Handle_t GPIOLed, GPIOBtn;

//clear registers
memset(&GPIOLed,0,sizeof(GPIOLed));
memset(&GPIOBtn,0,sizeof(GPIOBtn));

//enable peripheral clock
GPIOD_PCLK_EN();

//configure orange led in output mode
	if (LEDNumber == ORANGE_LED)
	{
		GPIOLed.pGPIOx = GPIOD;
		GPIOLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
		GPIOLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
		GPIOLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
		GPIOLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
		GPIOLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	}
	//configure green led in output mode
	else if (LEDNumber == GREEN_LED)
	{
		GPIOLed.pGPIOx = GPIOD;
		GPIOLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
		GPIOLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
		GPIOLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
		GPIOLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
		GPIOLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	}
	//configure red led in output mode
	else if (LEDNumber == RED_LED)
	{
		GPIOLed.pGPIOx = GPIOD;
		GPIOLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
		GPIOLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
		GPIOLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
		GPIOLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
		GPIOLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	}
	//configure blue led in output mode
	else if (LEDNumber == BLUE_LED)
	{
		GPIOLed.pGPIOx = GPIOD;
		GPIOLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;
		GPIOLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
		GPIOLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
		GPIOLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
		GPIOLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	}

	GPIO_Init(&GPIOLed);
//enable peripheral clock
GPIO_PeriClockControl(GPIOA,ENABLE);

//initialize pin
GPIOBtn.pGPIOx = GPIOA;
GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
GPIOBtn.GPIO_PinConfig.GPIO_PinMode = IT_MODE;
GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
GPIOBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
GPIO_Init(&GPIOBtn);


GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_12,GPIO_PIN_RESET);

//IRQ configurations
GPIO_IRQPriorityConfig(IRQ_NO_EXTI0,NVIC_IRQ_PRI0);
GPIO_IRQInterruptConfig(IRQ_NO_EXTI0,ENABLE);

while (1);

void EXTI0_IRQHandler(void)
{
   /// delay(); //200ms . wait till button de-bouncing gets over
	GPIO_IRQHandling(GPIO_PIN_NO_0); //clear the pending event from exti line
	GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_12);
}


}






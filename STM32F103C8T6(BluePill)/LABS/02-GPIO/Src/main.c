/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#include "STD_TYPES.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "main.h"


int main(void)
{
	GPIO_app();

	return 0;
}



void GPIO_app(void)
{
	RCC_voidInit();
	GPIO_voidEnableClock(GPIOA);

	GPIO_voidSetPinDirection(GPIOA, GPIO_u8PIN0, GPIO_PIN_OUTPUT_10MHZ_PUSH_PULL);	// PA0
	GPIO_voidSetPinDirection(GPIOA, GPIO_u8PIN1, GPIO_PIN_OUTPUT_10MHZ_PUSH_PULL);	// PA1


    /* Loop forever */
	while(1)		//for(;;);
	{
		Toggle_Green_Led();
		Toggle_Red_Led();
	}
}




void Delay(u32 Copy_u32T_ms)
{
	for(u32 Local_u32Counter = 0; Local_u32Counter < (Copy_u32T_ms * 500); Local_u32Counter++)
	{
		asm("NOP");
	}
}


void Toggle_Green_Led()
{
	//GPIO_voidSetPinValue(GPIOA, GPIO_u8PIN0, GPIO_u8PIN_HIGH);
	GPIO_voidTogglePin(GPIOA, GPIO_u8PIN0);
	Delay(50);
	//GPIO_voidSetPinValue(GPIOA, GPIO_u8PIN0, GPIO_u8PIN_LOW);
	//Delay(100);
}


void Toggle_Red_Led()
{
	GPIO_voidTogglePin(GPIOA, GPIO_u8PIN1);
	Delay(50);

//	GPIO_voidSetPinValue(GPIOA, GPIO_u8PIN1, GPIO_u8PIN_HIGH);
//	Delay(100);
//	GPIO_voidSetPinValue(GPIOA, GPIO_u8PIN1, GPIO_u8PIN_LOW);
//	Delay(100);
}
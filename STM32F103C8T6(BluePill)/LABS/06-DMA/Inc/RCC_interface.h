/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	MCAL				**************************/
/***********************		SWC		:	RCC					**************************/
/***********************		DATE	:	NOV 4, 2023			**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

#define 	RCC_BUS_AHB					1
#define 	RCC_BUS_APB1				3
#define 	RCC_BUS_APB2				6

/* BUS APB2 PERIPHERALS */
#define 	RCC_APB2_TIM11				21
#define 	RCC_APB2_TIM10				20
#define 	RCC_APB2_TIM9				19
#define 	RCC_APB2_ADC3				15
#define 	RCC_APB2_USART1				14
#define 	RCC_APB2_TIM8				13
#define 	RCC_APB2_SPI1				12
#define 	RCC_APB2_TIM1				11
#define 	RCC_APB2_ADC2				10
#define 	RCC_APB2_ADC1				9
#define 	RCC_APB2_GPIOG				8
#define 	RCC_APB2_GPIOF				7
#define 	RCC_APB2_GPIOE				6
#define 	RCC_APB2_GPIOD				5
#define 	RCC_APB2_GPIOC				4
#define 	RCC_APB2_GPIOB				3
#define 	RCC_APB2_GPIOA				2
#define 	RCC_APB2_AFIO				0


/* BUS APB2 PERIPHERALS */
#define 	RCC_APB1_DAC				29
#define 	RCC_APB1_PWR				28
#define 	RCC_APB1_BKP				27
#define 	RCC_APB1_CAN				25
#define 	RCC_APB1_USB				23
#define 	RCC_APB1_I2C2				22
#define 	RCC_APB1_I2C1				21
#define 	RCC_APB1_UART5				20
#define 	RCC_APB1_UART4				19
#define 	RCC_APB1_USART3				18
#define 	RCC_APB1_USART2				17
#define 	RCC_APB1_SPI3				15
#define 	RCC_APB1_SPI2				14
#define 	RCC_APB1_WWDG				11
#define 	RCC_APB1_TIM14				8
#define 	RCC_APB1_TIM13				7
#define 	RCC_APB1_TIM12				6
#define 	RCC_APB1_TIM7				5
#define 	RCC_APB1_TIM6				4
#define 	RCC_APB1_TIM5				3
#define 	RCC_APB1_TIM4				2
#define 	RCC_APB1_TIM3				1
#define 	RCC_APB1_TIM2				0


/* BUS APB2 PERIPHERALS */

#define 	RCC_AHB_SDIO				10
#define 	RCC_AHB_FSMC				8
#define 	RCC_AHB_CRC					6
#define 	RCC_AHB_FLITF				4
#define 	RCC_AHB_SRAM				2
#define 	RCC_AHB_DMA2				1
#define 	RCC_AHB_DMA1				0



#define 	GPIO_u8PIN_LOW				0
#define 	GPIO_u8PIN_HIGH				1


void RCC_voidInit(void);
void RCC_voidEnableClockPeripheral(u8 Copy_u8Bus_ID , u8 Copy_u8Peripheral_ID);
void RCC_voidDisableClockPeripheral(u8 Copy_u8Bus_ID , u8 Copy_u8Peripheral_ID);


#endif /* RCC_INTERFACE_H_ */






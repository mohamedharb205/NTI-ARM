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
#define 	RCC_APB2_TIM11RST			21
#define 	RCC_APB2_TIM10RST			20
#define 	RCC_APB2_TIM9RST			19
#define 	RCC_APB2_ADC3RST			15
#define 	RCC_APB2_USART1RST			14
#define 	RCC_APB2_TIM8RST			13
#define 	RCC_APB2_SPI1RST			12
#define 	RCC_APB2_TIM1RST			11
#define 	RCC_APB2_ADC2RST			10
#define 	RCC_APB2_ADC1RST			9
#define 	RCC_APB2_IOPGRST			8
#define 	RCC_APB2_IOPFRST			7
#define 	RCC_APB2_IOPERST			6
#define 	RCC_APB2_IOPDRST			5
#define 	RCC_APB2_IOPCRST			4
#define 	RCC_APB2_IOPBRST			3
#define 	RCC_APB2_IOPARST			2
#define 	RCC_APB2_AFIORST			0


#define 	GPIO_u8PIN_LOW				0
#define 	GPIO_u8PIN_HIGH				1


void RCC_voidInit(void);
void RCC_voidEnableClockPeripheral(u8 Copy_u8Bus_ID , u8 Copy_u8Peripheral_ID);
void RCC_voidDisableClockPeripheral(u8 Copy_u8Bus_ID , u8 Copy_u8Peripheral_ID);


#endif /* RCC_INTERFACE_H_ */






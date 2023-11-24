/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	MCAL				**************************/
/***********************		SWC		:	GPIO				**************************/
/***********************		DATE	:	NOV 5, 2023			**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/


#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_


/*****		PORTS 		*****/
#define 	GPIOA					0
#define 	GPIOB					1
#define 	GPIOC					2

/*****		 PINS		*****/
#define 	GPIO_u8PIN0				0
#define 	GPIO_u8PIN1				1
#define 	GPIO_u8PIN2				2
#define 	GPIO_u8PIN3				3
#define 	GPIO_u8PIN4				4
#define 	GPIO_u8PIN5				5
#define 	GPIO_u8PIN6				6
#define 	GPIO_u8PIN7				7
#define 	GPIO_u8PIN8				8
#define 	GPIO_u8PIN9				9
#define 	GPIO_u8PIN10			10
#define 	GPIO_u8PIN11			11
#define 	GPIO_u8PIN12			12
#define 	GPIO_u8PIN13			13
#define 	GPIO_u8PIN14			14
#define 	GPIO_u8PIN15			15


/*PINS VALUES*/
#define 	GPIO_u8PIN_LOW			0
#define 	GPIO_u8PIN_HIGH			1

/*PORTS VALUES*/
#define 	GPIO_u16PORT_LOW 	    0x0000	//0b0000000000000000
#define 	GPIO_u16PORT_HIGH		0xFFFF	//0b1111111111111111




/* CONFIGURATION OF PINS AS INPUT */
#define 	GPIO_PIN_INPUT_ANALOG						0b0000
#define 	GPIO_PIN_INPUT_FLOATING						0b0100
#define 	GPIO_PIN_INPUT_PULL_UP_DOWN					0b1000

/* AT 10 MHZ */
#define 	GPIO_PIN_OUTPUT_10MHZ_PUSH_PULL				0b0001
#define 	GPIO_PIN_OUTPUT_10MHZ_OPEN_DRAIN			0b0101
#define 	GPIO_PIN_OUTPUT_10MHZ_AF_PUSH_PULL			0b1001
#define 	GPIO_PIN_OUTPUT_10MHZ_AF_OPEN_DRAIN			0b1101


/* AT 2 MHZ */
#define 	GPIO_PIN_OUTPUT_2MHZ_PUSH_PULL				0b0010
#define 	GPIO_PIN_OUTPUT_2MHZ_OPEN_DRAIN				0b0110
#define 	GPIO_PIN_OUTPUT_2MHZ_AF_PUSH_PULL			0b1010
#define 	GPIO_PIN_OUTPUT_2MHZ_AF_OPEN_DRAIN			0b1110


/* AT 50 MHZ */
#define 	GPIO_PIN_OUTPUT_50MHZ_PUSH_PULL				0b0011
#define 	GPIO_PIN_OUTPUT_50MHZ_OPEN_DRAIN			0b0111
#define 	GPIO_PIN_OUTPUT_50MHZ_AF_PUSH_PULL			0b1011
#define 	GPIO_PIN_OUTPUT_50MHZ_AF_OPEN_DRAIN			0b1111




#define 	ENABLED					1
#define 	DISABLED				2

/*********************************************************************************/
/*****		 The Error State Notification Option can be configured as:		******/
/*****						1- ENABLED			2- DISABLED					******/
/*********************************************************************************/
#define 	GPIO_ERRPR_STATE_NOTIFICATION_OPTION			DISABLED



/**********************************************************************************************/
/**************		FUNCTION PROTOTYPES WITHOUT ERROR STATE NOTIFICATION		***************/
/**********************************************************************************************/
#if		GPIO_ERRPR_STATE_NOTIFICATION_OPTION == DISABLED

		void GPIO_voidEnableClock(u8 Copy_u8Port);
		void GPIO_voidSetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8PinDirection);
		void GPIO_voidSetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8PinValue);
		u8 	 GPIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin);
		void GPIO_voidTogglePin(u8 Copy_u8Port , u8 Copy_u8Pin);

		//void GPIO_voidSetPortDirection(u8 Copy_u8Port , u16 Copy_u16PortDirection);
		//void GPIO_voidSetPortValue(u8 Copy_u8Port , u16 Copy_u16PortValue);
		//void GPIO_voidTogglePort(u8 Copy_u8Port);

/**********************************************************************************************/
/**************		FUNCTION PROTOTYPES WITH ERROR STATE NOTIFICATION		*******************/
/**********************************************************************************************/
#elif	GPIO_ERRPR_STATE_NOTIFICATION_OPTION == ENABLED

		u8 GPIO_u8EnableClock(u8 Copy_u8Port);
		u8 DIO_u8SetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Direction);
		u8 DIO_u8SetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8PinValue);
		u8 DIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8* Copy_pu8Value);
		u8 DIO_u8TogglePin(u8 Copy_u8Port , u8 Copy_u8Pin);

		u8 DIO_u8SetPortDirection(u8 Copy_u8Port , u8 Copy_u8Direction);
		u8 DIO_u8SetPortValue(u8 Copy_u8Port , u8 Copy_u8PortValue);
		u8 DIO_u8TogglePort(u8 Copy_u8Port);
#endif

#endif /* GPIO_INTERFACE_H_ */


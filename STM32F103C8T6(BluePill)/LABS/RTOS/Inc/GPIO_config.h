/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	MCAL				**************************/
/***********************		SWC		:	GPIO				**************************/
/***********************		DATE	:	NOV 5, 2023			**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/


#ifndef GPIO_CONFIG_H_
#define GPIO_CONFIG_H_


//#define 	GPIO_PORT_DIRECTION_MASK			0b0000
/* Valid for low and high pins */
#define 	GPIO_PIN_DIRECTION_MASK				0b1111
#define 	GPIO_PORT_DIRECTION_MASK			0b11111111111111111111111111111111

/* Complete the masks for all situations input push pull , ..................*/


//#define 	GPIO_PORTA_INPUT_ANALOG					0b00000000 00000000 00000000 00000000
//#define 	GPIO_PORTA_INPUT_FLOATING				0b00000000 00000000 00000000 00000001
//#define 	GPIO_PORTA_INPUT_PULL_UP_DOWN			0b00000000 00000000 00000000 00000010
//
//#define 	GPIO_PORTB_INPUT_ANALOG					0b00000000 00000000 00000000 00000000
//#define 	GPIO_PORTB_INPUT_FLOATING				0b00000000 00000000 00000000 00010000
//#define 	GPIO_PORTB_INPUT_PULL_UP_DOWN			0b00000000 00000000 00000000 00100000
//
//#define 	GPIO_PORTC_INPUT_ANALOG					0b00000000 00000000 00000000 00000000
//#define 	GPIO_PORTC_INPUT_FLOATING				0b00000000 00000000 00000001 00000000
//#define 	GPIO_PORTC_INPUT_PULL_UP_DOWN			0b00000000 00000000 00000010 00000000


/* CONFIGURATION OF PINS AS OUTPUT */
/* AT 10 MHZ */
//#define 	GPIO_PORTA_OUTPUT_PUSH_PULL				0b00000000 00000000 00000000 00000001
//#define 	GPIO_PORTA_OUTPUT_OPEN_DRAIN			0b00000000 00000000 00000000 00000101
//#define 	GPIO_PORTA_OUTPUT_AF_PUSH_PULL			0b00000000 00000000 00000000 00001001
//#define 	GPIO_PORTA_OUTPUT_AF_OPEN_DRAIN			0b00000000 00000000 00000000 00001101
//
//#define 	GPIO_PORTA_OUTPUT_PUSH_PULL				0b00000000 00000000 00000000 00010000
//#define 	GPIO_PORTA_OUTPUT_OPEN_DRAIN			0b00000000 00000000 00000000 01010000
//#define 	GPIO_PORTA_OUTPUT_AF_PUSH_PULL			0b00000000 00000000 00000000 10010000
//#define 	GPIO_PORTA_OUTPUT_AF_OPEN_DRAIN			0b00000000 00000000 00000000 11010000
//
//#define 	GPIO_PORTA_OUTPUT_PUSH_PULL				0b00000000 00000000 00000001 00000000
//#define 	GPIO_PORTA_OUTPUT_OPEN_DRAIN			0b00000000 00000000 00000101 00000000
//#define 	GPIO_PORTA_OUTPUT_AF_PUSH_PULL			0b00000000 00000000 00001001 00000000
//#define 	GPIO_PORTA_OUTPUT_AF_OPEN_DRAIN			0b00000000 00000000 00001101 00000000

#endif /* GPIO_CONFIG_H_ */

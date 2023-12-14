/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	MCAL				**************************/
/***********************		SWC		:	GPIO				**************************/
/***********************		DATE	:	NOV 5, 2023			**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "GPIO_register.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

#include "RCC_interface.h"



#if		GPIO_ERRPR_STATE_NOTIFICATION_OPTION == DISABLED

		void GPIO_voidEnableClock(u8 Copy_u8Port)
		{
			switch(Copy_u8Port)
			{
				case GPIOA	:		RCC_voidEnableClockPeripheral(RCC_BUS_APB2, RCC_APB2_GPIOA);		break;	// activate the RCC for GPIOA
				case GPIOB	:		RCC_voidEnableClockPeripheral(RCC_BUS_APB2, RCC_APB2_GPIOB);		break;	// activate the RCC for GPIOB
				case GPIOC	:		RCC_voidEnableClockPeripheral(RCC_BUS_APB2, RCC_APB2_GPIOC);		break;	// activate the RCC for GPIOC
				default		:																			break;
			}
		}




		/********************************************************************************************************************/
		/*	Function: GPIO_voidSetPinDirection																				*/
		/*	Description: Sets the direction (input/output) of a specific pin within a port.									*/
		/*	Parameters:																										*/
		/*		- Copy_u8Port: The port to set the pin direction for (GPIO_u8PORTA, GPIO_u8PORTB, GPIO_u8PORTC).			*/
		/*		- Copy_u8Pin: The pin number (0-7) within the port.															*/
		/*		- Copy_u8PinDirection: The desired direction (GPIO_u8PIN_OUTPUT or GPIO_u8PIN_INPUT).						*/
		/********************************************************************************************************************/
		void GPIO_voidSetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8PinDirection)
		{
			if(( Copy_u8Port >= MIN_PORT && Copy_u8Port <= MAX_PORT) && ( Copy_u8Pin >= MIN_PIN && Copy_u8Pin <= MAX_PIN))
			{
				switch(Copy_u8Port)
				{
					case GPIOA :
						/* LOWER PINS */
						if(Copy_u8Pin <= GPIO_u8PIN7)
						{
							GPIOA_CRL &= ~((GPIO_PIN_DIRECTION_MASK << (Copy_u8Pin * 4)));
							GPIOA_CRL |= (Copy_u8PinDirection<< (Copy_u8Pin * 4));
						}
						/* HIGHER PINS */
						else if(Copy_u8Pin > GPIO_u8PIN7)
						{
							GPIOA_CRH &= ~((GPIO_PIN_DIRECTION_MASK << (Copy_u8Pin * 4)));
							GPIOA_CRH |= (Copy_u8PinDirection<< (Copy_u8Pin * 4));
						}
						break;

					case GPIOB :
						if(Copy_u8Pin <= GPIO_u8PIN7)
						{
							GPIOB_CRL &= ~((GPIO_PIN_DIRECTION_MASK << (Copy_u8Pin * 4)));
							GPIOB_CRL |= (Copy_u8PinDirection<< (Copy_u8Pin * 4));
						}
						else if(Copy_u8Pin > GPIO_u8PIN7)
						{
							GPIOB_CRH &= ~((GPIO_PIN_DIRECTION_MASK << (Copy_u8Pin * 4)));
							GPIOB_CRH |= (Copy_u8PinDirection<< (Copy_u8Pin * 4));
						}
						break;

					case GPIOC :
						if(Copy_u8Pin <= GPIO_u8PIN7)
						{
							GPIOC_CRL &= ~((GPIO_PIN_DIRECTION_MASK << (Copy_u8Pin * 4)));
							GPIOC_CRL |= (Copy_u8PinDirection<< (Copy_u8Pin * 4));
						}
						else if(Copy_u8Pin > GPIO_u8PIN7)
						{
							GPIOC_CRH &= ~((GPIO_PIN_DIRECTION_MASK << (Copy_u8Pin * 4)));
							GPIOC_CRH |= (Copy_u8PinDirection<< (Copy_u8Pin * 4));
						}
						break;

					default : break;
				}
			}
		}


		/************************************************************************************************************************/
		/*    Function: GPIO_voidSetPinValue																						*/
		/*    Description: Sets the value (high/low) of a specific pin within a port.											*/
		/*    Parameters:																										*/
		/*        - Copy_u8Port: The port to set the pin value for (GPIO_u8PORTA, GPIO_u8PORTB, GPIO_u8PORTC, GPIO_u8PORTD).		*/
		/*        - Copy_u8Pin: The pin number (0-7) within the port.															*/
		/*        - Copy_u8PinValue: The desired value (GPIO_u8PIN_HIGH or GPIO_u8PIN_LOW).										*/
		/************************************************************************************************************************/
		void GPIO_voidSetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8PinValue)
		{
			if(( Copy_u8Port >= MIN_PORT && Copy_u8Port <= MAX_PORT) && ( Copy_u8Pin >= MIN_PIN && Copy_u8Pin <= MAX_PIN))
			{
				if(Copy_u8PinValue == GPIO_u8PIN_HIGH)
				{
					switch(Copy_u8Port)
					{
						case GPIOA:  SET_BIT(GPIOA_ODR , Copy_u8Pin); 	break;
						case GPIOB:  SET_BIT(GPIOB_ODR , Copy_u8Pin); 	break;
						case GPIOC:  SET_BIT(GPIOC_ODR , Copy_u8Pin); 	break;
						default       	:  										break;
					}
				}
				else if(Copy_u8PinValue == GPIO_u8PIN_LOW)
				{
					switch(Copy_u8Port)
					{
						case GPIOA:  CLR_BIT(GPIOA_ODR , Copy_u8Pin); 	break;
						case GPIOB:  CLR_BIT(GPIOB_ODR , Copy_u8Pin); 	break;
						case GPIOC:  CLR_BIT(GPIOC_ODR , Copy_u8Pin); 	break;
						default       	:  										break;
					}
				}
			}
		}


		/****************************************************************************************************************************/
		/*    Function: GPIO_voidTogglePin																							*/
		/*    Description: Toggles the value of a specific pin within a port.														*/
		/*    Parameters:																											*/
		/*        - Copy_u8Port: The port containing the pin to be toggled (GPIO_u8PORTA, GPIO_u8PORTB, GPIO_u8PORTC, GPIO_u8PORTD).	*/
		/*        - Copy_u8Pin: The pin number (0-7) to be toggled.																	*/
		/****************************************************************************************************************************/
		void GPIO_voidTogglePin(u8 Copy_u8Port , u8 Copy_u8Pin)
		{
			if(( Copy_u8Port >= MIN_PORT && Copy_u8Port <= MAX_PORT) && ( Copy_u8Pin >= MIN_PIN && Copy_u8Pin <= MAX_PIN))
			{
				switch (Copy_u8Port)
				{
					case GPIOA 	: 	TOG_BIT(GPIOA_ODR , Copy_u8Pin); 		break ;
					case GPIOB 	: 	TOG_BIT(GPIOB_ODR , Copy_u8Pin); 		break ;
					case GPIOC 	: 	TOG_BIT(GPIOC_ODR , Copy_u8Pin); 		break ;
					default		: 								 			break ;
				}
			}
			else
			{
				// Do Nothing
			}
		}


		/********************************************************************************************************************/
		/*    Function: GPIO_u8GetPinValue																					*/
		/*    Description: Reads the value of a specific pin within a port.													*/
		/*    Parameters:																									*/
		/*        - Copy_u8Port: The port to read the pin value from (GPIO_u8PORTA, GPIO_u8PORTB, GPIO_u8PORTC, GPIO_u8PORTD).	*/
		/*        - Copy_u8Pin: The pin number (0-7) within the port.														*/
		/*    Returns: The value of the pin (GPIO_u8PIN_HIGH or GPIO_u8PIN_LOW).												*/
		/********************************************************************************************************************/
		u8 	 GPIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin)
		{
			if(( Copy_u8Port >= MIN_PORT && Copy_u8Port <= MAX_PORT) && ( Copy_u8Pin >= MIN_PIN && Copy_u8Pin <= MAX_PIN))
			{
				u8 Local_u8PinValue;

				switch(Copy_u8Port)
				{
					case GPIOA: 	Local_u8PinValue = GET_BIT(GPIOA_IDR , Copy_u8Pin); 		break;
					case GPIOB: 	Local_u8PinValue = GET_BIT(GPIOA_IDR , Copy_u8Pin); 		break;
					case GPIOC: 	Local_u8PinValue = GET_BIT(GPIOA_IDR , Copy_u8Pin); 		break;
					default   : 																break;
				}
				return Local_u8PinValue;
			}

			else
			{
				return	-1;
			}
		}





//
//		/****************************************************************************************************************/
//		/*   Function: GPIO_voidSetPortDirection																			*/
//		/*   Description: Sets the direction (input/output) of an entire port.											*/
//		/*   Parameters:																								*/
//		/*        - Copy_u8Port: The port to set the direction for (GPIO_u8PORTA, GPIO_u8PORTB, GPIO_u8PORTC, GPIO_u8PORTD).*/
//		/*        - Copy_u8Direction: The desired direction (GPIO_PORT_OUTPUT or GPIO_PORT_INPUT).						*/
//		/****************************************************************************************************************/
//		void GPIO_voidSetPortDirection(u8 Copy_u8Port , u8 Copy_u8Direction)
//		{
//			if( Copy_u8Port >= MIN_PORT && Copy_u8Port <= MAX_PORT )
//			{
//				switch(Copy_u8Port)
//				{
//					case GPIO_u8PORTA:  DDRA = Copy_u8Direction; 		break;
//					case GPIO_u8PORTB:  DDRB = Copy_u8Direction; 		break;
//					case GPIO_u8PORTC:  DDRC = Copy_u8Direction; 		break;
//					case GPIO_u8PORTD:  DDRD = Copy_u8Direction; 		break;
//					default       :  									break;
//				}
//			}
//		}
//
//
//
//
//
//		/****************************************************************************************************************/
//		/*    Function: GPIO_voidSetPortValue																			*/
//		/*    Description: Sets the value (high/low) of an entire port.													*/
//		/*    Parameters:																								*/
//		/*        - Copy_u8Port: The port to set the value for (GPIO_u8PORTA, GPIO_u8PORTB, GPIO_u8PORTC, GPIO_u8PORTD).	*/
//		/*        - Copy_u8PortVALUE: The desired value (GPIO_u8PORT_HIGH or GPIO_u8PORT_LOW).							*/
//		/****************************************************************************************************************/
//		void GPIO_voidSetPortValue(u8 Copy_u8Port , u8 Copy_u8PortValue)
//		{
//			if( Copy_u8Port >= MIN_PORT && Copy_u8Port <= MAX_PORT )
//			{
//				switch(Copy_u8Port)
//				{
//					case GPIO_u8PORTA:  	PORTA = Copy_u8PortValue; 		break;
//					case GPIO_u8PORTB:  	PORTB = Copy_u8PortValue; 		break;
//					case GPIO_u8PORTC:  	PORTC = Copy_u8PortValue; 		break;
//					case GPIO_u8PORTD:  	PORTD = Copy_u8PortValue; 		break;
//					default       	: 									break;
//				}
//			}
//		}
//
//
//
//
//
//
//
//
//
//		/****************************************************************************************************************************/
//		/*    Function: GPIO_voidTogglePort																							*/
//		/*    Description: Toggles the values of the entire port.																	*/
//		/*    Parameters:																											*/
//		/*        - Copy_u8Port: The port containing the pins to be toggled (GPIO_u8PORTA, GPIO_u8PORTB, GPIO_u8PORTC, GPIO_u8PORTD).	*/
//		/****************************************************************************************************************************/
//		void GPIO_voidTogglePort(u8 Copy_u8Port)
//		{
//			if( Copy_u8Port >= MIN_PORT && Copy_u8Port <= MAX_PORT )
//			{
//				switch (Copy_u8Port)
//				{
//					case GPIO_u8PORTA : 	TOG_REG(PORTA , GPIO_u8PORT_HIGH); 		break ;
//					case GPIO_u8PORTB : 	TOG_REG(PORTB , GPIO_u8PORT_HIGH); 		break ;
//					case GPIO_u8PORTC : 	TOG_REG(PORTC , GPIO_u8PORT_HIGH); 		break ;
//					case GPIO_u8PORTD :	TOG_REG(PORTD , GPIO_u8PORT_HIGH); 		break ;
//					default 	     :	 										break ;
//				}
//			}
//		}


#elif	GPIO_ERRPR_STATE_NOTIFICATION_OPTION == ENABLED

		u8 GPIO_voidSetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Direction)
		{
			u8 Local_u8ErrorState = OK;

			if(Copy_u8Pin >= MIN_PIN && Copy_u8Pin <= MAX_PIN )	// Check PINS
			{
				if(Copy_u8Direction == GPIO_u8PIN_OUTPUT)
				{
					switch(Copy_u8Port)
					{
						case GPIO_u8PORTA:  SET_BIT(DDRA , Copy_u8Pin); 	break;
						case GPIO_u8PORTB:  SET_BIT(DDRB , Copy_u8Pin); 	break;
						case GPIO_u8PORTC:  SET_BIT(DDRC , Copy_u8Pin); 	break;
						case GPIO_u8PORTD:  SET_BIT(DDRD , Copy_u8Pin); 	break;
						default       	:  Local_u8ErrorState = NOK;	break;	// Check PINS
					}
				}
				else if(Copy_u8Direction == GPIO_u8PIN_INPUT)
				{
					switch(Copy_u8Port)
					{
						case GPIO_u8PORTA:  CLR_BIT(DDRA , Copy_u8Pin); 	break;
						case GPIO_u8PORTB:  CLR_BIT(DDRB , Copy_u8Pin); 	break;
						case GPIO_u8PORTC:  CLR_BIT(DDRC , Copy_u8Pin); 	break;
						case GPIO_u8PORTD:  CLR_BIT(DDRD , Copy_u8Pin); 	break;
						default       	:  Local_u8ErrorState = NOK;	break;	// Check PORTS
					}
				}
				else /*Direction is not OUTPUT nor INPUT*/
				{
					Local_u8ErrorState = NOK;
				}
			}
			else /*Wrong PIN*/
			{
				Local_u8ErrorState = NOK;
			}

			return Local_u8ErrorState;
		}


		u8 GPIO_voidSetPortDirection(u8 Copy_u8Port , u8 Copy_u8Direction)
		{
			u8 Local_u8ErrorState = OK;

			switch(Copy_u8Port)
			{
				case GPIO_u8PORTA:  DDRA = Copy_u8Direction; 	break;
				case GPIO_u8PORTB:  DDRB = Copy_u8Direction; 	break;
				case GPIO_u8PORTC:  DDRC = Copy_u8Direction; 	break;
				case GPIO_u8PORTD:  DDRD = Copy_u8Direction; 	break;
				default       	:  Local_u8ErrorState = NOK;	break;	/*Wrong PORT*/
			}

			return Local_u8ErrorState;
		}


		u8 GPIO_voidSetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8PinValue)
		{
			u8 Local_u8ErrorState = OK;

			if(Copy_u8Pin >= MIN_PIN && Copy_u8Pin <= MAX_PIN )	// Check PINS
			{
				if(Copy_u8PinValue == GPIO_u8PIN_HIGH)
				{
					switch(Copy_u8Port)
					{
						case GPIO_u8PORTA:  SET_BIT(PORTA , Copy_u8Pin); 	break;
						case GPIO_u8PORTB:  SET_BIT(PORTB , Copy_u8Pin); 	break;
						case GPIO_u8PORTC:  SET_BIT(PORTC , Copy_u8Pin); 	break;
						case GPIO_u8PORTD:  SET_BIT(PORTD , Copy_u8Pin); 	break;
						default       	:  Local_u8ErrorState = NOK;	break;	// Check PINS
					}
				}
				else if(Copy_u8PinValue == GPIO_u8PIN_LOW)
				{
					switch(Copy_u8Port)
					{
						case GPIO_u8PORTA:  CLR_BIT(PORTA , Copy_u8Pin); 	break;
						case GPIO_u8PORTB:  CLR_BIT(PORTB , Copy_u8Pin); 	break;
						case GPIO_u8PORTC:  CLR_BIT(PORTC , Copy_u8Pin); 	break;
						case GPIO_u8PORTD:  CLR_BIT(PORTD , Copy_u8Pin); 	break;
						default       	:  Local_u8ErrorState = NOK;	break;	// Check PORTS
					}
				}
				else /*VALUE is not Valid*/
				{
					Local_u8ErrorState = NOK;
				}
			}
			else /*Wrong PIN*/
			{
				Local_u8ErrorState = NOK;
			}

			return Local_u8ErrorState;
		}



		u8 GPIO_voidSetPortValue(u8 Copy_u8Port , u8 Copy_u8PortValue)
		{
			u8 Local_u8ErrorState = OK;

			switch(Copy_u8Port)
			{
				case GPIO_u8PORTA:  PORTA = Copy_u8PortValue; 	break;
				case GPIO_u8PORTB:  PORTB = Copy_u8PortValue; 	break;
				case GPIO_u8PORTC:  PORTC = Copy_u8PortValue; 	break;
				case GPIO_u8PORTD:  PORTD = Copy_u8PortValue; 	break;
				default       	:  Local_u8ErrorState = NOK;	break;	/*Wrong PORT*/
			}

			return Local_u8ErrorState;
		}



		u8 GPIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8* Copy_pu8Value)
		{
			u8 Local_u8ErrorState = OK;

			if((Copy_u8Pin >= MIN_PIN && Copy_u8Pin <= MAX_PIN) && (Copy_pu8Value != NULL))	// Check PINS and Pointer
			{
				switch(Copy_u8Port)
				{
					case GPIO_u8PORTA:  		*Copy_pu8Value = GET_BIT(PINA , Copy_u8Pin); 	break;
					case GPIO_u8PORTB:  		*Copy_pu8Value = GET_BIT(PINB , Copy_u8Pin); 	break;
					case GPIO_u8PORTC:  		*Copy_pu8Value = GET_BIT(PINC , Copy_u8Pin); 	break;
					case GPIO_u8PORTD:  		*Copy_pu8Value = GET_BIT(PIND , Copy_u8Pin); 	break;
					default       	:  		Local_u8ErrorState = NOK;						break;	// Check PINS
				}
			}
			else /*Wrong PIN*/
			{
				Local_u8ErrorState = NOK;
			}

			return Local_u8ErrorState;
		}



		u8 GPIO_voidTogglePin(u8 Copy_u8Port , u8 Copy_u8Pin)
		{
			u8 Local_u8ErrorState = OK;

			if(Copy_u8Pin >= MIN_PIN && Copy_u8Pin <= MAX_PIN )	// Check PINS
			{
				switch(Copy_u8Port)
				{
					case GPIO_u8PORTA:  TOG_BIT(PORTA , Copy_u8Pin); 	break;
					case GPIO_u8PORTB:  TOG_BIT(PORTB , Copy_u8Pin); 	break;
					case GPIO_u8PORTC:  TOG_BIT(PORTC , Copy_u8Pin); 	break;
					case GPIO_u8PORTD:  TOG_BIT(PORTD , Copy_u8Pin); 	break;
					default       	:  Local_u8ErrorState = NOK;		break;	// Check PINS
				}
			}
			else /*Wrong PIN*/
			{
				Local_u8ErrorState = NOK;
			}

			return Local_u8ErrorState;
		}



		u8 GPIO_voidTogglePort(u8 Copy_u8Port)
		{
			u8 Local_u8ErrorState = OK;

			switch(Copy_u8Port)
			{
				case GPIO_u8PORTA:  TOG_REG(PORTA , Copy_u8Port); 	break;
				case GPIO_u8PORTB:  TOG_REG(PORTB , Copy_u8Port); 	break;
				case GPIO_u8PORTC:  TOG_REG(PORTC , Copy_u8Port); 	break;
				case GPIO_u8PORTD:  TOG_REG(PORTD , Copy_u8Port); 	break;
				default       	:  Local_u8ErrorState = NOK;		break;	/*Wrong PORT*/
			}

			return Local_u8ErrorState;
		}

#endif




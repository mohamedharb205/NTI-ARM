/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	MCAL				**************************/
/***********************		SWC		:	RCC					**************************/
/***********************		DATE	:	NOV 4, 2023			**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "RCC_register.h"
#include "RCC_private.h"
#include "RCC_config.h"



void RCC_voidInit(void)
{
	#if		RCC_CLOCK_SOURCE == RCC_HSI
			/* System Clock Switch */
			CLR_BIT(RCC_CFGR , RCC_CFGR_SW0);
			CLR_BIT(RCC_CFGR , RCC_CFGR_SW1);

			/* Enable the External Clock for RCC */
			SET_BIT(RCC_CR , RCC_CR_HSION);

			/* Check for the flag of Internal Clock Enable ... Polling */
			while(GET_BIT(RCC_CR , RCC_CR_HSIRDY) == 0);		// NOTE: This bit is read only, So I can not clear the flag

	#elif	RCC_CLOCK_SOURCE == RCC_HSE
			/* System Clock Switch */
			SET_BIT(RCC_CFGR , RCC_CFGR_SW0);
			CLR_BIT(RCC_CFGR , RCC_CFGR_SW1);

			/* Enable the External Clock for RCC */
			SET_BIT(RCC_CR , RCC_CR_HSEON);

			/* Check for the flag of External Clock Enable ... Polling */
			while(GET_BIT(RCC_CR , RCC_CR_HSERDY) == 0);		// NOTE: This bit is read only, So I can not clear the flag

	#elif	RCC_CLOCK_SOURCE == RCC_PLL
			/* System Clock Switch */
			CLR_BIT(RCC_CFGR , RCC_CFGR_SW0);
			SET_BIT(RCC_CFGR , RCC_CFGR_SW1);

			/* Enable the External Clock for RCC */
			SET_BIT(RCC_CR , RCC_CR_PLLON);

			/* Check for the flag of Internal Clock Enable ... Polling */
			while(GET_BIT(RCC_CR , RCC_CR_PLLRDY) == 0);		// NOTE: This bit is read only, So I can not clear the flag

	#else
		#error "INVALID RCC CLOCK SOURCE"
	#endif
}


void RCC_voidEnableClockPeripheral(u8 Copy_u8Bus_ID , u8 Copy_u8Peripheral_ID)
{
	if (Copy_u8Peripheral_ID < 32)
	{
		switch(Copy_u8Bus_ID)
		{
			case RCC_BUS_AHB  	:	SET_BIT(RCC_AHBENR, Copy_u8Peripheral_ID); 			break;
			case RCC_BUS_APB2 	:	SET_BIT(RCC_APB2ENR, Copy_u8Peripheral_ID); 		break;
			case RCC_BUS_APB1 	:	SET_BIT(RCC_APB1ENR, Copy_u8Peripheral_ID); 		break;
			default				:														break;
		}
	}
	else
	{
		// Do nothing
	}
}


void RCC_voidDisableClockPeripheral(u8 Copy_u8Bus_ID , u8 Copy_u8Peripheral_ID)
{
	if (Copy_u8Peripheral_ID < 32)
	{
		switch(Copy_u8Bus_ID)
		{
			case RCC_BUS_AHB  	:	CLR_BIT(RCC_AHBENR, Copy_u8Peripheral_ID); 			break;
			case RCC_BUS_APB2 	:	CLR_BIT(RCC_APB2ENR, Copy_u8Peripheral_ID); 		break;
			case RCC_BUS_APB1 	:	CLR_BIT(RCC_APB1ENR, Copy_u8Peripheral_ID); 		break;
			default				:														break;
		}
	}
	else
	{
		// Do nothing
	}
}




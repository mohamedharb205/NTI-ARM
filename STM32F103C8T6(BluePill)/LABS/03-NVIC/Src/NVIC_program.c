/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	MCAL				**************************/
/***********************		SWC		:	NVIC				**************************/
/***********************		DATE	:	NOV 06, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "NVIC_interface.h"
#include "NVIC_register.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


void NVIC_voidInit(void)
{
	/* Number of groups and number of subgroups */
	#ifndef SCB_AIRCR
	#define SCB_AIRCR		 *((volatile u32*)(0xE000ED00 + 0x0C))	// Application interrupt and reset control register
	#endif

	/* CONFIGURE THE NUMBER OF GROUPS AND SUBGROUPS AT THE CONFIGURATION FILE */
	SCB_AIRCR = PRIORITY_GROUPING;
}


void NVIC_voidEnableInterrupt(u8 Copy_u8InterruptNumber)
{
	/* Range Check */
	if(Copy_u8InterruptNumber < 32)		// you can access this register and the next by defining the register as 64 bits
	{
		NVIC_ISER0 = (1 << (Copy_u8InterruptNumber));
	}
	else if(Copy_u8InterruptNumber < 64)
	{
		NVIC_ISER1 = (1 << (Copy_u8InterruptNumber - 32));
	}
	else if(Copy_u8InterruptNumber < 81)
	{
		NVIC_ISER2 = (1 << (Copy_u8InterruptNumber - 64));
	}
}


void NVIC_voidDisableInterrupt(u8 Copy_u8InterruptNumber)
{
	if(Copy_u8InterruptNumber < 32)		// you can access this register and the next by defining the register as 64 bits
	{
		NVIC_ICER0 = (1 << (Copy_u8InterruptNumber));
	}
	else if(Copy_u8InterruptNumber < 64)
	{
		NVIC_ICER1 = (1 << (Copy_u8InterruptNumber - 32));
	}
	else if(Copy_u8InterruptNumber < 81)
	{
		NVIC_ICER2 = (1 << (Copy_u8InterruptNumber - 64));
	}
}


void NVIC_voidSetPendingFlag(u8 Copy_u8InterruptNumber)
{
	if(Copy_u8InterruptNumber < 32)		// you can access this register and the next by defining the register as 64 bits
	{
		NVIC_ISPR0 = (1 << Copy_u8InterruptNumber);
	}
	else if(Copy_u8InterruptNumber < 64)
	{
		Copy_u8InterruptNumber -= 32;
		NVIC_ISPR1 = (1 << Copy_u8InterruptNumber);
	}
	else if(Copy_u8InterruptNumber < 81)
	{
		NVIC_ISPR2 = (1 << (Copy_u8InterruptNumber - 64));
	}
}


void NVIC_voidClearPendingFlag(u8 Copy_u8InterruptNumber)
{
	if(Copy_u8InterruptNumber < 32)		// you can access this register and the next by defining the register as 64 bits
	{
		NVIC_ICPR0 = (1 << (Copy_u8InterruptNumber));
	}
	else if(Copy_u8InterruptNumber < 64)
	{
		NVIC_ICPR1 = (1 << (Copy_u8InterruptNumber - 32));
	}
	else if(Copy_u8InterruptNumber < 81)
	{
		NVIC_ICPR2 = (1 << (Copy_u8InterruptNumber - 64));
	}
}


u8 NVIC_u8GetActiveFlag(u8 Copy_u8InterruptNumber)
{
	u8 Local_u8FlagValue;
	if(Copy_u8InterruptNumber < 32)		// you can access this register and the next by defining the register as 64 bits
	{
		Local_u8FlagValue = GET_BIT(NVIC_IABR0 , Copy_u8InterruptNumber);
	}
	else if(Copy_u8InterruptNumber < 64)
	{
		Local_u8FlagValue = GET_BIT(NVIC_IABR1 , (Copy_u8InterruptNumber - 32));
	}
	else if(Copy_u8InterruptNumber < 81)
	{
		Local_u8FlagValue = GET_BIT(NVIC_IABR2 , (Copy_u8InterruptNumber - 64));
	}

	return Local_u8FlagValue;
}



//void NVIC_voidSetInterruptPriority(u8 Copy_u8InterruptNumber , u8 Copy_u8Priority)
//{
//	if(Copy_u8InterruptNumber < 81)
//	{
//		NVIC_IPR[Copy_u8InterruptNumber] = Copy_u8Priority << 4;
//	}
//}



void NVIC_voidSetInterruptPriority(u8 Copy_u8InterruptNumber, u8 Copy_u8Group, u8 Copy_u8Sub)
{
	u8 priority = 0;

	#if 	PRIORITY_GROUPING == GROUPS_16_SUBGROUPS_00
			priority = Copy_u8Group;
	#elif 	PRIORITY_GROUPING == GROUPS_08_SUBGROUPS_02
			priority = (Copy_u8Group<<1) | Copy_u8Sub;
	#elif 	PRIORITY_GROUPING == GROUPS_04_SUBGROUPS_04
			priority = (Copy_u8Group<<2) | Copy_u8Sub;
	#elif 	PRIORITY_GROUPING == GROUPS_02_SUBGROUPS_08
			priority = (Copy_u8Group<<3) | Copy_u8Sub;
	#elif	 PRIORITY_GROUPING == GROUPS_00_SUBGROUPS_16
			priority = Copy_u8Sub;
	#endif

	if(Copy_u8InterruptNumber < 81)
	{
		//NVIC_IPR[Copy_u8InterruptNumber] = (priority << 4);
		NVIC_IPR[Copy_u8InterruptNumber] = priority << 4;
	}
}

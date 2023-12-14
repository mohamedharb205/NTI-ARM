/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	MCAL				**************************/
/***********************		SWC		:	FPEC				**************************/
/***********************		DATE	:	NOV 20, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/


#include "../Inc/STD_TYPES.h"
#include "../Inc/BIT_MATH.h"

#include "../Inc/RCC_interface.h"
#include "../Inc/FPEC_interface.h"
#include "../Inc/FPEC_register.h"
#include "../Inc/FPEC_private.h"
#include "../Inc/FPEC_config.h"




void FPEC_vidEnableClock(void)
{
	//RCC_vidEnableClock(RCC_BUS_AHB, RCC_
	//RCC_vidEnableClock(RCC_AHB, FLITFEN);
}



void FPEC_voidEraseFlashArea(u8 Copy_u8StartPage, u8 Copy_u8EndPage)
{
	u8 Local_u8Counter;

	for (Local_u8Counter = Copy_u8StartPage; Local_u8Counter < copy_u8EndPage; Local_u8Counter++)
	{
		FPEC_voidEraseFlashPage(Local_u8Counter);
	}
}



void FPEC_voidEraseFlashPage(u8 Copy_u8PageNumber)
{
	/* 1- Wait Busy Flag */
	while (GET_BIT(FPEC->SR , 0) == 1);

	/* 2- Check if FPEC is locked or not */
	if (GET_BIT(FPEC->CR , 7) == 1)
	{
		FPEC->KEYR = 0x45670123;
		FPEC->KEYR = 0xCDEF89AB;
	}

	/* 3- Page Erase Operation */
	SET_BIT(FPEC->CR , 1);

	/* 4- Write Page address */
	FPEC->AR = (u32)(Copy_u8PageNumber * 1024) + FLASH_BASE_ADDRESS;

	/* 5- Start Operation */
	SET_BIT(FPEC->CR , 6);

	/* 6- Wait Busy Flag */
	while (GET_BIT(FPEC->SR , 0) == 1);

	/* 7- EOP */
	SET_BIT(FPEC->SR , 5);
	CLR_BIT(FPEC->CR , 1);
}



void FPEC_voidWriteFlash(u32 Copy_u32Address, u16* Copy_pu16Data, u8 Copy_u8Length)
{
	u8 Local_u8Counter;
	volatile u16 Local_u16TempData;

	/* 1- Wait Busy Flag */
	while (GET_BIT(FPEC->SR , 0) == 1);

	/* 2- Check if FPEC is locked or not */
	if (/* FPEC_CR->BitAccess.LOCK == 1 */ GET_BIT(FPEC->CR , 7) == 1)
	{
		FPEC -> KEYR = 0x45670123;
		FPEC -> KEYR = 0xCDEF89AB;
	}

	for (Local_u8Counter = 0; Local_u8Counter < Copy_u8Length; Local_u8Counter++)
	{
		/* 3- Write Flash Programming */
		SET_BIT(FPEC->CR , 0);

		/* 4- Half word operation */
		Local_u16TempData = Copy_pu16Data[Local_u8Counter];
		*((volatile u16*)Copy_u32Address) = Local_u16TempData;
		Copy_u32Address += 2;

		/* 5- Wait Busy Flag */
		while (GET_BIT(FPEC->SR , 0) == 1);

		/* 6- EOP */
		SET_BIT(FPEC->SR , 5);
		CLR_BIT(FPEC->CR , 0);
	}
}




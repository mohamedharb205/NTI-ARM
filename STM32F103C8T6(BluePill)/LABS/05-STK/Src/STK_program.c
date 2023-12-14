/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	MCAL				**************************/
/***********************		SWC		:	STK 				**************************/
/***********************		DATE	:	NOV 07, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_register.h"
#include "STK_private.h"
#include "STK_config.h"


static void (*STK_CallbackPtr) (void) = NULL;	/* Define CallBack Global Variable */
static u8 STK_u8ModeOfInterval;					/* Define Variable for interval Mode */


void	STK_voidInit()
{
	/* Disable SysTick and Interrupt and Select Clock */
	#if		STK_CLK_SRC == STK_AHB_DIV_8
			STK->CTRL = 0x00000000;		// CLR_BIT(STK -> CTRL , CTRL_CLKSOURCE);

	#elif	STK_CLK_SRC == STK_AHB
			STK->CTRL = 0x00000004;
	#else
	#error "Wrong Clock Source Option"
	#endif
}


void	STK_voidSetBusyWait(u32	Copy_u32Ticks)
{
	/* Load ticks to LOAD Register */
	STK -> LOAD = Copy_u32Ticks;

	/* Enable the SYSTICK */
	SET_BIT(STK -> CTRL , CTRL_ENABLE);

	/* Wait until the flag raised == Polling */
	while(GET_BIT(STK -> CTRL , CTRL_COUNTFLAG) == 0);

	/* Disable the SYSTICK */
	STK_voidStopInterval();
}


void STK_voidDelay_ms(u16 Copy_u16Milli_Second)
{
	/* Each tick = 1 Microsecond */
	STK_voidSetBusyWait(Copy_u16Milli_Second * 1000);
}


void	STK_voidSetIntervalSingle(u32	Copy_u32Ticks, void (*Copy_PvFunction)(void))
{
	/* Disable TIMER */
	CLR_BIT(STK->CTRL , CTRL_ENABLE);
	STK->VAL = 0;

	STK->LOAD = Copy_u32Ticks;

	/* Enable the SYSTICK */
	SET_BIT(STK->CTRL , CTRL_ENABLE);

	/* Save Call Back Function */
	STK_CallbackPtr = Copy_PvFunction;

	/* Set the mode single Interval */
	STK_u8ModeOfInterval = STK_SINGLE_INTERVAL;

	/* Enable STK Interrupt */
	SET_BIT(STK -> CTRL , CTRL_TICKINT);
}


void	STK_voidSetIntervalPeriodic(u32	Copy_u32Ticks, void (*Copy_PvFunction)(void))
{
	/* Disable TIMER */
	CLR_BIT(STK->CTRL , CTRL_ENABLE);
	STK->VAL = 0;

	STK -> LOAD = Copy_u32Ticks;

	/* Enable the SYSTICK */
	SET_BIT(STK -> CTRL , CTRL_ENABLE);

	/* Save Call Back Function */
	STK_CallbackPtr = Copy_PvFunction;

	/* Set the mode single Interval */
	STK_u8ModeOfInterval = STK_PERIOD_INTERVAL;

	/* Enable STK Interrupt */
	SET_BIT(STK -> CTRL , CTRL_TICKINT);
}


void	STK_voidStopInterval(void)
{
	/* Disable the interrupt */				// optional
	CLR_BIT(STK->CTRL, CTRL_TICKINT);

	/* Disable the SYSTICK */
	CLR_BIT(STK -> CTRL , CTRL_ENABLE);

	/* Clear values of LOAD and VAL registers */
	STK -> LOAD = 0;
	STK -> VAL = 0;
}


u32		STK_u32GetElapsedTime(void)
{
	/* Local_u32ElapsedTime = the difference between LOAD and VAL values */
	return (STK->LOAD - STK->VAL);
}


u32		STK_u32GetRemainingTime(void)
{
	/* Local_u32RemainingTime = the current remaining VAL value */
	return (STK->VAL);
}






/* Interrupt function Implementation */
void SysTick_Handler(void)
{
	if(STK_u8ModeOfInterval == STK_SINGLE_INTERVAL)
	{
		STK_voidStopInterval();
	}

	if (STK_CallbackPtr != NULL)
	{
		STK_CallbackPtr();
	}

	/* Clear the flag by reading it */		/* also can be cleared by setting it but reading it is the best solution */
	u8 Local_u8FlagReading = 0;
	Local_u8FlagReading = GET_BIT(STK->CTRL , CTRL_COUNTFLAG);
}








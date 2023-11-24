/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	MCAL				**************************/
/***********************		SWC		:	STK 				**************************/
/***********************		DATE	:	NOV 07, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/

#ifndef MCAL_STK_STK_INTERFACE_H_
#define MCAL_STK_STK_INTERFACE_H_

void	STK_voidInit(void);
void	STK_voidSetBusyWait(u32	Copy_u32Ticks);
void 	STK_voidDelay_ms(u16 Copy_u16Milli_Second);

void	STK_voidSetIntervalSingle(u32	Copy_u32Ticks, void (*Copy_PvFunction)(void));
void	STK_voidSetIntervalPeriodic(u32	Copy_u32Ticks, void (*Copy_PvFunction)(void));
void	STK_voidStopInterval(void);
u32		STK_u32GetElapsedTime(void);
u32		STK_u32GetRemainingTime(void);

#endif /* MCAL_STK_STK_INTERFACE_H_ */



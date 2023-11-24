/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	MCAL				**************************/
/***********************		SWC		:	NVIC				**************************/
/***********************		DATE	:	NOV 06, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/


#ifndef MCAL_NVIC_NVIC_INTERFACE_H_
#define MCAL_NVIC_NVIC_INTERFACE_H_


void NVIC_voidInit(void);

void NVIC_voidEnableInterrupt(u8 Copy_u8InterruptNumber);
void NVIC_voidDisableInterrupt(u8 Copy_u8InterruptNumber);

void NVIC_voidSetPendingFlag(u8 Copy_u8InterruptNumber);
void NVIC_voidClearPendingFlag(u8 Copy_u8InterruptNumber);

u8 NVIC_u8GetActiveFlag(u8 Copy_u8InterruptNumber);

void NVIC_voidSetInterruptPriority(u8 Copy_u8InterruptNumber , u8 Copy_u8Priority);
//void NVIC_voidSetInterruptPriority(u8 Copy_u8InterruptNumber, u8 Copy_u8Group, u8 Copy_u8Sub);

#endif /* MCAL_NVIC_NVIC_INTERFACE_H_ */



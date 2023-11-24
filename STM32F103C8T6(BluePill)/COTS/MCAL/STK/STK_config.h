/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	MCAL				**************************/
/***********************		SWC		:	STK 				**************************/
/***********************		DATE	:	NOV 07, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/

#ifndef MCAL_RCC_STK_CONFIG_H_
#define MCAL_RCC_STK_CONFIG_H_


/*******************************************************************************************/
/********				SysTick Clock Source Options								********/
/********											1- STK_AHB_DIV_8				********/
/********											2- STK_AHB						********/
/*******************************************************************************************/
#define			STK_CLK_SRC					STK_AHB_DIV_8



/*******************************************************************************************/
/********				SysTick INTERRUPT ENABLE Options								********/
/********											1- DISABLED				********/
/********											2- ENABLED						********/
/*******************************************************************************************/
#define			STK_INTERRUPT_ENABLE					ENABLED


#endif /* MCAL_RCC_STK_CONFIG_H_ */



/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	MCAL				**************************/
/***********************		SWC		:	STK 				**************************/
/***********************		DATE	:	NOV 07, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/

#ifndef MCAL_STK_STK_REGISTER_H_
#define MCAL_STK_STK_REGISTER_H_


typedef struct SYSTICK
{
	volatile u32 	CTRL;
	volatile u32 	LOAD;
	volatile u32 	VAL;	// should be exist to calculate the offset correctly
	volatile u32	CALIB;	// only readable

}STK_BASE;


#define 		STK			((volatile STK_BASE*) 0xE000E010)


/* CTRL REGISTER BITS */
#define 	CTRL_COUNTFLAG			16			// Flag if the counter reaches 0
#define 	CTRL_CLKSOURCE			2			// select the clock source
#define 	CTRL_TICKINT			1			// enable the interrupt
#define 	CTRL_ENABLE				0			// enable the counter


/* CTRL REGISTER BITS */
#define 	CTRL_COUNTFLAG			16			// Flag if the counter reaches 0
#define 	CTRL_CLKSOURCE			2			// select the clock source
#define 	CTRL_TICKINT			1			// enable the interrupt
#define 	CTRL_ENABLE				0			// enable the counter


#endif /* MCAL_STK_STK_REGISTER_H_ */



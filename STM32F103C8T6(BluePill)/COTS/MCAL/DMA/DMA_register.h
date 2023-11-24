/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	MCAL				**************************/
/***********************		SWC		:	DMA					**************************/
/***********************		DATE	:	NOV 07, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/

#ifndef MCAL_DMA_DMA_REGISTER_H_
#define MCAL_DMA_DMA_REGISTER_H_


typedef	struct
{
	volatile u32	CCR;
	volatile u32	CNDTR;
	volatile u32	CPAR;
	volatile u32	CMAR;
	volatile u32	Reserverd;		// do not forget it to set the addresses successfully
}Channel_t;

typedef	struct
{
	volatile u32	ISR;
	volatile u32	IFCR;
	Channel_t		Channel[7];
}DMA_t;



#define		DMA1_t	((DMA_t *)0x40020000)

#endif /* MCAL_DMA_DMA_REGISTER_H_ */


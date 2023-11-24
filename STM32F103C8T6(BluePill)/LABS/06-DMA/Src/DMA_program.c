/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	MCAL				**************************/
/***********************		SWC		:	DMA					**************************/
/***********************		DATE	:	NOV 07, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DMA_interface.h"
#include "DMA_register.h"
#include "DMA_private.h"
#include "DMA_config.h"



void DMA_voidEnablelock(u8 Copy_u8Peripheral)
{
	switch(Copy_u8Peripheral)
	{
		case DMA1	:	RCC_voidEnableClockPeripheral(RCC_BUS_AHB , DMA1);		break;
		case DMA2	:	RCC_voidEnableClockPeripheral(RCC_BUS_AHB , DMA2);		break;
		default		:															break;
	}
}


void	DMA1_voidChannelInit(void)
{
	/*
		1- Memory to memory
		2- priority very high
		3- Source and destination Size = 32 bit
		4- MINC & PINC Active
		5- No circular
		6- Direction Memory to memory (DIR = 0 , Source Peripheral, Destination Memory)
		7- Transfer complete interrupt
		0- Disable the channel
	*/
	DMA1_t->Channel[0].CCR = 0x00007AC2;
}


void	DMA1_voidChannelStart(u32* Copy_pu32SourceAddress, u32* Copy_pu32DestinationAddress, u16 Copy_u16BlockLength)
{
	/* Disable the Channel */
	CLR_BIT((DMA1_t->Channel[0].CCR) , 0);

	/* Load the Addresses */
	DMA1_t->Channel[0].CPAR = Copy_pu32SourceAddress;
	DMA1_t->Channel[0].CMAR = Copy_pu32DestinationAddress;

	/* Load the block length */
	DMA1_t->Channel[0].CNDTR = Copy_u16BlockLength;

	/* Enable the Channel */
	SET_BIT((DMA1_t->Channel[0].CCR) , 0);
}

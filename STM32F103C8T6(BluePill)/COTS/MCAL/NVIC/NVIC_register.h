/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	MCAL				**************************/
/***********************		SWC		:	NVIC				**************************/
/***********************		DATE	:	NOV 06, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/

#ifndef MCAL_NVIC_NVIC_REGISTER_H_
#define MCAL_NVIC_NVIC_REGISTER_H_

#define 	NVIC_BASE_ADDRESS		0xE000E100			// Don't forget and write  *((volatile u32)(0xE000E100))

#define 	NVIC_ISER0				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x00))
#define 	NVIC_ISER1				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x04))
#define 	NVIC_ISER2				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x08))

#define 	NVIC_ICER0				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x80))
#define 	NVIC_ICER1				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x84))
#define 	NVIC_ICER2				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x88))

#define 	NVIC_ISPR0				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x100))
#define 	NVIC_ISPR1				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x104))
#define 	NVIC_ISPR2				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x108))

#define 	NVIC_ICPR0				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x180))
#define 	NVIC_ICPR1				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x184))
#define 	NVIC_ICPR2				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x188))

#define 	NVIC_IABR0				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x200))
#define 	NVIC_IABR1				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x204))
#define 	NVIC_IABR2				*((volatile u32*)(NVIC_BASE_ADDRESS + 0x208))

/* Access as an array instead of writing 21 Register from 0 to 20  write the address without *   */
#define 	NVIC_IPR				((volatile u32*)(NVIC_BASE_ADDRESS + 0x300))


#define 	NVIC_STIR				*((volatile u32*)(NVIC_BASE_ADDRESS + 0xE00))


#endif /* MCAL_NVIC_NVIC_REGISTER_H_ */




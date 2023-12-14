/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	MCAL				**************************/
/***********************		SWC		:	RCC					**************************/
/***********************		DATE	:	NOV 4, 2023			**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/

#ifndef RCC_REGISTER_H_
#define RCC_REGISTER_H_


#define 	RCC_BASE_ADDRESS		0x40021000

#define 	RCC_CR					*((volatile u32*) (RCC_BASE_ADDRESS+0x00))
#define 	RCC_CFGR				*((volatile u32*) (RCC_BASE_ADDRESS+0x04))
#define 	RCC_CIR					*((volatile u32*) (RCC_BASE_ADDRESS+0x08))
#define 	RCC_APB2RSTR			*((volatile u32*) (RCC_BASE_ADDRESS+0x0C))
#define 	RCC_APB1RSTR			*((volatile u32*) (RCC_BASE_ADDRESS+0x10))
#define 	RCC_AHBENR				*((volatile u32*) (RCC_BASE_ADDRESS+0x14))
#define 	RCC_APB2ENR				*((volatile u32*) (RCC_BASE_ADDRESS+0x18))
#define 	RCC_APB1ENR				*((volatile u32*) (RCC_BASE_ADDRESS+0x1C))
#define 	RCC_BDCR				*((volatile u32*) (RCC_BASE_ADDRESS+0x20))
#define		RCC_CSR					*((volatile u32*) (RCC_BASE_ADDRESS+0x24))



/***************************** RCC_CR *****************************/
/* Bits (31 ... 26) - (23 ... 20) are reserved */
#define 	RCC_CR_PLLRDY			25
#define     RCC_CR_PLLON            24
#define     RCC_CR_CSSON            19
#define     RCC_CR_HSEBYP           18
#define     RCC_CR_HSERDY           17
#define     RCC_CR_HSEON            16
#define     RCC_CR_HSICAL7         	15
#define     RCC_CR_HSICAL6         	14
#define     RCC_CR_HSICAL5         	13
#define     RCC_CR_HSICAL4         	12
#define     RCC_CR_HSICAL3         	11
#define     RCC_CR_HSICAL2         	10
#define     RCC_CR_HSICAL1        	9
#define     RCC_CR_HSICAL0        	8
#define     RCC_CR_HSITRIM4         7
#define     RCC_CR_HSITRIM3         6
#define     RCC_CR_HSITRIM2         5
#define     RCC_CR_HSITRIM1         4
#define     RCC_CR_HSITRIM0         3
#define     RCC_CR_HSIRDY           1
#define     RCC_CR_HSION            0


/***************************** RCC_CFGR *****************************/
/* Bits (31 ... 27) are reserved */
#define 	RCC_CFGR_MCO2           26
#define 	RCC_CFGR_MCO1			25
#define 	RCC_CFGR_MCO0           24
#define 	RCC_CFGR_USBPRE         22
#define 	RCC_CFGR_PLLMUL3        21
#define 	RCC_CFGR_PLLMUL2        20
#define 	RCC_CFGR_PLLMUL1        19
#define 	RCC_CFGR_PLLMUL0        18
#define 	RCC_CFGR_PLLXTPRE       17
#define 	RCC_CFGR_PLLSRC         16
#define 	RCC_CFGR_ADCPRE1        15
#define 	RCC_CFGR_ADCPRE0        14
#define 	RCC_CFGR_PPRE22         13
#define 	RCC_CFGR_PPRE221        12
#define 	RCC_CFGR_PPRE20         11
#define 	RCC_CFGR_PPRE12         10
#define 	RCC_CFGR_PPRE11         9
#define 	RCC_CFGR_PPRE10         8
#define 	RCC_CFGR_HPRE3          7
#define 	RCC_CFGR_HPRE2          6
#define 	RCC_CFGR_HPRE1          5
#define 	RCC_CFGR_HPRE0          4
#define 	RCC_CFGR_SWS1           3
#define 	RCC_CFGR_SWS0           2
#define 	RCC_CFGR_SW1            1
#define 	RCC_CFGR_SW0            0


/***************************** RCC_AHBENR *****************************/
/* Bits (31 ... 11) - 9 - 7 - 5 - 3 - are reserved */
#define 	RCC_AHBENR_SDIOEN		10
#define 	RCC_AHBENR_FSMCEN		8
#define 	RCC_AHBENR_CRCEN		6
#define 	RCC_AHBENR_FLITFEN		4
#define 	RCC_AHBENR_SRAMEN		2
#define 	RCC_AHBENR_DMA2EN		1
#define 	RCC_AHBENR_DMA1EN		0



#endif /* RCC_REGISTER_H_ */



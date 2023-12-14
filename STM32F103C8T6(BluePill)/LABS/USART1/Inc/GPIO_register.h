/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	MCAL				**************************/
/***********************		SWC		:	GPIO				**************************/
/***********************		DATE	:	NOV 5, 2023			**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/


#ifndef GPIO_REGISTER_H_
#define GPIO_REGISTER_H_


#define 	GPIOA_BASE_ADDRESS			0x40010800
#define 	GPIOB_BASE_ADDRESS			0x40010C00
#define 	GPIOC_BASE_ADDRESS			0x40011000


/*					GPIOA REGISTERS ADDRESSES					*/
#define 	GPIOA_CRL					*((volatile u32*) (GPIOA_BASE_ADDRESS + 0x00))
#define 	GPIOA_CRH					*((volatile u32*) (GPIOA_BASE_ADDRESS + 0x04))
#define 	GPIOA_IDR					*((volatile u32*) (GPIOA_BASE_ADDRESS + 0x08))	/* Accessed By GET_BIT(GPIOA_IDR, BIT) */
#define 	GPIOA_ODR					*((volatile u32*) (GPIOA_BASE_ADDRESS + 0x0C))	/* Accessed By SET_BIT(GPIOA_ODR, BIT) */
#define 	GPIOA_BSRR					*((volatile u32*) (GPIOA_BASE_ADDRESS + 0x10))
#define 	GPIOA_BRR					*((volatile u32*) (GPIOA_BASE_ADDRESS + 0x14))
#define 	GPIOA_LCKR					*((volatile u32*) (GPIOA_BASE_ADDRESS + 0x18))

/*					GPIOB REGISTERS ADDRESSES					*/
#define 	GPIOB_CRL					*((volatile u32*) (GPIOB_BASE_ADDRESS + 0x00))
#define 	GPIOB_CRH					*((volatile u32*) (GPIOB_BASE_ADDRESS + 0x04))
#define 	GPIOB_IDR					*((volatile u32*) (GPIOB_BASE_ADDRESS + 0x08))	/* Accessed By GET_BIT(GPIOB_IDR, BIT) */
#define 	GPIOB_ODR					*((volatile u32*) (GPIOB_BASE_ADDRESS + 0x0C))	/* Accessed By SET_BIT(GPIOB_ODR, BIT) */
#define 	GPIOB_BSRR					*((volatile u32*) (GPIOB_BASE_ADDRESS + 0x10))
#define 	GPIOB_BRR					*((volatile u32*) (GPIOB_BASE_ADDRESS + 0x14))
#define 	GPIOB_LCKR					*((volatile u32*) (GPIOB_BASE_ADDRESS + 0x18))

/*					GPIOC REGISTERS ADDRESSES					*/
#define 	GPIOC_CRL					*((volatile u32*) (GPIOC_BASE_ADDRESS + 0x00))
#define 	GPIOC_CRH					*((volatile u32*) (GPIOC_BASE_ADDRESS + 0x04))
#define 	GPIOC_IDR					*((volatile u32*) (GPIOC_BASE_ADDRESS + 0x08))	/* Accessed By GET_BIT(GPIOC_IDR, BIT) */
#define 	GPIOC_ODR					*((volatile u32*) (GPIOC_BASE_ADDRESS + 0x0C))	/* Accessed By SET_BIT(GPIOC_ODR, BIT) */
#define 	GPIOC_BSRR					*((volatile u32*) (GPIOC_BASE_ADDRESS + 0x10))
#define 	GPIOC_BRR					*((volatile u32*) (GPIOC_BASE_ADDRESS + 0x14))
#define 	GPIOC_LCKR					*((volatile u32*) (GPIOC_BASE_ADDRESS + 0x18))






#define 	GPIOA_CRL_CNF0_0			0
#define 	GPIOA_CRL_CNF0_1			1
#define 	GPIOA_CRL_MODE0_0			2
#define 	GPIOA_CRL_MODE0_1			3
#define 	GPIOA_CRL_CNF1_0			4
#define 	GPIOA_CRL_CNF1_1			5
#define 	GPIOA_CRL_MODE1_0			6
#define 	GPIOA_CRL_MODE1_1			7
#define 	GPIOA_CRL_CNF2_0			8
#define 	GPIOA_CRL_CNF2_1			9
#define 	GPIOA_CRL_MODE2_0			10
#define 	GPIOA_CRL_MODE2_1			11
#define 	GPIOA_CRL_CNF3_0			12
#define 	GPIOA_CRL_CNF3_1			13
#define 	GPIOA_CRL_MODE3_0			14
#define 	GPIOA_CRL_MODE3_1			15
#define 	GPIOA_CRL_CNF4_0			16
#define 	GPIOA_CRL_CNF4_1			17
#define 	GPIOA_CRL_MODE4_0			18
#define 	GPIOA_CRL_MODE4_1			19
#define 	GPIOA_CRL_CNF5_0			20
#define 	GPIOA_CRL_CNF5_1			21
#define 	GPIOA_CRL_MODE5_0			22
#define 	GPIOA_CRL_MODE5_1			23
#define 	GPIOA_CRL_CNF6_0			24
#define 	GPIOA_CRL_CNF6_1			25
#define 	GPIOA_CRL_MODE6_0			26
#define 	GPIOA_CRL_MODE6_1			27
#define 	GPIOA_CRL_CNF7_0			28
#define 	GPIOA_CRL_CNF7_1			29
#define 	GPIOA_CRL_MODE7_0			30
#define 	GPIOA_CRL_MODE7_1			31

#define 	GPIOA_CRH_CNF0_0			0
#define 	GPIOA_CRH_CNF0_1			1
#define 	GPIOA_CRH_MODE0_0			2
#define 	GPIOA_CRH_MODE0_1			3
#define 	GPIOA_CRH_CNF1_0			4
#define 	GPIOA_CRH_CNF1_1			5
#define 	GPIOA_CRH_MODE1_0			6
#define 	GPIOA_CRH_MODE1_1			7
#define 	GPIOA_CRH_CNF2_0			8
#define 	GPIOA_CRH_CNF2_1			9
#define 	GPIOA_CRH_MODE2_0			10
#define 	GPIOA_CRH_MODE2_1			11
#define 	GPIOA_CRH_CNF3_0			12
#define 	GPIOA_CRH_CNF3_1			13
#define 	GPIOA_CRH_MODE3_0			14
#define 	GPIOA_CRH_MODE3_1			15
#define 	GPIOA_CRH_CNF4_0			16
#define 	GPIOA_CRH_CNF4_1			17
#define 	GPIOA_CRH_MODE4_0			18
#define 	GPIOA_CRH_MODE4_1			19
#define 	GPIOA_CRH_CNF5_0			20
#define 	GPIOA_CRH_CNF5_1			21
#define 	GPIOA_CRH_MODE5_0			22
#define 	GPIOA_CRH_MODE5_1			23
#define 	GPIOA_CRH_CNF6_0			24
#define 	GPIOA_CRH_CNF6_1			25
#define 	GPIOA_CRH_MODE6_0			26
#define 	GPIOA_CRH_MODE6_1			27
#define 	GPIOA_CRH_CNF7_0			28
#define 	GPIOA_CRH_CNF7_1			29
#define 	GPIOA_CRH_MODE7_0			30
#define 	GPIOA_CRH_MODE7_1			31





#define 	GPIOB_CRL_CNF0_0			0
#define 	GPIOB_CRL_CNF0_1			1
#define 	GPIOB_CRL_MODE0_0			2
#define 	GPIOB_CRL_MODE0_1			3
#define 	GPIOB_CRL_CNF1_0			4
#define 	GPIOB_CRL_CNF1_1			5
#define 	GPIOB_CRL_MODE1_0			6
#define 	GPIOB_CRL_MODE1_1			7
#define 	GPIOB_CRL_CNF2_0			8
#define 	GPIOB_CRL_CNF2_1			9
#define 	GPIOB_CRL_MODE2_0			10
#define 	GPIOB_CRL_MODE2_1			11
#define 	GPIOB_CRL_CNF3_0			12
#define 	GPIOB_CRL_CNF3_1			13
#define 	GPIOB_CRL_MODE3_0			14
#define 	GPIOB_CRL_MODE3_1			15
#define 	GPIOB_CRL_CNF4_0			16
#define 	GPIOB_CRL_CNF4_1			17
#define 	GPIOB_CRL_MODE4_0			18
#define 	GPIOB_CRL_MODE4_1			19
#define 	GPIOB_CRL_CNF5_0			20
#define 	GPIOB_CRL_CNF5_1			21
#define 	GPIOB_CRL_MODE5_0			22
#define 	GPIOB_CRL_MODE5_1			23
#define 	GPIOB_CRL_CNF6_0			24
#define 	GPIOB_CRL_CNF6_1			25
#define 	GPIOB_CRL_MODE6_0			26
#define 	GPIOB_CRL_MODE6_1			27
#define 	GPIOB_CRL_CNF7_0			28
#define 	GPIOB_CRL_CNF7_1			29
#define 	GPIOB_CRL_MODE7_0			30
#define 	GPIOB_CRL_MODE7_1			31

#define 	GPIOB_CRH_CNF0_0			0
#define 	GPIOB_CRH_CNF0_1			1
#define 	GPIOB_CRH_MODE0_0			2
#define 	GPIOB_CRH_MODE0_1			3
#define 	GPIOB_CRH_CNF1_0			4
#define 	GPIOB_CRH_CNF1_1			5
#define 	GPIOB_CRH_MODE1_0			6
#define 	GPIOB_CRH_MODE1_1			7
#define 	GPIOB_CRH_CNF2_0			8
#define 	GPIOB_CRH_CNF2_1			9
#define 	GPIOB_CRH_MODE2_0			10
#define 	GPIOB_CRH_MODE2_1			11
#define 	GPIOB_CRH_CNF3_0			12
#define 	GPIOB_CRH_CNF3_1			13
#define 	GPIOB_CRH_MODE3_0			14
#define 	GPIOB_CRH_MODE3_1			15
#define 	GPIOB_CRH_CNF4_0			16
#define 	GPIOB_CRH_CNF4_1			17
#define 	GPIOB_CRH_MODE4_0			18
#define 	GPIOB_CRH_MODE4_1			19
#define 	GPIOB_CRH_CNF5_0			20
#define 	GPIOB_CRH_CNF5_1			21
#define 	GPIOB_CRH_MODE5_0			22
#define 	GPIOB_CRH_MODE5_1			23
#define 	GPIOB_CRH_CNF6_0			24
#define 	GPIOB_CRH_CNF6_1			25
#define 	GPIOB_CRH_MODE6_0			26
#define 	GPIOB_CRH_MODE6_1			27
#define 	GPIOB_CRH_CNF7_0			28
#define 	GPIOB_CRH_CNF7_1			29
#define 	GPIOB_CRH_MODE7_0			30
#define 	GPIOB_CRH_MODE7_1			31





#define 	GPIOC_CRL_CNF0_0			0
#define 	GPIOC_CRL_CNF0_1			1
#define 	GPIOC_CRL_MODE0_0			2
#define 	GPIOC_CRL_MODE0_1			3
#define 	GPIOC_CRL_CNF1_0			4
#define 	GPIOC_CRL_CNF1_1			5
#define 	GPIOC_CRL_MODE1_0			6
#define 	GPIOC_CRL_MODE1_1			7
#define 	GPIOC_CRL_CNF2_0			8
#define 	GPIOC_CRL_CNF2_1			9
#define 	GPIOC_CRL_MODE2_0			10
#define 	GPIOC_CRL_MODE2_1			11
#define 	GPIOC_CRL_CNF3_0			12
#define 	GPIOC_CRL_CNF3_1			13
#define 	GPIOC_CRL_MODE3_0			14
#define 	GPIOC_CRL_MODE3_1			15
#define 	GPIOC_CRL_CNF4_0			16
#define 	GPIOC_CRL_CNF4_1			17
#define 	GPIOC_CRL_MODE4_0			18
#define 	GPIOC_CRL_MODE4_1			19
#define 	GPIOC_CRL_CNF5_0			20
#define 	GPIOC_CRL_CNF5_1			21
#define 	GPIOC_CRL_MODE5_0			22
#define 	GPIOC_CRL_MODE5_1			23
#define 	GPIOC_CRL_CNF6_0			24
#define 	GPIOC_CRL_CNF6_1			25
#define 	GPIOC_CRL_MODE6_0			26
#define 	GPIOC_CRL_MODE6_1			27
#define 	GPIOC_CRL_CNF7_0			28
#define 	GPIOC_CRL_CNF7_1			29
#define 	GPIOC_CRL_MODE7_0			30
#define 	GPIOC_CRL_MODE7_1			31

#define 	GPIOC_CRH_CNF0_0			0
#define 	GPIOC_CRH_CNF0_1			1
#define 	GPIOC_CRH_MODE0_0			2
#define 	GPIOC_CRH_MODE0_1			3
#define 	GPIOC_CRH_CNF1_0			4
#define 	GPIOC_CRH_CNF1_1			5
#define 	GPIOC_CRH_MODE1_0			6
#define 	GPIOC_CRH_MODE1_1			7
#define 	GPIOC_CRH_CNF2_0			8
#define 	GPIOC_CRH_CNF2_1			9
#define 	GPIOC_CRH_MODE2_0			10
#define 	GPIOC_CRH_MODE2_1			11
#define 	GPIOC_CRH_CNF3_0			12
#define 	GPIOC_CRH_CNF3_1			13
#define 	GPIOC_CRH_MODE3_0			14
#define 	GPIOC_CRH_MODE3_1			15
#define 	GPIOC_CRH_CNF4_0			16
#define 	GPIOC_CRH_CNF4_1			17
#define 	GPIOC_CRH_MODE4_0			18
#define 	GPIOC_CRH_MODE4_1			19
#define 	GPIOC_CRH_CNF5_0			20
#define 	GPIOC_CRH_CNF5_1			21
#define 	GPIOC_CRH_MODE5_0			22
#define 	GPIOC_CRH_MODE5_1			23
#define 	GPIOC_CRH_CNF6_0			24
#define 	GPIOC_CRH_CNF6_1			25
#define 	GPIOC_CRH_MODE6_0			26
#define 	GPIOC_CRH_MODE6_1			27
#define 	GPIOC_CRH_CNF7_0			28
#define 	GPIOC_CRH_CNF7_1			29
#define 	GPIOC_CRH_MODE7_0			30
#define 	GPIOC_CRH_MODE7_1			31



#endif /* GPIO_REGISTER_H_ */



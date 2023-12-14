/*
 * TIMERx_register.h
 *
 *  Created on: Dec 14, 2023
 *      Author: EngMoS
 */

#ifndef TIMERX_REGISTER_H_
#define TIMERX_REGISTER_H_



typedef struct
{
	u32 CR1;
	u32 CR2;
	u32 SMCR;
	u32 DIER;
	u32 SR;
	u32 EGR;
	u32 CCMR1;
	u32 CCMR2;
	u32 CCER;
	u32 CNT;
	u32 PSC;
	u32 ARR;
	u32 RCR;
	u32 CCR1;
	u32 CCR2;
	u32 CCR3;
	u32 CCR4;
	u32 BDTR;
	u32 DCR;
	u32 DMAR;

}GPTM_t;


/*General purpose timers*/
#define TIM3 ((volatile GPTM_t*) (0x40000400))



/* CR1_REG Bits */
#define CR1_CEN 		0
#define CR1_UDIS 		1
#define CR1_URS 		2
#define CR1_OPM 		3
#define CR1_DIR 		4
#define CR1_CMS_1 		5
#define CR1_CMS_2 		6
#define CR1_ARPE 		7

/*EGR_REG Bits */






#endif /* TIMERX_REGISTER_H_ */

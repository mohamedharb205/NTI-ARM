/*
 * TIMERx_register.h
 *
 *  Created on: Dec 14, 2023
 *      Author: EngMoS
 */

#ifndef TIMERX_REGISTER_H_
#define TIMERX_REGISTER_H_



typedef struct {
	volatile u32 TIM1_CR1;
	volatile u32 TIM1_CR2;
	volatile u32 TIM1_SMCR;
	volatile u32 TIM1_DIER;
	volatile u32 TIM1_SR;
	volatile u32 TIM1_EGR;
	volatile u32 TIM1_CCMR1;
	volatile u32 TIM1_CCMR2;
	volatile u32 TIM1_CCER;
	volatile u32 TIM1_CNT;
	volatile u32 TIM1_PSC;
	volatile u32 TIM1_ARR;
	volatile u32 TIM1_RCR;
	volatile u32 TIM1_CCR1;
	volatile u32 TIM1_CCR2;
	volatile u32 TIM1_CCR3;
	volatile u32 TIM1_CCR4;
	volatile u32 TIM1_BDTR;
	volatile u32 TIM1_DCR;
	volatile u32 TIM1_DMAR;
}AdvancedTimer_t;

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

typedef struct
{
	u32 CR1;
	u32 CR2;
	u32 DIER;
	u32 SR;
	u32 EGR;
	u32 CNT;
	u32 PSC;
	u32 APR;
} BasicTimer_t;

/*Advanced timers*/
#define TIM1 ((volatile AdvancedTimer_t*) (0x40012C00))
//#define TIM8 ((volatile AdvancedTimer_t*) (0x40013400))

/*General purpose timers*/
#define TIM2 ((volatile GPTM_t*) (0x40000000))
#define TIM3 ((volatile GPTM_t*) (0x40000400))
#define TIM4 ((volatile GPTM_t*) (0x40000800))
#define TIM5 ((volatile GPTM_t*) (0x40000C00))

volatile GPTM_t* TIMERx_GetTimerID(u8 copy_u8TimerID);
/*General purpose timers*/
#define TIM9  ((volatile GPTM_t*) (0x40014C00))
#define TIM10 ((volatile GPTM_t*) (0x40015000))
#define TIM11 ((volatile GPTM_t*) (0x40015400))
#define TIM12 ((volatile GPTM_t*) (0x40001800))
#define TIM13 ((volatile GPTM_t*) (0x40001C00))
#define TIM14 ((volatile GPTM_t*) (0x40002000))

/*Basic timer*/
#define TIM6 ((volatile BasicTimer_t *) (0x40001000))
#define TIM7 ((volatile BasicTimer_t *) (0x40001400))



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

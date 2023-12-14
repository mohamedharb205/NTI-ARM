/*
 * TIMERx_config.h
 *
 *  Created on: Dec 14, 2023
 *      Author: EngMoS
 */

#ifndef TIMERX_CONFIG_H_
#define TIMERX_CONFIG_H_



/* Options:- TIMER_ENABLE  -  TIMER_DISABLE */
#define TIMER_2_ENABLE 					TIMER_ENABLE
/* Options:- TIMER_COUNT_UP  -  TIMER_COUNT_DOWN */
#define TIMER_2_DIRECTION 				TIMER_COUNT_UP
/* Options:- 0.... 65565 */
#define TIMWER_2_PRESCALER				1
#define TIMER_2_MAX_VALUE 				65535


/* Options:- TIMER_ENABLE  -  TIMER_DISABLE */
#define TIMER_3_ENABLE 					TIMER_ENABLE
/* Options:- TIMER_COUNT_UP  -  TIMER_COUNT_DOWN */
#define TIMER_3_DIRECTION 				TIMER_COUNT_UP
/* Options:- 0.... 65565 */
#define TIMWER_3_PRESCALER 				2
#define TIMER_3_MAX_VALUE 				1000

/* Options:- TIMER_ENABLE  -  TIMER_DISABLE */
#define TIMER_4_ENABLE 					TIMER_DISABLE
/* Options:- TIMER_COUNT_UP  -  TIMER_COUNT_DOWN */
#define TIMER_4_DIRECTION 				TIMER_COUNT_UP
/* Options:- 0.... 65565 */
#define TIMWER_4_PRESCALER 				1
#define TIMER_4_MAX_VALUE 				65535

/* Options:- TIMER_ENABLE  -  TIMER_DISABLE */
#define TIMER_5_ENABLE				 	TIMER_DISABLE
/* Options:- TIMER_COUNT_UP  -  TIMER_COUNT_DOWN */
#define TIMER_5_DIRECTION 				TIMER_COUNT_UP
/* Options:- 0.... 65565 */
#define TIMWER_5_PRESCALER 				1
#define TIMER_5_MAX_VALUE 				65535







/*My  Work*/


#define TIM3_COMPARE_VAL_CH1			199
#define TIM3_MAX_NUM_OF_TICKS_CH1		999

#define TIM3_COMPARE_VAL_CH2			199
#define TIM3_MAX_NUM_OF_TICKS_CH2		999





#endif /* TIMERX_CONFIG_H_ */

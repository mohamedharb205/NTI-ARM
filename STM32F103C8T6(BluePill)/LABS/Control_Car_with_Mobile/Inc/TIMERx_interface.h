/*
 * TIMERx_interface.h
 *
 *  Created on: Dec 14, 2023
 *      Author: EngMoS
 */

#ifndef TIMERX_INTERFACE_H_
#define TIMERX_INTERFACE_H_


#define TIMER3      3


#define CH1         1
#define CH2         2
#define CH3         3
#define CH4         4


/* My work*/

void TIM3_PWM_Init(void);
void TIM3_PWM_CH1_Generate(u8 Copy_u8Duty);
void TIM3_PWM_CH2_Generate(u8 Copy_u8Duty);
void TIM3_PWM_CH1_Change_Duty(u16 Copy_u16DutyPercentege);
void TIM3_PWM_CH2_Change_Duty(u16 Copy_u16DutyPercentege);



#endif /* TIMERX_INTERFACE_H_ */

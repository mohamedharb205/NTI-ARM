/*
 * TIMERx_interface.h
 *
 *  Created on: Dec 14, 2023
 *      Author: EngMoS
 */

#ifndef TIMERX_INTERFACE_H_
#define TIMERX_INTERFACE_H_


typedef enum
{
    RISING_EDGE = 0,
    FALLING_EDGE
}Trigger_Type;

typedef void (*timer_callback_t)(void);


#define TIMER2      2
#define TIMER3      3
#define TIMER4      4
#define TIMER5      5

#define CH1         1
#define CH2         2
#define CH3         3
#define CH4         4
void TIMERx_voidInit(void);


void TIMERx_voidPWMSetup(u8 Copy_u8TimerID, u8 Copy_u8ChannelID);

void TIMERx_voidSetPWMDuty(u8 Copy_u8TimerID, u8 Copy_u8ChannelID, u32 Copy_u32Duty);

void TIMERx_voidInputCaptureSetup(u8 Copy_u8TimerID, u8 Copy_u8ChannelID);

void TIMERx_voidStartTimer(u8 Copy_u8TimerID);

void TIMERx_voidStopTimer(u8 Copy_u8TimerID);

void TIMERx_voidGetInputCaptureCounter(u8 Copy_u8TimerID, u8 Copy_u8ChannelID, u32 *ptr_Counts);



void TIMERx_voidSetInputCaptureTrigger(u8 Copy_u8TimerID, u8 Copy_u8ChannelID, u8 Copy_u8ICTrigger);

void TIMERx_voidInputCaptureCallback(u8 Copy_u8TimerID, u8 Copy_u8ChannelID, timer_callback_t ptr);

/* My work*/

void TIM3_PWM_Init(void);
void TIM3_PWM_CH1_Generate(u8 Copy_u8Duty);
void TIM3_PWM_CH2_Generate(u8 Copy_u8Duty);
void TIM3_PWM_CH1_Change_Duty(u16 Copy_u16DutyPercentege);
void TIM3_PWM_CH2_Change_Duty(u16 Copy_u16DutyPercentege);



#endif /* TIMERX_INTERFACE_H_ */

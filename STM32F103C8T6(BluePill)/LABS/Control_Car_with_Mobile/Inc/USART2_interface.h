/*
 * USART1_Interface.h
 *
 *  Created on: Dec 11, 2023
 *      Author: EngMoS
 */

#ifndef USART2_INTERFACE_H_
#define USART2_INTERFACE_H_



void USART2_voidInit             ( void                ) ;
void USART2_voidSendCharSync    ( u8 Copy_u8Char      ) ;
void USART2_voidSendStringSynch ( u8 * Copy_ptrString ) ;
u8   USART2_u8RecCharSynch     ( void                ) ;
u8 * USART2_PtrReadStringSynch ( void                ) ;

void USART2_voidSetCallBack     ( void (*ptr) (void)  ) ;


void UART2_voidTransmit(u8 arr[]);
u8 UART2_u8Receive(u8* Copy_u8Data);



#endif /* USART2_INTERFACE_H_ */

/*
 * USART2_register.h
 *
 *  Created on: Dec 12, 2023
 *      Author: EngMoS
 */

#ifndef USART2_REGISTER_H_
#define USART2_REGISTER_H_



typedef struct{

	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;

}USART_Type;


#define USART1 ( ( volatile USART_Type* ) 0x40013800 )
#define USART2 ( ( volatile USART_Type* ) 0x40004400 )
#define USART3 ( ( volatile USART_Type* ) 0x40004800 )
#define UART4 (  ( volatile USART_Type* ) 0x40004C00 )
#define UART5 (  ( volatile USART_Type* ) 0x40005000 )



#endif /* USART2_REGISTER_H_ */

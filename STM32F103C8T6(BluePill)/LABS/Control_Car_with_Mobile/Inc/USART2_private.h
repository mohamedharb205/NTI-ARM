/*
 * USART2_private.h
 *
 *  Created on: Dec 12, 2023
 *      Author: EngMoS
 */

#ifndef USART2_PRIVATE_H_
#define USART2_PRIVATE_H_


#define USART2_DISABLE          0
#define USART2_ENABLE           1

#define _8BIT_WORD_LENGTH       0
#define _9BIT_WORD_LENGTH       1

#define PARITY_DISABLE          0
#define EVEN_PARITY             1
#define ODD_PARITY              2

#define INT_DISABLE             0
#define TXE_INT_ENABLE          1
#define TCE_INT_ENABLE          3
#define RXNE_INT_ENABLE         5

#define TRANSMITTER_DISABLE     0
#define TRANSMITTER_ENABLE      1

#define RECEIVER_DISBLE         0
#define RECEIVER_ENABLE         1

#define ONE_STOP_BIT            0
#define HALF_STOP_BIT           1
#define TWO_STOP_BIT            2
#define ONE_AND_HALF_STOP_BIT   3



#endif /* USART2_PRIVATE_H_ */

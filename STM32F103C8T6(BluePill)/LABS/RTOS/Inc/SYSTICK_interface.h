
#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

#define STK_INT_EN   1
#define STK_INT_DIS  0

void STK_voidInit( void );

void STK_voidStart( u32 Copy_PreloadValue );

void STK_voidINTStatus( u8 Copy_u8Status );

u8 STK_u8ReadFlag( void );

void STK_voidSetCallBack( void (*ptr)(void) );

#endif /* SYSTICK_INTERFACE_H_ */


#include"../Inc/STD_TYPES.h"
#include"../Inc/BIT_MATH.h"
#include"../Inc/SYSTICK_interface.h"
#include"../Inc/SYSTICK_register.h"



void ( * STK_CallBack ) ( void );

void SysTick_Handler(void){

	STK_CallBack();

}

void STK_voidSetCallBack( void (*ptr)(void) ){

	STK_CallBack = ptr;
}

void STK_voidInit( void ){

	// Enable Systick Interrupt  -  Clock = AHB / 8 - Stop Systic
	STK->CTRL = 0x00000002;

}


void STK_voidStart( u32 Copy_PreloadValue ){

	// AHB = EXT = 8MHZ & CLOCK OF STK = AHB / 8 = 8MHZ / 8 = 1MHZ = 1 Micro For Each Count
	//Load Reload Value
	STK->LOAD = Copy_PreloadValue - 1;
	//Clear Val Register
	STK->VAL  = 0 ;
	//Enable Systick
	SET_BIT( STK->CTRL , 0 );

}

void STK_voidINTStatus( u8 Copy_u8Status ){

	 STK->CTRL &= ~( 1 << 1 );
	 STK->CTRL |=  ( Copy_u8Status << 1 );

}

u8 STK_u8ReadFlag( void ){

	return ( GET_BIT( STK->CTRL , 16 ) );
}

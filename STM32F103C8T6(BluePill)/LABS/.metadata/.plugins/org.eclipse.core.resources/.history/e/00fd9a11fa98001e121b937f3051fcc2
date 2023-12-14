/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/


#include "../Inc/STD_TYPES.h"
#include "../Inc/BIT_MATH.h"

#include "../Inc/RCC_interface.h"
#include "../Inc/GPIO_interface.h"
#include "../Inc/RTOS_interface.h"



void LED1 ( void );
void LED2 ( void );
void LED3 ( void );


int main(void)
{
	RCC_voidInit();
	RCC_voidEnableClockPeripheral(RCC_BUS_APB2, RCC_APB2_GPIOA);

	GPIO_voidSetPinDirection(GPIOA, GPIO_u8PIN0, GPIO_PIN_OUTPUT_2MHZ_PUSH_PULL);
	GPIO_voidSetPinDirection(GPIOA, GPIO_u8PIN1, GPIO_PIN_OUTPUT_2MHZ_PUSH_PULL);
	GPIO_voidSetPinDirection(GPIOA, GPIO_u8PIN2, GPIO_PIN_OUTPUT_2MHZ_PUSH_PULL);

	RTOS_voidCreateTask( 0 , 1000 , LED1 , 0 );
	RTOS_voidCreateTask( 1 , 2000 , LED2 , 0 );
	RTOS_voidCreateTask( 2 , 3000 , LED3 , 0 );

	RTOS_voidStart();

	while(1);

	return 0;
}


void LED1 ( void )
{
	GPIO_voidTogglePin(GPIOA, GPIO_u8PIN0);
}

void LED2 ( void )
{
	GPIO_voidTogglePin(GPIOA, GPIO_u8PIN1);
}

void LED3 ( void )
{
	GPIO_voidTogglePin(GPIOA, GPIO_u8PIN2);
}

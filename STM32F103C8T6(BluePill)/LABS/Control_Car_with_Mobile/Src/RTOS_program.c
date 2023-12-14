
#include "../Inc/STD_TYPES.h"
#include "../Inc/SYSTICK_interface.h"
#include "../Inc/RTOS_interface.h"
#include "../Inc/RTOS_private.h"
#include "../Inc/RTOS_config.h"




static TASK_TCB SYS_TASKS[ TASK_NUMBERS ] = { { NULL } };

void RTOS_voidStart( void ){

	STK_voidSetCallBack( RTOS_voidSchedular );

	STK_voidInit();
	/* Tick time = 10 milliysecond */
	STK_voidStart( TICK_TIME );

}

void RTOS_voidCreateTask( u8 Copy_u8Priority , u16 Copy_u16Periodicity , void (*Copy_pvTask)( void ) , u16 Copy_u16FirstDelay ){

	if( SYS_TASKS[ Copy_u8Priority ].TaskHandler == NULL ){

		SYS_TASKS[ Copy_u8Priority ].Periodicity = Copy_u16Periodicity ;
		SYS_TASKS[ Copy_u8Priority ].TaskHandler = Copy_pvTask         ;
		SYS_TASKS[ Copy_u8Priority ].FirstDelay  = Copy_u16FirstDelay  ;
		SYS_TASKS[ Copy_u8Priority ].State       = TASK_READY          ;

	}
	else{

		/* Do No Thing */

	}

}

void RTOS_voidSuspendTask ( u8 Copy_u8TaskID ){

	SYS_TASKS[ Copy_u8TaskID ].State = TASK_SUSPEND ;

}

void RTOS_voidResumeTask  ( u8 Copy_u8TaskID ){

	SYS_TASKS[ Copy_u8TaskID ].State = TASK_READY   ;

}
void RTOS_voidDeleteTask  ( u8 Copy_u8TaskID ){

	SYS_TASKS[ Copy_u8TaskID ].TaskHandler = NULL ;

}


void RTOS_voidSchedular( void ){

	u8 LOC_u8TaskCounter      ;

	for( LOC_u8TaskCounter = 0 ; LOC_u8TaskCounter < TASK_NUMBERS ; LOC_u8TaskCounter++ ){

		if( ( SYS_TASKS[ LOC_u8TaskCounter ].TaskHandler != NULL ) && ( SYS_TASKS[ LOC_u8TaskCounter ].State == TASK_READY ) ){

			if( SYS_TASKS[ LOC_u8TaskCounter ].FirstDelay == 0 ){

				SYS_TASKS[ LOC_u8TaskCounter ].FirstDelay = SYS_TASKS[ LOC_u8TaskCounter ].Periodicity - 1 ;
				SYS_TASKS[ LOC_u8TaskCounter ].TaskHandler();

			}
			else{

				SYS_TASKS[ LOC_u8TaskCounter ].FirstDelay--;

			}

		}
		else{

			/* Do No Thing */

		}

	}

}



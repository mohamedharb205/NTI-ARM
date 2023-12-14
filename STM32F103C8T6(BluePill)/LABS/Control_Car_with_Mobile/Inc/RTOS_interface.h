
#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_

void RTOS_voidStart( void );

void RTOS_voidCreateTask( u8 Copy_u8Priority , u16 Copy_u16Periodicity , void (*Copy_pvTask)( void ) , u16 Copy_u16FirstDelay );

void RTOS_voidSuspendTask ( u8 Copy_u8TaskID );
void RTOS_voidResumeTask  ( u8 Copy_u8TaskID );
void RTOS_voidDeleteTask  ( u8 Copy_u8TaskID );

#endif /* RTOS_INTERFACE_H_ */


#ifndef RTOS_PRIVATE_H_
#define RTOS_PRIVATE_H_

typedef struct{

	u16  Periodicity               ;
	void ( *TaskHandler )( void )  ;
	u16  FirstDelay                ;
	u8   State                     ;

}TASK_TCB ;

#define TASK_READY       0
#define TASK_SUSPEND     1

void RTOS_voidSchedular( void );

#endif /* RTOS_PRIVATE_H_ */

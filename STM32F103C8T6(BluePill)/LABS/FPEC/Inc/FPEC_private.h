/*****************************************************************************************/
/*****************************************************************************************/
/***********************		AUTHOR	:	MOHAMED HARB		**************************/
/***********************		LAYER	:	MCAL				**************************/
/***********************		SWC		:	FPEC				**************************/
/***********************		DATE	:	NOV 20, 2023		**************************/
/***********************		VERSION	:	V01					**************************/
/*****************************************************************************************/
/*****************************************************************************************/

#ifndef FPEC_PRIVATE_H_
#define FPEC_PRIVATE_H_


#define FLASH_BASE_ADDRESS		0x08000000


typedef union
{
	struct{
		u32  PG    :1 ;
		u32  PER   :1 ;
		u32  MER   :1 ;
		u32  RES1  :1 ;
		u32  OPTPG :1 ;
		u32  OPTER :1 ;
		u32  STRT  :1 ;
		u32  LOCK  :1 ;
		u32  RES2  :1 ;
		u32  OPTWRE:1 ;
		u32  ERRIE :1 ;
		u32  RES3  :1 ;
		u32  EOPIE :1 ;
		u32  RES4  :19;
	}BitAccess;

	u32 WordAccess;
}FPEC_CR_TYPE;

#define FPEC_CR 	((FPEC_CR_TYPE*)0x40022010)


typedef struct
{
	volatile u32 ACR;
	volatile u32 KEYR;
	volatile u32 OPTKEYR;
	volatile u32 SR;
	volatile u32 CR;
	volatile u32 AR;
	volatile u32 RESERVED;
	volatile u32 OBR;
	volatile u32 WRPR;
}FPEC_TYPE;

#define		FPEC ((FPEC_TYPE*)0x40022000)



#endif /* FPEC_PRIVATE_H_ */
/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 14 FEB 2023				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : EXTI           			 ***********************/
/* Version 	: 2.00             			 ***********************/
/***************************************************************/
#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

typedef struct{

	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;

}EXTI_Type;

#define EXTI ((volatile EXTI_Type *) 0x40010400)


#endif	/* EXTI_PRIVATE_H_ */
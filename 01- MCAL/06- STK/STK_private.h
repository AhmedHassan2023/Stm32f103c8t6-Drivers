/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 14 FEB 2023				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : STK           			 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/
#ifndef STK_PRIVATE_H_
#define STK_PRIVATE_H_

typedef struct
{
	volatile u32 CTRL  ;
	volatile u32 LOAD  ;
	volatile u32 VAL   ;
}MSTK_Type;

#define     MSTK    ((MSTK_Type*)0xE000E010)


#define     MSTK_SRC_AHB           0
#define     MSTK_SRC_AHB_8         1

#define     MSTK_SINGLE_INTERVAL    0
#define     MSTK_PERIOD_INTERVAL    1

#endif	/* STK_PRIVATE_H_ */
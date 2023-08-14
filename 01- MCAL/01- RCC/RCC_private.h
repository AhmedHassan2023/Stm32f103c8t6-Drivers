/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 13 FEB 2023				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : RCC           			 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/
#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

#define RCC_HSE_CRYSTAL		1
#define RCC_HSE_RC			2
#define RCC_HSI				3
#define RCC_PLL				4


typedef struct
{
	volatile u32 CR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 APB2RSTR;
	volatile u32 APB1RSTR;
	volatile u32 AHBENR;
	volatile u32 APB2ENR;
	volatile u32 APB1ENR;
	volatile u32 BDCR;
	volatile u32 CSR;
	
}RCC_t;

#define RCC  ((volatile RCC_t*)0x40021000)

#endif	/* RCC_PRIVATE_H_ */

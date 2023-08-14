/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 13 FEB 2023				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : RCC           			 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/
#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/* Options : 	1- RCC_HSE_CRYSTAL
				2- RCC_HSE_RC
				3- RCC_HSI
				4- RCC_PLL				*/
#define RCC_CLOCK_TYPE 		 RCC_HSE_CRYSTAL

/* Options : 	1- RCC_PLL_IN_HSI_DIV_2
				2- RCC_PLL_IN_HSE_DIV_2
				3- RCC_PLL_IN_HSE		*/
/* Note : Select Value only if you have PLL as input Clock Source */
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_INPUT	RCC_PLL_IN_HSE_DIV_2
#endif

/* Options : 2 to 16 */
/* Note : Select value only if you have PLL as input Clock Source */
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_MUL_VAL		4
#endif


/*
 * 0xxx: system clock not divided
 * 1000: system clock divided by 2
 * 1001: system clock divided by 4
 * 1010: system clock divided by 8
 * 1011: system clock divided by 16
 * 1100: system clock divided by 64
 * 1101: system clock divided by 128
 * 1110: system clock divided by 256
 * 1111: system clock divided by 512
 */



#endif	/* RCC_CONFIG_H_ */

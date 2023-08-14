/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 20 FEB 2023				 ***********************/
/* Layer   	: HAL           		   	 ***********************/
/* SWC      : CLCD           			 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/
#ifndef CLCD_PRIVATE_H_
#define CLCD_PRIVATE_H_

#define FOUR_BITS_MODE	0
#define EIGHT_BITS_MODE	1

static void CLCD_voidSetDataPort(u8 Copy_u8Data);

static void CLCD_voidSetHalfDataPort(u8 Copy_u8Data);

static void CLCD_voidSendEnablePulse(void);

#endif	/* CLCD_PRIVATE_H_ */

/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 19 FEB 2023				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : FPEC           			 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/
#ifndef FPEC_INTERFACE_H_
#define FPEC_INTERFACE_H_

void FPEC_voidEraseAppArea(void);

void FPEC_voidFlashPageErase(u8 Copy_u8PageNumber);

void FPEC_voidFlashWrite(u32 Copy_u32Address, u16* Copy_u16Data, u8 Copy_u8Length);


#endif	/* FPEC_INTERFACE_H_ */

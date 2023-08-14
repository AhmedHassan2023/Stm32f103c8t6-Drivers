/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 19 FEB 2023				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : HEXPARSR           		 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/
#ifndef HEXPARSR_INTERFACE_H_
#define HEXPARSR_INTERFACE_H_

void HEXPARSER_voidParseData(u8* Copy_pu8DataBuffer);

void HEXPARSR_voidParseUpperAddress(u8* Copy_pu8DataBuffer);

void HEXPARSER_voidParseRecord(u8* Copy_pu8DataBuffer);


#endif	/* HEXPARSR_INTERFACE_H_ */

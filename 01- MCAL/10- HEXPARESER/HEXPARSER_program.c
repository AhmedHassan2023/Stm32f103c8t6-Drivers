/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 19 FEB 2023				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : HEXPARSR           		 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "FPEC_interface.h"

#include "HEXPARSER_interface.h"
#include "HEXPARSER_private.h"
#include "HEXPARSER_config.h"

u16 Data[100] = {0};

u32 Address= 0x08000000;

u8 AsciToHex(u8 Copy_u8Asci)
{
	u8 Local_u8Result;

	if( (Copy_u8Asci >= 48)  && (Copy_u8Asci <= 57) )
	{
		Local_u8Result = Copy_u8Asci - 48 ;
	}
	else
	{
		Local_u8Result = Copy_u8Asci - 55 ;
	}

	return Local_u8Result ;
}

void HEXPARSER_voidParseData(u8* Copy_pu8DataBuffer)
{
	u8 Local_u8DigitLow,Local_u8DigitHigh,Local_u8CC,Local_u8Iterator;
	u8 Local_u8DataDigit0,Local_u8DataDigit1,Local_u8DataDigit2,Local_u8DataDigit3;
	u8 Local_u8DataCounter = 0;

	/* Get Character Count */
	Local_u8DigitHigh = AsciToHex(Copy_pu8DataBuffer[1]);
	Local_u8DigitLow  = AsciToHex(Copy_pu8DataBuffer[2]);
	Local_u8CC 		  = (Local_u8DigitHigh<<4) | Local_u8DigitLow;

	/* Get Address */
	Local_u8DataDigit0 = AsciToHex(Copy_pu8DataBuffer[3]);
	Local_u8DataDigit1 = AsciToHex(Copy_pu8DataBuffer[4]);
	Local_u8DataDigit2 = AsciToHex(Copy_pu8DataBuffer[5]);
	Local_u8DataDigit3 = AsciToHex(Copy_pu8DataBuffer[6]);

	/* Clear Low Part of Address */

	Address = Address & 0xFFFF0000;
	Address = Address |(Local_u8DataDigit3) |(Local_u8DataDigit2 <<4) |(Local_u8DataDigit1 <<8) |(Local_u8DataDigit0 <<12);

	for(Local_u8Iterator = 0; Local_u8Iterator < (Local_u8CC/2) ; Local_u8Iterator++)
	{
		Local_u8DataDigit0 = AsciToHex(Copy_pu8DataBuffer[ (4 * Local_u8Iterator) + 9]);
		Local_u8DataDigit1 = AsciToHex(Copy_pu8DataBuffer[ (4 * Local_u8Iterator) + 10]);
		Local_u8DataDigit2 = AsciToHex(Copy_pu8DataBuffer[ (4 * Local_u8Iterator) + 11]);
		Local_u8DataDigit3 = AsciToHex(Copy_pu8DataBuffer[ (4 * Local_u8Iterator) + 12]);

		Data[Local_u8DataCounter] = (Local_u8DataDigit3 << 8) | (Local_u8DataDigit2 << 12) | (Local_u8DataDigit1) | (Local_u8DataDigit0 << 4);

		//Data[Local_u8DataCounter] = (Local_u8DataDigit3 ) | (Local_u8DataDigit2 << 4) | (Local_u8DataDigit1<<8) | (Local_u8DataDigit0 << 12);
		Local_u8DataCounter++;
	}

	FPEC_voidFlashWrite(Address,Data,Local_u8CC/2);

}

void HEXPARSR_voidParseUpperAddress(u8* Copy_pu8DataBuffer)
{
//	u8 Local_u8Digit0,Local_u8Digit1,Local_u8Digit2,Local_u8Digit3;
//
//	u32 Local_u32Address = 0;
//
//	/* Get Address */
//	Local_u8Digit0 = AsciToHex(Copy_pu8DataBuffer[3]);
//	Local_u8Digit1 = AsciToHex(Copy_pu8DataBuffer[4]);
//	Local_u8Digit2 = AsciToHex(Copy_pu8DataBuffer[5]);
//	Local_u8Digit3 = AsciToHex(Copy_pu8DataBuffer[6]);
//
//	/* Clear Low Part of the Address */
//	Local_u32Address = FLASH_BASE_ADDRESS;
//
//	Local_u32Address = Local_u32Address & 0x0000FFFF;
//
//	Local_u32Address = Local_u32Address | (u32)((u32)(Local_u8Digit3 << 28) | (u32)(Local_u8Digit2 << 24) | (u32)(Local_u8Digit1 << 20) | (u32)(Local_u8Digit0 << 16));
//

}

void HEXPARSER_voidParseRecord(u8* Copy_pu8DataBuffer)
{
	switch(Copy_pu8DataBuffer[8])
	{
	case '0' : HEXPARSER_voidParseData(Copy_pu8DataBuffer) ; break;
	case '4' : HEXPARSR_voidParseUpperAddress(Copy_pu8DataBuffer); break;
	}
}

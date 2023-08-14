/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 20 FEB 2023				 ***********************/
/* Layer   	: HAL           		   	 ***********************/
/* SWC      : CLCD           			 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "CLCD_interface.h"
#include "CLCD_private.h"
#include "CLCD_config.h"

void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	/*SET RS pin to low for Command*/
	MGPIO_voidSetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,LOW);

	/*SET RW pin low for Write*/
	MGPIO_voidSetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,LOW);

#if CLCD_DATA_LENGTH_MODE == FOUR_BITS_MODE

	/*Set High 4 Bits Order of Command */
	CLCD_voidSetHalfDataPort(Copy_u8Command >> 4);

	/*Send Enable Pulse*/
	MGPIO_voidSetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,HIGH);
	MSTK_voidSetBusyWait(5000);
	MGPIO_voidSetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,LOW);

	/*Set Low 4 Bits Order of Command */
	CLCD_voidSetHalfDataPort(Copy_u8Command);

	/*Send Enable Pulse*/
	MGPIO_voidSetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,HIGH);
	MSTK_voidSetBusyWait(5000);
	MGPIO_voidSetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,LOW);

#elif CLCD_DATA_LENGTH_MODE == EIGHT_BITS_MODE

	/* Set Command to Data Pins */
	CLCD_voidSetDataPort(Copy_u8Command);

	/* Send Enable Pulse */
	MGPIO_voidSetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,HIGH);
	MSTK_voidSetBusyWait(5000);
	MGPIO_voidSetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,LOW);


#else
#error "Wrong Data Length Configuration"
#endif

}

void CLCD_voidSendData(u8 Copy_u8Data)
{
	/*SET RS pin to High for Data*/
	MGPIO_voidSetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,HIGH);

	/*SET RW pin Low for Write*/
	MGPIO_voidSetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,LOW);

#if CLCD_DATA_LENGTH_MODE == FOUR_BITS_MODE

	/*Set High 4 Bits Order of Command */
	CLCD_voidSetHalfDataPort(Copy_u8Data >> 4);

	/*Send Enable Pulse*/
	MGPIO_voidSetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,HIGH);
	MSTK_voidSetBusyWait(5000);
	MGPIO_voidSetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,LOW);

	/*Set Low 4 Bits Order of Command */
	CLCD_voidSetHalfDataPort(Copy_u8Data);

	/*Send Enable Pulse*/
	MGPIO_voidSetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,HIGH);
	MSTK_voidSetBusyWait(5000);
	MGPIO_voidSetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,LOW);

#elif CLCD_DATA_LENGTH_MODE == EIGHT_BITS_MODE

	/* Set Command to Data Pins */
	CLCD_voidSetDataPort(Copy_u8Data);

	/* Send Enable Pulse */
	MGPIO_voidSetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,HIGH);
	MSTK_voidSetBusyWait(5000);
	MGPIO_voidSetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,LOW);



#else
#error " Wrong Data Length Configuration "
#endif

}

void CLCD_voidInit(void)
{
	/*Wait for more than 15 ms*/
	MSTK_voidSetBusyWait(50000);

#if CLCD_DATA_LENGTH_MODE == FOUR_BITS_MODE

	CLCD_voidSetHalfDataPort(0b0011);
	CLCD_voidSendEnablePulse();
	/* Send Enable Pulse */
	MSTK_voidSetBusyWait(5000);

	CLCD_voidSetHalfDataPort(0b0011);
	CLCD_voidSendEnablePulse();

	/* Send Enable Pulse */
	MSTK_voidSetBusyWait(500);

	CLCD_voidSetHalfDataPort(0b0011);
	CLCD_voidSendEnablePulse();

	CLCD_voidSetHalfDataPort(0b0010);
	CLCD_voidSendEnablePulse();

	CLCD_voidSetHalfDataPort(0b0010);
	CLCD_voidSendEnablePulse();

	CLCD_voidSetHalfDataPort(0b1100);
	CLCD_voidSendEnablePulse();

	CLCD_voidSetHalfDataPort(0b0000);
	CLCD_voidSendEnablePulse();

	CLCD_voidSetHalfDataPort(0b1000);
	CLCD_voidSendEnablePulse();

	CLCD_voidSetHalfDataPort(0b0000);
	CLCD_voidSendEnablePulse();

	CLCD_voidSetHalfDataPort(0b0001);
	CLCD_voidSendEnablePulse();

	CLCD_voidSetHalfDataPort(0b0000);
	CLCD_voidSendEnablePulse();

	CLCD_voidSetHalfDataPort(0b0110);
	CLCD_voidSendEnablePulse();

	CLCD_voidSendCommand(0b00001100);

	CLCD_voidSendCommand(0b00000001);

#elif CLCD_DATA_LENGTH_MODE == EIGHT_BITS_MODE

	CLCD_voidSendCommand(0b00110000);

	CLCD_voidSendCommand(0b00110000);

	CLCD_voidSendCommand(0b00110000);

	/*Function Send command : 2 Lines, 5*8 Font size*/
	CLCD_voidSendCommand(0b00111000);

	/*Display on off control: display enable, disable cursor, no blink cursor*/
	CLCD_voidSendCommand(0b00001000);

	/*Clear display -> 0b00000001 == 1*/
	CLCD_voidSendCommand(0b00000001);

	/*Entry mode set -> 0b00000110*/
	CLCD_voidSendCommand(0b00000110);

	/*Display on off control: set bit 3, display enable, disable cursor, no blink cursor*/
	CLCD_voidSendCommand(0b00001100);


#else
#error " Wrong Data Length Configuration "
#endif
}

void CLCD_voidSendString(const char* Copy_pcString)
{
	u8 Local_u8Counter=0;
	while(Copy_pcString[Local_u8Counter]!= '\0')
	{
		CLCD_voidSendData(Copy_pcString[Local_u8Counter]);
		Local_u8Counter++;
	}
}

void CLCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	u16 Local_u8Address;
	if (Copy_u8XPos==0)
	{
		/*Location is at first line*/
		Local_u8Address=Copy_u8YPos;
	}
	else if(Copy_u8XPos==1)
	{
		/*Location is at second line*/
		Local_u8Address=Copy_u8YPos+0x40;
	}
	else if (Copy_u8XPos==2)
	{
		/*Location is at third line*/
		Local_u8Address=Copy_u8YPos+0x14;
	}
	else if (Copy_u8XPos==3)
	{
		/*Location is at forth line*/
		Local_u8Address=Copy_u8YPos+0x54;
	}

	/*set bit number 7 for Set DDRAM Address command then send the command*/
	CLCD_voidSendCommand(Local_u8Address+128);
}

void CLCD_voidWriteSpecialCharacter(u8* Copy_pu8Pattern, u8 Copy_u8PatternNumber, u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	u8 Local_u8CGRAMAddress=0, Local_u8Iterator;

	/*Calculate CGRAM Address whose each block is 8 bytes*/
	Local_u8CGRAMAddress= Copy_u8PatternNumber*8;

	/*Send CGRAM Address command to LCD, with setting bit 6, clearing bit 7*/
	CLCD_voidSendCommand(Local_u8CGRAMAddress+64);

	/*Write the Pattern into CGRAM */
	for(Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++)
	{
		CLCD_voidSendData(Copy_pu8Pattern[Local_u8Iterator]);

	}
	/*go back to DDRAM to display the pattern*/
	CLCD_voidGoToXY(Copy_u8XPos,Copy_u8YPos);

	/*Display the Pattern written in CGRAM */
	CLCD_voidSendData(Copy_u8PatternNumber);
}

void CLCD_voidWriteNumber(u32 Copy_u32Number,u32 Copy_u32FieldLength)
{
	u16 str[5]={0,0,0,0,0};
	u16 i=4,j=0;

	if(Copy_u32Number<0)
	{
		CLCD_voidSendData('-');
		Copy_u32Number = Copy_u32Number*(-1);

	}

	while(Copy_u32Number)
	{
		str[i]=Copy_u32Number%10;
		Copy_u32Number=Copy_u32Number/10;
		i--;
	}

	if(Copy_u32FieldLength==-1)
	{
		while(str[j]==0)
		{
			j++;
		}
	}
	else
	{
		j=5-Copy_u32FieldLength;
	}

	for(i=j;i<5;i++)
	{
		CLCD_voidSendData('0'+str[i]);
	}

}

static void CLCD_voidSetDataPort(u8 Copy_u8Data)
{
	u8 Local_u8BitValue;

	Local_u8BitValue = GET_BIT(Copy_u8Data,0);
	MGPIO_voidSetPinValue(CLCD_DATA_PORT,CLCD_D0_PIN,Local_u8BitValue);

	Local_u8BitValue = GET_BIT(Copy_u8Data,1);
	MGPIO_voidSetPinValue(CLCD_DATA_PORT,CLCD_D1_PIN,Local_u8BitValue);

	Local_u8BitValue = GET_BIT(Copy_u8Data,2);
	MGPIO_voidSetPinValue(CLCD_DATA_PORT,CLCD_D2_PIN,Local_u8BitValue);

	Local_u8BitValue = GET_BIT(Copy_u8Data,3);
	MGPIO_voidSetPinValue(CLCD_DATA_PORT,CLCD_D3_PIN,Local_u8BitValue);

	Local_u8BitValue = GET_BIT(Copy_u8Data,4);
	MGPIO_voidSetPinValue(CLCD_DATA_PORT,CLCD_D4_PIN,Local_u8BitValue);

	Local_u8BitValue = GET_BIT(Copy_u8Data,5);
	MGPIO_voidSetPinValue(CLCD_DATA_PORT,CLCD_D5_PIN,Local_u8BitValue);

	Local_u8BitValue = GET_BIT(Copy_u8Data,6);
	MGPIO_voidSetPinValue(CLCD_DATA_PORT,CLCD_D6_PIN,Local_u8BitValue);

	Local_u8BitValue = GET_BIT(Copy_u8Data,7);
	MGPIO_voidSetPinValue(CLCD_DATA_PORT,CLCD_D7_PIN,Local_u8BitValue);

}

static void CLCD_voidSetHalfDataPort(u8 Copy_u8Data)
{
	u8 Local_u8BitValue;

	Local_u8BitValue = GET_BIT(Copy_u8Data,0);
	MGPIO_voidSetPinValue(CLCD_DATA_PORT,CLCD_D4_PIN,Local_u8BitValue);

	Local_u8BitValue = GET_BIT(Copy_u8Data,1);
	MGPIO_voidSetPinValue(CLCD_DATA_PORT,CLCD_D5_PIN,Local_u8BitValue);

	Local_u8BitValue = GET_BIT(Copy_u8Data,2);
	MGPIO_voidSetPinValue(CLCD_DATA_PORT,CLCD_D6_PIN,Local_u8BitValue);

	Local_u8BitValue = GET_BIT(Copy_u8Data,3);
	MGPIO_voidSetPinValue(CLCD_DATA_PORT,CLCD_D7_PIN,Local_u8BitValue);
}

static void CLCD_voidSendEnablePulse(void)
{
	/* Send Enable Pulse */
	MGPIO_voidSetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,HIGH);
	MSTK_voidSetBusyWait(5000);
	MGPIO_voidSetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,LOW);
}

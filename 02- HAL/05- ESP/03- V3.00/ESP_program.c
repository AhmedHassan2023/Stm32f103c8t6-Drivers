/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 21 FEB 2023				 ***********************/
/* Layer   	: HAL           		   	 ***********************/
/* SWC      : ESP           			 ***********************/
/* Version 	: 3.00             			 ***********************/
/***************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "USART_interface.h"
#include "STK_interface.h"

#include "ESP_interface.h"
#include "ESP_private.h"
#include "ESP_config.h"

u8 volatile DataCome[200];

u8 volatile Iterator = 0;

void USART1_voidNotificationFunc(void)
{
	/* Receive ESP8266 Response */
	DataCome[Iterator] =USART1_u8ReadDataRTegister();

	Iterator++;

	USART1_voidClearFlags();
}


void ESP_voidInit(void)
{
	u8 Local_u8Result = 0;
	u8 Local_u8Data[100];

	while(Local_u8Result == 0)
	{
		/* Stop ECHO */
		USART1_voidSendStringSynch("ATE0\r\n");

		/* Check if Command Was Sent Correctly */
		Local_u8Result = voidESPValidateCmd(Local_u8Data,100);
	}



	while(Local_u8Result == 0)
	{
		/* Set Station Mode */
		USART1_voidSendStringSynch("AT+CWMODE=3\r\n");

		/* Check if Command Was Sent Correctly */
		Local_u8Result = voidESPValidateCmd(Local_u8Data,100);
	}


	while(Local_u8Result == 0)
	{

		/* Set Transfer Mode */
		USART1_voidSendStringSynch("AT+CIPMODE=0\r\n");

		/* Check if Command Was Sent Correctly */
		Local_u8Result = voidESPValidateCmd(Local_u8Data,100);
	}

}

void ESP_voidConnectToWIFI(u8* Copy_pu8SSID, u8* Copy_pu8Password)
{
	u8 Local_u8Result = 0 ;
	u8 Local_u8Data[100];

	while(Local_u8Result == 0)
	{
		/* Connect To WIFI */
		USART1_voidSendStringSynch("AT+CWJAP=\"");
		USART1_voidSendStringSynch(Copy_pu8SSID);
		USART1_voidSendStringSynch("\",\"");
		USART1_voidSendStringSynch(Copy_pu8Password);
		USART1_voidSendStringSynch("\"\r\n");

		Local_u8Result = voidESPValidateCmd(Local_u8Data,100);

	}

}

void ESP_voidConnectToServer(u8* Copy_pu8IP, u8* Copy_pu8Port)
{
	u8 Local_u8Result = 0 ;
	u8 Local_u8Data[100];

	while(Local_u8Result == 0)
	{
		/* Connect To Server */
		USART1_voidSendStringSynch("AT+CIPSTART=\"");
		USART1_voidSendStringSynch("TCP\",\"");
		USART1_voidSendStringSynch(Copy_pu8IP);
		USART1_voidSendStringSynch("\",");
		USART1_voidSendStringSynch(Copy_pu8Port);
		USART1_voidSendStringSynch("\r\n");

		Local_u8Result = voidESPValidateCmd(Local_u8Data,100);

	}

}

u8 ESP_voidReceiveData(u8* Copy_pu8Server,u8* Copy_pu8Length)
{
	ESP_voidClearBuffer();

	USART1_voidSendStringSynch("AT+CIPSEND=");
	USART1_voidSendStringSynch(Copy_pu8Length);
	USART1_voidSendStringSynch("\r\n");

	/* Wait 4000 ms*/
	MSTK_voidSetBusyWait(2000000);

	ESP_voidClearBuffer();

	USART1_voidSendStringSynch("GET http://");
	USART1_voidSendStringSynch(Copy_pu8Server);
	USART1_voidSendStringSynch("/status.txt\r\n");

	/* Wait 20000 ms */
	MSTK_voidSetBusyWait(2000000);

	ESP_voidConnectToServer("172.107.162.12","80");

	return DataCome[50];
}

u8 voidESPValidateCmd(u8* Copy_pu8Data, u16 Copy_u16Max)
{

	u16 i=0;
	u8 Result = 0;

	while(i < Copy_u16Max)
	{
		Copy_pu8Data[i] = USART1_u8ReceiveDataSynch();
		i++;
	}



	/* Check if OK */
	for(i=0;i<100;i++)
	{
		if((Copy_pu8Data[i]=='O' && Copy_pu8Data[i+1] == 'K')||(Copy_pu8Data[i] == 'C' && Copy_pu8Data[i+1] == 'O' && Copy_pu8Data[i+2] == 'N' && Copy_pu8Data[i+3] == 'N' && Copy_pu8Data[i+4]=='E' && Copy_pu8Data[i+5]=='C' && Copy_pu8Data[i+6]=='T'))
		{
			Result = 1;
			break;
		}
	}

	return Result;

}

void ESP_voidClearBuffer(void)
{
	u8 Local_u8Iterator = 0;
	Iterator = 0 ;

	for(Local_u8Iterator = 0 ; Local_u8Iterator <150 ; Local_u8Iterator++)
	{
		DataCome[Local_u8Iterator] = 0 ;
	}
}

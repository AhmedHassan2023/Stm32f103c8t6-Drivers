/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 22 JAN 2023				 ***********************/
/* Layer   	: HAL           		   	 ***********************/
/* SWC      : ESP           			 ***********************/
/* Version 	: 1.00             			 ***********************/
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
	/* Set USART1 CallBack Function To receive The Responce of The ESP8266 */
	USART1_voidSetCallBack(USART1_voidNotificationFunc);

	/* Stop ECHO */
	USART1_voidSendStringSynch("AT\r\n");

	/* Wait 3000 ms */
	MSTK_voidSetBusyWait(2000000);

	/* Clear ESP8266 Buffer */
	ESP_voidClearBuffer();

//	USART1_voidSendStringSynch("ATE0\r\n");
//
//	/* Wait 3000 ms */
//	MSTK_voidSetBusyWait(3000,MILLI_SEC);
//
//	/* Clear ESP8266 Buffer */
//	ESP_voidClearBuffer();

	/* Set Station Mode */
	USART1_voidSendStringSynch("AT+CWMODE=3\r\n");

	/* Wait 3000 ms */
	MSTK_voidSetBusyWait(2000000);

	/* Clear ESP8266 Buffer */
	ESP_voidClearBuffer();


	/* Set Transfer Mode */
	USART1_voidSendStringSynch("AT+CIPMODE=0\r\n");

	/* Wait 3000 ms */
	MSTK_voidSetBusyWait(2000000);

}

void ESP_voidConnectToWIFI(u8* Copy_pu8SSID, u8* Copy_pu8Password)
{
	u8 Local_u8Result = 0 ;

	ESP_voidClearBuffer();

	USART1_voidSendStringSynch("AT+CWJAP=\"");
	USART1_voidSendStringSynch(Copy_pu8SSID);
	USART1_voidSendStringSynch("\",\"");
	USART1_voidSendStringSynch(Copy_pu8Password);
	USART1_voidSendStringSynch("\"\r\n");

	/* Wait 8000 ms */
	MSTK_voidSetBusyWait(2000000);


}

void ESP_voidConnectToServer(u8* Copy_pu8IP, u8* Copy_pu8Port)
{
	u8 Local_u8Result = 0 ;

	ESP_voidClearBuffer();

	USART1_voidSendStringSynch("AT+CIPSTART=\"");
	USART1_voidSendStringSynch("TCP\",\"");
	USART1_voidSendStringSynch(Copy_pu8IP);
	USART1_voidSendStringSynch("\",");
	USART1_voidSendStringSynch(Copy_pu8Port);
	USART1_voidSendStringSynch("\r\n");

	/* Wait 2000 ms */
	MSTK_voidSetBusyWait(2000000);

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

u8 voidESPValidateCmd(void)
{


	u8 Local_u8Responce[100];
	u8 i=0;
	u8 Dummy[100];
	u8 Result = 0;

	while(i != 255)
	{

		Local_u8Responce[i] = USART1_u8ReadDataRTegister();
		Dummy[i] = USART1_u8ReceiveDataSynch();
		i++;
	}



	/* Check if OK */
	if(Local_u8Responce[0] == 'O' && Local_u8Responce[1] == 'K')
	{
		Result = 1 ;
	}

	/* Ckeck if SEND OK */
	//	else if(Local_u8Responce[0] == 'S' && Local_u8Responce[6] == 'K')
	//	{
	//		Result = 2 ;
	//	}

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

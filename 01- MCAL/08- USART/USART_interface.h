/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 18 FEB 2023				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : USART           			 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/
#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

void USART1_voidInit(void);

void USART1_voidSendDataSynch(u8 Copy_u8Data);

void USART1_voidSendStringSynch(const char *Copy_pcString);

u8 USART1_u8ReceiveDataSynch(void);

u8 USART1_u8ReadDataRTegister(void);

void USART1_voidClearFlags(void);

void USART1_voidEnableIntrrupt(void);

void USART1_voidDisableIntrrupt(void);

void USART1_voidSetCallBack(void (*Copy_pvNotificationFunc)(void));


#endif	/* USART_INTERFACE_H_ */

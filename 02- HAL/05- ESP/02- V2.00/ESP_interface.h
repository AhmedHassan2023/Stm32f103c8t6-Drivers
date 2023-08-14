/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 22 JAN 2023				 ***********************/
/* Layer   	: HAL           		   	 ***********************/
/* SWC      : ESP           			 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/

#ifndef ESP_INTERFACE_H_
#define ESP_INTERFACE_H_

void ESP_voidInit(void);

void ESP_voidConnectToWIFI(u8* Copy_pu8SSID, u8* Copy_pu8Password);

void ESP_voidConnectToServer(u8* Copy_pu8IP, u8* Copy_pu8Port);

u8 ESP_voidReceiveData(u8* Copy_pu8Server,u8* Copy_pu8Length);



#endif	/* ESP_INTERFACE_H_ */

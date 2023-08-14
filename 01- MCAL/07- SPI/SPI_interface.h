/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 18 FEB 2023				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : SPI           			 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/
#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void MSPI1_voidInit(void);

u8 SPI1_u8SendReciveSynch(u8 Copy_u8DataToTransmit,u8 *Copy_pu8ReceivedData);



#endif	/* SPI_INTERFACE_H_ */

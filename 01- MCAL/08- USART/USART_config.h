/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 18 FEB 2023				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : USART           			 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/
#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_

/* Baud Rate Register Value Options : 	1- 9600   --> 0x341
 * 										2- 115200 --> 0x45   */
#define USART1_BUAD_RATE_VALUE 		0x341

#define USART1_TIME_OUT				50000


#endif	/* USART_CONFIG_H_ */

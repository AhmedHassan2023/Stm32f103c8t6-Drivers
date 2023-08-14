/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 18 FEB 2023				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : SPI           			 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/
#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

/* Write it in pair port,pin */
#define SPI1_SLAVE_PIN		GPIOA,PIN0

/* SPI Mode Select Options : 	1- SPI1_MASTER
								2- SPI1_SLAVE		*/
#define SPI1_MODE_SELECT			SPI1_MASTER

/* SPI Baud Rate Control Options :	1- SPI1_CLK_OVER_2
									2- SPI1_CLK_OVER_4
									3- SPI1_CLK_OVER_8
									4- SPI1_CLK_OVER_16
									5- SPI1_CLK_OVER_32
									6- SPI1_CLK_OVER_64
									7- SPI1_CLK_OVER_128
									8- SPI1_CLK_OVER_256	*/
#define SPI1_CLK_RATE			SPI1_CLK_OVER_16

/* SPI Data transmit Order Options :	1- SPI1_MSB
										2- SPI1_LSB			*/
#define SPI1_DATA_ORDER			SPI1_LSB	

/* SPI CLOCK Polarity Options :	1- SPI1_FALLING_EDGE
 * 								2- SPI1_RISING_EDGE			*/
 #define SPI1_CLK_POL		SPI1_RISING_EDGE
 
 /* SPI Clock Phase Options :
 * 							 1- SPI1_SAMPLE
 * 							 2- SPI1_SETUP */
#define SPI1_CLK_PHASE		SPI1_SAMPLE

#define SPI1_u32_TIMEOUT		50000


#endif	/* SPI_CONFIG_H_ */
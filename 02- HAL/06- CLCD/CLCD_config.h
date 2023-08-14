/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 20 FEB 2023				 ***********************/
/* Layer   	: HAL           		   	 ***********************/
/* SWC      : CLCD           			 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/
#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_
/* Control Port and Pins */
#define CLCD_CTRL_PORT	GPIOB

#define CLCD_RS_PIN		PIN0
#define CLCD_RW_PIN		PIN1
#define CLCD_E_PIN		PIN10

/* Data Port and Pins */
#define CLCD_DATA_PORT	GPIOA
#define CLCD_D0_PIN		PIN0
#define CLCD_D1_PIN		PIN1
#define CLCD_D2_PIN		PIN2
#define CLCD_D3_PIN		PIN3
#define CLCD_D4_PIN		PIN4
#define CLCD_D5_PIN		PIN5
#define CLCD_D6_PIN		PIN6
#define CLCD_D7_PIN		PIN7

/* Data Length Mode Options :	1- FOUR_BITS_MODE
 * 								2- EIGHT_BITS_MODE	 */
#define CLCD_DATA_LENGTH_MODE 	FOUR_BITS_MODE

#endif	/* CLCD_CONFIG_H_ */

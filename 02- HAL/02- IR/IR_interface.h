/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 15 FEB 2023				 ***********************/
/* Layer   	: HAL           		   	 ***********************/
/* SWC      : IR	           			 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/
#ifndef IR_INTERFACE_H_
#define IR_INTERFACE_H_

#define PIN0	0
#define PIN1	1

#define GPIOA	0


void IR_voidInit(void);

void IR_voidTakeAction(void);

u8 IR_u8GetData(void);

#endif	/* IR_INTERFACE_H_ */

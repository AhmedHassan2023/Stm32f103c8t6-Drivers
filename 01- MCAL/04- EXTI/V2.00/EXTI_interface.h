/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 14 FEB 2023				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : EXTI           			 ***********************/
/* Version 	: 2.00             			 ***********************/
/***************************************************************/
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/* External Interrupt Modes */
#define RISING_EDGE    1
#define FALLING_EDGE   2
#define ON_CHANGE      3

/* PORTs */
#define PORTA           0
#define PORTB           1
#define PORTC           2

/* External Interrupt Lines */
#define EXTI_LINE0  0
#define EXTI_LINE1  1
#define EXTI_LINE2  2

void MEXTI_voidInit(void);
void MEXTI_voidSetSignalLatch(u8 Copy_u8EXTILine , u8 Copy_u8EXTISenseMode);
void MEXTI_voidEnableEXTI(u8 Copy_u8EXTILine);
void MEXTI_voidDisableEXTI(u8 Copy_u8EXTILine);
void MEXTI_voidSoftwareTrigger(u8 Copy_u8EXTILine);

void MEXTI_voidSetCallBack(void (*ptr) (void));



#endif	/* EXTI_INTERFACE_H_ */

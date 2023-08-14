/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: ahmed
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"

volatile u8 	u8StartFlag		= 0;
volatile u32 	u32FrameData[50]	= {0} ;
volatile u8 	u8EdgeCounter		= 0 ;
volatile u8 	u8Data				= 0 ;
void voidPlay(void)
{
	switch(u8Data)
	{
	case 3 : MGPIO_voidSetPinValue(GPIOA,PIN1,HIGH);	MGPIO_voidSetPinValue(GPIOA,PIN2,HIGH);  MGPIO_voidSetPinValue(GPIOA,PIN3,HIGH);	break;
	case 2 : MGPIO_voidSetPinValue(GPIOA,PIN1,LOW);		MGPIO_voidSetPinValue(GPIOA,PIN2,LOW);	 MGPIO_voidSetPinValue(GPIOA,PIN3,LOW);	break;
	case 4 : MGPIO_voidSetPinValue(GPIOA,PIN1,HIGH);	break;
	case 5 : MGPIO_voidSetPinValue(GPIOA,PIN2,HIGH);	break;
	case 6 : MGPIO_voidSetPinValue(GPIOA,PIN3,HIGH);	break;

	}
}

void voidTakeAction(void)
{
	u8 i ;
	u8Data = 0;

	if((u32FrameData[0] >= 1000) && (u32FrameData[0] <= 16000))
	{
		for(i=0;i<8;i++)
		{
			if( (u32FrameData[17+i] >= 2000 ) && (u32FrameData[17+i] <=2400 ))
			{
				SET_BIT(u8Data,i);
			}
			else
			{
				CLR_BIT(u8Data,i);
			}
		}

		voidPlay();
	}
	else
	{
		/* Invalid Frame */
	}

	u8StartFlag     = 0;
	u32FrameData[0] = 0;
	u8EdgeCounter   = 0;
}

void voidGetFrame(void)
{
	if(u8StartFlag == 0)
	{
		/* Start Timer */
		MSTK_voidSetIntervalSingle(1000000,voidTakeAction);
		u8StartFlag = 1;
	}
	else
	{
		u32FrameData[u8EdgeCounter] = MSTK_u32GetElapsedTime();
		MSTK_voidSetIntervalSingle(1000000,voidTakeAction);
		u8EdgeCounter++;
	}
}
void main(void)
{
	/* Clock Initialization */
	RCC_voidInit();

	/* GPIO Enable */
	RCC_voidEnableClock(RCC_APB2,GPIOA_EN);

	/* IO Pins Initialization */
	MGPIO_voidSetPinDirection(GPIOA,PIN0,INPUT_FLOATING);		/* A0 Input Floating 				*/
	MGPIO_voidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP);	/* A1 Output Low Speed PP "RED" 	*/
	MGPIO_voidSetPinDirection(GPIOA,PIN2,OUTPUT_SPEED_2MHZ_PP);	/* A2 Output Low Speed PP "GREEN" 	*/
	MGPIO_voidSetPinDirection(GPIOA,PIN3,OUTPUT_SPEED_2MHZ_PP);	/* A3 Output Low Speed PP "BLUE" 	*/

	/* EXTI Initialization */
	MEXTI_voidSetCallBack(voidGetFrame);
	MEXTI_voidInit();

	/* Enable EXTI0 From NVIC */
	MNVIC_voidInit();
	MNVIC_voidEnableInterrupt(6);

	MSTK_voidInit();




	while(1)
	{

	}
}




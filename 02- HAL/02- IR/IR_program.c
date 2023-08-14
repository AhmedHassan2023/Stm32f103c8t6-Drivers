/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 15 FEB 2023				 ***********************/
/* Layer   	: HAL           		   	 ***********************/
/* SWC      : IR	           			 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"
#include "EXTI_interface.h"
#include "NVIC_interface.h"

#include "IR_interface.h"
#include "IR_private.h"
#include "IR_config.h"

volatile u8 	u8StartFlag			= 0	  ;
volatile u32 	u32FrameData[50]	= {0} ;
volatile u8 	u8EdgeCounter		= 0   ;
volatile u8 	u8Data				= 0   ;

void IR_voidInit(void)
{
	/* Set IR Pin to Input Floating */
	MGPIO_voidSetPinDirection(IR_GPIO_PORT,IR_PIN,INPUT_FLOATING);

	/* Set EXTI0 call Back Function */
	MEXTI_voidSetCallBack(IR_voidGetFrame);

	/* EXTI Initialization to Falling Edge */
	MEXTI_voidInit();

	/* Enable EXTI0 From NVIC */
	MNVIC_voidInit();

	MNVIC_voidEnableInterrupt(EXTI0_EN);

	/* Initialize STK */
	MSTK_voidInit();

}

void IR_voidGetFrame(void)
{
	u8 i;
	if(u8StartFlag == 0)
	{
		/* Start Timer */
		MSTK_voidSetIntervalSingle(1000000,IR_voidTakeAction);
		u8StartFlag = 1;
	}
	else if(u8StartFlag == 1)
	{
		u32FrameData[u8EdgeCounter] = MSTK_u32GetElapsedTime();
		MSTK_voidSetIntervalSingle(1000000,IR_voidTakeAction);
		u8EdgeCounter++;
	}

	if(u8EdgeCounter == 33 )
	{
		for(i=0;i<33;i++)
		{
			u32FrameData[i] = 1000000 - u32FrameData[i];
		}
		for(i=17;i<25;i++)
		{
			if(u32FrameData[i] >= 2300);
			{

			}
		}

	}
}

void IR_voidTakeAction(void)
{
	u8 Local_u8Iterator = 0;
	u8Data = 0;

	if((u32FrameData[0] >= 10000) && (u32FrameData[0] <= 16000))
	{
		for(Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++)
		{
			if( (u32FrameData[17+Local_u8Iterator] >= 2000 ) && (u32FrameData[17+Local_u8Iterator] <=2400 ))
			{
				SET_BIT(u8Data,Local_u8Iterator);
			}
			else
			{
				CLR_BIT(u8Data,Local_u8Iterator);
			}
		}

	}
	else
	{
		/* Invalid Frame */
	}

	MNVIC_voidDisableInterrupt(EXTI0_EN);

}


u8 IR_u8GetData(void)
{
	u8 Local_u8Data = 0 ;



	Local_u8Data = u8Data ;

	u8StartFlag     = 0;
	u32FrameData[0] = 0;
	u8EdgeCounter   = 0;

	MNVIC_voidEnableInterrupt(EXTI0_EN);

	return Local_u8Data ;

}

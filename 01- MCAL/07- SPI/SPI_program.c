/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 18 FEB 2023				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : SPI           			 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

static void (*SPI1_pvCallBackNotificationFunc)(void) = NULL;

static u8 *SPI1_pu8ReceivedData = NULL;

u8 SPI1_u8Busystate = SPI1_IDLE;

void MSPI1_voidInit(void)
{
		/* 1- Mode Select */
#if SPI1_MODE_SELECT == SPI1_MASTER
	{
		/* 1- Master Mode */
		SET_BIT(SPI->CR1,SPI1_CR1_MSTR);

		/* Baud Rate Control */
#if SPI1_CLK_RATE == SPI1_CLK_OVER_2
		{
			CLR_BIT(SPI->CR1,SPI1_CR1_BR1);
			CLR_BIT(SPI->CR1,SPI1_CR1_BR2);
			CLR_BIT(SPI->CR1,SPI1_CR1_BR3);
		}
#elif SPI1_CLK_RATE == SPI1_CLK_OVER_4
		{
			SET_BIT(SPI->CR1,SPI1_CR1_BR1);
			CLR_BIT(SPI->CR1,SPI1_CR1_BR2);
			CLR_BIT(SPI->CR1,SPI1_CR1_BR3);
		}
#elif SPI1_CLK_RATE == SPI1_CLK_OVER_8
		{
			CLR_BIT(SPI->CR1,SPI1_CR1_BR1);
			SET_BIT(SPI->CR1,SPI1_CR1_BR2);
			CLR_BIT(SPI->CR1,SPI1_CR1_BR3);
		}
#elif SPI1_CLK_RATE == SPI1_CLK_OVER_16
		{
			SET_BIT(SPI->CR1,SPI1_CR1_BR1);
			SET_BIT(SPI->CR1,SPI1_CR1_BR2);
			CLR_BIT(SPI->CR1,SPI1_CR1_BR3);
		}
#elif SPI1_CLK_RATE == SPI1_CLK_OVER_32
		{
			CLR_BIT(SPI->CR1,SPI1_CR1_BR1);
			CLR_BIT(SPI->CR1,SPI1_CR1_BR2);
			SET_BIT(SPI->CR1,SPI1_CR1_BR3);
		}
#elif SPI1_CLK_RATE == SPI1_CLK_OVER_64
		{
			SET_BIT(SPI->CR1,SPI1_CR1_BR1);
			CLR_BIT(SPI->CR1,SPI1_CR1_BR2);
			SET_BIT(SPI->CR1,SPI1_CR1_BR3);
		}
#elif SPI1_CLK_RATE == SPI1_CLK_OVER_128
		{
			CLR_BIT(SPI->CR1,SPI1_CR1_BR1);
			SET_BIT(SPI->CR1,SPI1_CR1_BR2);
			SET_BIT(SPI->CR1,SPI1_CR1_BR3);
		}
#elif SPI1_CLK_RATE == SPI1_CLK_OVER_256
		{
			SET_BIT(SPI->CR1,SPI1_CR1_BR1);
			SET_BIT(SPI->CR1,SPI1_CR1_BR2);
			SET_BIT(SPI->CR1,SPI1_CR1_BR3);
		}

#else
#error "Wrong SPI CLOCK Rate Configuration"
#endif

	}
	/* 2- Slave Mode */
#elif SPI1_MODE_SELECT == SPI1_SLAVE
	{
		CLR_BIT(SPI->CR1,SPI1_CR1_MSTR);
	}

#else
#error "Wrong SPI Mode Configuration"
#endif

	/* 2- Data Order Selection*/
#if SPI1_DATA_ORDER == SPI1_LSB
	{
		SET_BIT(SPI->CR1,SPI1_CR1_LSB_FIRST);
	}

#elif SPI1_DATA_ORDER == SPI1_MSB
	{
		CLR_BIT(SPI->CR1,SPI1_CR1_LSB_FIRST)
	}

#else
#error "Wrong SPI Data Order Configuration"
#endif

	/* 3- Select Clock Polarity */
#if SPI_CLK_POL == SPI1_RISING_EDGE
	{
		CLR_BIT(SPI->CR1,SPI1_CR1_CPOL);
	}
#elif SPI_CLK_POL == SPI1_FALLING_EDGE
	{
		SET_BIT(SPI->CR1,SPI1_CR1_CPOL);
	}
#endif

	/* 4- Selecting Clock Phase*/
#if SPI1_CLK_PHASE == SPI1_SAMPLE
	{
		CLR_BIT(SPI->CR1,SPI1_CR1_CPHA);
	}
#elif SPI1_CLK_PHASE == SPI1_SETUP
	{
		SET_BIT(SPI->CR1,SPI1_CR1_CPHA);
	}
#endif


	/* 5- SPI Enable */
	SET_BIT(SPI->CR1,SPI1_CR1_SPE);
}

u8 SPI1_u8SendReciveSynch(u8 Copy_u8DataToTransmit,u8 *Copy_pu8ReceivedData)
{
	u32 Local_u32Counter = 0;
	u8 Local_u8ErrorStatus = OK;

	if(Copy_pu8ReceivedData  == NULL)
	{
		Local_u8ErrorStatus = NULL_POINTER;
	}

	else
	{

		/* Clear For Slave Select Pin  */
		MGPIO_voidSetPinValue(SPI1_SLAVE_PIN,LOW);

		/* Send Data */
		SPI -> DR = Copy_u8DataToTransmit ;

		/* wait Busy flag to Fetch */
		while( (GET_BIT(SPI -> SR,SPI1_SR_BSY) == 1) && (Local_u32Counter != SPI1_u32_TIMEOUT))
		{
			Local_u32Counter ++ ;
		}

		if(Local_u32Counter == SPI1_u32_TIMEOUT)
		{
			/* Loop Is Broken because the Time Out Is Reached */
			Local_u8ErrorStatus = NOK;
		}
		else
		{
			/* Return to the received data */
			*Copy_pu8ReceivedData = SPI -> DR ;
		}
		/* Set Slave Select Pin */
		MGPIO_voidSetPinValue(SPI1_SLAVE_PIN,HIGH);
	}

	return Local_u8ErrorStatus;
	}

/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 13 FEB 2023				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : RCC           			 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/
#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

/* System Buses*/
#define RCC_AHB		0
#define RCC_APB1	1
#define RCC_APB2	2

/* AHB Bus Periphrals */
#define    DMA1_EN      0
#define    DMA2_EN      1
#define    SRAM_EN      2
#define    FLITF_EN		4
#define    CRC_EN       6
#define    FSMC_EN      8
#define    SDIO_EN      10

/* APB1 Peripherals */
#define    TIM2_EN         0
#define    TIM3_EN         1
#define    TIM4_EN         2
#define    TIM5_EN         3
#define    TIM6_EN         4
#define    TIM7_EN         5
#define    TIM12ENC_EN     6
#define    TIM13_EN        7
#define    TIM14_EN        8
#define    WWDG_EN         11
#define    SPI2_EN         14
#define    SPI3_EN         15
#define    USART2_EN       17
#define    USART3_EN       18
#define    UART4_EN        19
#define    UART5_EN        20
#define    I2C1_EN         21
#define    I2C2_EN         22
#define    USB_EN          23
#define    CAN_EN          25
#define    BKP_EN          27
#define    PWR_EN          28
#define    DAC_EN          29

/* APB2 Peripherals */
#define    AFIO_EN         0
#define    GPIOA_EN        2
#define    GPIOB_EN        3
#define    GPIOC_EN        4
#define    GPIOD_EN        5
#define    GPIOE_EN        6
#define    GPIOF_EN        7
#define    GPIOG_EN        8
#define    ADC1_EN         9
#define    ADC2_EN         10
#define    TIM1_EN         11
#define    SPI1_EN         12
#define    TIM8_EN         13
#define    USART1_EN       14
#define    ADC3_EN         15
#define    TIM9_EN         19
#define    TIM10_EN        20
#define    TIM11_EN        21

void RCC_voidInit(void);

void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);

void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);


#endif	/* RCC_INTERFACE_H_ */

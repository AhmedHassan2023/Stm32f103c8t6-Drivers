/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 18 FEB 2023				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : SPI           			 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/
#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

typedef struct
{
	volatile u32 CR1    ;
	volatile u32 CR2    ;
	volatile u32 SR     ;
	volatile u32 DR     ;
	volatile u32 CRCPR  ;
	volatile u32 RXCRCR ;
	volatile u32 TXCRCR ;
	volatile u32 I2SCFGR;
	volatile u32 I2SPR  ; 
	
}SPI_Register;


#define SPI   ((volatile SPI_Register*)0x40013000)

/* SPI1_CR1 : SPI Control Register 1 Bits */
#define SPI1_CR1_CPHA			0				/* Clock Phase 							*/
#define SPI1_CR1_CPOL			1				/* Clock Polarity 						*/
#define SPI1_CR1_MSTR			2				/* Master Selection 					*/
#define SPI1_CR1_BR1			3				/* Baud Rate Control Bit 1 				*/
#define SPI1_CR1_BR2			4				/* Baud Rate Control Bit 2 				*/
#define SPI1_CR1_BR3			5				/* Baud Rate Control Bit 3			 	*/
#define SPI1_CR1_SPE			6				/* SPI Enable 							*/
#define SPI1_CR1_LSB_FIRST		7				/* Frame Format 						*/
#define SPI1_CR1_SSI			8				/* Internal Slave Select 				*/
#define SPI1_CR1_SSM			9				/* Software Slave Management 			*/
#define SPI1_CR1_RX_ONLY		10				/* receive Only							*/
#define SPI1_CR1_DFF			11				/* Data Frame Format					*/
#define SPI1_CR1_CRC_NEXT		12				/* CRC Transfer Next 					*/
#define SPI1_CR1_CRC_EN			13				/* Hardware CRC Calculation Enable 		*/
#define SPI1_CR1_BIDI_EN		14				/* Bidirectional Data Mode Enable		*/
#define SPI1_CR1_BIDI_MODE		15

/* SPI1_SR : SPI Status Register Bits*/

#define SPI1_SR_RXNE		0					/* Receive Buffer Not Empty 	*/
#define SPI1_SR_TXE			1					/* Transmit Buffer Empty 		*/
#define SPI1_SR_CHSIDE		2					/* Channel Side 				*/
#define SPI1_SR_UDR			3					/* Underrun Flag 				*/
#define SPI1_SR_CRCERR		4					/* CRC Error Flag			 	*/
#define SPI1_SR_MODF		5					/* Mode Fault 					*/
#define SPI1_SR_OVR			6					/* Overrun Flag 				*/
#define SPI1_SR_BSY			7					/* Busy Flag 					*/

/* SPI1 Busy State 	: 	1- SPI1_IDLE
 * 						2- SPI1_BUSY	*/

#define SPI1_IDLE	0							/* SPI Not Busy State 	*/
#define SPI1_BUSY	1							/* SPI Busy State 		*/


#endif	/* SPI_PRIVATE_H_ */

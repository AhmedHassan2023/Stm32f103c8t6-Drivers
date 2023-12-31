/***************************************************************/
/* Author  	: Ahmed Hassan     			 ***********************/
/* Date		: 14 FEB 2023				 ***********************/
/* Layer   	: MCAL           		   	 ***********************/
/* SWC      : GPIO           			 ***********************/
/* Version 	: 1.00             			 ***********************/
/***************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"


void MGPIO_voidSetPinDirection( u8 Copy_u8Port , u8 Copy_u8Pin , u8 u8Copy_u8Mode )
{
	switch(Copy_u8Port){
	case GPIOA:

		if(Copy_u8Pin <= 7 )
		{//low

			MGPIOA->CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ));// R M W
			MGPIOA->CRL |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 );

		}
		else if(Copy_u8Pin <=15 )
		{//high

			Copy_u8Pin = Copy_u8Pin - 8;
			MGPIOA->CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			MGPIOA->CRH |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 );
		}

		break;

	case GPIOB:

		if(Copy_u8Pin <= 7 )
		{//low

			MGPIOB->CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );// R M W
			MGPIOB->CRL |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;

		}
		else if(Copy_u8Pin <=15 )
		{//high

			Copy_u8Pin = Copy_u8Pin - 8;
			MGPIOB->CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			MGPIOB->CRH |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;
		}

		break;
	case GPIOC:

		if(Copy_u8Pin <= 7 )
		{//low

			MGPIOC->CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );// R M W
			MGPIOC->CRL |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;

		}
		else if(Copy_u8Pin <=15 )
		{//high

			Copy_u8Pin = Copy_u8Pin - 8;
			MGPIOC->CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			MGPIOC->CRH |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;
		}

		break;
	default :break;
	
	}
}

void MGPIO_voidSetPinValue( u8 Copy_u8Port , u8 Copy_u8Pin , u8 u8Copy_u8Value )
{
	switch(Copy_u8Port){
	case GPIOA:

		if( u8Copy_u8Value == HIGH )
		{

			SET_BIT( MGPIOA->ODR , Copy_u8Pin );

		}
		else if( u8Copy_u8Value == LOW )
		{
			CLR_BIT( MGPIOA->ODR , Copy_u8Pin );
		}

		break;
	case GPIOB:

		if( u8Copy_u8Value == HIGH )
		{

			SET_BIT( MGPIOB->ODR , Copy_u8Pin );

		}
		else if( u8Copy_u8Value == LOW )
		{
			CLR_BIT( MGPIOB->ODR , Copy_u8Pin );
		}

		break;
	case GPIOC:

		if( u8Copy_u8Value == HIGH )
		{

			SET_BIT( MGPIOC->ODR , Copy_u8Pin );

		}
		else if( u8Copy_u8Value == LOW )
		{
			CLR_BIT( MGPIOC->ODR , Copy_u8Pin );
		}

		break;

	}
}

u8   MGPIO_u8GetPinValue( u8 Copy_u8Port , u8 Copy_u8Pin )
{
	u8 LOC_u8Result = 0 ;

	switch(Copy_u8Port){
	case GPIOA:

		LOC_u8Result = GET_BIT( MGPIOA->IDR , Copy_u8Pin );

		break;
	case GPIOB:

		LOC_u8Result = GET_BIT( MGPIOB->IDR , Copy_u8Pin );

		break;
	case GPIOC:

		LOC_u8Result = GET_BIT( MGPIOB->IDR , Copy_u8Pin );

		break;

	}

	return LOC_u8Result;
	
}


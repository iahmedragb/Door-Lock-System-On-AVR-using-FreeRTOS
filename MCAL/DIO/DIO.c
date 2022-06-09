/*=======================================================================================
============================   - DIO.c				 ============================
============================   - Created: May 20, 2022			 ============================
============================   - Author: Ahmed Tiba			     ============================
============================   - Version : _1_				 ============================
============================   - Note :
									     *-
									     *-
=======================================================================================*/


/*=======================================================================================
============================   The Foundation Of Function   =============================
=========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
#include "../../LIB/Bit_Math.h"
#include "../../LIB/Std_Types.h"
#include "../../LIB/Error_State.h"

/*======================================*/

/*===========  INCLUDE MCAL  ===========*/
#include "DIO_Private.h"
#include "DIO_Config.h"
#include "DIO.h"
/*======================================*/

/*===========  INCLUDE HAL   ===========*/

/*======================================*/

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
/*
@Brief	:	Write the port specified direction as input or output

@param	:	DIO_DDRx where x can be (A..D) to select the DIO peripheral for atmega32 device

@param	:	Copy_DDRx_Value Specified Value

@return	:	Error State value

*/
ES_t M_DIO_enuSetPortDirection(DIO_DDR DIO_DDRx, u8 Copy_DDRx_Value)
{
	if(DIO_DDRx <= DIO_DDRD)
	{
		switch(DIO_DDRx)
			{
				case DIO_DDRA : DDRA = Copy_DDRx_Value;break;
				case DIO_DDRB : DDRB = Copy_DDRx_Value;break;
				case DIO_DDRC : DDRC = Copy_DDRx_Value;break;
				case DIO_DDRD : DDRD = Copy_DDRx_Value;break;
			}
		return ES_OK;
	}else
	{
		return ES_OUT_OF_RANGE;
	}
	return ES_NOK;
}
/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
/*
@Brief	:	Write the port pin specified direction as input or output

@param	:	DIO_DDRx where x can be (A..D) to select the DIO peripheral for atmega32 device

@param	:	DIO_Pinx where x can be (0..7) to select the DIO peripheral for atmega32 device

@param	:	DIO_Directionx where x can be (Input or Output) to select the DIO peripheral for atmega32 device

@return	:	Error State value

*/
ES_t M_DIO_enuSetPinDirection(DIO_DDR DIO_DDRx,DIO_Pin DIO_Pinx, DIO_Direction DIO_Directionx)
{
	if((DIO_DDRx <= DIO_DDRD) &&( DIO_Pinx <= DIO_Pin7) && (DIO_Directionx <=DIO_Direction_Output))
		{
			switch(DIO_DDRx)
				{
					case DIO_DDRA : CLR_BIT(DDRA,DIO_Pinx);DDRA|=(DIO_Directionx<<DIO_Pinx);break;
					case DIO_DDRB : CLR_BIT(DDRB,DIO_Pinx);DDRB|=(DIO_Directionx<<DIO_Pinx);break;
					case DIO_DDRC : CLR_BIT(DDRC,DIO_Pinx);DDRC|=(DIO_Directionx<<DIO_Pinx);break;
					case DIO_DDRD : CLR_BIT(DDRD,DIO_Pinx);DDRD|=(DIO_Directionx<<DIO_Pinx);break;
				}
			return ES_OK;
		}else
		{
			return ES_OUT_OF_RANGE;
		}
		return ES_NOK;
}
/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
/*
@Brief	:	Write the port specified Output Value

@param	:	DIO_PORTx where x can be (A..D) to select the DIO peripheral for atmega32 device

@param	:	Copy_PORTx_Value Specified Value

@return	:	Error State value
*/
ES_t M_DIO_enuSetPortValue(DIO_PORT DIO_PORTx, u8 Copy_PORTx_Value)
{
	if(DIO_PORTx <= DIO_PORTD)
	{
		switch(DIO_PORTx)
		{
		case DIO_PORTA : PORTA = Copy_PORTx_Value;break;
		case DIO_PORTB : PORTB = Copy_PORTx_Value;break;
		case DIO_PORTC : PORTC = Copy_PORTx_Value;break;
		case DIO_PORTD : PORTD = Copy_PORTx_Value;break;
		}
		return ES_OK;
	}else
	{
		return ES_OUT_OF_RANGE;
	}
	return ES_NOK;
}

/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
/*
@Brief	:	Write the port pin specified state as low or high

@param	:	DIO_PORTx where x can be (A..D) to select the DIO peripheral for atmega32 device

@param	:	DIO_Pinx where x can be (0..7) to select the DIO peripheral for atmega32 device

@param	:	DIO_Statex where x can be (Low or High) to select the DIO peripheral for atmega32 device

@return	:	Error State value

*/
ES_t M_DIO_enuSetPinValue(DIO_PORT DIO_PORTx,DIO_Pin DIO_Pinx, DIO_State DIO_Statex)
{
	if(DIO_PORTx <= DIO_PORTD && DIO_Pinx <= DIO_Pin7 && DIO_Statex <=DIO_State_High)
		{
			switch(DIO_PORTx)
			{
				case DIO_PORTA: CLR_BIT(PORTA,DIO_Pinx);PORTA |= (DIO_Statex<<DIO_Pinx);break;
				case DIO_PORTB: CLR_BIT(PORTB,DIO_Pinx);PORTB |= (DIO_Statex<<DIO_Pinx);break;
				case DIO_PORTC: CLR_BIT(PORTC,DIO_Pinx);PORTC |= (DIO_Statex<<DIO_Pinx);break;
				case DIO_PORTD: CLR_BIT(PORTD,DIO_Pinx);PORTD |= (DIO_Statex<<DIO_Pinx);break;
			}
			return ES_OK;
		}else
		{
			return ES_OUT_OF_RANGE;
		}
		return ES_NOK;
}
/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
/*
@Brief	:	Read the port value

@param	:	DIO_DDRx where x can be (A..D) to select the DIO peripheral for atmega32 device

@param	:	Copy_pu8ReadPIN pointer to unsigned 8-bit character

@return	:	Error State value

*/

ES_t M_DIO_enuGetPINValue(DIO_PIN DIO_PINx, u8* Copy_pu8ReadPIN)
{
	if(Copy_pu8ReadPIN != NULL)
	{
		if(DIO_PINx <= DIO_PIND)
		{
			switch(DIO_PINx)
			{
				case DIO_PINA : *Copy_pu8ReadPIN = PINA;break;
				case DIO_PINB : *Copy_pu8ReadPIN = PINB;break;
				case DIO_PINC : *Copy_pu8ReadPIN = PINC;break;
				case DIO_PIND : *Copy_pu8ReadPIN = PIND;break;
			}
			return ES_OK;
		}
		else
		{
			return ES_OUT_OF_RANGE;
		}
	}else
	{
		return ES_NULL_POINTER;
	}
	return ES_NOK;
}
/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
/*
@Brief	:	Read the port pin specified state as low or high

@param	:	DIO_PINx where x can be (A..D) to select the DIO peripheral for atmega32 device

@param	:	DIO_Pinx where x can be (0..7) to select the DIO peripheral for atmega32 device

@param	:	Copy_pu8ReadPin a pointer to unsigned 8-bit character

@return	:	Error State value

*/
ES_t M_DIO_enuGetPinValue(DIO_PIN DIO_PINx,DIO_Pin DIO_Pinx, u8* Copy_pu8ReadPin)
{
	if(Copy_pu8ReadPin != NULL)
		{
			if(DIO_PINx <= DIO_PIND && DIO_Pinx<=DIO_Pin7)
			{
				switch(DIO_PINx)
				{
					case DIO_PINA : *Copy_pu8ReadPin = GET_BIT(PINA,DIO_Pinx) ;break;
					case DIO_PINB : *Copy_pu8ReadPin = GET_BIT(PINB,DIO_Pinx) ;break;
					case DIO_PINC : *Copy_pu8ReadPin = GET_BIT(PINC,DIO_Pinx) ;break;
					case DIO_PIND : *Copy_pu8ReadPin = GET_BIT(PIND,DIO_Pinx) ;break;
				}
				return ES_OK;
			}
			else
			{
				return ES_OUT_OF_RANGE;
			}
		}else
		{
			return ES_NULL_POINTER;
		}
		return ES_NOK;
}
/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
/*
@Brief	:	Toggle the port value

@param	:	DIO_PORTx where x can be (A..D) to select the DIO peripheral for atmega32 device

@return	:	Error State value

*/
ES_t M_DIO_enuTogglePortValue(DIO_PORT DIO_PORTx)
{
	if(DIO_PORTx <=DIO_PORTD)
	{
		switch(DIO_PORTx)
				{
				case DIO_PORTA : PORTA ^= 0xFF;break;
				case DIO_PORTB : PORTB ^= 0xFF;break;
				case DIO_PORTC : PORTC ^= 0xFF;break;
				case DIO_PORTD : PORTD ^= 0xFF;break;
				}
				return ES_OK;
	}else
	{
		return ES_OUT_OF_RANGE;
	}
	return ES_NOK;
}
/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
/*
@Brief	:	Toggle the port pin

@param	:	DIO_PORTx where x can be (A..D) to select the DIO peripheral for atmega32 device

@param	:	DIO_Pinx where x can be (0..7) to select the DIO peripheral for atmega32 device

@return	:	Error State value

*/
ES_t M_DIO_enuTogglePinValue(DIO_PORT DIO_PORTx,DIO_Pin DIO_Pinx)
{
	if(DIO_PORTx <= DIO_PORTD && DIO_Pinx <= DIO_Pin7)
			{
				switch(DIO_PORTx)
				{
					case DIO_PORTA: TGL_BIT(PORTA,DIO_Pinx);break;
					case DIO_PORTB: TGL_BIT(PORTB,DIO_Pinx);break;
					case DIO_PORTC: TGL_BIT(PORTC,DIO_Pinx);break;
					case DIO_PORTD: TGL_BIT(PORTD,DIO_Pinx);break;
				}
				return ES_OK;
			}else
			{
				return ES_OUT_OF_RANGE;
			}
			return ES_NOK;
	return ES_NOK;
}
/*====================================================   END_ FUNCTION   ====================================================*/


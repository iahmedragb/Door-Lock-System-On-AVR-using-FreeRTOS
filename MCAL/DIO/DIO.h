/*======================================================================================
========================    - DIO.h					 ===========================
========================    - Created: May 20, 2022			     ===========================
========================    - Author: Ahmed Tiba   			 ===========================
========================    - Version : _1_				     ===========================
========================    - Note :
									*-
									*-
=======================================================================================*/

/*=====================================================================================
		* What i sell To Customer
		*  The Architect Give The API
						- The Name Of Function
						- What is The Input
						- What Is The Output
						- Macro

======================================================================================*/
#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_
/*Enums*/
/**********  DDR   **********/

typedef enum
{
	DIO_DDRA=0,
	DIO_DDRB=1,
	DIO_DDRC=2,
	DIO_DDRD=3
}DIO_DDR;

/**********  PORT   **********/

typedef enum
{
	DIO_PORTA=0,
	DIO_PORTB=1,
	DIO_PORTC=2,
	DIO_PORTD=3
}DIO_PORT;

/**********  PIN   **********/

typedef enum
{
	DIO_PINA=0,
	DIO_PINB=1,
	DIO_PINC=2,
	DIO_PIND=3
}DIO_PIN;

/**********  Pin   **********/

typedef enum
{
	DIO_Pin0=0,
	DIO_Pin1=1,
	DIO_Pin2=2,
	DIO_Pin3=3,
	DIO_Pin4=4,
	DIO_Pin5=5,
	DIO_Pin6=6,
	DIO_Pin7=7
}DIO_Pin;

/**********  Direction   **********/

typedef enum
{
	DIO_Direction_Input=0,
	DIO_Direction_Output=1
}DIO_Direction;

/**********  State   **********/

typedef enum
{
	DIO_State_Low=0,
	DIO_State_High=1
}DIO_State;

/**********  Type   **********/

typedef enum
{
	DIO_Type_Float=0,
	DIO_Type_PullUp=1
}DIO_Type;

/*
@Brief	:	Write the port specified direction as input or output

@param	:	DIO_DDRx where x can be (A..D) to select the DIO peripheral for atmega32 device

@param	:	Copy_DDRx_Value Specified Value

@return	:	Error State value

*/
ES_t M_DIO_enuSetPortDirection(DIO_DDR DIO_DDRx, u8 Copy_DDRx_Value);

/*
@Brief	:	Write the port pin specified direction as input or output

@param	:	DIO_DDRx where x can be (A..D) to select the DIO peripheral for atmega32 device

@param	:	DIO_Pinx where x can be (0..7) to select the DIO peripheral for atmega32 device

@param	:	DIO_Directionx where x can be (Input or Output) to select the DIO peripheral for atmega32 device

@return	:	Error State value

*/
ES_t M_DIO_enuSetPinDirection(DIO_DDR DIO_DDRx,DIO_Pin DIO_Pinx, DIO_Direction DIO_Directionx);
/*
@Brief	:	Write the port specified Output Value

@param	:	DIO_PORTx where x can be (A..D) to select the DIO peripheral for atmega32 device

@param	:	Copy_PORTx_Value Specified Value

@return	:	Error State value
*/
ES_t M_DIO_enuSetPortValue(DIO_PORT DIO_PORTx, u8 Copy_PORTx_Value);
/*
@Brief	:	Write the port pin specified state as low or high

@param	:	DIO_PORTx where x can be (A..D) to select the DIO peripheral for atmega32 device

@param	:	DIO_Pinx where x can be (0..7) to select the DIO peripheral for atmega32 device

@param	:	DIO_Statex where x can be (Low or High) to select the DIO peripheral for atmega32 device

@return	:	Error State value

*/
ES_t M_DIO_enuSetPinValue(DIO_PORT DIO_PORTx,DIO_Pin DIO_Pinx, DIO_State DIO_Statex);
/*
@Brief	:	Read the port value

@param	:	DIO_DDRx where x can be (A..D) to select the DIO peripheral for atmega32 device

@param	:	Copy_pu8ReadPIN pointer to unsigned 8-bit character

@return	:	Error State value

*/

ES_t M_DIO_enuGetPINValue(DIO_PIN DIO_PINx, u8* Copy_pu8ReadPIN);
/*
@Brief	:	Read the port pin specified state as low or high

@param	:	DIO_PINx where x can be (A..D) to select the DIO peripheral for atmega32 device

@param	:	DIO_Pinx where x can be (0..7) to select the DIO peripheral for atmega32 device

@param	:	Copy_pu8ReadPin a pointer to unsigned 8-bit character

@return	:	Error State value

*/
ES_t M_DIO_enuGetPinValue(DIO_PIN DIO_PINx,DIO_Pin DIO_Pinx, u8* Copy_pu8ReadPin);
/*
@Brief	:	Toggle the port value

@param	:	DIO_PORTx where x can be (A..D) to select the DIO peripheral for atmega32 device

@return	:	Error State value

*/
ES_t M_DIO_enuTogglePortValue(DIO_PORT DIO_PORTx);
/*
@Brief	:	Toggle the port pin

@param	:	DIO_PORTx where x can be (A..D) to select the DIO peripheral for atmega32 device

@param	:	DIO_Pinx where x can be (0..7) to select the DIO peripheral for atmega32 device

@return	:	Error State value

*/
ES_t M_DIO_enuTogglePinValue(DIO_PORT DIO_PORTx,DIO_Pin DIO_Pinx);
#endif /* MCAL_DIO_DIO_H_ */

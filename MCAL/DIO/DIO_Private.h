/*======================================================================================
=======================    - DIO_Private.h					 ===========================
========================    - Created: May 20, 2022			     ===========================
========================    - Author: Ahmed Tiba   			 ===========================
========================    - Version : _1_				     ===========================
========================    - Note :
									*-
									*-
=======================================================================================*/


/**************************************************************************************

*	 - User can't Edit this file
	
		Contains
*	  - Register _ Defination
*	  - Developer Related : - Static API
							- Macro
							- User-Defined Datatypes

**************************************************************************************/
#ifndef MCAL_DIO_DIO_PRIVATE_H_
#define MCAL_DIO_DIO_PRIVATE_H_

/*PORT	D*/
#define PIND	(*(volatile u8*)(0x30))
#define DDRD	(*(volatile u8*)(0x31))
#define PORTD	(*(volatile u8*)(0x32))
/*PORT	C*/
#define PINC	(*(volatile u8*)(0x33))
#define DDRC	(*(volatile u8*)(0x34))
#define PORTC	(*(volatile u8*)(0x35))
/*PORT	B*/
#define PINB	(*(volatile u8*)(0x36))
#define DDRB	(*(volatile u8*)(0x37))
#define PORTB	(*(volatile u8*)(0x38))
/*PORT	A*/
#define PINA	(*(volatile u8*)(0x39))
#define DDRA	(*(volatile u8*)(0x3A))
#define PORTA	(*(volatile u8*)(0x3B))

#endif /* MCAL_DIO_DIO_PRIVATE_H_ */

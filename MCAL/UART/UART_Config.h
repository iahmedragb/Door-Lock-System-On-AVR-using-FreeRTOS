/*
* UART_Config.h
*
* Created: 3/30/2022 5:09:09 PM
*  Author: Ahmed
*/


#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

#define Freq	16000000UL
#define Bauderate	9600UL
typedef enum
{
	Asynchronous=0,
	Synchronous
}UART_MODE_t;

typedef enum
{
	Disable=0,
	Even=2,
	Odd=3
}UART_Parity_t;
typedef enum
{
	One_bit=0,
	Two_bit=1
}UART_Stop_Bits_t;
typedef enum
{
	Five_bit=0,
	Six_bit=1,
	Seven_bit=2,
	Eight_bit=3,
	Nine_bit=7
}UART_DataMode_t;
typedef enum
{
	Transmit_Rising_Receive_Falling=0,
	Transmit_Falling_Receive_Rising=1
}UART_CLK_Polarity_t;
#endif /* UART_CONFIG_H_ */
/*
 * UART_Prog.c
 *
 * Created: 3/30/2022 5:09:26 PM
 *  Author: Ahmed
 */ 
#include "../../LIB/Bit_Math.h"
#include "../../LIB/Std_Types.h"
#include "../../LIB/Error_State.h"
#include "../../LIB/Interrupt.h"

#include "UART_Config.h"
#include "UART_Private.h"
static void(*UART_AppFun)(void)=NULL;
static volatile u8 *UART_AppParameter=NULL;
void UART_Init(void)
{
	CLR_BIT(DDRD,0);
	SET_BIT(DDRD,1);
	/*Enable Rx*/
	SET_BIT(UCSRB,4);
	/*Enable Tx*/
	SET_BIT(UCSRB,3);
	
	/*UCSRC Select*/	/*Asynchronous mode*/	/*Parity mode disabled*/			/*1-bit stop*/		/*8-bits character size*/			/*Clock Polarity*/
	SET_BIT(UCSRC,7);	CLR_BIT(UCSRC,6);		CLR_BIT(UCSRC,5);CLR_BIT(UCSRC,4);	CLR_BIT(UCSRC,3);	SET_BIT(UCSRC,2);SET_BIT(UCSRC,1);	CLR_BIT(UCSRC,0);
	
	
	/*Baud Rate 9600*/
	UBRRL = 51;

	/*Interreupt ON receive*/
	SET_BIT(UCSRB,7);
}
void UART_Send(u8 data)
{
	/*Wait till buffer is empty*/
	while((GET_BIT(UCSRA,5)) == 0);
	/*Transmit data*/
	UDR = data;
}
u8 UART_Receive(void)
{
	/*Wait for data to be received*/
	while((GET_BIT(UCSRA,7)) == 0);
	/*Return the received data*/
	return UDR;
}
void UART_Callback(void (*pAppFun)(void),u8 * pAppParameter)
{
	UART_AppFun=pAppFun;
	UART_AppParameter = pAppParameter;
}
ISR(USART_RXC_vect_13)
{
	*UART_AppParameter=UDR;
	UART_AppFun();
}

/*
 * UART_Interface.h
 *
 * Created: 3/30/2022 5:09:01 PM
 *  Author: Ahmed
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_Init(void);
void UART_Send(u8 data);
u8 UART_Receive(void);
void UART_Callback(void (*pAppFun)(void),u8 * pAppParameter);


#endif /* UART_INTERFACE_H_ */

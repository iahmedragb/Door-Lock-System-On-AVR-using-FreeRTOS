/*
 * UART_Private.h
 *
 * Created: 3/30/2022 5:09:17 PM
 *  Author: Ahmed
 */ 


#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_
#define DDRD	(*(volatile u8*)(0x31))

#define UDR		(*(volatile u8*)(0x2C))
#define UCSRA	(*(volatile u8*)(0x2B))
#define UCSRB	(*(volatile u8*)(0x2A))
#define UBRRL	(*(volatile u8*)(0x29))
#define UCSRC	(*(volatile u8*)(0x40))
//#define UBRRH	(*(volatile u8*)(0x40))



#endif /* UART_PRIVATE_H_ */
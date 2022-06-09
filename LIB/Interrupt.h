/*
 * Interrupt.h
 *
 * Created: 3/19/2022 10:44:08 PM
 *  Author: Ahmed
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#define ISR(vect_num)	void vect_num(void)__attribute__((signal));\
						void vect_num(void)
						
#define RESET_vect_0			__vector_0
#define INT0_vect_1				__vector_1
#define INT1_vect_2				__vector_2
#define INT2_vect_3				__vector_3
#define TIMER2_COMP_vect_4		__vector_4
#define TIMER2_OVF_vect_5		__vector_5
#define TIMER1_CAPT_vect_6		__vector_6
#define TIMER1_COMPA_vect_7		__vector_7
#define TIMER1_COMPB_vect_8		__vector_8
#define TIMER1_OVF_vect_9		__vector_9
#define TIMER0_COMP_vect_10		__vector_10
#define TIMER0_OVF_vect_11		__vector_11
#define SPI_STC_vect_12			__vector_12
#define USART_RXC_vect_13		__vector_13
#define USART_UDRE_vect_14		__vector_14
#define USART_TXC_vect_15		__vector_15
#define ADC_vect_16				__vector_16
#define EE_RDY_vect_17			__vector_17
#define ANA_COMP_vect_18		__vector_18
#define TWI_vect_19				__vector_19
#define SPM_RDY_vect_20			__vector_20



#endif /* INTERRUPT_H_ */
/*
 * Bit_Math.h
 *
 * Created: 3/18/2022 7:21:53 PM
 *  Author: Ahmed
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT) (REG) |= (1<<(BIT))
#define CLR_BIT(REG,BIT) (REG) &= ~(1<<(BIT))
#define TGL_BIT(REG,BIT) (REG) ^= (1<<(BIT))
#define GET_BIT(REG,BIT) (((REG)>>(BIT))&(1U))

#endif /* BIT_MATH_H_ */

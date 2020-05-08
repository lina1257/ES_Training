/*
 * Bit_Math.h
 *
 * Created: 4/20/2020 1:17:34 PM
 *  Author: Lina
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define   Set_Bit(Reg,bit)           Reg|=(1<<bit)
#define   Clear_Bit(Reg,bit)         Reg&=~(1<<bit)
#define   Toggel_Bit(Reg,bit)        Reg^=(1<<bit)

#define   Get_Bit(Reg,bit)           ((Reg>>bit)&1)



#endif /* BIT_MATH_H_ */
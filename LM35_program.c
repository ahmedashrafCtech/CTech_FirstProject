/*
 * LM35_program.c
 *
 *  Created on: Feb 28, 2023
 *      Author: Abdullah.Abomosallam
 */


#include"../../MCAL/ADC/ADC_interface.h"
#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"

#include"LM35_interface.h"
void LM35_voidInit(void)
{


	ADC_voidInit();


}
f32 LM35_u16ReadTemp()
{
	ADC_voidStartConversion();
	while(ADC_u8CheckFlag()==0);
	u16 Local_u16Steps =ADC_u8Getvalue();//each step equivalent to 4.8mv
f32 Local_f32Volt=(f32)Local_u16Steps*4.8;
//each 10mv is equivalent to 1 Celsuis degree

return (Local_f32Volt/10.0 );




}

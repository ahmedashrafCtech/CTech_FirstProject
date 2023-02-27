/*
 *  * ADC_interface.h
 *
 *  Created on: Feb 27, 2023
 *      Author: Abdullah.Abomosallam
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

#include"../../LIB/STD_TYPES.h"

#define ADC_AREF           1
#define ADC_AVCC           2
#define ADC_INTERNAL2V    3
///////////////////////

#define ADC_RIGHT      1
#define ADC_LEFT       2

#define ADC_SINGLE_ENDED  0
#define ADC_DIFFRENTIAL   1

#define ADC_CHANNEL0      0
#define ADC_CHANNEL1      1
#define ADC_CHANNEL2      2
#define ADC_CHANNEL3      3
#define ADC_CHANNEL4      4
#define ADC_CHANNEL5      5
#define ADC_CHANNEL6      6
#define ADC_CHANNEL7      7


#define ADC_POLLING   0
#define ADC_INTERRUPT 1


#define ADC_PRESCALER_2   1
#define ADC_PRESCALER_4   2
#define ADC_PRESCALER_8   3
#define ADC_PRESCALER_16  4
#define ADC_PRESCALER_32  5
#define ADC_PRESCALER_64  6
#define ADC_PRESCALER_128 7

#define ADC_SINGLE_CONVERSION     0
#define ADC_FREE_RUNNING          1

void ADC_voidInit();
u16 ADC_u8Getvalue();
u8 ADC_u8CheckFlag();
void ADC_voidStartConversion();

#endif /* MCAL_ADC_ADC_INTERFACE_H_ */

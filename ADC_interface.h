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

#define ADC_SCHANNEL0      0b00000000  //s For single ended
#define ADC_SCHANNEL1      0b00000001
#define ADC_SCHANNEL2      0b00000010
#define ADC_SCHANNEL3      0b00000011
#define ADC_SCHANNEL4      0b00000100
#define ADC_SCHANNEL5      0b00000101
#define ADC_SCHANNEL6      0b00000110
#define ADC_SCHANNEL7      0b00000111
   //D for deffrential
#define ADC_DCHANNEL0      0b00010000
#define ADC_DCHANNEL1      0b00010001
#define ADC_DCHANNEL2      0b00010010
#define ADC_DCHANNEL3      0b00010011
#define ADC_DCHANNEL4      0b00010100
#define ADC_DCHANNEL5      0b00010101
#define ADC_DCHANNEL6      0b00010110
#define ADC_DCHANNEL7      0b00010111


#define ADC_MUXMASK      0b11100000

#define ADC_POLLING   0
#define ADC_INTERRUPT 1


#define ADC_PRESCALER_2    0b00000000
#define ADC_PRESCALER_4    0b00000001
#define ADC_PRESCALER_8    0b00000011
#define ADC_PRESCALER_16   0b00000100
#define ADC_PRESCALER_32   0b00000101
#define ADC_PRESCALER_64   0b00000110
#define ADC_PRESCALER_128  0b00000111
#define ADC_PREDCALER_MASK 0b11111000

#define ADC_SINGLE_CONVERSION     0
#define ADC_FREE_RUNNING          1
/**
 * this function initialize the ADC peripheral
 * @param void
 * @return void
 *
 *
 */
void ADC_voidInit();

/**
 *this function gets the value of analouge signal
 *@return unsigned  16 bit value
 * @param non
 *
 *
 *
 */
u16 ADC_u8Getvalue();
u8 ADC_u8CheckFlag();
void ADC_voidStartConversion();

#endif /* MCAL_ADC_ADC_INTERFACE_H_ */

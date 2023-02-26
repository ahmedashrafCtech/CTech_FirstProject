/*
 * BTN_interface.h
 *
 *  Created on: Feb 26, 2023
 *      Author: Abdullah.Abomosallam
 */

#ifndef HAL_BTN_BTN_INTERFACE_H_
#define HAL_BTN_BTN_INTERFACE_H_
#include"BIT_MATH.h"
#include"STD_TYPES.h"

typedef struct
{
u8 port;
u8 pin;
u8 connection;




}BTN_TYPE;



#define BTN_PULLUP 1
#define BTN_FLOATING 0

#define BTN_PRESSED     1
#define BTN_NOT_PRESSED 0

#define DCM_PORTA  0
#define BTN_PORTB  1
#define BTN_PORTC  2
#define BTN_PORTD  3


#define BTN_PIN0   0
#define BTN_PIN1   1
#define BTN_PIN2   2
#define BTN_PIN3   3
#define BTN_PIN4   4
#define BTN_PIN5   5
#define BTN_PIN6   6
#define BTN_PIN7   7


void BTN_VoidInit(BTN_TYPE *PtrStruct );
u8 BTN_u8GetButtonStatus (BTN_TYPE *PtrStruct);

#endif /* HAL_BTN_BTN_INTERFACE_H_ */

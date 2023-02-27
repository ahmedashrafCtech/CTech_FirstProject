/*
 * Timer0.h
 *
 *  Created on: Feb 27, 2023
 *      Author: Osama.Mahmoud
 */

#ifndef TIMER0_H_
#define TIMER0_H_

#include "STD_TYPES.h"

#define FOC0       7
#define WGM00      6
#define COM01      5
#define COM00      4
#define WGM01      3

#define OCF0    1
#define TOV0    0

#define OCIE0   1
#define TOIE0   0

#define TCCR0    (*(volatile u8*)(0x53))
#define TCNT0    (*(volatile u8*)(0x52))
#define TWCR     (*(volatile u8*)(0x56))
#define SPMCR    (*(volatile u8*)(0x57))
#define TIFR     (*(volatile u8*)(0x58))
#define TIMSK    (*(volatile u8*)(0x59))
#define OCR0     (*(volatile u8*)(0x5C))


#define NORMAL_MODE           0
#define PHASE_CORRECT_MODE    1
#define CTC_MODE              2
#define FASTPWM_MODE          3

#define NO_CLOCK              0
#define PRESCALER_1           1
#define PRESCALER_8           2
#define PRESCALER_64          3
#define PRESCALER_256         4
#define PRESCALER_1024        5

#define DISSCONNECT_MODE      0
#define TOGGLE_MODE           1
#define INVERTING_MODE        2
#define NON_INVERTING_MODE    3

void Timer0_init(u8 mode , u8 prescaler , u8 compare_mode);
void Timer0_OV_InterruptEnable(void);
void Timer0_OV_InterruptDisable(void);
void Timer0_OC_InterruptEnable(void);
void Timer0_OC_InterruptDisable(void);
void Timer0_OVF_SetCallBack(void(*LocalFptr)(void));
void Timer0_Oc_SetCallBack(void(*LocalFptr)(void));

#endif /* TIMER0_H_ */

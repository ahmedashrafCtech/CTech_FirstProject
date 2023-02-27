/*
 * Timer0.c
 *
 *  Created on: Feb 27, 2023
 *      Author: Osama.Mahmoud
 */


#include "MemMap.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Timer0.h"



static void (*Timer0_OVF_Fptr) (void)=NULLPTR;
static void (*Timer0_OC_Fptr)  (void)=NULLPTR;

void Timer0_init(u8 mode , u8 prescaler , u8 OC0_mode)
{
	switch(mode)
	{
	case NORMAL_MODE:
		WRITE_BIT(TCCR0 , WGM00 , 0);
		WRITE_BIT(TCCR0 , WGM01 , 0);
		break;
	case PHASE_CORRECT_MODE:
		WRITE_BIT(TCCR0 , WGM00 , 1);
		WRITE_BIT(TCCR0 , WGM01 , 0);
		break;
	case CTC_MODE:
		WRITE_BIT(TCCR0 , WGM00 , 0);
		WRITE_BIT(TCCR0 , WGM01 , 1);
		break;
	case FASTPWM_MODE:
		WRITE_BIT(TCCR0 , WGM00 , 1);
		WRITE_BIT(TCCR0 , WGM01 , 1);
		break;
	}

	TCCR0 &= 0xF8;
	TCCR0 |= prescaler;

	switch(OC0_mode)
	{
	case DISSCONNECT_MODE:
		WRITE_BIT(TCCR0 , COM00 , 0);
		WRITE_BIT(TCCR0 , COM01 , 0);
		break;
	case TOGGLE_MODE:
		WRITE_BIT(TCCR0 , COM00 , 1);
		WRITE_BIT(TCCR0 , COM01 , 0);
		break;
	case NON_INVERTING_MODE:
		WRITE_BIT(TCCR0 , COM00 , 0);
		WRITE_BIT(TCCR0 , COM01 , 1);
		break;
	case INVERTING_MODE:
		WRITE_BIT(TCCR0 , COM00 , 1);
		WRITE_BIT(TCCR0 , COM01 , 1);
		break;
	}

}

void Timer0_OV_InterruptEnable(void)
{
	WRITE_BIT(TIMSK,TOIE0 , 1);
}
void Timer0_OV_InterruptDisable(void)
{
	WRITE_BIT(TIMSK,TOIE0 , 0);
}
void Timer0_OC_InterruptEnable(void)
{
	WRITE_BIT(TIMSK,OCIE0 , 1);
}

void Timer0_OC_InterruptDisable(void)
{
	WRITE_BIT(TIMSK,OCIE0 , 0);
}


void Timer0_OVF_SetCallBack(void(*LocalFptr)(void))
{
	Timer0_OVF_Fptr=LocalFptr;
}

void Timer0_Oc_SetCallBack(void(*LocalFptr)(void))
{
	Timer0_OC_Fptr=LocalFptr;
}


ISR(TIMER0_OVF_vect)
{
	if (Timer0_OVF_Fptr!=NULLPTR)
	{
		Timer0_OVF_Fptr();
	}
}
ISR(TIMER0_COMP_vect)
{
	if (Timer0_OC_Fptr!=NULLPTR)
	{
		Timer0_OC_Fptr();
	}
}

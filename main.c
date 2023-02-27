/*
 * main.c
 *
 *  Created on: Feb 23, 2023
 *      Author: Osama.Mahmoud
 */

#include "MemMap.h"
#include "STD_TYPES.h"
#include "DIO.h"
#include "Timer0.h"

volatile u16 c=0,flag,ton,ttotal;
volatile s32 T_total;
void func1(void)
{
	if (flag==0)
	{
		ton=10;
		flag=1;
	}
	else if (flag==1)
	{
		ton=15;
		flag=2;
	}
	else if (flag==2)
	{
		ton=20;
		flag=0;
	}
}

void func2(void)
{
	static u8 c=0;
	c++;
	if (c==ton)
	{
		DIO_WrtPin(PortD , Pin4 , Pin_Low);
	}
	else if (c==ttotal)
	{
		DIO_WrtPin(PortD , Pin4 , Pin_High);
		c=0;
	}
}

int main()
{
	sei();
	EXI_Enable(EX_INT0);
	EXTI_TriggerEdge(EX_INT0,FALLING_EDGE);

	DIO_EXTI_CallBack(EX_INT0 , func1);
	Timer0_Oc_SetCallBack(func2);
	Timer0_init(CTC_MODE , PRESCALER_8 , DISSCONNECT_MODE);
	OCR0 = 99;                   //each 100us -> oc interrupt
	ttotal = 200;

	Timer0_OC_InterruptEnable();
	while(1)
	{

	}

	return 0;
}

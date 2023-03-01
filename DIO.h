
#ifndef		DIO_H
#define		DIO_H



#include "BIT_MATH.h"

#include "DIO_reg.h"

#define 	PORT_HIGH_VAL 	0xFF
#define		PORT_LOW_VAL	0x00




#define     EX_NONE            0
#define 	EX_INT0            1
#define 	EX_INT1            2
#define 	EX_INT2            3

#define     GPIO_MODE          0
#define     EXTI_MODE          1

#define     NONE_EDGE          0
#define 	LOW_LEVEL          1
#define 	ANY_LOGIC_CHANGE   2
#define 	FALLING_EDGE       3
#define 	RISING_EDGE        4

//#define     EDGE_LEVEL             FALLING_EDGE


typedef enum {
	Pin0,
	Pin1,
	Pin2,
	Pin3,
	Pin4,
	Pin5,
	Pin6,
	Pin7,
}Pin_Num;

typedef enum {
	PortA,
	PortB,
	PortC,
	PortD,
}Port_Num;

typedef enum {
	Pin_Input,
	Pin_Output,
}Pin_DirType;

typedef enum {
	Pin_Low,
	Pin_High,
}Pin_ValType;




void DIO_SetDir(Port_Num Port, Pin_Num Pin, Pin_DirType Pin_Dir);

void DIO_ENPullup(Port_Num Port, Pin_Num Pin);

void DIO_WrtPin(Port_Num Port, Pin_Num Pin, Pin_ValType Value);

u8 DIO_READPin(Port_Num Port, Pin_Num Pin);

void DIO_TglPin(Port_Num Port, Pin_Num Pin);

void DIO_WRTPort(Port_Num Port, u8 Value);

void DIO_DIRPort(Port_Num Port, u8 Direction);

void EXI_Enable(u8 Interrupt);
void EXI_Disable(u8 Interrupt);
void EXTI_TriggerEdge(u8 Interrupt,u8 Edge);
void DIO_EXTI_CallBack(u8 Interrupt,void(*LocalPtr)(void));


#endif

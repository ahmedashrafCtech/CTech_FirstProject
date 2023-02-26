
#ifndef		DIO_H
#define		DIO_H

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#define 	PORT_HIGH_VAL 	0xFF
#define		PORT_LOW_VAL	0x00

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


#endif

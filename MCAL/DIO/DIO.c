#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_reg.h"

#include "DIO.h"
#include "DIO_config.h"



void DIO_SetDir(Port_Num Port, Pin_Num Pin, Pin_DirType Pin_Dir)
{
	switch (Port){
		case PortA:
			WRITE_BIT(DIO_DDRA_REG,Pin,Pin_Dir);
		break;
		case PortB:
			WRITE_BIT(DIO_DDRB_REG,Pin,Pin_Dir);
		break;
		case PortC:
			WRITE_BIT(DIO_DDRC_REG,Pin,Pin_Dir);
		break;
		case PortD:
			WRITE_BIT(DIO_DDRD_REG,Pin,Pin_Dir);
		break;
		default:
		break;
		
	}
}

void DIO_ENPullup(Port_Num Port, Pin_Num Pin)
{
	WRITE_BIT(DIO_SFIOR_REG,DIO_SFIOR_PUD,STD_LOW);
	DIO_WrtPin(Port, Pin, Pin_High);
}

void DIO_WrtPin(Port_Num Port, Pin_Num Pin, Pin_ValType Value)
{
	switch (Port){
		case PortA:
			WRITE_BIT(DIO_PORTA_REG,Pin,Value);
		break;
		case PortB:
			WRITE_BIT(DIO_PORTB_REG,Pin,Value);
		break;
		case PortC:
			WRITE_BIT(DIO_PORTC_REG,Pin,Value);
		break;
		case PortD:
			WRITE_BIT(DIO_PORTD_REG,Pin,Value);
		break;
		default:
		break;
		
	}
}

u8 DIO_READPin(Port_Num Port, Pin_Num Pin)
{
	u8 Local_u8Data = 0;
	switch (Port){
		case PortA:
			Local_u8Data = GET_BIT(DIO_PINA_REG,Pin);
		break;
		case PortB:
			Local_u8Data = GET_BIT(DIO_PINB_REG,Pin);
		break;
		case PortC:
			Local_u8Data = GET_BIT(DIO_PINC_REG,Pin);
		break;
		case PortD:
			Local_u8Data = GET_BIT(DIO_PIND_REG,Pin);
		break;
		default:
		break;
		
	}
	return Local_u8Data;
}

void DIO_TglPin(Port_Num Port, Pin_Num Pin)
{
	switch (Port){
		case PortA:
			TOGGLE_BIT(DIO_PORTA_REG,Pin);
		break;
		case PortB:
			TOGGLE_BIT(DIO_PORTB_REG,Pin);
		break;
		case PortC:
			TOGGLE_BIT(DIO_PORTC_REG,Pin);
		break;
		case PortD:
			TOGGLE_BIT(DIO_PORTD_REG,Pin);
		break;
		default:
		break;
		
	}
}

void DIO_WRTPort(Port_Num Port, u8 Value)
{
	switch (Port){
		case PortA:
			DIO_PORTA_REG = Value;
		break;
		case PortB:
			DIO_PORTB_REG = Value;
		break;
		case PortC:
			DIO_PORTC_REG = Value;
		break;
		case PortD:
			DIO_PORTD_REG = Value;
		break;
		default:
		break;
		
	}
}

void DIO_DIRPort(Port_Num Port, u8 Direction)
{
	switch (Port){
		case PortA:
			DIO_DDRA_REG = Direction;
		break;
		case PortB:
			DIO_DDRB_REG = Direction;
		break;
		case PortC:
			DIO_DDRC_REG = Direction;
		break;
		case PortD:
			DIO_DDRD_REG = Direction;
		break;
		default:
		break;
		
	}
}

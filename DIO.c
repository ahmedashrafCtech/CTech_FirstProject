
#include "STD_TYPES.h"
#include "MemMap.h"
#include "DIO.h"
#include "DIO_config.h"


static void (*INT0_Fptr) (void)=NULLPTR;
static void (*INT1_Fptr) (void)=NULLPTR;
static void (*INT2_Fptr) (void)=NULLPTR;

void EXTI_TriggerEdge(u8 Interrupt,u8 Edge)
{
	switch(Interrupt){
		case EX_INT0:
		switch(Edge){
			case LOW_LEVEL:
			WRITE_BIT(MCUCR,ISC00 , STD_LOW);
			WRITE_BIT(MCUCR,ISC01 , STD_LOW);
			break;
			case ANY_LOGIC_CHANGE:
			WRITE_BIT(MCUCR,ISC00 , STD_HIGH);
			WRITE_BIT(MCUCR,ISC01 , STD_LOW);
			break;
			case FALLING_EDGE:
			WRITE_BIT(MCUCR,ISC00 , STD_LOW);
			WRITE_BIT(MCUCR,ISC01 , STD_HIGH);
			break;
			case RISING_EDGE:
			WRITE_BIT(MCUCR,ISC00 , STD_HIGH);
			WRITE_BIT(MCUCR,ISC01 , STD_HIGH);
			break;

		}
		break;
		case EX_INT1:
		switch(Edge){
			case LOW_LEVEL:
			WRITE_BIT(MCUCR,ISC10 , STD_LOW);
			WRITE_BIT(MCUCR,ISC11 , STD_LOW);
			break;
			case ANY_LOGIC_CHANGE:
			WRITE_BIT(MCUCR,ISC10 , STD_HIGH);
			WRITE_BIT(MCUCR,ISC11 , STD_LOW);
			break;
			case FALLING_EDGE:
			WRITE_BIT(MCUCR,ISC10 , STD_LOW);
			WRITE_BIT(MCUCR,ISC11 , STD_HIGH);
			break;
			case RISING_EDGE:
			WRITE_BIT(MCUCR,ISC10 , STD_HIGH);
			WRITE_BIT(MCUCR,ISC11 , STD_HIGH);
			break;

		}
		break;
		case EX_INT2:
		switch(Edge){
			case FALLING_EDGE:
			WRITE_BIT(MCUCSR,ISC2 , STD_LOW);
			break;
			case RISING_EDGE:
			WRITE_BIT(MCUCSR,ISC2 , STD_HIGH);
			break;
			default:
			WRITE_BIT(MCUCSR,ISC2 , STD_LOW);
		}
		break;
	}

}

/*void DIO_EXTI_SetDir(Port_Num Port, Pin_Num Pin, Pin_DirType Pin_Dir , u8 Mode , u8 interrupt , u8 edge)
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

	if( (Pin_Dir == Pin_Input) && (Mode == EXTI_MODE) )
	{
		EXTI_TriggerEdge(interrupt, edge);
	}

}*/

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



void DIO_EXTI_CallBack(u8 Interrupt,void(*LocalPtr)(void))
{
	switch(Interrupt){
		case EX_INT0:
		INT0_Fptr=LocalPtr;
		break;
		case EX_INT1:
		INT1_Fptr=LocalPtr;
		break;
		case EX_INT2:
		INT2_Fptr=LocalPtr;
		break;
	}
}

void EXI_Enable(u8 Interrupt)
{
	switch(Interrupt){
		case EX_INT0:
		WRITE_BIT(GICR,INT0 , STD_HIGH);
		break;
		case EX_INT1:
		WRITE_BIT(GICR,INT1 , STD_HIGH);
		break;
		case EX_INT2:
		WRITE_BIT(GICR,INT2 , STD_HIGH);
		break;
	}
}
void EXI_Disable(u8 Interrupt)
{
		switch(Interrupt){
		case EX_INT0:
		WRITE_BIT(GICR,INT0 , STD_LOW);
		break;
		case EX_INT1:
		WRITE_BIT(GICR,INT1 , STD_LOW);
		break;
		case EX_INT2:
		WRITE_BIT(GICR,INT2 , STD_LOW);
		break;
	}
}


/*******************************ISR********************************/
ISR(INT0_vect)
{
	if (INT0_Fptr!=NULLPTR)
	{
		INT0_Fptr();
	}
}
ISR(INT1_vect)
{
	if (INT1_Fptr!=NULLPTR)
	{
		INT1_Fptr();
	}
}
ISR(INT2_vect)
{
	if (INT2_Fptr!=NULLPTR)
	{
		INT2_Fptr();
	}
}

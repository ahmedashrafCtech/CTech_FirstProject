#include"../../LIB/STD_TYPES.h"
#include"../../MCAL/DIO/DIO.h"


#define DCM_FORWARD 1
#define DCM_REVERSE 0

#define DCM_PORTA  0
#define DCM_PORTB  1
#define DCM_PORTC  2
#define DCM_PORTD  3


#define DCM_PIN0   0
#define DCM_PIN1   1
#define DCM_PIN2   2
#define DCM_PIN3   3
#define DCM_PIN4   4
#define DCM_PIN5   5
#define DCM_PIN6   6
#define DCM_PIN7   7



typedef struct 
{
	u8 port;
	u8 pin ;
	u8 connection;
	
} DCM_TYPE;

void DCM_voidDCMOn(DCM_TYPE copy_DCMStructDCM1);
void DCM_voidDCMOff(DCM_TYPE copy_DCMStructDCM1);
void DCM_voidInit(DCM_TYPE copy_DCMStructDCM1);

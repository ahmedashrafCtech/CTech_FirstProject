#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO.h"
#include"DCM_interface.h"

void DCM_voidDCMOn(DCM_TYPE copy_DCMStructDCM1)

{
	if((copy_DCMStructDCM1.connection)==DCM_FORWARD)
	{
DIO_WrtPin(copy_DCMStructDCM1.port,copy_DCMStructDCM1.pin,Pin_High);
	}
	else if((copy_DCMStructDCM1.connection)==DCM_REVERSE)
	{
DIO_WrtPin(copy_DCMStructDCM1.port,copy_DCMStructDCM1.pin,Pin_Low);	
	}
	
}
void DCM_voidDCMOff(DCM_TYPE copy_DCMStructDCM1)
{
	
	
	if((copy_DCMStructDCM1.connection)==DCM_FORWARD)
	{
DIO_WrtPin(copy_DCMStructDCM1.port,copy_DCMStructDCM1.pin,Pin_Low);
	}
	else if((copy_DCMStructDCM1.connection)==DCM_REVERSE)
	{
DIO_WrtPin(copy_DCMStructDCM1.port,copy_DCMStructDCM1.pin,Pin_High);	
	}
	
	
	
}
void DCM_voidInit(DCM_TYPE copy_DCMStructDCM1)
{
	
	DIO_SetDir(copy_DCMStructDCM1.port,copy_DCMStructDCM1.pin, Pin_Output);
	
	
	
	
	
	
}



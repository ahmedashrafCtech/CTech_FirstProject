/*
 * BTN_program.c
 *
 *  Created on: Feb 26, 2023
 *      Author: Abdullah.Abomosallam
 */

#include"BIT_MATH.h"
#include"STD_TYPES.h"

#include"BTN_interface.h"
#include"../../MCAL/DIO/DIO.h"

void BTN_VoidInit(BTN_TYPE *PtrStruct )
{

	DIO_SetDir(PtrStruct->port,PtrStruct->pin,Pin_Input);
if(PtrStruct->connection==BTN_PULLUP)
{

DIO_ENPullup(PtrStruct->port,PtrStruct->pin);


}


}
u8 BTN_u8GetButtonStatus (BTN_TYPE *PtrStruct)
{

u8 local_u8Status= DIO_READPin(PtrStruct->port,PtrStruct->pin);

if(PtrStruct->connection==BTN_PULLUP)

{
if(local_u8Status==Pin_Low)
{

	return BTN_PRESSED ;
}

else if (local_u8Status==Pin_High)
{

	return BTN_NOT_PRESSED ;

}

}

else if(PtrStruct->connection==BTN_FLOATING)
{
	{
	if(local_u8Status==Pin_Low)
	{

		return BTN_NOT_PRESSED ;
	}

	else if (local_u8Status==Pin_High)
	{

		return BTN_PRESSED ;

	}

	}



}

}

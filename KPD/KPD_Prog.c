/********************************************/
/*  Auther : Alsabagh                       */
/*  Version : V01                           */
/*  Date    : 26 FEB 2023                   */
/********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "KPD_Private.h"
#include "KPD_Config.h"
#include "KPD_Int.h"

#include"util/delay.h"

void HKPD_vidKpdInit(void)
{
	DIO_SetDir(KPD_R1_PORT,KPD_R1_PIN,Pin_Output);
	DIO_SetDir(KPD_R2_PORT,KPD_R2_PIN,Pin_Output);
	DIO_SetDir(KPD_R3_PORT,KPD_R3_PIN,Pin_Output);
	DIO_SetDir(KPD_R3_PORT,KPD_R4_PIN,Pin_Output);

	DIO_SetDir(KPD_C1_PORT,KPD_C1_PIN,Pin_Input);
	DIO_SetDir(KPD_C2_PORT,KPD_C2_PIN,Pin_Input);
	DIO_SetDir(KPD_C3_PORT,KPD_C3_PIN,Pin_Input);
	DIO_SetDir(KPD_C4_PORT,KPD_C4_PIN,Pin_Input);

	DIO_WrtPin(KPD_R1_PORT,KPD_R1_PIN,Pin_High);
	DIO_WrtPin(KPD_R2_PORT,KPD_R2_PIN,Pin_High);
	DIO_WrtPin(KPD_R3_PORT,KPD_R3_PIN,Pin_High);
	DIO_WrtPin(KPD_R4_PORT,KPD_R4_PIN,Pin_High);
}
u8   HKPD_vidKpdRead(void)
{
	u8 Local_u8KpdValue = NOT_PRESSED ;
	u8 Local_u8RowNum = 0 ;
	u8 Local_u8ColNum = 0 ;

	for(Local_u8RowNum = KPD_R1_PIN ; Local_u8RowNum <=KPD_R4_PIN; Local_u8RowNum++)
	{
		DIO_WrtPin(KPD_R1_PORT,Local_u8RowNum,Pin_Low);
		for(Local_u8ColNum = KPD_C1_PIN ; Local_u8ColNum <=KPD_C4_PIN ;Local_u8ColNum++)
		{
			if(DIO_READPin(KPD_C1_PORT , Local_u8ColNum) == PRESSED )
			{
				_delay_ms(DEBOUNCING_TIME);
				if(DIO_READPin(KPD_C1_PORT , Local_u8ColNum) == PRESSED )
				{
					while(DIO_READPin(KPD_C1_PORT , Local_u8ColNum) == PRESSED);
					Local_u8KpdValue = KPD_Value[Local_u8RowNum - KPD_R1_PIN ][Local_u8ColNum - KPD_C1_PIN];
					break ;
				}
			}
		}
		DIO_WrtPin(KPD_R1_PORT,Local_u8RowNum,Pin_High);
	}
	return Local_u8KpdValue ;

}

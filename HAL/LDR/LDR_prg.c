
/**
 * @file LDR_prg.c
 * @author Ahmed Ashraf
 * @brief program file of LDR
 * @version 1.0
 * @date 1/3/2023
 * @copyright Coretech Innovations company 2023
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LDR_prv.h"
#include "LDR_cfg.h"
#include "LDR_int.h"
#include "ADC_interface.h"




u16 H_LDR_u16GetValue(void)
{
	u16 Local_u16Data;

	ADC_voidStartConversion();
	while(!(ADC_u8CheckFlag()));
	Local_u16Data = ADC_u8Getvalue();
	return Local_u16Data;
}

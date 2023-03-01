/********************************************/
/*  Auther : Alsabagh                       */
/*  Version : V01                           */
/*  Date    : 27 FEB 2023                   */
/********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "IIC_Private.h"
#include "IIC_Config.h"
#include "IIC_Int.h"

void M_IIC_void_Init(void)
{
	// prescaler  =  1
	WRITE_BIT(TWSR_REG,TWPS1_BIT,0);
	WRITE_BIT(TWSR_REG,TWPS0_BIT,0);

	// Bit Rate  fCPU = 8 MHz, prescaler = 1 , SCL = 400 kHz
	TWBR_REG = 0x02;
	// Enable TWI
	WRITE_BIT(TWCR_REG,TWEN_BIT,1);
}

void M_IIC_void_sendStart(void)
{
	// send start + clear flag + Enable TWI
	TWCR_REG = (1<<TWINT_BIT)|(1<<TWSTA_BIT)|(1<<TWEN_BIT);
	// wait until job is done
	while(GET_BIT(TWCR_REG,TWINT_BIT) == 0);
}
void M_IIC_void_sendStop(void)
{
	// send stop + clear flag + Enable TWI
	TWCR_REG = (1<<TWINT_BIT)|(1<<TWEN_BIT)| (1<<TWSTO_BIT);
}


void M_IIC_void_sendByte(u8 copy_u8data)
{
	//load data to be sent to  data register (SLA+R/W or msg)
	TWDR_REG = copy_u8data;
	// clear flag + Enable TWI
	TWCR_REG = (1<<TWINT_BIT) | (1<<TWEN_BIT);
	// wait until job is done
	while(GET_BIT(TWCR_REG,TWINT_BIT) == 0);
}
u8   M_IIC_u8_getStatus(void)
{
	return (TWSR_REG & IIC_STATUS_MASK);
}
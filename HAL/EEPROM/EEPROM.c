#include "STD_TYPES.h"
#include "IIC_Int.h"
#include "EEPROM.h"


void EEPROM_Init(void)
{
	M_IIC_void_Init();
}
u8 EEPROM_Write_Byte( u16 address , u8 data)
{
   	M_IIC_void_sendStart();
	
	if(M_IIC_u8_getStatus() != IIC_MT_START_SUCCESS){
		return ERROR;
	}
	M_IIC_void_sendByte((u8)(0xA0 | ((address&0x0700)>>7)));
	
	if(M_IIC_u8_getStatus() != IIC_MT_SLA_W_ACK){
		return ERROR;
	}
	
	M_IIC_void_sendByte((u8)address);
	if(M_IIC_u8_getStatus() != IIC_MT_DATA_ACK){
		return ERROR;
	}
	
	M_IIC_void_sendByte(data);
	
	if(M_IIC_u8_getStatus() != IIC_MT_DATA_ACK){
		return ERROR;
	}
	M_IIC_void_sendStop();
	
	return SUCCESS;
}


u8 EEPROM_Read_Byte( u16 address , u8 *pdata)
{
	M_IIC_void_sendStart();
    if (M_IIC_u8_getStatus() != IIC_MR_START_SUCCESS)
        return ERROR;
		
    /* Send the device address, we need to get A8 A9 A10 address bits from the
     * memory location address and R/W=0 (write) */
    M_IIC_void_sendByte((u8)((0xA0) | ((address & 0x0700)>>7)));
    if (M_IIC_u8_getStatus() != IIC_MT_SLA_W_ACK)
        return ERROR;
		
    /* Send the required memory location address */
    M_IIC_void_sendByte((u8)(address));
    if (M_IIC_u8_getStatus() != IIC_MT_DATA_ACK)
        return ERROR;
		
    /* Send the Repeated Start Bit */
    M_IIC_void_sendStart();
    if (M_IIC_u8_getStatus() != IIC_MT_REPEATED_START_SUCCESS)
        return ERROR;
		
    /* Send the device address, we need to get A8 A9 A10 address bits from the
     * memory location address and R/W=1 (Read) */
    M_IIC_void_sendByte((u8)((0xA0) | ((address & 0x0700)>>7) | 1));
    if (M_IIC_u8_getStatus() != IIC_MR_SLA_R_ACK)
        return ERROR;

    /* Read Byte from Memory without send ACK */
     M_IIC_void_receiveByte_ACK(pdata);

    if (M_IIC_u8_getStatus() != IIC_MR_DATA_NOACK)
        return ERROR;

    /* Send the Stop Bit */
    M_IIC_void_sendStop();

    return SUCCESS;
	
}

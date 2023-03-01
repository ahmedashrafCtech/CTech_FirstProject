#ifndef EEPROM_H
#define EEPROM_H



#define ERROR 0
#define SUCCESS 1

#define M24C_ADD         0b1010000

void EEPROM_Init(void);
u8 EEPROM_Write_Byte( u16 address , u8 data);
u8 EEPROM_Read_Byte( u16 address , u8*pdata);



#endif
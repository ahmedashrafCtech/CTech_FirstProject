/********************************************/
/*  Auther : Alsabagh                       */
/*  Version : V01                           */
/*  Date    : 27 FEB 2023                   */
/********************************************/


#ifndef IIC_INT_H
#define IIC_INT_H

// Master Tx
#define IIC_MT_START_SUCCESS            0x08
#define IIC_MT_REPEATED_START_SUCCESS   0x10
#define IIC_MT_SLA_W_ACK                0x18
#define IIC_MT_SLA_W_NOACK              0x20
#define IIC_MT_DATA_ACK                 0x28   // I received ACK
#define IIC_MT_DATA_NOACK               0x30   // I received NO ACK
#define IIC_MT_ARBITRATION_LOST         0x38

//Master Rx
#define IIC_MR_START_SUCCESS            0x08
#define IIC_MR_REPEATED_START_SUCCESS   0x10
#define IIC_MR_SLA_R_ACK                0x40
#define IIC_MR_SLA_R_NOACK              0x48
#define IIC_MR_DATA_ACK                 0x50   // I will send ACK
#define IIC_MR_DATA_NOACK               0x58   // I will send no ACK
#define IIC_MR_ARBITRATION_LOST         0x38

void M_IIC_void_Init(void);
void M_IIC_void_sendStart(void);
void M_IIC_void_sendStop(void);
void M_IIC_void_sendByte(u8 copy_u8data);
void M_IIC_void_receiveByte_ACK(u8 * ptr);
u8   M_IIC_u8_getStatus(void);



#endif //IIC_INT_H

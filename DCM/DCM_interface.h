#ifndef DCM_INTERFACE_H_
#define DCM_INTERFACE_H_

#define DCM_FORWARD 1
#define DCM_REVERSE 0

#define DCM_PORTA  PortA
#define DCM_PORTB  PortB
#define DCM_PORTC  PortC
#define DCM_PORTD  PortD


#define DCM_PIN0  Pin0
#define DCM_PIN1  Pin1
#define DCM_PIN2  Pin2
#define DCM_PIN3  Pin3
#define DCM_PIN4  Pin4
#define DCM_PIN5  Pin5
#define DCM_PIN6  Pin6
#define DCM_PIN7  Pin7



typedef struct 
{
	u8 port;
	u8 pin ;
	u8 connection;
	
} DCM_TYPE;

void DCM_voidDCMOn(DCM_TYPE copy_DCMStructDCM1);
void DCM_voidDCMOff(DCM_TYPE copy_DCMStructDCM1);
void DCM_voidInit(DCM_TYPE copy_DCMStructDCM1);
#endif

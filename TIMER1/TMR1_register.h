/*preprocessor header file guard*/
#ifndef TMR1_REGISTER_H
#define TMR1_REGISTER_H


#define TCCR1A   (*(volatile u8 *)(0x4F))  //Timer/Counter1 Control Register A
#define TCCR1B   (*(volatile u8 *)(0x4E))  //Timer/Counter1 Control Register B
#define TCNTA    (*(volatile u16*)(0x4C))  //Timer/Counter1 Register
#define OCR1A    (*(volatile u16*)(0x4A))  //Timer/Counter1 Output Compare Register A
#define OCR1B    (*(volatile u16*)(0x48))  //Timer/Counter1 Output Compare Register B
#define ICR1     (*(volatile u16*)(0x46))  //Timer/Counter1 Input Capture Register

#define TIMSK    (*(volatile u8 *)(0x59))  //Timer/Counter Interrupt Mask Register
#define TIFR     (*(volatile u8 *)(0x58))  //Timer/Counter Interrupt Flag Register

#define SREG     (*(volatile u8 *)(0x5F))


#endif

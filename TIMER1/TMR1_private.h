/*preprocessor header file guard*/
#ifndef TMR1_PRIVATE_H
#define TMR1_PRIVATE_H


/************************Private macros************************/

#define PRESCALER_MASK           0b11111000

/*TCCR1A  bits*/
#define TCCR1A_COM1A1             7    //two bits for OCA1 pin behavior
#define TCCR1A_COM1A0             6
#define TCCR1A_COM1B1             5    //two bits for OCB1 pin behavior
#define TCCR1A_COM1B0             4
#define TCCR1A_WGM11              1    //two bits for mode of TIMER1
#define TCCR1A_WGM10              0

/*TCCR1B bits*/
#define TCCR1B_ICES1              6    //Input Capture Edge Select
#define TCCR1B_WGM13              4    //two bits for mode of TIMER1
#define TCCR1B_WGM12              3
#define TCCR1B_CS12               2    //three bits for prescaler
#define TCCR1B_CS11               1
#define TCCR1B_CS10               0

/*TIMSK bits*/
#define TIMSK_TICIE1              5    //input capture interrupt enable
#define TIMSK_OCIE1A              4    //Output Compare A Match Interrupt Enable
#define TIMSK_OCIE1B              3    //Output Compare B Match Interrupt Enable
#define TIMSK_TOIE1               2    //Overflow interrupt enable

/*TIFR bits*/
#define TIFR_ICF1                 5    //input capture flag
#define TIFR_OCF1A                4    //Output Compare A Match Flag
#define TIFR_OCF1B                3    //Output Compare B Match Flag
#define TIFR_TOV1                 2    //Overflow flag

#endif

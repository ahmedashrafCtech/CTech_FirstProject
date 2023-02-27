/*preprocessor header file guard*/
#ifndef TMR1_INTERFACE_H
#define TMR1_INTERFACE_H

/**************************************Interfacing macros**************************************/

/*different prescaler values*/
#define NO_PRESCALSER        0
#define PRESCALER_1          1
#define PRESCALER_8          2
#define PRESCALER_64         3
#define PRESCALER_256        4
#define PRESCALER_1024       5




/**************************************Functions' prototypes**************************************/
/*this function is to run TIMER1 in normal mode synchronously*/
//TESTED>>>>>>>
void TMR1_voidNormalSync(u8 Copy_u8Prescaler);

/*this function is to run TIMER1 in normal mode asynchronously*/
//TESTED>>>>>>>
void TMR1_voidNormalAsync(u8 Copy_u8Prescaler);

/*this function is to perform call back for application ISR*/
//TESTED>>>>>>>
void TMR1_voidSetCallBack(void(*PtrToFunc)(void));

/*this function is to perform 1sec sync delay by CTC mode*/
//TESTED>>>>>>>
void TMR1_voidComMatchSync();

/*this function is to stop TIMER1*/
//TESTED>>>>>>>
void TMR1_voidStopTimer1(void);



#endif

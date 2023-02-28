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

/*different interrupt sources*/
#define NORMAL               0
#define CTC                  1

/*different channels for pwm signal*/
#define CHANNEL_A            0
#define CHANNEL_B            1

/*different values of output frequency of pwm signal represented by value of ICR1 register*/
/*considering fixed prescaler = 8 -> tick time = 1us*/
#define FREQ_1000                         1000
#define FREQ_500                          2000
#define FREQ_250                          4000
#define FREQ_200                          5000
#define FREQ_125                          8000
#define FREQ_100                          10000
#define FREQ_50                           20000
#define FREQ_25                           40000
#define FREQ_20                           50000



/**************************************Functions' prototypes**************************************/
/*this function is to run TIMER1 in normal mode synchronously*/
//TESTED>>>>>>>
void TMR1_voidNormalSync(u8 Copy_u8Prescaler);

/*this function is to run TIMER1 in normal mode asynchronously*/
//TESTED>>>>>>>
void TMR1_voidNormalAsync(u8 Copy_u8Prescaler);

/*this function is to perform 1sec sync delay by CTC mode*/
//TESTED>>>>>>>
void TMR1_voidComMatchSync();

/*this function is to perform 1sec sync delay by CTC mode*/
//TESTED>>>>>>>
void TMR1_voidComMatchAsync();

/*this function is to generate a pwm signal on channel A or B*/
/*duty cycle in range [0:100]*/
//TESTED OVER LED INTENSITY
void TMR1_voidFastPwm(u8 Copy_u8Channel , u16 Copy_u16Frequency , u8 Copy_u8DutyCycle);

/*this function is to perform a delay period synchronously*/
//TESTED>>>>>>>
void TMR1_voidDelaySync(u16 Copy_u16TimeIn_ms);

/*this function is to perform a delay period asynchronously*/
//TESTED>>>>>>>
void TMR1_voidDelayAsync(u16 Copy_u16TimeIn_ms);

/*this function is to perform call back for application ISR*/
//TESTED>>>>>>>
void TMR1_voidSetCallBack(u8 Copy_u8SrcID,void(*PtrToFunc)(void));

/*this function is to stop TIMER1*/
//TESTED>>>>>>>
void TMR1_voidStopTimer1(void);

#endif

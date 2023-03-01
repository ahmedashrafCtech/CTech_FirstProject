/*preprocessor header file guard*/
#ifndef BUZZER_INTERFACE_H_
#define BUZZER_INTERFACE_H_

/*********************interfacing macros***********************/

/*connections of buzzer*/
#define BUZZER_PORTA      PortA
#define BUZZER_PORTB      PortB
#define BUZZER_PORTC      PortC
#define BUZZER_PORTD      PortD

/*pin of the buzzer*/
#define BUZZER_PIN0       Pin0
#define BUZZER_PIN1       Pin1
#define BUZZER_PIN2       Pin2
#define BUZZER_PIN3       Pin3
#define BUZZER_PIN4       Pin4
#define BUZZER_PIN5       Pin5
#define BUZZER_PIN6       Pin6
#define BUZZER_PIN7       Pin7


/*********************Functions' prototypes***********************/

/*this function is to initialize direction of buzzer pin to be output*/
void BUZZER_voidInit(u8 Copy_u8BuzzerPort , u8 Copy_u8BuzzerPin);

/*this function is to fire the buzzer*/
void BUZZER_voidSetBuzzerOn(u8 Copy_u8BuzzerPort , u8 Copy_u8BuzzerPin);

/*this function is to stop the buzzer*/
void BUZZER_voidSetBuzzerOff(u8 Copy_u8BuzzerPort , u8 Copy_u8BuzzerPin);

#endif /* BUZZER_INTERFACE_H_ */

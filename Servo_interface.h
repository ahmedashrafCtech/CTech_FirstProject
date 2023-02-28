/*preprocessor header file guard*/
#ifndef SERVO_INTERFACE_H
#define SERVO_INTERFACE_H


/***********************Interfacing macros*************************/
#define SERVO_CHANNEL_A             CHANNEL_A
#define SERVO_CHANNEL_B             CHANNEL_B


/***********************Functions' prototypes*************************/

/*this function is to move a servo connected to channel A or B to a certain angle[0:180]*/
void SERVO_voidMoveServo(u8 Copy_u8Channel , u8 Copy_u8Angle);





#endif

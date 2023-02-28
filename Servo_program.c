
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO.h"
#include "TMR1_interface.h"
#include "Servo_interface.h"

void SERVO_voidMoveServo(u8 Copy_u8Channel , u8 Copy_u8Angle)
{
	TMR1_voidFastPwm(Copy_u8Channel , FREQ_20 , Copy_u8Angle);
}

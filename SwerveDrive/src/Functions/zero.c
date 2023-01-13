#include "main.h"
#include "zero.h"

void zero(){
 int counts;
 if(joystickGetDigital(1, 8, JOY_UP) == 1){
 imeReset(IME_MOTOR_0);
 imeReset(IME_MOTOR_1);
 imeReset(IME_MOTOR_2);
 imeReset(IME_MOTOR_3);
 }
}
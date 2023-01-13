#include "main.h"
#include "turn.h"

void turn(){
 int counts;
 if(joystickGetDigital(1, 8, JOY_DOWN) == 1){
 delay(100);
 while(joystickGetDigital(1, 8, JOY_DOWN) == 0){
  motorSet(6, -kp*(45-(imeGet(IME_MOTOR_0, &counts)*27/79)));
  motorSet(7, kp*(45+(imeGet(IME_MOTOR_1, &counts)*27/79)));
  motorSet(8, kp*(45+(imeGet(IME_MOTOR_2, &counts)*27/79)));
  motorSet(9, -kp*(45-(imeGet(IME_MOTOR_3, &counts)*27/79)));

  motorSet(2, joystickGetAnalog(1,4));
  motorSet(3, joystickGetAnalog(1,4));
  motorSet(4, joystickGetAnalog(1,4));
  motorSet(5, joystickGetAnalog(1,4));
  delay(20);
  }
}}
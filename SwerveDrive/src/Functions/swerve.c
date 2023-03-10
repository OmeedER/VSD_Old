#include "main.h"
#include "swerve.h"

int counts;
float kp = 1.4;
float M_PI = 3.1415926535;
float target;
float speed;

void swerve(){
 if(abs(joystickGetAnalog(1,1)) > 15 || abs(joystickGetAnalog(1,2)) > 15){
 if(joystickGetAnalog(1,2) == 0 && joystickGetAnalog(1,1) != 0){
 target = 158;
 speed = joystickGetAnalog(1,1);
 }
 else{
 target = (180/M_PI)*atan2(joystickGetAnalog(1,1), joystickGetAnalog(1,2));
 speed = sqrt(pow(joystickGetAnalog(1,1),2) + pow(joystickGetAnalog(1,2),2));
 }
 motorSet(6, -kp*(target - (imeGet(IME_MOTOR_1, &counts)*27/79)));
 motorSet(7, -kp*(target - (imeGet(IME_MOTOR_2, &counts)*27/79)));
 motorSet(8, -kp*(target - (imeGet(IME_MOTOR_3, &counts)*27/79)));
 motorSet(9, -kp*(target - (imeGet(IME_MOTOR_4, &counts)*27/79)));

 motorSet(2, speed);
 motorSet(3, speed);
 motorSet(4, speed);
 motorSet(6, speed);
 }
 else{
 motorStopAll();
 }
 delay(20);
}

void turn(){
 if(joystickGetDigital(1, 8, JOY_DOWN) == 1){
 delay(100);
 while(joystickGetDigital(1, 8, JOY_DOWN) == 0){
  motorSet(6, -kp*(45-(imeGet(IME_MOTOR_1, &counts)*27/79)));
  motorSet(7, kp*(45+(imeGet(IME_MOTOR_2, &counts)*27/79)));
  motorSet(8, kp*(45+(imeGet(IME_MOTOR_3, &counts)*27/79)));
  motorSet(9, -kp*(45-(imeGet(IME_MOTOR_4, &counts)*27/79)));

  motorSet(2, joystickGetAnalog(1,4));
  motorSet(3, joystickGetAnalog(1,4));
  motorSet(4, joystickGetAnalog(1,4));
  motorSet(5, joystickGetAnalog(1,4));
  delay(20);
  }
}}

void zero(){
 if(joystickGetDigital(1, 8, JOY_UP) == 1){
 imeReset(IME_MOTOR_1);
 imeReset(IME_MOTOR_2);
 imeReset(IME_MOTOR_3);
 imeReset(IME_MOTOR_4);
 }
}
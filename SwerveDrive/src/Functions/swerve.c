#include "main.h"
#include "swerve.h"

void swerve(){
 int counts;
 float target;
 float speed;
 float kp = 1.4;
 if(abs(joystickGetAnalog(1,1)) > 15 || abs(joystickGetAnalog(1,2)) > 15){
 if(joystickGetAnalog(1,2) == 0 && joystickGetAnalog(1,1) != 0){
 target = 158;
 speed = joystickGetAnalog(1,1);
 }
 else{
 target = (180/M_PI)*atan2(joystickGetAnalog(1,1), joystickGetAnalog(1,2));
 speed = sqrt(pow(joystickGetAnalog(1,1),2) + pow(joystickGetAnalog(1,2),2));
 }
 motorSet(6, -kp*(target - (imeGet(IME_MOTOR_0, &counts)*27/79)));
 motorSet(7, -kp*(target - (imeGet(IME_MOTOR_1, &counts)*27/79)));
 motorSet(8, -kp*(target - (imeGet(IME_MOTOR_2, &counts)*27/79)));
 motorSet(9, -kp*(target - (imeGet(IME_MOTOR_3, &counts)*27/79)));

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
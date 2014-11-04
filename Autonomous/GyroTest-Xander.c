#pragma config(Sensor, S1,     IRSEEKER2,           sensorLowSpeed)
#pragma config(Sensor, S3,     GYRO,                sensorAnalogInactive)
#pragma config(Motor,  motorA,          M_BACK,        tmotorNormal, PIDControl, encoder)
#pragma config(Motor,  motorB,          M_RIGHT,       tmotorNormal, PIDControl, encoder)
#pragma config(Motor,  motorC,          M_LEFT,        tmotorNormal, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// For the Gyro
#include "drivers/HTGYRO-driver.h"

// These are the angles the motors are at
#define aWheel1 0.0
#define aWheel2 126.87
#define aWheel3 233.13

// Set this to another value if you want the motors to peak at a different
// top speed
#define MAXMOTORSPEED 100

// Current heading of the robot
float currHeading = 0;

// Task to keep track of the current heading using the HT Gyro
task getHeading () {
	float delTime = 0;
	float prevHeading = 0;
	float curRate = 0;

  HTGYROstartCal(GYRO);
  PlaySound(soundBeepBeep);
  while (true) {
    time1[T1] = 0;
    curRate = HTGYROreadRot(GYRO);
    if (abs(curRate) > 3) {
      prevHeading = currHeading;
      currHeading = prevHeading + curRate * delTime;
      if (currHeading > 360) currHeading -= 360;
      else if (currHeading < 0) currHeading += 360;
    }
    wait1Msec(5);
    delTime = ((float)time1[T1]) / 1000;
    //delTime /= 1000;
  }
}


// Move the robot at the angle specified using Vb as the base speed.
// rotSpeed specifies the amount of rotation the robot body should have.
void MoveRobot(int angle, int Vb, int rotSpeed) {
  float Vw1, Vw2, Vw3, norm_factor;

  // Adjust the angle to make it more intuitive
  angle-=90;

  // Calculate the individual motor speeds
  Vw1 = rotSpeed + Vb * cosDegrees(angle);
  Vw2 = rotSpeed + Vb * (-0.6 * cosDegrees(angle) + 0.8 * sinDegrees(angle));
  Vw3 = (rotSpeed + Vb * (-0.6 * cosDegrees(angle) - 0.8 * sinDegrees(angle))) * -1;

  // This normalises all of the values to make sure
  // no motor value peaks over 100%
  if (Vw1 > MAXMOTORSPEED) {
    norm_factor = MAXMOTORSPEED / Vw1;
  } else if (Vw2 > MAXMOTORSPEED) {
    norm_factor = MAXMOTORSPEED / Vw2;
  } else if (Vw3 > MAXMOTORSPEED) {
    norm_factor = MAXMOTORSPEED / Vw3;
  } else {
    norm_factor = 1.0;
  }

  // Power the motors.
  motor[motorA] = Vw1 * norm_factor;
  motor[motorB] = Vw2 * norm_factor;
  motor[motorC] = Vw3 * norm_factor;
}


/*
 Main task
 */
task main () {
  StartTask(getHeading);
  wait1Msec(500);
  while (true) {
    // This is where the magic happens.  It's so much simpler than you would think.
    MoveRobot(currHeading, 60, 70);
    wait1Msec(10);
  }
}
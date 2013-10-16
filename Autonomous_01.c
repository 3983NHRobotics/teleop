#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S2,     sensorSonar,    sensorHiTechnicIRSeeker600)
#pragma config(Sensor, S3,     sensorLight,    sensorLightActive)
#pragma config(Motor,  mtr_S1_C1_1,     motorLeft,     tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     motorRight,    tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     motorArm,      tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     motorH,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorI,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C4_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    servo2,               tServoStandard)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//####################################################################################//
//																																										//
//															2013-2014 Autonomous Code															//
//													  Team 3983 - Highlands Robotics													//
//																   Code by T. Kluge																	//
//																																										//
//####################################################################################//


//referenced files here

#include "joystickdriver.c"

//vars + functions here

void moveForward(int mtime, int mpower) {

	motor[motorLeft] = mpower;
	motor[motorRight] = mpower;
	wait1Msec(mtime * 1000);
	motor[motorLeft] = 0;
	motor[motorRight] = 0;

}

void moveBackward(int mtime, int mpower) {

	motor[motorLeft] = -1 * mpower;
	motor[motorRight] = -1 * mpower;
	wait1Msec(mtime * 1000);
	motor[motorLeft] = 0;
	motor[motorRight] = 0;

}

void turnLeft(int mtime, int mpower) {

	motor[motorLeft] = -1 * mpower;
	motor[motorRight] = mpower;
	wait1Msec(mtime * 1000);
	motor[motorLeft] = 0;
	motor[motorRight] = 0;

}

void turnRight(int mtime, int mpower) {

	motor[motorLeft] = mpower;
	motor[motorRight] = -1 * mpower;
	wait1Msec(mtime * 1000);
	motor[motorLeft] = 0;
	motor[motorRight] = 0;

}

void armLift(int mtime, int mpower) {

	motor[motorArm] = mpower;
	//motor[motorArm2] = mpower;
	wait1Msec(mtime * 1000);
	motor[motorArm] = 0;
	//motor[motorArm2] = 0;

}

void hippoFlip(int deg) {

	servo[srvo_S1_C4_1] = deg;

}

void hippoScoop(int deg) {
	//something
}

void initializeRobot() {

	PlaySound(soundFastUpwardTones);
	return;

}

task main()
{

	initializeRobot();
	waitForStart();
	//autonomous code chain loop thing begin
	//function format: func(time<seconds>, power<percent>) or func(angle<degrees>)

	while(true) {

		motor[motorLeft] = 70;
		motor[motorRight] = 70;//go forward until...

		if (SensorValue[sensorHiTechnicIRSeeker600] >= 10) {//IR beacon is detected (weak)
			motor[motorLeft] = 30;
			motor[motorRight] = 30;//continue going forwards, but more slowly until...
			if (SensorValue[sensorHiTechnicIRSeeker600] >=20) {//IR beacon is detected (strong)

				break;//begin predetermined chain of functions

			}
		}
	}

	turnLeft(1.5, 60);//turn to basket

	moveForward(2, 100);//move up to basket

	armLift(1.7, 70);//raise arm

	moveForward(0.5, 50);//move over basket

	hippoFlip(180);//flip bucket

	moveBackward(0.5, 50);//move away from basket

	turnRight(2, 100);//turn away from basket

	armLift(1.7, -100);//lower arm

	moveForward(4, 100);//move to end of ramp

	turnLeft(2, 70);//turn left 90deg

	moveForward(2, 100);//move in front of ramp

	turnLeft(2, 70);//turn left 90deg

	moveForward(4, 100);//go up ramp

}
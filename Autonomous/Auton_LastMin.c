#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Motor,  motorA,          ,              tmotorNormal, openLoop, encoder)
#pragma config(Motor,  motorB,          ,              tmotorNormal, openLoop)
#pragma config(Motor,  motorC,          ,              tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     motorBack1,    tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorBack2,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     motorFront1,   tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorFront2,   tmotorNormal, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_1,     motorLock,     tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorArm,        tmotorNormal, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//####################################################################################//
//																																										//
//                              2014-2015 3983 Autonomous Code												//
//                         Teams 3983 and 7005 - Highlands Robotics										//
//                             Code by T. Kluge and A. Malik													//
//																																										//
//####################################################################################//

// User Config ---------------
bool inDebug = true;
// End Config ----------------

#include "JoystickDriver.c"
//#include "../GlobalFunctions/debug.h"

int srvoVal[] = {103,194};
int ff[] = {490, 613, 640, 750, 640, 750};

task main() {
	nVolume = 3;
	PlayImmediateTone(400, 20);
	waitForStart();
	ClearSounds();
			PlayImmediateTone(ff[0], 10);
			// PlayImmediateTone(ff[1], 10);
			// PlayImmediateTone(ff[2], 10);
			// PlayImmediateTone(ff[3], 20);
			// PlayImmediateTone(ff[4], 10);
			// PlayImmediateTone(ff[5], 40);


			int moveTime[] = {
			  3600, //move forward
			  1000, //back up
			  1800, //turn left
			  2000, //go forward
			  500, //turn left more
			  1600, //go forward
			  1000, //back up
			  2000, //turn 180
			  700, //go forward
			  700, //back up
			  0
			  };
			int slowDelay = 1000;
			int liftTime = 450;
			int armTime = 500;

			//raise lock
			motor[motorLock] = 30;
			wait1Msec(liftTime + 220);
			motor[motorLock] = 0;
			//move forward and stop
	    motor[motorBack1] = -100;
			motor[motorBack2] = -100;
			motor[motorFront1] = -100;
			motor[motorFront2] = -100;
			wait1Msec(moveTime[0] - slowDelay);
			motor[motorBack1] = -20;
			motor[motorBack2] = -20;
			motor[motorFront1] = -20;
			motor[motorFront2] = -20;
			wait1Msec(slowDelay + 500);
			//lower lock
			motor[motorLock] = -15;
			wait1Msec(liftTime);
			motor[motorLock] = 0;
			//stop forwards
			motor[motorBack1] = -0;
			motor[motorBack2] = -0;
			motor[motorFront1] = -0;
			motor[motorFront2] = -0;
			wait1Msec(500);
			//move backwards
			motor[motorBack1] = 100;
			motor[motorBack2] = 100;
			motor[motorFront1] = 100;
			motor[motorFront2] = 100;
			wait1Msec(moveTime[1]);
			motor[motorBack1] = -0;
			motor[motorBack2] = -0;
			motor[motorFront1] = -0;
			motor[motorFront2] = -0;
			//turn left
			motor[motorBack1] = 100;
			motor[motorBack2] = -100;
			motor[motorFront1] = 100;
			motor[motorFront2] = -100;
			wait1Msec(moveTime[2]);
			//go forwards
			motor[motorBack1] = -100;
			motor[motorBack2] = -100;
			motor[motorFront1] = -100;
			motor[motorFront2] = -100;
			wait1Msec(moveTime[3]);
			//turn left more
			motor[motorBack1] = 100;
			motor[motorBack2] = -100;
			motor[motorFront1] = 100;
			motor[motorFront2] = -100;
			wait1Msec(moveTime[4]);
			motor[motorBack1] = -100;
			motor[motorBack2] = -100;
			motor[motorFront1] = -100;
			motor[motorFront2] = -100;
			wait1Msec(moveTime[5]);
			motor[motorBack1] = -0;
			motor[motorBack2] = -0;
			motor[motorFront1] = -0;
			motor[motorFront2] = -0;
			//raise lock
			motor[motorLock] = 30;
			wait1Msec(liftTime + 220);
			motor[motorLock] = 0;
			//back up
			motor[motorBack1] = 100;
			motor[motorBack2] = 100;
			motor[motorFront1] = 100;
			motor[motorFront2] = 100;
			wait1Msec(moveTime[6]);
			motor[motorBack1] = -0;
			motor[motorBack2] = -0;
			motor[motorFront1] = -0;
			motor[motorFront2] = -0;
			////turn 180
			// motor[motorBack1] = -100;
			// motor[motorBack2] = 100;
			// motor[motorFront1] = -100;
			// motor[motorFront2] = 100;
			// wait1Msec(moveTime[7]);
			////go forward
			// motor[motorBack1] = -100;
			// motor[motorBack2] = -100;
			// motor[motorFront1] = -100;
			// motor[motorFront2] = -100;
			// wait1Msec(moveTime[8]);
			// motor[motorBack1] = -0;
			// motor[motorBack2] = -0;
			// motor[motorFront1] = -0;
			// motor[motorFront2] = -0;
			////swing arm
			// motor[motorArm] = 20;
			// wait1Msec(armTime);
			// motor[motorArm] = 0;
			////back up
			// motor[motorBack1] = 100;
			// motor[motorBack2] = 100;
			// motor[motorFront1] = 100;
			// motor[motorFront2] = 100;
			// wait1Msec(moveTime[9]);
			// motor[motorBack1] = -0;
			// motor[motorBack2] = -0;
			// motor[motorFront1] = -0;
			// motor[motorFront2] = -0;
			////swing arm back
			// motor[motorArm] = -20;
			// wait1Msec(armTime);
			// motor[motorArm] = 0;

}

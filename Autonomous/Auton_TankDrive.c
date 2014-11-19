#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  HTMotor)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     motorLift,     tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     motorSweeper,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorLeft,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorRight, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     motorH,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     motorI,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C3_1,    servoBucket,            tServoStandard)
#pragma config(Servo,  srvo_S1_C3_2,    servo2,           tServoStandard)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//####################################################################################//
//																																										//
//                                 2014-2015 Autonomous Code													//
//                         Teams 3983 and 7005 - Highlands Robotics										//
//                                    Code by T. Kluge																//
//																																										//
//####################################################################################//

// User Config ---------------
bool inDebug = true;
// End Config ----------------

#include "../drivers/JoystickDriver_CustomNoSplash.c"
#include "MenuSelector.c"
#include "../GlobalFunctions/debug.h"
#include "../GlobalFunctions/GlobalFunctions.c"

//variable initialization

bool FORWARD_LEFT_RIGHT = false;
bool FORWARD_RIGHT_LEFT = false;

//Main Program

task main() {

	chooseProgram(); //start the program chooser

	switch (PROGID) { //handle the results from the program chooser
		case 1:
			FORWARD_LEFT_RIGHT = true;
			//debug("Auton prog set to FORWARD_LEFT_RIGHT");
			break;
		case 2:
			FORWARD_RIGHT_LEFT = true;
			//debug("Auton prog set to FORWARD_RIGHT_LEFT");
			break;
		case 3:
			//debug_clear();
			//debug("Cleared Debug Stream");
			break;
		default:
			FORWARD_LEFT_RIGHT = true;
			//debug("Auton prog defaulted to FORWARD_LEFT_RIGHT");
			PlaySoundFile("Woops.rso");
			break;
	} //end switch(PROGID)

	moveForward(3000, 100);
	if (FORWARD_LEFT_RIGHT)
		turnLeft(2000, 100);
	else if (FORWARD_RIGHT_LEFT)
		turnRight(2000, 100);
	else
		wait1Msec(1000);

	moveForward(2000, 100);

	if (FORWARD_LEFT_RIGHT)
		turnRight(2000, 100);
	else if (FORWARD_RIGHT_LEFT)
		turnLeft(2000, 100);
	else
		wait1Msec(1000);

	moveBackward(3000, 100);

} //end task main

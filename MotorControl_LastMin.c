#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorA,          ,              tmotorNormal, openLoop, encoder)
#pragma config(Motor,  motorB,          ,              tmotorNormal, openLoop)
#pragma config(Motor,  motorC,          ,              tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     motorBack1,    tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorBack2,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     motorFront1,   tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorFront2,   tmotorNormal, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_1,     motorLock,     tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorArm,      tmotorNormal, openLoop)
#pragma config(Servo,  srvo_S1_C4_1,    crServo,              tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C4_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//####################################################################################//
//																																										//
//                              2014-2015 Motor Control Code													//
//                         Teams 3983 and 7005 - Highlands Robotics										//
//                                    Code by T. Kluge																//
//																																										//
//####################################################################################//

//#include "drivers/JoystickDriver_CustomNoSplash.c"
#include "joystickdriver.c"

string menuFirst = "Motor Control";
string placeholder = "PlaceHolder";
string prog[] = {
				 "S1_C1_1",
				 "S1_C1_2",
				 "S1_C2_1",
				 "S1_C2_2",
				 "S1_C3_1",
				 "S1_C3_2",
				 "S1_C4_1",
				 "S1_C4_2"
			};
string motorName[] = {
				 "S1_C1_1",
				 "S1_C1_2",
				 "S1_C2_1",
				 "S1_C2_2",
				 "S1_C3_1",
				 "S1_C3_2",
				 "S1_C4_1",
				 "S1_C4_2"
};
string motorType = "motor";
string mtc;

int totalChoices = 8;
int totalMotors = 6;
int selectionValue = 1;
int motorToControl;
int motorOffset = 2; //because the motor array also includes the 3 NXT motors (2 for controllers, -1 for NXT motors)

bool progSelected = false;
bool runningMotor = false;
bool dirTextSet = false;

void updateDisplay();
void updateSelFirst();
void updateSelSecond();
void updateSelThird();
void updateSelFourth();
void updateSelFifth();
void updateSelSixth();
void updateSelSeventh();
void updateSelEighth();
int chooseMotor();
void stopAllMotors();
void runMotor();
void displaySplash();

task main() {
	disableDiagnosticsDisplay();
	displaySplash();
	while(true) {
		progSelected = false;
		//selectionValue = 1;
		motorToControl = chooseMotor(); //IT WORKS
		nxtDisplayTextLine(2, "MotorTC: %d", motorToControl);
		if (motorToControl > totalMotors) {
			motorType = "servo";
			nxtDisplayTextLine(3, "MotorTC: servo");
		}
		nxtDisplayTextLine(4, "%s", motorName[motorToControl - 1]);
		mtc = motorName[motorToControl - 1];
		wait1Msec(500);
		runMotor();
		wait1Msec(500);
	}
}

void runMotor() {
	runningMotor = true;
		//nxtDisplayCenteredTextLine (1, "Motor: %d", motorToControl);
		nxtDisplayCenteredTextLine(1, "Orange btn exit");
		nxtDisplayCenteredTextLine(2, "%s", mtc);

		while (runningMotor) {
		//Right arrow
			while (nNxtButtonPressed == 1) {
				if(!dirTextSet) {
					nxtDisplayCenteredTextLine(4, "Running %s", motorType);
					nxtDisplayCenteredTextLine(5, "> > >");
				}
				dirTextSet = true;
				if (motorType == "motor") {
		 			motor[motorToControl + motorOffset] = 100;
		 		} else {
		 			//servo[motorToControl - (totalMotors + 1)] = ServoValue[motorToControl - (totalMotors + 1)] + 1
		 		servo[crServo] = ServoValue[crServo] + 1;
		 		wait1Msec(50);
		 		}
		 		if (nNxtButtonPressed == -1) {
					break;
				}
			}
			while (nNxtButtonPressed == 2) {
				if (!dirTextSet) {
					nxtDisplayCenteredTextLine(4, "Running %s", motorType);
					nxtDisplayCenteredTextLine(5, " < < <");
				}
				dirTextSet = true;
				if (motorType == "motor") {
		 			motor[motorToControl + motorOffset] = -100;
		 		} else {
		 		nxtDisplayTextLine(6, "%d", motorToControl - (totalMotors + 1));
		 			//servo[motorToControl - (totalMotors + 1)] = ServoValue[motorToControl - (totalMotors + 1)] - 1;
		 		servo[crServo] = ServoValue[crServo] - 1;
		 		wait1Msec(50);
		 		}
		 		if (nNxtButtonPressed == -1) {
					break;
					stopAllMotors();
				}
			}
			if (nNxtButtonPressed == 3) {
				runningMotor = false;
			}
			if (nNxtButtonPressed == -1) {
				stopAllMotors();
				dirTextSet = false;
				nxtDisplayTextLine(4, "");
				nxtDisplayTextLine(5, "");
			}
		}
}

void stopAllMotors() {
	motor[0] = 0;
	motor[1] = 0;
	motor[2] = 0;
	motor[mtr_S1_C1_1] = 0;
	motor[mtr_S1_C1_2] = 0;
	motor[mtr_S1_C2_1] = 0;
	motor[mtr_S1_C2_2] = 0;
	motor[mtr_S1_C3_1] = 0;
	motor[mtr_S1_C3_2] = 0;

	//for (int i = 0; i < motor.length; i++) {
	//	motor[i] = 0;
	//}
}

int chooseMotor() {
	//Initialize the display with the program choices
	updateDisplay();
	wait1Msec(50);
	while (!progSelected) {
		//Right arrow
		switch (nNxtButtonPressed) {
			case 1:
				PlaySoundFile("! Click.rso");
				eraseDisplay();
				selectionValue++;
				updateDisplay();
				wait1Msec(300);
				break;
			case 2:
				PlaySoundFile("! Click.rso");
				eraseDisplay();
				selectionValue--;
				updateDisplay();
				wait1Msec(300);
				break;
			case 3:
				PlaySoundFile("! Attention.rso");
				eraseDisplay();
				/*selectedProgram = selectionValue;
				runSelectedPgm();*/
				progSelected = true;
				break;
		}
		if (selectionValue > totalChoices) {
			selectionValue = 1;
			eraseDisplay();
			updateDisplay();
		}
		if (selectionValue <= 0) {
			selectionValue = totalChoices;
			eraseDisplay();
			updateDisplay();
		}
	}
	return selectionValue;
}

void updateDisplay() {
	switch (selectionValue) {
		case 1:
			updateSelFirst();
			break;
		case 2:
			updateSelSecond();
			break;
		case 3:
			updateSelThird();
			break;
		case 4:
			updateSelFourth();
			break;
		case 5:
			updateSelFifth();
			break;
		case 6:
			updateSelSixth();
			break;
		case 7:
			updateSelSeventh();
			break;
		case 8:
			updateSelEighth();
			break;
		default: break;
	}
}

void updateSelFirst() {

	nxtDisplayCenteredTextLine (1, "%s", menuFirst);
	nxtDisplayTextLine (2, "%s <", prog[0]);
	nxtDisplayTextLine (3, "%s", prog[1]);
	nxtDisplayTextLine (4, "%s", prog[2]);
	nxtDisplayTextLine (5, "%s", prog[3]);
	nxtDisplayTextLine (6, "%s", prog[4]);
	//drawArrow_1();

}

void updateSelSecond() {

	nxtDisplayCenteredTextLine (1, "%s", menuFirst);
	nxtDisplayTextLine (2, "%s", prog[0]);
	nxtDisplayTextLine (3, "%s <", prog[1]);
	nxtDisplayTextLine (4, "%s", prog[2]);
	nxtDisplayTextLine (5, "%s", prog[3]);
	nxtDisplayTextLine (6, "%s", prog[4]);
	//drawArrow_2();

}
void updateSelThird() {

	nxtDisplayCenteredTextLine (1, "%s", menuFirst);
	nxtDisplayTextLine (2, "%s", prog[0]);
	nxtDisplayTextLine (3, "%s", prog[1]);
	nxtDisplayTextLine (4, "%s <", prog[2]);
	nxtDisplayTextLine (5, "%s", prog[3]);
	nxtDisplayTextLine (6, "%s", prog[4]);
	//drawArrow_3();

}
void updateSelFourth() {

	nxtDisplayCenteredTextLine (1, "%s", menuFirst);
	nxtDisplayTextLine (2, "%s", prog[0]);
	nxtDisplayTextLine (3, "%s", prog[1]);
	nxtDisplayTextLine (4, "%s", prog[2]);
	nxtDisplayTextLine (5, "%s <", prog[3]);
	nxtDisplayTextLine (6, "%s", prog[4]);
	//drawArrow_4();

}
void updateSelFifth() {

	nxtDisplayCenteredTextLine (1, "%s", menuFirst);
	nxtDisplayTextLine (2, "%s", prog[0]);
	nxtDisplayTextLine (3, "%s", prog[1]);
	nxtDisplayTextLine (4, "%s", prog[2]);
	nxtDisplayTextLine (5, "%s", prog[3]);
	nxtDisplayTextLine (6, "%s <", prog[4]);
	//drawArrow_5();

}
void updateSelSixth() {
	nxtDisplayCenteredTextLine (1, "%s", menuFirst);
	nxtDisplayTextLine (2, "%s <", prog[5]);
	nxtDisplayTextLine (3, "%s", prog[6]);
	nxtDisplayTextLine (4, "%s", prog[7]);
	nxtDisplayTextLine (5, "%s", placeholder);
	nxtDisplayTextLine (6, "%s", placeholder);

}
void updateSelSeventh() {
	nxtDisplayCenteredTextLine (1, "%s", menuFirst);
	nxtDisplayTextLine (2, "%s", prog[5]);
	nxtDisplayTextLine (3, "%s <", prog[6]);
	nxtDisplayTextLine (4, "%s", prog[7]);
	nxtDisplayTextLine (5, "%s", placeholder);
	nxtDisplayTextLine (6, "%s", placeholder);

}
void updateSelEighth() {
	nxtDisplayCenteredTextLine (1, "%s", menuFirst);
	nxtDisplayTextLine (2, "%s", prog[5]);
	nxtDisplayTextLine (3, "%s", prog[6]);
	nxtDisplayTextLine (4, "%s <", prog[7]);
	nxtDisplayTextLine (5, "%s", placeholder);
	nxtDisplayTextLine (6, "%s", placeholder);

}
void displaySplash() {
	nxtDisplayCenteredTextLine(1, "Motor Control");
	nxtDisplayCenteredTextLine(2, "by T. Kluge");
	nxtDisplayCenteredTextLine(4, ":)");
	wait1Msec(500);
}

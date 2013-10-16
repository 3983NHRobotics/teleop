#pragma config(Sensor, S2,     HTPB,     sensorI2CCustom9V)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

			//####################################################################################//
			//																																										//
			//											  2013-2014 ProtoBoard Integration Code	  										//
			//													  Team 3983 - Highlands Robotics													//
			//								    						Code by Xander Soldaat															//
			//																																										//
			//####################################################################################//

#include "joystickdriver.c"
#include "Drivers\hitechnic-protoboard.h"

task main() {
  // Local variables
  int inputdata;

  // The data to be written: 0x3F = 111111 binary,
  // makes all digital ports outputs.
  HTPBsetupIO(HTPB, 0x3F);

  while(true) {
    // Read a 10bit wide analogue value from A0
    inputdata = HTPBreadADC(HTPB, 0, 10);
    eraseDisplay();
    nxtDisplayTextLine(1, "%d", inputdata);

    // If A0 is less than 50% of the max value
    // turn off the LED, otherwise switch it on
    if(inputdata < 512)
      HTPBwriteIO(HTPB, 0x00);
    else
      HTPBwriteIO(HTPB, 0x01);

    wait1Msec(50);
  }
}
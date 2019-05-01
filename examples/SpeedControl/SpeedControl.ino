#include "DeltaRobotOne.h"

//Create the DeltaRobotOne-Object
DeltaRobotOne robot(0, 0, 0, 0, 0, 0, 0x27);

//Pos p(position x, position y, position z)
//Create pos object(x,y,z)
Pos P10(0.0, 0.0, 70.0);
Pos P20(0.0, 0.0, 100.0);

//Setup
void setup()
{
  //Robot setup is required. 
  //Use this line as the first line in all your sketches.
  //Initialisation of some objects and parameters.
  robot.setup();

  //Set power cycle on for servo motors and light
  //Attention: Servo motors move to zero position in a fast way 
  //if you power on the main cycle at the first time!
  robot.power.mainOn();
  
  //Wait for 1 second
  robot.functions.waitFor(1000);
  
  //Print out some information on display
  robot.display.printLine1(F("Move Home..."));

  //Move th robot to the home position (X=0.0,Y=0.0,Z=85.0)
  robot.move.ptp(home);

  //Clear the display
  robot.display.clear();
  //Print out some information on display
  robot.display.printLine1(F("Speed Control"));

  //Wait for 2 seconds
  robot.functions.waitFor(2000);
}

//Loop
void loop()
{
  //Speed parameters can set at the end of the move ptp functions
  //move.ptp(position x, position y, position z, speed v)
  //move.ptp(Pos p, speed v)
  
  //There are two ways to set the speed parameters
  
  //First way: Direct input of parameters
  //1.0 = 1.0% -> 100.0 = 100.0%

  //Move Z-Axis
  robot.move.ptp(P10,15.0);
  
  //Move Z-Axis
  robot.move.ptp(P20,30.0);
  
  //Second way: Using of predefined speed parameters
  //Speed::slow = 10%
  //Speed::half = 50%
  //Speed::fast = 90%
  //Speed::full = 100%

  //Move Z-Axis
  robot.move.ptp(P10, Speed::half);
  
  //Move Z-Axis
  robot.move.ptp(P20, Speed::fast);

  //Wait for 2 seconds
  robot.functions.waitFor(2000);

  //Move Z-Axis
  robot.move.ptp(P10, Speed::full);

  //Give the servos time to reach th position
  //Wait for 0.5 second
  robot.functions.waitFor(500);
  
  //Move Z-Axis
  robot.move.ptp(P20, Speed::full);

  //Wait for 2 seconds
  robot.functions.waitFor(2000);
}

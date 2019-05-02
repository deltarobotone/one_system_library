#include "DeltaRobotOne.h"

//Create the DeltaRobotOne-Object
DeltaRobotOne robot(0, 0, 0, 0, 0, 0, 0x27);

//Pos p(position x, position y, position z)
//Create pos object(x,y,z)
Pos P10(0.0, 0.0, 70.0);
Pos P20(0.0, 0.0, 100.0);
Pos P30(0.0, 0.0, 70.0);

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
  robot.display.printLine1(F("Move Basic"));

  //Wait for 2 seconds
  robot.functions.waitFor(2000);
}

//Loop
void loop()
{
  //This example shows you how to use the basic move function of the robot

  //There are two ways to use the move function (ptp=point to point)
  //First we use the preset speed parameter (50%) 
  //Use example "SpeedControl" for changing the speed of the robot
  
  //First way: Direct input of parameters
  //move.ptp(position x, position y, position z)

  //Move Z-Axis
  robot.move.ptp(0.0,0.0,70.0);

  //Move Z-Axis
  robot.move.ptp(0.0,0.0,100.0);

  //Wait for 2 seconds
  robot.functions.waitFor(2000);
  
  //Second way: Using of position class (Pos)
  //Pos p(position x, position y, position z)
  //Pos objects are defined at the top of this sketch
  //move.ptp(Pos p) 
  
  //Move Z-Axis
  robot.move.ptp(P10);
  
  //Move Z-Axis
  robot.move.ptp(P20);

  //Wait for 2 seconds
  robot.functions.waitFor(2000);

  //For using the same Pos class object for more than 
  //one position it is possible to manipulate the object

  //Manipulate Z-Parameter
  P30.z = 70.0;
  //Move Z-Axis
  robot.move.ptp(P30);

  //Manipulate Z-Parameter
  P30.z = 100.0;
  //Move Z-Axis
  robot.move.ptp(P30);

  //Wait for 2 seconds
  robot.functions.waitFor(2000);
}

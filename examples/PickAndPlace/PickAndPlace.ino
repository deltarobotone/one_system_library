#include "DeltaRobotOne.h"

//Create the DeltaRobotOne-Object
DeltaRobotOne robot(0, 0, 0, 0, 0, 0, 0x27);

//Pos p(position x, position y, position z)
//Create pos object(x,y,z)
Pos P10(35.0, 0.0, 100.0);
Pos P20(35.0, 0.0, 110.0);
Pos P30(-35.0, 0.0, 100.0);

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
  robot.display.printLine1(F("Pick and Place"));

  //Wait for 2 seconds
  robot.functions.waitFor(2000);
}

//Loop
void loop()
{
  //This example shows you how to define a pick and place application

  //Define a waiting time for the steps
  int time = 200;

  //Move to first position in a fast way
  robot.move.ptp(P10, Speed::fast);
  robot.functions.waitFor(time);

  //Move to second position in a slow way
  robot.move.ptp(P20, Speed::slow);
  //Pick: Close the gripper 
  robot.gripper.close();
  //Light green
  robot.light.on(Colour::green, Intensity::max);
  robot.functions.waitFor(time);

  //Move back to first position with half speed
  robot.move.ptp(P10, Speed::half);
  robot.functions.waitFor(time);

  //Move to third position in a fast way
  robot.move.ptp(P30, Speed::fast);
  robot.functions.waitFor(time);

  //If you don't want to define a position object for every position
  //you can manipulate the object (or use the move.ptp(x,y,z,speed) function
  
  //Add 10 mm to Z-Axis
  P30.z += 10.0;
  
  //Move to second position in a slow way
  robot.move.ptp(P30, Speed::slow);
  //Place: Open the gripper 
  robot.gripper.open();
  //Light red
  robot.light.on(Colour::red, Intensity::max);
  robot.functions.waitFor(time);

  //Sub 10 mm from Z-Axis
  P30.z -= 10.0;
  
  //Move back to third position with half speed
  robot.move.ptp(P30, Speed::half);
  robot.functions.waitFor(time);
}

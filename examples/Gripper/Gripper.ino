#include "DeltaRobotOne.h"

//Every robot has different values for servo-offset A,B,C and 
//tcp-offset X,Y,Z because of the variance between the servo motors

//Please adjust the offset values to your system properties
//DeltaRobotOne robot(A,B,C,X,Y,Z,LCD);

//If your display doesn't work try adress 0x3F

//Help: https://github.com/deltarobotone/how_to_build_your_robot/wiki/Step-5:-Servo-assembly

//Create the DeltaRobotOne-Object
DeltaRobotOne robot(0, 0, 0, 0, 0, 0, 0x27);

//Setup
void setup()
{
  //The robot.setup() function is required. 
  //Use this function in the first line of your setup function.
  robot.setup();

  //Set power cycle on for servo motors and light
  //Attention: Servo motors move to zero position in a fast way 
  //if you power on the main cycle at the first time!
  robot.power.mainOn();
  
  //Wait for 1 second
  robot.functions.waitFor(1000);
  
  //Print out some information on display
  robot.display.printLine1(F("Move Home..."));

  //Move the robot to the home position (X=0.0,Y=0.0,Z=85.0)
  robot.move.ptp(home);

  //Clear the display
  robot.display.clear();

  //Print out some information on display
  robot.display.printLine1(F("Gripper"));

  //Wait for 2 seconds
  robot.functions.waitFor(2000);
}

//Loop
void loop()
{
  //This example shows you how to use the gripper of the robot

  //Activate gripper (magnet)
  robot.gripper.close();

  //Wait for 2 seconds
  robot.functions.waitFor(2000);

  //Deactivate gripper (magnet)
  robot.gripper.open();

  //Wait for 2 seconds
  robot.functions.waitFor(2000);

  //Check status before you use gripper functions (optional)
  //Status false = Gripper open
  //Status true = Gripper closed
  
  if (robot.gripper.getStatus() == false) 
  {
  robot.gripper.close();
  }

  //Wait for 2 seconds
  robot.functions.waitFor(2000);

  if (robot.gripper.getStatus() == true)
  {
  robot.gripper.open();
  }

  //Wait for 2 seconds
  robot.functions.waitFor(2000);
}

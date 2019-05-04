#include "DeltaRobotOne.h"

//Every robot has different values for servo-offset A,B,C and 
//tcp-offset X,Y,Z because of the variance between the servo motors

//Please adjust the offset values to your system properties
//DeltaRobotOne robot(A,B,C,X,Y,Z,LCD);

//If your display doesn't work try adress 0x3F

//Help: https://github.com/deltarobotone/how_to_build_your_robot/wiki/Step-5:-Servo-assembly

//Create the DeltaRobotOne-Object
DeltaRobotOne robot(0, 0, 0, 0, 0, 0, 0x27);

//Define some variables for display printing control
int Value = 0;
int LastValue = 1;

//Setup
void setup()
{
  //The robot.setup() function is required. 
  //Use this function in the first line of your setup function.
  robot.setup();

  //Clear the display
  robot.display.clear();

  //Print out some information on display
  robot.display.printLine1(F("Encoder"));

  //Wait for 1 second
  robot.functions.waitFor(1000);

  //Reset all encoder values
  robot.encoder.reset();

  //Set encoder limit min
  robot.encoder.setLimitMin(0);
  
  //Set encoder limit max
  robot.encoder.setLimitMax(10);
}

//Loop
void loop()
{
  // This example shows you how to use the rotary encoder of the robot

  //Get the actual encoder value
  Value = robot.encoder.getValue();

  //If encoder value get changed print the new value on the display
  if (Value != LastValue)
  {
    robot.display.clear();
    robot.display.printLine1(F("Encoder"));
    robot.display.printLine2(String(Value));
    LastValue = Value;      
  }
}

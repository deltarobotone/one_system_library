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
  robot.display.printLine1(F("Workingspace"));

  //Wait for 1 second
  robot.functions.waitFor(1000);
}

//Loop
void loop()
{
  //This example shows you the working space limits of the robot

  //There is a workingspace defined for this robot to protect it from damage
  //The workingspace has 4 levels defined as a cylindrical form on the Z-Axis
  //The example let the robot move around the workingspace levels

  //Level 1
  //Z-Axis: 70.0-79.0mm
  //Radius = 25.0mm

  //Level 2
  //Z-Axis: 80.0-99.0mm
  //Radius = 45.0mm

  //Level 3
  //Z-Axis: 100.0-119.0mm
  //Radius = 35.0mm

  //Level 4
  //Z-Axis: 120.0-129.0mm
  //Radius = 15.0mm

  //This code is based on the "Circles" example
  float pi = 3.14;
  float stepWidth = (2 * pi) / 2880;
  float stepCounter = 0.0;
  float circleRadius = 0.0;
  
  Pos Position(0.0, 0.0, 0.0);

  //Level 1
  //Z-Axis: 70.0-79.0mm
  //Radius = 25.0mm

  stepCounter = 0.0;
  Position.y = 0.0;
  Position.x = 25.0;
  Position.z = 70.0;
  circleRadius = 25.0;
  robot.move.ptp(Position, Speed::half);
  robot.functions.waitFor(1000);

  for (int i = 0; i < 2880; i++)
  {
    Position.x = circleRadius * cos(stepCounter);
    Position.y = circleRadius * sin(stepCounter);
    robot.move.ptp(Position, Speed::full);
    stepCounter = stepCounter + stepWidth;
  }

  stepCounter = 0.0;
  Position.y = 0.0;
  Position.x = 25.0;
  Position.z = 79.0;
  circleRadius = 25.0;
  robot.move.ptp(Position, Speed::half);
  robot.functions.waitFor(1000);

  for (int i = 0; i < 2880; i++)
  {
    Position.x = circleRadius * cos(stepCounter);
    Position.y = circleRadius * sin(stepCounter);
    robot.move.ptp(Position, Speed::full);
    stepCounter = stepCounter + stepWidth;
  }

  //Level 2
  //Z-Axis: 80.0-99.0mm
  //Radius = 45.0mm
  
  stepCounter = 0.0;
  Position.y = 0.0;
  Position.x = 45.0;
  Position.z = 80.0;
  circleRadius = 45.0;
  robot.move.ptp(Position, Speed::half);
  robot.functions.waitFor(1000);

  for (int i = 0; i < 2880; i++)
  {
    Position.x = circleRadius * cos(stepCounter);
    Position.y = circleRadius * sin(stepCounter);
    robot.move.ptp(Position, Speed::full);
    stepCounter = stepCounter + stepWidth;
  }

  stepCounter = 0.0;
  Position.y = 0.0;
  Position.x = 45.0;
  Position.z = 99.0;
  circleRadius = 45.0;
  robot.move.ptp(Position, Speed::half);
  robot.functions.waitFor(1000);

  for (int i = 0; i < 2880; i++)
  {
    Position.x = circleRadius * cos(stepCounter);
    Position.y = circleRadius * sin(stepCounter);
    robot.move.ptp(Position, Speed::full);
    stepCounter = stepCounter + stepWidth;
  }

  //Level 3
  //Z-Axis: 100.0-119.0mm
  //Radius = 35.0mm

  stepCounter = 0.0;
  Position.y = 0.0;
  Position.x = 37.5;
  Position.z = 100.0;
  circleRadius = 37.5;
  robot.move.ptp(Position, Speed::half);
  robot.functions.waitFor(1000);

  for (int i = 0; i < 2880; i++)
  {
    Position.x = circleRadius * cos(stepCounter);
    Position.y = circleRadius * sin(stepCounter);
    robot.move.ptp(Position, Speed::full);
    stepCounter = stepCounter + stepWidth;
  }

  stepCounter = 0.0;
  Position.y = 0.0;
  Position.x = 37.5;
  Position.z = 119.0;
  circleRadius = 37.5;
  robot.move.ptp(Position, Speed::half);
  robot.functions.waitFor(1000);

  for (int i = 0; i < 2880; i++)
  {
    Position.x = circleRadius * cos(stepCounter);
    Position.y = circleRadius * sin(stepCounter);
    robot.move.ptp(Position, Speed::full);
    stepCounter = stepCounter + stepWidth;
  }

  //Level 4
  //Z-Axis: 120.0-129.0mm
  //Radius = 15.0mm

  stepCounter = 0.0;
  Position.y = 0.0;
  Position.x = 15.0;
  Position.z = 120.0;
  circleRadius = 15.0;
  robot.move.ptp(Position, Speed::half);
  robot.functions.waitFor(1000);
  
  for (int i = 0; i < 2880; i++)
  {
    Position.x = circleRadius * cos(stepCounter);
    Position.y = circleRadius * sin(stepCounter);
    robot.move.ptp(Position, Speed::full);
    stepCounter = stepCounter + stepWidth;
  }

  stepCounter = 0.0;
  Position.y = 0.0;
  Position.x = 15.0;
  Position.z = 129.0;
  circleRadius = 15.0;
  robot.move.ptp(Position, Speed::half);
  robot.functions.waitFor(1000);
  
  for (int i = 0; i < 2880; i++)
  {
    Position.x = circleRadius * cos(stepCounter);
    Position.y = circleRadius * sin(stepCounter);
    robot.move.ptp(Position, Speed::full);
    stepCounter = stepCounter + stepWidth;
  }

  robot.move.ptp(home, Speed::half);

  //Wait for 1 second
  robot.functions.waitFor(1000);
}

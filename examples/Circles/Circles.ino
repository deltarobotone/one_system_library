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
  robot.display.printLine1(F("Circles"));

  //Wait for 1 second
  robot.functions.waitFor(1000);
}

//Loop
void loop()
{
  // This example shows you how to move circles

  //Define pi
  float pi = 3.14;
  
  //Calculate the stepwidth
  float stepWidth = (2 * pi) / 2880;
  
  //Counter for stepwidth
  float stepCounter = 0.0;
  
  //Define circle radius
  float circleRadius = 45.0F;
  
  //Create position class object for circle positions
  Pos Position(0.0, 0.0, 0.0);
  
  //Set start position
  Position.y = 0.0;
  Position.x = 45.0;
  Position.z = 90.0;

  //Move with half speed to startposition
  robot.move.ptp(Position, Speed::half);

  //Wait for 1 second
  robot.functions.waitFor(1000);

  //To move the robot on a circle:
  //Calculate robot position on X-Axis with cosinus-function
  //Calculate robot position on Y-Axis with sinus-function
  //Move to positions with full speed
  //The robot speed depends on stepwidth in fact of the resolution
  for (int i = 0; i < 2880; i++)
  {
    Position.x = circleRadius * cos(stepCounter);
    Position.y = circleRadius * sin(stepCounter);
    robot.move.ptp(Position, Speed::full);
    stepCounter = stepCounter + stepWidth;
  }

  stepWidth = (2 * pi) / 1440;
  stepCounter = 0.0;

  for (int i = 0; i < 1440; i++)
  {
    Position.x = circleRadius * cos(stepCounter);
    Position.y = circleRadius * sin(stepCounter);
    robot.move.ptp(Position, Speed::full);
    stepCounter = stepCounter + stepWidth;
  }

  stepWidth = (2 * pi) / 720;
  stepCounter = 0.0;

  for (int i = 0; i < 720; i++)
  {
    Position.x = circleRadius * cos(stepCounter);
    Position.y = circleRadius * sin(stepCounter);
    robot.move.ptp(Position, Speed::full);
    stepCounter = stepCounter + stepWidth;
  }

  stepWidth = (2 * pi) / 360;
  stepCounter = 0.0;

  for (int i = 0; i < 360; i++)
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

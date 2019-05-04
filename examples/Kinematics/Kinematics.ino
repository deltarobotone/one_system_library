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

  //This example shows you how to define the kinematics and the workingspace of a delta robot

  //If you developed your own links you can use this function to setup the new kinematic
  //Base -> Servolink   = LengthA
  //Servolink length    = LengthB
  //Effectorlink lenght = LenghtC
  //TCP -> Effektorlink = LengthD
  
  //Function to change kinematics parameter
  //move.setKinematics(float lengthA, float lengthB, float lengthC, float lengthD)
  //Example with standard parameters
  robot.move.setKinematics(31.0F, 50.0F, 90.0F, 15.0F);

  //If you change the kinematics you have to adjust the workingspace
  //Workingspace has 4 levels
  //The cylindrical form of a level is defined with z-axis parameter and radius
  
  //setWorkingSpace(int level, float zmin, float zmax, float radius)
  //Example with standard parameters

  //Level 1
  //Z-Axis: 70.0-79.0mm
  //Radius = 25.0mm
  robot.move.setWorkingSpace(1, 70.0F, 79.0F, 25.0F);
  //Level 2
  //Z-Axis: 80.0-99.0mm
  //Radius = 45.0mm
  robot.move.setWorkingSpace(2, 80.0F, 99.0F, 45.0F);
  //Level 3
  //Z-Axis: 100.0-119.0mm
  //Radius = 37.5mm
  robot.move.setWorkingSpace(3, 100.0F, 119.0F, 37.5F);
  //Level 4
  //Z-Axis: 120.0-129.0mm
  //Radius = 15.0mm
  robot.move.setWorkingSpace(4, 120.0F, 129.0F, 15.0F);
}

void loop()
{

}

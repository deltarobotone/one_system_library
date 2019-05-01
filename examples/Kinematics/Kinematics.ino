#include "DeltaRobotOne.h"

//Create the DeltaRobotOne-Object
DeltaRobotOne robot(0, 0, 0, 0, 0, 0, 0x27);

//Setup
void setup()
{
  //Robot setup is required. 
  //Use this line as the first line in all your sketches.
  //Initialisation of some objects and parameters.
  robot.setup();

  //Function to change kinematics parameter
  //If you developed other links you can use this function to setup the new kinematic
  //Base -> Servolink = LengthA
  //Servolinklength = LengthB
  //Effectorlinklenght = LenghtC
  //TCP->Effektorlink = LengthD
  //For more information use the github wiki
  
  //move.setKinematicsLength(float lengthA, float lengthB, float lengthC, float lengthD)
  //Standard parameter
  robot.move.setKinematicsLength(31.0F, 50.0F, 90.0F, 15.0F);

  //If you cange the kinematiks you have to adjust the working space
  //Workingspace has 4 levels
  //The cylindrical form of a level is defined with z-axis parameter and radius
  
  //setWorkingSpaceLevel(int level, float radius, float zmin, float zmax)
  //Standard parameter

  //Level 1
  //Z-Axis: 70.0-79.0mm
  //Radius = 25.0mm
  robot.move.setWorkingSpaceLevel(1, 25.0F, 70.0F, 80.0F);
  //Level 2
  //Z-Axis: 80.0-99.0mm
  //Radius = 45.0mm
  robot.move.setWorkingSpaceLevel(2, 45.0F, 80.0F, 100.0F);
  //Level 3
  //Z-Axis: 100.0-119.0mm
  //Radius = 35.0mm
  robot.move.setWorkingSpaceLevel(3, 35.0F, 100.0F, 120.0F);
  //Level 4
  //Z-Axis: 120.0-129.0mm
  //Radius = 15.0mm
  robot.move.setWorkingSpaceLevel(4, 15.0F, 120.0F, 130.0F);
}

//Loopmove
void loop()
{
  //This example shows you how to use the menu function of the robot
}

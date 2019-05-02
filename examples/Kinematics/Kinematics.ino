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
  //If you developed your own links you can use this function to setup the new kinematic
  //Base -> Servolink = LengthA
  //Servolinklength = LengthB
  //Effectorlinklenght = LenghtC
  //TCP -> Effektorlink = LengthD
  
  //move.setKinematics(float lengthA, float lengthB, float lengthC, float lengthD)
  //ExampleStandard parameter
  robot.move.setKinematics(31.0F, 50.0F, 90.0F, 15.0F);

  //If you change the kinematics you have to adjust the workingspace
  //Workingspace has 4 levels
  //The cylindrical form of a level is defined with z-axis parameter and radius
  
  //setWorkingSpace(int level, float zmin, float zmax, float radius)
  //Example: Standard parameter

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

//Loopmove
void loop()
{
  //This example shows you how to define the kinematics and the workingspace of a delta robot
}

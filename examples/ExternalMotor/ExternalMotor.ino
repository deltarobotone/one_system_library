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
  robot.display.printLine1(F("External Motor"));

  //Wait for 2 seconds
  robot.functions.waitFor(2000);
}

//Loop
void loop()
{
  //This example shows you how to use an external motor on the robot interface
  //Connect a DC-Motor to interface pins M+ (5V max) and M- (Ground)

  //The motor speed can be set beetween 1 and 255
  //Set a high motor speed
  int speedValue = 255;

  //Start the motor
  // if you have a high motorspeed you can use this function in this way
  robot.extmotor.start(speedValue);

  //Wait for 2 seconds
  robot.functions.waitFor(2000);

  //Stop the motor
  robot.extmotor.stop();

  //Wait for 2 seconds
  robot.functions.waitFor(2000);

  //Set a slow motor speed
  speedValue = 50;

  //If you have a slow motorspeed you can use the startup parameter 
  //to set a high speed for 500 milliseconds to start the motor
  //Start the motor with startup function
  robot.extmotor.start(speedValue,true);

  //Wait for 2 seconds
  robot.functions.waitFor(2000);

  //Set a normal motor speed
  speedValue = 150;
  
  //Change the speed of the motor while the motor is running
  robot.extmotor.setSpeed(speedValue);

  //Wait for 2 seconds
  robot.functions.waitFor(2000);

  //Stop the motor
  robot.extmotor.stop();

  //Wait for 2 seconds
  robot.functions.waitFor(2000);
}

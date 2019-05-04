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
  robot.display.printLine1(F("Light Fade"));

  //Wait for 2 seconds
  robot.functions.waitFor(2000);
}

//Loop
void loop()
{
  //This example shows you how to use the fade functions of the robot light
  //There are some useful predefined parameters for light functions

  //Parameters for the colour
  //Colour::red
  //Colour::green
  //Colour::blue
  //Colour::yellow
  //Colour::magenta
  //Colour::cyan
  //Colour::white

  //Blink and fade functions has to be implemented in a loop
  //So you can integrate the light functions in your programm loop 
  //without blocking the program 

  //Reset the internal fade value to begin with lights off
  robot.light.fadeReset();
  
  //Fade with green light for 5 seconds
  //fade(int time, int min, int max, int stepsize, int colour)
  while(true)
  {
    robot.light.fade(2500, 0, 255, 5, Colour::green);
    if (robot.functions.pulse(5000))break;
  }
  
  //Reset the internal fade value to begin with lights off
  robot.light.fadeReset();
  //Wait for 1 second
  robot.functions.waitFor(1000);

  //Fade fast with blue light for 5 seconds
  while(true)
  {
    robot.light.fadeFast(Colour::blue);
    if (robot.functions.pulse(5000))break;
  }

  //Reset the internal fade value to begin with lights off
  robot.light.fadeReset();
  //Wait for 1 second
  robot.functions.waitFor(1000);

  //Fade slow with red light for 5 seconds
  while(true)
  {
    robot.light.fadeSlow(Colour::red);
    if (robot.functions.pulse(5000))break;
  }
  
  //Reset the internal fade value to begin with lights off
  robot.light.fadeReset();
  //Wait for 1 second
  robot.functions.waitFor(1000);

  while(true)
  {
    robot.light.heartbeat(Colour::magenta);
    if (robot.functions.pulse(5000))break;
  }

  //Wait for 1 second
  robot.functions.waitFor(1000);
}

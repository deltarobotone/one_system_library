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
  robot.display.printLine1(F("Functions"));

  //Wait for 2 seconds
  robot.functions.waitFor(2000);
}

//Loop
void loop()
{
  // This example shows you how to use some time functions of the robot

  //Two time functions are integrated. The whole robot code is free of delay functions
  //If you use a delay function the servo motors are lose their signals and positions
  //because the microcontroler is doing nothing in this time

  //If you want to stop your code for a defined time 
  //you can use the waitFor function of the robot

  //Print out some information
  robot.display.clear();
  robot.display.printLine1(F("Waiting for"));
  robot.display.printLine2(F("3 seconds"));
  
  //Wait for 3 seconds
  robot.functions.waitFor(3000);

  //Print out some information
  robot.display.clear();
  robot.display.printLine1(F("Waiting for"));
  robot.display.printLine2(F("1 second"));
 
  //Wait for 1 second
  robot.functions.waitFor(1000);

  //If you want to do something for a defined time
  //or something schould happen in a cyclic way 
  //you can use the pulse function

  //Light magenta
  robot.light.on(Colour::magenta, Intensity::max);

  //Print out some information
  robot.display.clear();
  robot.display.printLine1(F("Pulse in"));
  robot.display.printLine2(F("5 seconds"));
  
  while(true)
  {
    //Light blink
    robot.light.blinkFast();

    //The pulse function to terminate the while loop
    if (robot.functions.pulse(5000))
    {
    break;
    }
  }
  //Light off
  robot.light.off();
}

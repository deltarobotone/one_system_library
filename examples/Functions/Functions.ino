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

  //Set power cycle on for servo motors and light
  //Attention: Servo motors move to zero position in a fast way 
  //if you power on the main cycle at the first time!
  robot.power.mainOn();
  
  //Wait for 1 second
  robot.functions.waitFor(1000);
  
  //Print out some information on display
  robot.display.printLine1(F("Move Home..."));

  //Move th robot to the home position (X=0.0,Y=0.0,Z=85.0)
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

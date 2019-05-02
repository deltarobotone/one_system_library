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
  robot.display.printLine1(F("Light Blink"));

  //Wait for 2 seconds
  robot.functions.waitFor(2000);
}

//Loop
void loop()
{
  //This example shows you how to use the blink functions of the robot light
  //There are some useful predefined parameters for light functions

  //Parameters for the colour
  //Colour::red
  //Colour::green
  //Colour::blue
  //Colour::yellow
  //Colour::magenta
  //Colour::cyan
  //Colour::white

  //Parameter for intensity
  //Intensity::min  (20%)
  //Intensity::half (50%)
  //Intensity::max  (100%)
  //You can use also values between 0 and 255 for the intensity parameter

  //Set light on + Set intensity max + Set colour blue
  robot.light.on(Colour::blue, Intensity::max);

  //Blink and fade functions has to be implemented in a loop
  //So you can integrate the light functions in your programm loop 
  //without blocking the program 

  //Blink for 5 seconds
  //400 milliseconds on / 600 milliseconds off
  while(true)
  {
    robot.light.blink(400, 600);
    if (robot.functions.pulse(5000))break;
  }

  //Wait for 1 second
  robot.functions.waitFor(1000);

  //Set colour green
  robot.light.setColour(Colour::green);

  //Blink fast for 5 seconds
  while(true)
  {
    robot.light.blinkFast();
    if (robot.functions.pulse(5000))break;
  }

  //Wait for 1 second
  robot.functions.waitFor(1000);

  //Set colour red
  robot.light.setColour(Colour::red);

  //Blink slow for 5 seconds
  while(true)
  {
    robot.light.blinkSlow();
    if (robot.functions.pulse(5000))break;
  }

  //Wait for 1 second
  robot.functions.waitFor(1000);

  //Set colour cyan
  robot.light.setColour(Colour::cyan);

  //Blink for 1 second (Function blocks the programm for the given time)
  robot.light.blinkTime(1000);

  //Wait for 1 second
  robot.functions.waitFor(1000);
}

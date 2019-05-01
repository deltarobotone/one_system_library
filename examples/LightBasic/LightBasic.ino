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
  robot.display.printLine1(F("Light Basic"));

  //Wait for 2 seconds
  robot.functions.waitFor(2000);
}

//Loop
void loop()
{
  //This example shows you how to use the light of the robot
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

  //Set colour blue
  robot.light.setColour(Colour::blue);

  //Set intensity max
  robot.light.setIntensity(Intensity::max);

  //Set light on
  robot.light.on();

  //Wait for 2 seconds
  robot.functions.waitFor(2000);

  //Set light on + Set intensity max + Set colour green
  robot.light.on(Colour::green, Intensity::max);
  
  //Wait for 2 seconds
  robot.functions.waitFor(2000);

  //Set colour red
  robot.light.setColour(Colour::red);

  //Wait for 2 seconds
  robot.functions.waitFor(2000);

  //Set colour magenta
  robot.light.setColour(Colour::magenta);

  //Wait for 2 seconds
  robot.functions.waitFor(2000);

  //Set colour cyan
  robot.light.setColour(Colour::cyan);

  //Wait for 2 seconds
  robot.functions.waitFor(2000);

  //Set colour yellow
  robot.light.setColour(Colour::yellow);

  //Wait for 2 seconds
  robot.functions.waitFor(2000);

  //Set colour white
  robot.light.setColour(Colour::white);

  //Wait for 2 seconds
  robot.functions.waitFor(2000);

  //Set light off
  robot.light.off();

  //Wait for 2 seconds
  robot.functions.waitFor(2000);

  //Set light on + Set intensity max + Set colour blue
  robot.light.on(Colour::blue, Intensity::max);

  //Wait for 2 seconds
  robot.functions.waitFor(2000);

  //Set intensity half
  robot.light.setIntensity(Intensity::half);

  //Wait for 2 seconds
  robot.functions.waitFor(2000);

  //Set intensity min
  robot.light.setIntensity(Intensity::min);

  //Wait for 2 seconds
  robot.functions.waitFor(2000);

  //Set light off
  robot.light.off();

  //Wait for 2 seconds
  robot.functions.waitFor(2000);
  
}

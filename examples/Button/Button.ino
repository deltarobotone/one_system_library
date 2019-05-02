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
  robot.display.printLine1(F("Button"));

  //Wait for 2 seconds
  robot.functions.waitFor(2000);
}

//Loop
void loop()
{
  //This example shows you how to use the buttons of the robot
  //There are some useful predefined parameters for button functions

  //Parameters for the colour
  //ButtonID::top
  //ButtonID::center
  //ButtonID::encoder

  //You can use the button on two different ways

  //First option button.clicked(ButtonID)

  //Check if button is pushed and released (clicked)
  //Use top button
  if(robot.button.clicked(ButtonID::top))
  {
    //Light blue
    robot.light.on(Colour::blue,Intensity::max);
  }

  //Second option button.pushed(ButtonID)
  //and button.released(ButtonID)

  //Check if button is pushed
  //Use center button
  if(robot.button.push(ButtonID::center))
  {
    //Waif for button release
    robot.button.release(ButtonID::center);
    //Light green
    robot.light.on(Colour::green,Intensity::max);
  }

  //With the second option it is possible to do something while the button is pushed
  
  //Check if button is pushed
  //Use encoder button
  if(robot.button.push(ButtonID::encoder))
  {
    //Light red
    robot.light.on(Colour::red,Intensity::max);
    //Waif for button release
    robot.button.release(ButtonID::encoder);
    //Light off
    robot.light.off();
  }
  
}

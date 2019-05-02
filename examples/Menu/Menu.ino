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
}

//Loop
void loop()
{
  //This example shows you how to use the menu function of the robot

  //Define a variable for select information
  int select = 0;

  //Name the menu items (1-5 items are possible)
  //setItem(int position, String text)
  
  robot.menu.setItem(1, F("Light Blue"));
  robot.menu.setItem(2, F("Light Red"));
  robot.menu.setItem(3, F("Light Green"));
  robot.menu.setItem(4, F("Light White"));
  robot.menu.setItem(5, F("Light Off"));

  //Start the menu and wait for select information
  //Menu comes with a blue light (heartbeat)
  select = robot.menu.start();

  //use the select information to do something in your code
  if (select != 0)
  {
    if (select == 1) 
    {
      robot.light.on(Colour::blue,Intensity::max);
	    robot.functions.waitFor(2000);
    }
    if (select == 2) 
    {
      robot.light.on(Colour::red,Intensity::max);
	    robot.functions.waitFor(2000);
    }
    if (select == 3) 
    {
      robot.light.on(Colour::green,Intensity::max);
	    robot.functions.waitFor(2000);
    }
    if (select == 4) 
    {
      robot.light.on(Colour::white,Intensity::max);
	    robot.functions.waitFor(2000);
    }
    if (select == 5) 
    {
      robot.light.off();
	    robot.functions.waitFor(2000);
    }
  }}

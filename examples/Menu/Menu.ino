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

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
  robot.display.printLine1(F("Remote"));

  //Wait for 2 seconds
  robot.functions.waitFor(2000);
}

//Loop
void loop()
{
    // This example shows you how to use the remote function of the robot
    // The remote control function activates the communication protocol of the robot 
    // If you want to communicate via bluetooth you have to activate the module first

    //Activate bluetooth based remote control with top button 
    if (robot.button.clicked(ButtonID::top))
    {
      //Print out some information
      robot.display.printLine2(F("Bluetooth"));
      
      //Activate bluetooth module
      robot.power.bluetoothOn();
      
      //Wait for 2 seconds
      robot.functions.waitFor(2000);
      
      //Print out some information
      robot.screen.signals();
      
      //Start remote control mode (stop with center button)
      //Use one easy protocol to communicate with the robot 
      robot.remote.control();
      
      //Deactivate bluetooth module
      robot.power.bluetoothOff();

      //Print out some information on display
      robot.display.printLine1(F("Remote"));
    }
    
    //Activate usb serial based remote control with encoder button 
    if (robot.button.clicked(ButtonID::encoder))
    {
      //Print out some information
      robot.display.printLine2(F("USB"));
      
      //Wait for 2 seconds
      robot.functions.waitFor(2000);
      
      //Print out some information
      robot.screen.signals();
      
      //Start remote control mode (stop with center button)
      //Use one easy protocol to communicate with the robot 
      //Don't forget to activate the USB MODE Ctrl via the switch on the circuit board
      robot.remote.control();

      //Print out some information on display
      robot.display.printLine1(F("Remote"));
    }
}

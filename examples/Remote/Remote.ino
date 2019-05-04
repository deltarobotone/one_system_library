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
  robot.display.printLine1(F("Remote"));

  //Wait for 2 seconds
  robot.functions.waitFor(2000);

  //Set robot ID
  //The robot ID was used in the communication protocol
  //More information: https://github.com/deltarobotone/one_easy_protocol
  //If you want to communicate with more than one robot,
  //every robot needs an unique ID.
  robot.setID('1');
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

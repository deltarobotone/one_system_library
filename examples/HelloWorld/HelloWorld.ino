#include "DeltaRobotOne.h"

//Every robot has different values for servo-offset A,B,C and 
//tcp-offset X,Y,Z because of the variance between the servo motors

//Please adjust the offset values to your system properties
//DeltaRobotOne robot(A,B,C,X,Y,Z,LCD);

//If your display doesn't work try adress 0x3F

//Help: https://github.com/deltarobotone/how_to_build_your_robot/wiki/Step-5:-Servo-assembly

//Create the DeltaRobotOne-Object
//The DeltaRobotOne class includes all basic function of the robot. 
DeltaRobotOne robot(0, 0, 0, 0, 0, 0, 0x27);

// DeltaRobotOne (A,B,C,X,Y,Z,LCD)
// A = Offset Servo A (Degrees) : Default 0
// B = Offset Servo B (Degrees) : Default 0
// C = Offset Servo C (Degrees) : Default 0
// X = Offset TCP X (Millimeters) : Default 0
// Y = Offset TCP Y (Millimeters) : Default 0
// Z = Offset TCP Z (Millimeters) : Default 0
// LCD = I2C Adress Display : Default 0x27  


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
  robot.display.printLine1(F("Hello World"));
}

//Loop
void loop()
{
}

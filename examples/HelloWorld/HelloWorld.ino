#include "DeltaRobotOne.h"

//Create the DeltaRobotOne-Object
//The DeltaRobotOne class includes all basic function of the robot. 
DeltaRobotOne robot(0, 0, 0, 0, 0, 0, 0x27);

// DeltaRobotOne ( A, B, C, X, Y, Z, LCD )
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
  robot.display.printLine1(F("Hello World"));
}

//Loop
void loop()
{
}

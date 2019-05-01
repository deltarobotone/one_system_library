#include "DeltaRobotOne.h"

//Create the DeltaRobotOne-Object
DeltaRobotOne robot(0, 0, 0, 0, 0, 0, 0x27);

//Define some variables for display printing control
int Value = 0;
int LastValue = 1;
  
//Setup
void setup()
{
  //Robot setup is required. 
  //Use this line as the first line in all your sketches.
  //Initialisation of some objects and parameters.
  robot.setup();

  //Clear the display
  robot.display.clear();
  //Print out some information on display
  robot.display.printLine1(F("Encoder"));

  //Wait for 1 second
  robot.functions.waitFor(1000);

  //Reset all encoder values
  robot.encoder.reset();

  //Set encoder limit min
  robot.encoder.setLimitMin(0);
  
  //Set encoder limit max
  robot.encoder.setLimitMax(10);
}

//Loop
void loop()
{
  //Get the actual encoder value
  Value = robot.encoder.getValue();

  //If encoder value get changed print the new value on the display
  if (Value != LastValue)
  {
    robot.display.clear();
    robot.display.printLine1(F("Encoder"));
    robot.display.printLine2(String(Value));
    LastValue = Value;      
  }
}

#include "DeltaRobotOne.h"

// Create the DeltaRobotOne-Object
DeltaRobotOne robot(0, 0, 0, 0, 0, 0, 0x27);

// DeltaRobotOne ( A, B, C, X, Y, Z, LCD )
// A = Offset Servo A (Degrees) : Default 0
// B = Offset Servo B (Degrees) : Default 0
// C = Offset Servo C (Degrees) : Default 0
// X = Offset TCP X (Millimeters) : Default 0
// Y = Offset TCP Y (Millimeters) : Default 0
// Z = Offset TCP Z (Millimeters) : Default 0
// LCD = I2C Adress Display : Default 0x27  

//Prototypes
void pickAndPlace(DeltaRobot::DeltaRobotOne &robot, const float &speed);
void circle(DeltaRobot::DeltaRobotOne &robot);
void colourTest(DeltaRobot::DeltaRobotOne &robot, int time);

//Setup
void setup()
{
	robot.setup();

	robot.screen.info(1400);
	robot.screen.progress(1600, F("Booting"));
	robot.power.mainOn();

	colourTest(robot,300);
	robot.display.printLine1(F("Move Home..."));
	robot.move.ptp(home, Speed::slow);

	robot.screen.ready();
	robot.light.on(Colour::blue, Intensity::max);
}

//Loop
void loop()
{
	robot.light.blinkSlow();

	if (robot.button.clicked(ButtonID::top) || robot.button.clicked(ButtonID::center) || robot.button.clicked(ButtonID::encoder))
	{
		int MenuSelect = 0;
		{
			robot.menu.setItem(1, F("Live-Mode"));
			robot.menu.setItem(2, F("Applications"));
			robot.menu.setItem(3, F("Remote"));
			robot.menu.setItem(4, F("Ext. Motor"));
			robot.menu.setItem(5, F("Setupposition"));
			MenuSelect = robot.menu.start();
		}

		if (MenuSelect == 1)
		{
			robot.screen.progress(500, F("Loading"));
			robot.livemode.start();
		}

		if (MenuSelect == 2)
		{
			int appSelect = 0;
			{
				robot.menu.setItem(1, F("Pick Place SLOW"));
				robot.menu.setItem(2, F("Pick Place HALF"));
				robot.menu.setItem(3, F("Pick Place FAST"));
				robot.menu.setItem(4, F("Pick Place MAX"));
				robot.menu.setItem(5, F("Circle"));
				appSelect = robot.menu.start();
			}

			if (appSelect != 0)
			{
				robot.screen.progress(300, F("Loading"));
				if (appSelect == 1) pickAndPlace(robot, Speed::slow);
				if (appSelect == 2) pickAndPlace(robot, Speed::half);
				if (appSelect == 3) pickAndPlace(robot, Speed::fast);
				if (appSelect == 4) pickAndPlace(robot, Speed::full);
				if (appSelect == 5) circle(robot);
			}
		}

		if (MenuSelect == 3)
		{
			int remoteSelect = 0;
			{
				robot.menu.setItem(1, F("USB Serial"));
				robot.menu.setItem(2, F("Bluetooth"));
				robot.menu.setItem(3, F(""));
				robot.menu.setItem(4, F(""));
				robot.menu.setItem(5, F(""));
				remoteSelect = robot.menu.start();
			}
			if (remoteSelect != 0)
			{
				robot.screen.progress(300, F("Loading"));
				if (remoteSelect == 1) robot.power.bluetoothOff();
				if (remoteSelect == 2) robot.power.bluetoothOn();
				robot.screen.signals();
				robot.remote.control();
				robot.power.bluetoothOff();
			}
		}
		if (MenuSelect == 4)
		{
			robot.light.on(Colour::yellow, Intensity::max);
			robot.extmotor.control();
			robot.light.off();
		}
		if (MenuSelect == 5)
		{
			robot.servosetup.start();
		}
		robot.screen.ready();
		robot.light.on(Colour::blue, Intensity::max);
	}
}

void pickAndPlace(DeltaRobot::DeltaRobotOne &robot,const float &speed)
{
	Pos P10(31.0, -17.5, 108.0);
	Pos P20(31.0, 17.5, 108.0);
	Pos P30(0.0, -35.0, 108.0);
	Pos P40(0.0, 0.0, 108.0);
	Pos P50(0.0, 35.0, 108.0);
	Pos P60(-31.0, -17.5, 108.0);
	Pos P70(-31.0, 17.5, 108.0);

	int time = 0;

	if (speed < Speed::full) time = 10;
	else time = 250;

	robot.light.off();
	robot.move.ptp(home, speed);
	robot.light.on(Colour::white, Intensity::max);
	robot.functions.waitFor(time);

	robot.move.ptp(P60, speed);
	robot.functions.waitFor(time);

	P60.z += 10.0;
	robot.move.ptp(P60, speed);
	robot.gripper.close();
	robot.light.on(Colour::green, Intensity::max);
	robot.functions.waitFor(time);

	P60.z -= 10.0;
	robot.move.ptp(P60, speed);
	robot.functions.waitFor(time);

	robot.move.ptp(P50, speed);
	robot.functions.waitFor(time);

	P50.z += 10.0;
	robot.move.ptp(P50, speed);
	robot.gripper.open();
	robot.light.on(Colour::red, Intensity::max);
	robot.functions.waitFor(time);

	P50.z -= 10.0;
	robot.move.ptp(P50, speed);
	robot.functions.waitFor(time);

	robot.move.ptp(P70, speed);
	robot.functions.waitFor(time);

	P70.z += 10.0;
	robot.move.ptp(P70, speed);
	robot.gripper.close();
	robot.light.on(Colour::green, Intensity::max);
	robot.functions.waitFor(time);

	P70.z -= 10.0;
	robot.move.ptp(P70, speed);
	robot.functions.waitFor(time);

	robot.move.ptp(P20, speed);
	robot.functions.waitFor(time);

	P20.z += 10.0;
	robot.move.ptp(P20, speed);
	robot.gripper.open();
	robot.light.on(Colour::red, Intensity::max);
	robot.functions.waitFor(time);

	P20.z -= 10.0;
	robot.move.ptp(P20, speed);
	robot.functions.waitFor(time);

	robot.move.ptp(P50, speed);
	robot.functions.waitFor(time);

	P50.z += 10.0;
	robot.move.ptp(P50, speed);
	robot.gripper.close();
	robot.light.on(Colour::green, Intensity::max);
	robot.functions.waitFor(time);

	P50.z -= 10.0;
	robot.move.ptp(P50, speed);
	robot.functions.waitFor(time);

	robot.move.ptp(P10, speed);
	robot.functions.waitFor(time);

	P10.z += 10.0;
	robot.move.ptp(P10, speed);
	robot.gripper.open();
	robot.light.on(Colour::red, Intensity::max);
	robot.functions.waitFor(time);

	P10.z -= 10.0;
	robot.move.ptp(P10, speed);
	robot.functions.waitFor(time);

	robot.move.ptp(P20, speed);
	robot.functions.waitFor(time);

	P20.z += 10.0;
	robot.move.ptp(P20, speed);
	robot.gripper.close();
	robot.light.on(Colour::green, Intensity::max);
	robot.functions.waitFor(time);

	P20.z -= 10.0;
	robot.move.ptp(P20, speed);
	robot.functions.waitFor(time);

	robot.move.ptp(P30, speed);
	robot.functions.waitFor(time);

	P30.z += 10.0;
	robot.move.ptp(P30, speed);
	robot.gripper.open();
	robot.light.on(Colour::red, Intensity::max);
	robot.functions.waitFor(time);

	P30.z -= 10.0;
	robot.move.ptp(P30, speed);
	robot.functions.waitFor(time);

	robot.move.ptp(P10, speed);
	robot.functions.waitFor(time);

	P10.z += 10.0;
	robot.move.ptp(P10, speed);
	robot.gripper.close();
	robot.light.on(Colour::green, Intensity::max);
	robot.functions.waitFor(time);

	P10.z -= 10.0;
	robot.move.ptp(P10, speed);
	robot.functions.waitFor(time);

	robot.move.ptp(P60, speed);
	robot.functions.waitFor(time);

	P60.z += 10.0;
	robot.move.ptp(P60, speed);
	robot.gripper.open();
	robot.light.on(Colour::red, Intensity::max);
	robot.functions.waitFor(time);

	P60.z -= 10.0;
	robot.move.ptp(P60, speed);
	robot.functions.waitFor(time);

	robot.move.ptp(P30, speed);
	robot.functions.waitFor(time);

	P30.z += 10.0;
	robot.move.ptp(P30, speed);
	robot.gripper.close();
	robot.light.on(Colour::green, Intensity::max);
	robot.functions.waitFor(time);

	P30.z -= 10.0;
	robot.move.ptp(P30, speed);
	robot.functions.waitFor(time);

	robot.move.ptp(P70, speed);
	robot.functions.waitFor(time);

	P70.z += 10.0;
	robot.move.ptp(P70, speed);
	robot.gripper.open();
	robot.light.on(Colour::red, Intensity::max);
	robot.functions.waitFor(time);

	P70.z -= 10.0;
	robot.move.ptp(P70, speed);
	robot.functions.waitFor(time);

	robot.move.ptp(home, speed);
	robot.display.clear();
	robot.functions.waitFor(time);
}

void circle(DeltaRobot::DeltaRobotOne &robot)
{
	robot.light.on(Colour::yellow, Intensity::max);

  	// This example shows you how to move a circle

  	//Define pi
  	float pi = 3.14;
  
  	//Calculate the stepwidth
  	float stepWidth = (2 * pi) / 2880;
  
  	//Counter for stepwidth
  	float stepCounter = 0.0;
  
  	//Define circle radius
  	float circleRadius = 45.0F;
  
  	//Create position class object for circle positions
  	Pos Position(0.0, 0.0, 0.0);
  
  	//Set start position
  	Position.y = 0.0;
  	Position.x = 45.0;
  	Position.z = 90.0;

  	//Move with half speed to startposition
  	robot.move.ptp(Position, Speed::half);

  	//Wait for 1 second
  	robot.functions.waitFor(1000);

  	//To move the robot on a circle:
  	//Calculate robot position on X-Axis with cosinus-function
  	//Calculate robot position on Y-Axis with sinus-function
  	//Move to positions with full speed
  	//The robot speed depends on stepwidth in fact of the resolution
  	for (int i = 0; i < 2880; i++)
  	{
    	Position.x = circleRadius * cos(stepCounter);
    	Position.y = circleRadius * sin(stepCounter);
    	robot.move.ptp(Position, Speed::full);
    	stepCounter = stepCounter + stepWidth;
  	}

  	stepWidth = (2 * pi) / 1440;
  	stepCounter = 0.0;

  	for (int i = 0; i < 1440; i++)
  	{
    	Position.x = circleRadius * cos(stepCounter);
    	Position.y = circleRadius * sin(stepCounter);
    	robot.move.ptp(Position, Speed::full);
    	stepCounter = stepCounter + stepWidth;
  	}

  	stepWidth = (2 * pi) / 720;
  	stepCounter = 0.0;

  	for (int i = 0; i < 720; i++)
  	{
    	Position.x = circleRadius * cos(stepCounter);
    	Position.y = circleRadius * sin(stepCounter);
    	robot.move.ptp(Position, Speed::full);
    	stepCounter = stepCounter + stepWidth;
  	}

  	stepWidth = (2 * pi) / 360;
  	stepCounter = 0.0;

  	for (int i = 0; i < 360; i++)
  	{
    	Position.x = circleRadius * cos(stepCounter);
    	Position.y = circleRadius * sin(stepCounter);
    	robot.move.ptp(Position, Speed::full);
    	stepCounter = stepCounter + stepWidth;
  	}
	robot.move.ptp(home, Speed::half);
	robot.light.off();
}

void colourTest(DeltaRobot::DeltaRobotOne &robot, int time)
{
	robot.screen.progress(50, F("Testing LED's..."));
	robot.light.on(Colour::red, Intensity::max);
	robot.functions.waitFor(time);
	robot.light.setColour(Colour::green);
	robot.functions.waitFor(time);
	robot.light.setColour(Colour::blue);
	robot.functions.waitFor(time);
	robot.light.setColour(Colour::yellow);
	robot.functions.waitFor(time);
	robot.light.setColour(Colour::cyan);
	robot.functions.waitFor(time);
	robot.light.setColour(Colour::magenta);
	robot.functions.waitFor(time);
	robot.light.setColour(Colour::white);
	robot.functions.waitFor(time);
	robot.light.off();
	robot.display.clear();
}
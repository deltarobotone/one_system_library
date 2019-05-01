#include "DeltaRobotOne.h"

DeltaRobot::DeltaRobotOne::DeltaRobotOne(int offsetServoA, int offsetServoB, int offsetServoC, int offsetTCPX, int offsetTCPY, int offsetTCPZ, uint8_t displayAdress) :
	display(displayAdress),
	light(),
	extmotor(encoder,button,display),
	menu(light, display, button, encoder),
	screen(display, move),
	livemode(move,light,display,button,encoder,gripper,screen),
	remote(move,light,display,button,gripper,screen,extmotor),
	servosetup(screen,move,light,button)
{
	move = DeltaRobot::Move(offsetServoA, offsetServoB, offsetServoC, offsetTCPX, offsetTCPY, offsetTCPZ);
}

void DeltaRobot::DeltaRobotOne::setup()
{
	pinMode(Pins::servoA, OUTPUT);
	pinMode(Pins::servoB, OUTPUT);
	pinMode(Pins::servoC, OUTPUT);

	pinMode(Pins::mainPower, OUTPUT);
	pinMode(Pins::bluetoothPower, OUTPUT);
	pinMode(Pins::externalMotor, OUTPUT);

	pinMode(Pins::ledR, OUTPUT);
	pinMode(Pins::ledG, OUTPUT);
	pinMode(Pins::ledB, OUTPUT);
	pinMode(Pins::ledI, OUTPUT);

	pinMode(Pins::gripper, OUTPUT);

	pinMode(Pins::buttonTop, INPUT);
	pinMode(Pins::buttonCenter, INPUT);
	pinMode(Pins::buttonEncoder, INPUT);

	move.setup();
	display.setup();
	encoder.setup();
	remote.setID(robotID);
}

void DeltaRobot::DeltaRobotOne::setID(char id)
{
	robotID = id;
	remote.setID(id);
}

char DeltaRobot::DeltaRobotOne::getID()
{
	return robotID;
}


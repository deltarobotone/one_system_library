#include "Gripper.h"


DeltaRobot::Gripper::Gripper()
{
}

void DeltaRobot::Gripper::open()
{
	digitalWrite(Pins::gripper, LOW);
	gripperStatus = false;
}

void DeltaRobot::Gripper::close()
{
	digitalWrite(Pins::gripper, HIGH);
	gripperStatus = true;
}

bool DeltaRobot::Gripper::getStatus()
{
	return gripperStatus;
}

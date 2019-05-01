#include "Power.h"

DeltaRobot::Power::Power()
{
}

void DeltaRobot::Power::bluetoothOn()
{
	digitalWrite(Pins::bluetoothPower, HIGH);
}

void DeltaRobot::Power::bluetoothOff()
{
	digitalWrite(Pins::bluetoothPower, LOW);
}

void DeltaRobot::Power::mainOn()
{
	digitalWrite(Pins::mainPower, HIGH);
}

void DeltaRobot::Power::mainOff()
{
	digitalWrite(Pins::mainPower, LOW);
}
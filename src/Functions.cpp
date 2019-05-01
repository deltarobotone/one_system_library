#include "Functions.h"

DeltaRobot::Functions::Functions()
{
}

void DeltaRobot::Functions::waitFor(int milliseconds)
{
	delayMillis = millis();
	while (true)
	{
	if (millis() - delayMillis >= milliseconds)
	{
		break;
	}
	}
}

bool DeltaRobot::Functions::pulse(int milliseconds)
{
	if ((millis() - pulseMillis >= milliseconds) && pulseStatus == false)
	{
		pulseMillis = millis();
		pulseStatus = true;
		pulseValue = false;
	}

	if (millis() - pulseMillis < milliseconds)
	{
		pulseStatus = true;
		pulseValue = false;
	}

	if ((millis() - pulseMillis >= milliseconds) && pulseStatus == true)
	{
		pulseValue = true;
		pulseStatus = false;
	}
	return pulseValue;
}

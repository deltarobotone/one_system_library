#include "Encoder.h"

int DeltaRobot::Encoder::encoderValue = 0;
int DeltaRobot::Encoder::statusA = LOW;
int DeltaRobot::Encoder::statusB = LOW;
int DeltaRobot::Encoder::lastStatusA = LOW;
int DeltaRobot::Encoder::lastStatusB = LOW;
int DeltaRobot::Encoder::valueLimitMin = -1000;
int DeltaRobot::Encoder::valueLimitMax = 1000;

DeltaRobot::Encoder::Encoder()
{
}

void DeltaRobot::Encoder::setup()
{
	DeltaRobot::Encoder::encoderValue = 0;
	attachInterrupt(1, encoderA, CHANGE);
	attachInterrupt(0, encoderB, CHANGE);
}

void DeltaRobot::Encoder::encoderA()
{
	DeltaRobot::Encoder::statusA = digitalRead(Pins::encoderA);
	DeltaRobot::Encoder::statusB = digitalRead(Pins::encoderB);
}

void DeltaRobot::Encoder::encoderB()
{
	DeltaRobot::Encoder::statusA = digitalRead(Pins::encoderA);
	DeltaRobot::Encoder::statusB = digitalRead(Pins::encoderB);
}

int DeltaRobot::Encoder::getValue()
{
	if (DeltaRobot::Encoder::lastStatusB == LOW && DeltaRobot::Encoder::statusB == LOW)
	{
		if ((DeltaRobot::Encoder::lastStatusA == LOW) && (DeltaRobot::Encoder::statusA == HIGH))
		{
			if (DeltaRobot::Encoder::encoderValue < DeltaRobot::Encoder::valueLimitMax)
			{
				DeltaRobot::Encoder::encoderValue++;
			}
		}
	}

	if (DeltaRobot::Encoder::lastStatusB == LOW && DeltaRobot::Encoder::statusB == HIGH)
	{
		if ((DeltaRobot::Encoder::lastStatusA == LOW) && (DeltaRobot::Encoder::statusA == LOW))
		{
			if (DeltaRobot::Encoder::encoderValue > DeltaRobot::Encoder::valueLimitMin)
			{
				DeltaRobot::Encoder::encoderValue--;
			}
		}
	}

	DeltaRobot::Encoder::lastStatusA = DeltaRobot::Encoder::statusA;
	DeltaRobot::Encoder::lastStatusB = DeltaRobot::Encoder::statusB;

	return DeltaRobot::Encoder::encoderValue;
}

void DeltaRobot::Encoder::setValue(int value)
{
	DeltaRobot::Encoder::encoderValue = value;
}

void DeltaRobot::Encoder::setLimitMin(int value)
{
	valueLimitMin = value;
}

void DeltaRobot::Encoder::setLimitMax(int value)
{
	valueLimitMax = value;
}

int DeltaRobot::Encoder::getLimitMin()
{
	return valueLimitMin;
}

int DeltaRobot::Encoder::getLimitMax()
{
	return valueLimitMax;
}

void DeltaRobot::Encoder::reset()
{
	DeltaRobot::Encoder::valueLimitMin = -1000;
	DeltaRobot::Encoder::valueLimitMax = 1000;
	DeltaRobot::Encoder::encoderValue = 0;
}


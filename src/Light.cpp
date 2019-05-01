#include "Light.h"

DeltaRobot::Light::Light()
{
}

void DeltaRobot::Light::on()
{
	setIntensity(Intensity::max);
}

void DeltaRobot::Light::off()
{
	setIntensity(Intensity::off);
}

void DeltaRobot::Light::setColour(int colour)
{
	switch (colour)
	{
	case 1:
		digitalWrite(Pins::ledR, HIGH);
		digitalWrite(Pins::ledG, LOW);
		digitalWrite(Pins::ledB, LOW);
		break;
	case 2:
		digitalWrite(Pins::ledR, LOW);
		digitalWrite(Pins::ledG, HIGH);
		digitalWrite(Pins::ledB, LOW);
		break;
	case 3:
		digitalWrite(Pins::ledR, LOW);
		digitalWrite(Pins::ledG, LOW);
		digitalWrite(Pins::ledB, HIGH);
		break;
	case 4:
		digitalWrite(Pins::ledR, HIGH);
		digitalWrite(Pins::ledG, HIGH);
		digitalWrite(Pins::ledB, LOW);
		break;
	case 5:
		digitalWrite(Pins::ledR, HIGH);
		digitalWrite(Pins::ledG, LOW);
		digitalWrite(Pins::ledB, HIGH);
		break;
	case 6:
		digitalWrite(Pins::ledR, LOW);
		digitalWrite(Pins::ledG, HIGH);
		digitalWrite(Pins::ledB, HIGH);
		break;
	case 7:
		digitalWrite(Pins::ledR, HIGH);
		digitalWrite(Pins::ledG, HIGH);
		digitalWrite(Pins::ledB, HIGH);
		break;
	default:
		break;
	}
}

void DeltaRobot::Light::setIntensity(int intensity)
{
	analogWrite(Pins::ledI, intensity);
}

void DeltaRobot::Light::on(int colour, int intensity)
{
	setColour(colour);
	setIntensity(intensity);
}

void DeltaRobot::Light::blink(int timeOn, int timeOff)
{
	if (blinkStatus == false)
	{
		if (functions.pulse(timeOff) == true)
		{
			on();
			blinkStatus = true;
		}
	}
	if (blinkStatus == true)
	{
		if (functions.pulse(timeOn) == true)
		{
			off();
			blinkStatus = false;
		}
	}
}

void DeltaRobot::Light::blinkFast()
{
	blink(200, 200);
}

void DeltaRobot::Light::blinkTime(int milliseconds)
{
	blinkLimitMillis = millis();

	while (millis() - blinkLimitMillis < milliseconds)
	{
		blink(50, 50);
	}
}

void DeltaRobot::Light::blinkSlow()
{
	blink(1000, 1000);
}

void DeltaRobot::Light::fade(int time, int min, int max, int stepsize, int colour)
{
	if (fadeValue >= max)
	{
		fadeStatus = false;
	}
	if (fadeValue <= min)
	{
		fadeValue = min;
		fadeStatus = true;
	}

	int Steptime = (time / ((max - min) / stepsize));

	if (fadeStatus == true && functions.pulse(Steptime))
	{
		fadeValue = fadeValue + stepsize;
		on(colour, fadeValue);
	}

	if (fadeStatus == false && functions.pulse(Steptime))
	{
		fadeValue = fadeValue - stepsize;
		on(colour, fadeValue);
	}
}

void DeltaRobot::Light::fadeFast(int colour)
{
	fade(500, 30, 200, 2, colour);
}

void DeltaRobot::Light::fadeSlow(int colour)
{
	fade(2000, 30, 200, 2, colour);
}

void DeltaRobot::Light::fadeReset()
{
	fadeStatus = false;
	fadeValue = 0;
}

void DeltaRobot::Light::heartbeat(int colour)
{
	fade(900, 20, 160, 3, colour);
}

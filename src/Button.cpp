#include "Button.h"

DeltaRobot::Button::Button()
{
	inputStatus = false;
	inputValue = false;
	debounceStatus = false;
	startTime = 0;
	pushTime = 20;
	releaseTime = 10;
}

bool DeltaRobot::Button::debounceInput(int pin, int debounceTime)
{
	inputStatus = digitalRead(pin);

	if (inputStatus == HIGH && debounceStatus == false)
	{
		startTime = millis();
		debounceStatus = true;
	}

	if ((millis() - startTime > debounceTime) && debounceStatus == true)
	{
		inputValue = true;
		debounceStatus = false;
	}

	if ((millis() - startTime > debounceTime) && inputStatus == false)
	{
		inputValue = false;
	}
	inputStatus = false;
	return inputValue;
}

bool DeltaRobot::Button::push(int buttonID)
{
	switch (buttonID)
	{
	case 1:
	{
		return debounceInput(Pins::buttonTop, pushTime);
	}
	break;
	case 2:
	{
		return debounceInput(Pins::buttonCenter, pushTime);
	}
	break;
	case 3:
	{
		return debounceInput(Pins::buttonEncoder, pushTime);
	}
	break;
	default:
		break;
	}
}

void DeltaRobot::Button::release(int buttonID)
{
	int pin = 0;
	switch (buttonID)
	{
	case 1:
	{
		pin = Pins::buttonTop;
		break;
	}
	case 2:
	{

		pin = Pins::buttonCenter;
		break;
	}
	case 3:
	{
		pin = Pins::buttonEncoder;
		break;
	}
	default:
		break;
	}
	while (true)
	{
		bool a = digitalRead(pin);
		functions.waitFor(releaseTime);
		bool b = digitalRead(pin);
		if (a == false && b == false)
		{
			functions.waitFor(releaseTime);
			break;
		}
	}
}

bool DeltaRobot::Button::clicked(int buttonID)
{
	if (push(buttonID))
	{
		release(buttonID);
		return true;
	}
	return false;
}



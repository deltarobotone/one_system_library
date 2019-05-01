#include "ExtMotor.h"

DeltaRobot::ExternalMotor::ExternalMotor(
	DeltaRobot::Encoder &encoder, 
	DeltaRobot::Button &button, 
	DeltaRobot::Display &display):
	encoder(encoder),
	button(button),
	display(display)
{
}

void DeltaRobot::ExternalMotor::start(int motorspeed, bool startup)
{
	DeltaRobot::Functions functions;
	speed = motorspeed;
	if (status == false && speed != 0 && startup == true)
	{
		analogWrite(Pins::externalMotor, 255);
		functions.waitFor(500);
		analogWrite(Pins::externalMotor, speed);
		status = true;
	}
	else
	{
		analogWrite(Pins::externalMotor, speed);
		status = true;
	}
}

void DeltaRobot::ExternalMotor::stop()
{
	analogWrite(Pins::externalMotor, LOW);
	status = false;
}

int DeltaRobot::ExternalMotor::getSpeed()
{
	return speed;
}

void DeltaRobot::ExternalMotor::setSpeed(int motorspeed)
{
	speed = motorspeed;
	if (status == true)
	{
		analogWrite(Pins::externalMotor, speed);
	}
}

bool DeltaRobot::ExternalMotor::getStatus()
{
	return status;
}

void DeltaRobot::ExternalMotor::control()
{
	int oldValue = 0;
	float speedValue = 0.0;
	encoder.setup();
	int min = 0;
	int max = 50;
	encoder.setLimitMax(max);
	encoder.setLimitMin(min);
	int value = speed / 5;
	encoder.setValue(value);
	display.clear();

	if (status == true)
	{
		display.printLine1(F("Speed:         %"));
		speedValue = (speed / 250.0) * 100.0;
		display.printLine1(String(speedValue),7);
		display.printLine2(F("Status:         "));
		if (status == true) display.printLine2(F("ON"), 8);
		else display.printLine2(F("OFF"), 8);
	}
	else
	{
		display.printLine1(F("Press Button 3"));
		display.printLine2(F("to start Motor"));
	}

	while (true)
	{
		if (status == false)
		{
			if (button.clicked(ButtonID::encoder))
			{
				start(speed);
				display.printLine1(F("Speed:         %"));
				speedValue = (speed / 250.0) * 100.0;
				display.printLine1(String(speedValue), 7);
				display.printLine2(F("Status:         "));
				display.printLine2(F("ON "), 8);
			}
		}
		if (status == true)
		{
			if (button.clicked(ButtonID::encoder))
			{
				stop();
				display.printLine1(F("Speed:         %"));
				speedValue = (speed / 250.0) * 100.0;
				display.printLine1(String(speedValue), 7);
				display.printLine2(F("Status:         "));
				display.printLine2(F("OFF"), 8);
			}
		}
		speed = 5 * encoder.getValue();
		if (speed != oldValue)
		{
			setSpeed(speed);
			oldValue = speed;
			display.printLine1(F("Speed:         %"));
			speedValue = (speed / 250.0) * 100.0;
			display.printLine1(String(speedValue), 7);
			display.printLine2(F("Status:         "));
			if (status == true) display.printLine2(F("ON"), 8);
			else display.printLine2(F("OFF"), 8);
		}
		if (button.clicked(ButtonID::center))
		{
			break;
		}
	}
}

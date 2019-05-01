#include "LiveMode.h"

DeltaRobot::LiveMode::LiveMode(
	DeltaRobot::Move & move, 
	DeltaRobot::Light & light, 
	DeltaRobot::Display & display,
	DeltaRobot::Button & button, 
	DeltaRobot::Encoder & encoder, 
	DeltaRobot::Gripper & gripper, 
	DeltaRobot::Screen & screen):
	move(move),
	light(light),
	display(display),
	button(button),
	encoder(encoder),
	gripper(gripper),
	screen(screen)
{
}

void DeltaRobot::LiveMode::start()
{
	bool directionX = true;
	bool directionY = true;
	bool directionZ = true;
	int value = 0;
	int lastValue = 1;
	bool limit = true;
	bool workingspace = true;
	int encoderValue = 0;

	DeltaRobot::Pos position(home);
	screen.position();

	while (true)
	{
		screen.position();
		display.printText("-", 0, 0);
		display.printText("+", 2, 0);
		encoder.reset();
		encoderValue = int(position.x);
		encoder.setValue(encoderValue);

		while (directionX)
		{
			value = encoder.getValue();
			if (value != lastValue)
			{
				workingspace = true;
				position.x = value;
				limit = move.ptp(position,Speed::full);
				if (limit == false)
				{
					screen.limit();
					light.on(Colour::red, Intensity::max);
					workingspace = false;
					if (value < 0)
					{
						encoderValue = int(position.x) + 1;
						encoder.setValue(encoderValue);
					}
					else
					{
						encoderValue = int(position.x) - 1;
						encoder.setValue(encoderValue);
					}
				}
				else
				{
					screen.position();
					display.printText("-", 0, 0);
					display.printText("+", 2, 0);
				}
				lastValue = encoder.getValue();
			}

			if (gripper.getStatus() == false)
			{
				if (button.clicked(ButtonID::top))
				{
					gripper.close();
					display.clear();
					display.printLine1(F("Gripper close"));
				}
			}

			if (gripper.getStatus() == true)
			{
				if (button.clicked(ButtonID::top))
				{
					gripper.open();
					display.clear();
					display.printLine1(F("Gripper open"));
				}
			}

			if (button.clicked(ButtonID::center))
			{
				gripper.open();
				encoder.reset();
				move.ptp(home);
				display.clear();
				return;
			}

			if (limit == true)
			{
				if (button.clicked(ButtonID::encoder))break;
			}
			if(workingspace == true)light.heartbeat(Colour::green);
		}

		screen.position();
		display.printText("-", 6, 0);
		display.printText("+", 8, 0);
		encoderValue = int(position.y);
		encoder.setValue(encoderValue);

		while (directionY)
		{
			value = encoder.getValue();
			if (value != lastValue)
			{
				workingspace = true;
				position.y = value;
				limit = move.ptp(position, Speed::full);
				if (limit == false)
				{
					screen.limit();
					light.on(Colour::red, Intensity::max);
					workingspace = false;
					if (value < 0)
					{
						encoderValue = int(position.y) + 1;
						encoder.setValue(encoderValue);
					}
					else
					{
						encoderValue = int(position.y) - 1;
						encoder.setValue(encoderValue);
					}
				}
				else
				{
					screen.position();
					display.printText("-", 6, 0);
					display.printText("+", 8, 0);
				}
				lastValue = encoder.getValue();
			}

			if (gripper.getStatus() == false)
			{
				if (button.clicked(ButtonID::top))
				{
					gripper.close();
					display.clear();
					display.printLine1(F("Gripper close"));
				}
			}

			if (gripper.getStatus() == true)
			{
				if (button.clicked(ButtonID::top))
				{
					gripper.open();
					display.clear();
					display.printLine1(F("Gripper open"));
				}
			}

			if (button.clicked(ButtonID::center))
			{
				gripper.open();
				encoder.reset();
				move.ptp(home);
				display.clear();
				return;
			}

			if (limit == true)
			{
				if (button.clicked(ButtonID::encoder))break;
			}
			if (workingspace == true)light.heartbeat(Colour::green);
		}

		screen.position();
		display.printText("+", 12, 0);
		display.printText("-", 14, 0);
		encoder.reset();
		encoderValue = int(position.z);
		encoder.setValue(encoderValue);

		while (directionZ)
		{
			value = encoder.getValue();
			if (value != lastValue)
			{
				workingspace = true;
				position.z = value;
				limit = move.ptp(position, Speed::full);
				if (limit == false)
				{
					screen.limit();
					light.on(Colour::red, Intensity::max);
					workingspace = false;
					if (value > 100)
					{
						encoderValue = int(position.z) - 1;
						encoder.setValue(encoderValue);
					}
					else
					{
						encoderValue = int(position.z) + 1;
						encoder.setValue(encoderValue);
					}
				}
				else
				{
					screen.position();
					display.printText("-", 12, 0);
					display.printText("+", 14, 0);
				}
				lastValue = encoder.getValue();
			}

			if (gripper.getStatus() == false)
			{
				if (button.clicked(ButtonID::top))
				{
					gripper.close();
					display.clear();
					display.printLine1(F("Gripper close"));
				}
			}

			if (gripper.getStatus() == true)
			{
				if (button.clicked(ButtonID::top))
				{
					gripper.open();
					display.clear();
					display.printLine1(F("Gripper open"));
				}
			}

			if (button.clicked(ButtonID::center))
			{
				gripper.open();
				encoder.reset();
				move.ptp(home);
				display.clear();
				return;
			}

			if (limit == true)
			{
				if (button.clicked(ButtonID::encoder))break;
			}
			if (workingspace == true)light.heartbeat(Colour::green);
		}
	}
}

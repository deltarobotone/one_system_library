#include "Remote.h"

DeltaRobot::Remote::Remote(
	DeltaRobot::Move & move, 
	DeltaRobot::Light & light, 
	DeltaRobot::Display & display, 
	DeltaRobot::Button & button, 
	DeltaRobot::Gripper & gripper, 
	DeltaRobot::Screen & screen, 
	DeltaRobot::ExternalMotor & motor):
	move(move), 
	light(light), 
	display(display), 
	button(button), 
	gripper(gripper), 
	screen(screen), 
	motor(motor)
{
}

void DeltaRobot::Remote::control()
{
	DeltaRobot::Functions functions;
	char rxData[22] = {};
	Serial.begin(9600);
	int signals = 0;

	while (true)
	{
		while (Serial.available() > 0)
		{
			Serial.readBytes(rxData, 22);

			if (rxData[0] == robotID)
			{
				signals = 0;
				if (rxData[2] == 'M')
				{
					Pos position;
					float velocity = 0;
					protocol.move(rxData, position, velocity);
					if (move.ptp(position, velocity) == false)
					{
						Serial.write('0');
						screen.limit();
					}
					else screen.position();
				}

				if (rxData[2] == 'G')
				{
					bool status = false;
					protocol.gripper(rxData, status);
					if (status == true)
					{
						gripper.close();
						display.clear();
						display.printLine1(F("Gripper close"));
					}
					if (status == false)
					{
						gripper.open();
						display.clear();
						display.printLine1(F("Gripper open"));
					}
				}

				if (rxData[2] == 'L')
				{
					int colour = Colour::blue;
					int intensity = 0;
					bool status = false;
					protocol.light(rxData, colour, intensity, status);
					if (status == true)
					{
						light.on(colour, intensity);
						display.clear();
						display.printLine1(F("Light on"));
						if(colour == Colour::red)display.printLine2(F("Colour red"));
						if (colour == Colour::green)display.printLine2(F("Colour green"));
						if (colour == Colour::blue)display.printLine2(F("Colour blue"));
						if (colour == Colour::magenta)display.printLine2(F("Colour magenta"));
						if (colour == Colour::yellow)display.printLine2(F("Colour yellow"));
						if (colour == Colour::cyan)display.printLine2(F("Colour cyan"));
						if (colour == Colour::white)display.printLine2(F("Colour white"));
					}
					if (status == false)
					{
						light.off();
						display.clear();
						display.printLine1(F("Light off"));
					}
				}

				if (rxData[2] == 'E')
				{
					bool status;
					int speed;
					protocol.extmotor(rxData, speed, status);
					if (status == true)
					{
						motor.start(speed);
						display.clear();
						display.printLine1(F("Motor on"));
						display.printLine2(F("Speed:         %"));
						display.printLine2(String(speed), 7);
					}
					if (status == false)
					{
						motor.stop();
						display.clear();
						display.printLine1(F("Motor off"));
					}
				}
			}
		}

		if (functions.pulse(500))
		{
			Serial.write(robotID);
			signals++;
			if (signals >= 30)
			{
				signals = 0;
				screen.signals();
			}
		}

		if (button.clicked(ButtonID::center))
		{
			gripper.open();
			display.clear();
			return;
		}
	}
}

void DeltaRobot::Remote::setID(char & id)
{
	robotID = id;
}

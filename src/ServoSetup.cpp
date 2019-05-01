#include "ServoSetup.h"

DeltaRobot::ServoSetup::ServoSetup(
	DeltaRobot::Screen & screen, 
	DeltaRobot::Move & move, 
	DeltaRobot::Light & light, 
	DeltaRobot::Button & button) : 
	screen(screen),
	move(move),
	light(light),
	button(button)
{
}

void DeltaRobot::ServoSetup::start()
{
	move.setupPosition(0.0F);
	screen.angles();

	int step = 1;
	while (true)
	{
		light.heartbeat(Colour::magenta);

		if (button.clicked(ButtonID::encoder) && step == 1)
		{
			move.setupPosition(45.0F);
			screen.angles();
			step = 2;
		}

		if (button.clicked(ButtonID::encoder) && step == 2)
		{
			move.setupPosition(90.0F);
			screen.angles();
			step = 3;
		}

		if (button.clicked(ButtonID::encoder) && step == 3)
		{
			move.ptp(home);
			light.off();
			break;
		}
	}
}

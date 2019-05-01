#ifndef SERVOSETUP
#define SERVOSETUP

#include "Arduino.h"
#include "Screen.h"
#include "Move.h"
#include "Button.h"
#include "Light.h"

namespace DeltaRobot
{
	class ServoSetup
	{
	private:
		DeltaRobot::Screen &screen;
		DeltaRobot::Move &move;
		DeltaRobot::Light &light;
		DeltaRobot::Button &button;
	public:
		ServoSetup(DeltaRobot::Screen &screen, DeltaRobot::Move &move, DeltaRobot::Light &light, DeltaRobot::Button &button);
		void start();
	};
}
#endif
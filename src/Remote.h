#ifndef REMOTE
#define REMOTE

#include "Arduino.h"
#include "Button.h"
#include "Display.h"
#include "Gripper.h"
#include "Light.h"
#include "Screen.h"
#include "Move.h"
#include "ExtMotor.h"
#include "Protocol.h"

namespace DeltaRobot
{
	class Remote
	{
	private:
		DeltaRobot::Move &move;
		DeltaRobot::Light &light;
		DeltaRobot::Display &display;
		DeltaRobot::Button &button;
		DeltaRobot::Gripper &gripper;
		DeltaRobot::Screen &screen;
		DeltaRobot::ExternalMotor &motor;
		DeltaRobot::Protocol protocol;
		char robotID = '1';
	public:
		Remote(
			DeltaRobot::Move &move,
			DeltaRobot::Light &light,
			DeltaRobot::Display &display,
			DeltaRobot::Button &button,
			DeltaRobot::Gripper &gripper,
			DeltaRobot::Screen &screen,
			DeltaRobot::ExternalMotor &motor);
		void setID(char &id);
		void control();
	};
}
#endif

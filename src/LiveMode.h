#ifndef LIVEMODE
#define LIVEMODE

#include "Arduino.h"
#include "Button.h"
#include "Display.h"
#include "Encoder.h"
#include "Gripper.h"
#include "Light.h"
#include "Screen.h"
#include "Move.h"

namespace DeltaRobot
{
	class LiveMode
	{
	private:
		DeltaRobot::Move &move;
		DeltaRobot::Light &light;
		DeltaRobot::Display &display;
		DeltaRobot::Button &button;
		DeltaRobot::Encoder &encoder;
		DeltaRobot::Gripper &gripper;
		DeltaRobot::Screen &screen;
	public:
		LiveMode(
			DeltaRobot::Move &move,
			DeltaRobot::Light &light,
			DeltaRobot::Display &display,
			DeltaRobot::Button &button,
			DeltaRobot::Encoder &encoder,
			DeltaRobot::Gripper &gripper,
			DeltaRobot::Screen &screen);
		void start();
	};
}
#endif
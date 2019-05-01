#ifndef MOTOR
#define MOTOR

#include "Arduino.h"
#include "Pins.h"
#include "Functions.h"
#include "Encoder.h"
#include "Button.h"
#include "Display.h"

namespace DeltaRobot
{
	class ExternalMotor
	{
	private:
		DeltaRobot::Encoder &encoder;
		DeltaRobot::Button &button;
		DeltaRobot::Display &display;
		bool status = false;
		int speed = 0;
	public:
		ExternalMotor(DeltaRobot::Encoder &encoder, DeltaRobot::Button &button, DeltaRobot::Display &display);
		void start(int motorspeed, bool startup = false);
		void stop();
		int getSpeed();
		void setSpeed(int motorspeed);
		bool getStatus();
		void control();
	};
}
#endif
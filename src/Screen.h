#ifndef SCREEN
#define SCREEN

#include "Arduino.h"
#include "Functions.h"
#include "Display.h"
#include "Signs.h"
#include "Move.h"

namespace DeltaRobot
{
	class Screen
	{
	private:
		DeltaRobot::Display &display;
		DeltaRobot::Move &move;
	public:
		Screen(DeltaRobot::Display &display, DeltaRobot::Move &move);
		void info(unsigned long time);
		void progress(unsigned long time, String text);
		void ready();
		void limit();
		void signals();
		void angles();
		void position();
	};
}
#endif

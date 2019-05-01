#ifndef LIGHT
#define LIGHT

#include "Arduino.h"
#include "Functions.h"
#include "Pins.h"

namespace DeltaRobot
{
	class Light
	{
	private:
		DeltaRobot::Functions functions;
		int fadeValue = 0;
		bool fadeStatus = false;
		bool blinkStatus = false;
		unsigned long blinkLimitMillis = 0;

	public:
		Light();

		void on();
		void on(int colour, int intensity);
		void off();
		void setColour(int colour);
		void setIntensity(int intensity);

		void blink(int timeOn, int timeOff);
		void blinkFast();
		void blinkSlow();
		void blinkTime(int milliseconds);

		void fade(int time, int min, int max, int stepsize, int colour);
		void fadeFast(int colour);
		void fadeSlow(int colour);
		void fadeReset();
		void heartbeat(int colour);
	};
}
namespace Colour
{
	const int red = 1;
	const int green = 2;
	const int blue = 3;
	const int yellow = 4;
	const int magenta = 5;
	const int cyan = 6;
	const int white = 7;
}
namespace Intensity
{
	const int off = 0;
	const int min = 55;
	const int half = 155;
	const int max = 255;
}
#endif


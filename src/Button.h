#include "Arduino.h"
#include "Functions.h"
#include "Pins.h"

#ifndef BUTTON
#define BUTTON

namespace DeltaRobot
{
	class Button
	{
	private:
		DeltaRobot::Functions functions;
		bool inputStatus;
		bool inputValue;
		bool debounceStatus;
		unsigned long startTime;
		unsigned long pushTime;
		unsigned long releaseTime;
		bool debounceInput(int pin, int time);
	public:
		Button();
		bool push(int buttonID);
		void release(int buttonID);
		bool clicked(int buttonID);
	};
}
namespace ButtonID
{
	const int top = 1;
	const int center = 2;
	const int encoder = 3;
}
#endif

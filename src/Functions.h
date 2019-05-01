#ifndef FUNCTIONS
#define FUNCTIONS

#include "Arduino.h"

namespace DeltaRobot
{
	class Functions
	{
	private:
		unsigned long delayMillis = 0;
		unsigned long pulseMillis = 0;
		bool pulseStatus = false;
		bool pulseValue = false;
	public:
		Functions();
		void waitFor(int milliseconds);
		bool pulse(int milliseconds);
	};
}
#endif


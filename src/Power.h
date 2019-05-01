#ifndef POWER
#define POWER

#include "Arduino.h"
#include "Pins.h"

namespace DeltaRobot
{
	class Power
	{
	public:
		Power();
		void bluetoothOn();
		void bluetoothOff();
		void mainOn();
		void mainOff();
	};
}
#endif

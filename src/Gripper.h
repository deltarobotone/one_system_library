
#ifndef GRIPPER
#define GRIPPER

#include "Arduino.h"
#include "Pins.h"

namespace DeltaRobot
{
	class Gripper
	{
	private:
		bool gripperStatus = false;
	public:
		Gripper();
		void open();
		void close();
		bool getStatus();
	};
}
#endif
#ifndef ENCODER
#define ENCODER

#include "Arduino.h"
#include "Pins.h"

namespace DeltaRobot
{
	class Encoder
	{
	private:
		static void encoderA();
		static void encoderB();
		static int encoderValue;
		static int lastStatusA;
		static int lastStatusB;
		static int statusA;
		static int statusB;
		static int valueLimitMin;
		static int valueLimitMax;
	public:
		Encoder();
		void setup();
		int getValue();
		void setValue(int value);
		void setLimitMin(int value);
		void setLimitMax(int value);
		int getLimitMin();
		int getLimitMax();
		void reset();
	};
}
#endif

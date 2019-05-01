#ifndef MOTION
#define MOTION

#include "Arduino.h"
#include "Servo.h"
#include "Pins.h"

namespace DeltaRobot
{
	class MotionData
	{
	public:
		MotionData();
		void init(float &servoSpeed);
		void step(float &time);
		float offset = 0.0F;
		float start = 0.0F;
		float end = 0.0F;
		float angle = 0.0F;
	private:
		float speed = 0.0F;
		float coeff5 = 0.0F;
		float coeff6 = 0.0F;
		float coeff7 = 0.0F;
		float coeff8 = 0.0F;
	};

	class Motion
	{
	private:
		Servo servoA;
		Servo servoB;
		Servo servoC;
	public:
		Motion();
		void setup();
		void ptp(DeltaRobot::MotionData &servoA, DeltaRobot::MotionData &servoB, DeltaRobot::MotionData &servoC, float speed);
	};
}
#endif
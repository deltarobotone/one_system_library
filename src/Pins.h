#ifndef PINS
#define PINS

#include "Arduino.h"

namespace Pins
{
	const int servoA = 10;
	const int servoB = 9;
	const int servoC = 6;

	const int mainPower = 13;
	const int bluetoothPower = 4;
	const int externalMotor = 11;

	const int gripper = 14;

	const int ledR = 7;
	const int ledG = 12;
	const int ledB = 8;
	const int ledI = 5;

	const int buttonTop = 15;
	const int buttonCenter = 17;
	const int buttonEncoder = 16;

	const int encoderA = 3;
	const int encoderB = 2;
}
#endif
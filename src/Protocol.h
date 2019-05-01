#ifndef PROTOCOL
#define PROTOCOL

#include "Arduino.h"
#include "Move.h"
#include "Light.h"

namespace DeltaRobot
{
	class Protocol
	{
	public:
		Protocol();
		void move(char(&rxData)[22], Pos &position, float &speed);
		void gripper(char(&rxData)[22], bool &status);
		void light(char(&rxData)[22], int &colour, int &intensity, bool &status);
		void extmotor(char(&rxData)[22], int &speed, bool &status);
	};
}
#endif

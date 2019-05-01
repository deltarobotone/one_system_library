#ifndef MOVE
#define MOVE

#include "Arduino.h"
#include "Motion.h"

namespace Speed
{
	const float slow = 10.0;
	const float half = 50.0;
	const float fast = 90.0;
	const float full = 100.0;
}

namespace DeltaRobot
{
	class Pos
	{
	public:
		Pos();
		Pos(float posX, float posY, float posZ);
		float x = 0.0F;
		float y = 0.0F;
		float z = 0.0F;
	};

	class ServoData
	{
	public:
		ServoData();
		float a = 0.0F;
		float b = 0.0F;
		float c = 0.0F;
	};

	class Kinematics
	{
	public:
		Kinematics();
		float a = 0.0F;
		float b = 0.0F;
		float c = 0.0F;
		float d = 0.0F;
	};

	class Space
	{
	public:
		Space();
		float radius = 0.0F;
		float zmin = 0.0F;
		float zmax = 0.0F;
	};

	class Move
	{
	private:
		DeltaRobot::ServoData servoAngle;
		DeltaRobot::Motion motioncontroller;
		DeltaRobot::MotionData servoA;
		DeltaRobot::MotionData servoB;
		DeltaRobot::MotionData servoC;
		DeltaRobot::Pos robotPosition;
		DeltaRobot::Pos tcpOffset;
		float deltakinematic(float x, float y, float z, char servo);
		bool checkWorkingSpace(DeltaRobot::Pos &position);
		void setStandardLevels();
		Space levels[4];
		Kinematics length;

	public:
		Move(int offsetServoA = 0, int offsetServoB = 0, int offsetServoC = 0, int offsetTCPX = 0, int offsetTCPY = 0, int offsetTCPZ = 0);
		void setup();
		void setupPosition(float angle);
		bool ptp(DeltaRobot::Pos &position, float speed = Speed::half);
		bool ptp(float positionX, float positionY, float positionZ, float speed = Speed::half);
		Pos getPosition();
		ServoData getAngles();
		void setKinematicsLength(float lengthA, float lengthB, float lengthC, float lengthD);
		void setWorkingSpaceLevel(int level, float radius, float zmin, float zmax);
	};
	static DeltaRobot::Pos home(0.0F, 0.0F, 85.0F);
}
#endif
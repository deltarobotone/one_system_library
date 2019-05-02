#include "Move.h"

DeltaRobot::Move::Move(int offsetServoA, int offsetServoB, int offsetServoC, int offsetTCPX, int offsetTCPY, int offsetTCPZ)
{
	servoA.offset = offsetServoA;
	servoB.offset = offsetServoB;
	servoC.offset = offsetServoC;
	tcpOffset.x = offsetTCPX;
	tcpOffset.y = offsetTCPY;
	tcpOffset.z = offsetTCPZ;
}

float DeltaRobot::Move::deltakinematic(float posX, float posY, float posZ, char servo)
{
	float x = 0.0F, y = 0.0F, z = 75.0F;
	float pi120 = 120.0F * (PI / 180.0F);
	float pi240 = 240.0F * (PI / 180.0F);

	posX =  (cos(PI)*(posX)) + (sin(PI)*(posY));
	posY = -(sin(PI)*(posX)) + (cos(PI)*(posY));

	if (servo == 'A')
	{
		x = posX;
		y = posY;
		z = posZ;
	}

	if (servo == 'B')
	{
		x =  (cos(pi120)*(posX)) + (sin(pi120)*(posY));
		y = -(sin(pi120)*(posX)) + (cos(pi120)*(posY));
		z = posZ;
	}

	if (servo == 'C')
	{
		x =  (cos(pi240)*(posX)) + (sin(pi240)*(posY));
		y = -(sin(pi240)*(posX)) + (cos(pi240)*(posY));
		z = posZ;
	}

	float lenght1 = sqrt(pow(length.c, 2.0F) - pow(x, 2.0F));
	float length2 = (length.a - length.d + y);
	float length3 = sqrt(pow(length2, 2.0F) + pow(z, 2.0F));

	float alpha = (360.0F / (2.0F * PI))*(atan2(z, length2));
	float gamma = (360.0F / (2.0F * PI))*(acos((pow(lenght1, 2) - pow(length3, 2.0F) - pow(length.b, 2.0F)) / (-2.0F * length3 * length.b)));
	float theta = 180.0F - alpha - gamma;

	return theta;
}

void DeltaRobot::Move::setup()
{
	setKinematics(31.0, 50.0, 90.0, 15.0);

	setWorkingSpace(1, 70.0, 79.0, 25.0);
	setWorkingSpace(2, 80.0, 99.0, 45.0);
	setWorkingSpace(3, 100.0, 119.0, 37.5);
	setWorkingSpace(4, 120.0, 130.0, 15.0);

	motioncontroller.setup();
}

void DeltaRobot::Move::setupPosition(float angle)
{
	servoA.start = servoAngle.a;
	servoB.start = servoAngle.b;
	servoC.start = servoAngle.c;

	servoAngle.a = angle;
	servoAngle.b = angle;
	servoAngle.c = angle;

	servoA.end = servoAngle.a;
	servoB.end = servoAngle.b;
	servoC.end = servoAngle.c;

	motioncontroller.ptp(servoA, servoB, servoC, Speed::slow);
}

bool DeltaRobot::Move::ptp(DeltaRobot::Pos &position, float speed)
{
	bool limit = false;
	limit = checkWorkingSpace(position);

	if (limit == false)
	{
		robotPosition.x = position.x;
		robotPosition.y = position.y;
		robotPosition.z = position.z;

		servoA.start = servoAngle.a;
		servoB.start = servoAngle.b;
		servoC.start = servoAngle.c;

		servoAngle.a = deltakinematic(robotPosition.x + tcpOffset.x, robotPosition.y + tcpOffset.y, robotPosition.z + tcpOffset.z, 'A');
		servoAngle.b = deltakinematic(robotPosition.x + tcpOffset.x, robotPosition.y + tcpOffset.y, robotPosition.z + tcpOffset.z, 'B');
		servoAngle.c = deltakinematic(robotPosition.x + tcpOffset.x, robotPosition.y + tcpOffset.y, robotPosition.z + tcpOffset.z, 'C');

		servoA.end = servoAngle.a;
		servoB.end = servoAngle.b;
		servoC.end = servoAngle.c;
		
		motioncontroller.ptp(servoA, servoB, servoC, speed);
	}
	else
	{
		return false;
	}
	return true;
}

bool DeltaRobot::Move::ptp(float positionX, float positionY, float positionZ, float speed)
{
	DeltaRobot::Pos position;
	position.x = positionX;
	position.y = positionY;
	position.z = positionZ;
	return ptp(position,speed);
}

DeltaRobot::Pos DeltaRobot::Move::getPosition()
{
	return robotPosition;
}

DeltaRobot::ServoData DeltaRobot::Move::getAngles()
{
	return servoAngle;
}

void DeltaRobot::Move::setKinematics(float lengthA, float lengthB, float lengthC, float lengthD)
{
	length.a = lengthA;
	length.b = lengthB;
	length.c = lengthC;
	length.d = lengthD;
}

DeltaRobot::Pos::Pos()
{
	x = home.x;
	y = home.y;
	z = home.z;
}

DeltaRobot::Pos::Pos(float posx, float posy, float posz)
{
	x = posx;
	y = posy;
	z = posz;
}

DeltaRobot::ServoData::ServoData()
{
	a = 0.0F;
	b = 0.0F;
	c = 0.0F;
}

DeltaRobot::Kinematics::Kinematics()
{
}

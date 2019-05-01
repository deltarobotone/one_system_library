#include "Motion.h"

DeltaRobot::MotionData::MotionData()
{
}

void DeltaRobot::MotionData::init(float &servoSpeed)
{
speed=servoSpeed;
angle = start;
coeff5=(35*(end-start))/pow(speed,4);
coeff6=-(84*(end-start))/pow(speed,5);
coeff7=(70*(end-start))/pow(speed,6);
coeff8=-(20*(end-start))/pow(speed,7);
}

void DeltaRobot::MotionData::step(float &time)
{
angle=coeff8*pow(time,7)+ coeff7*pow(time,6)+ coeff6*pow(time,5)+ coeff5*pow(time,4)+start;
}

DeltaRobot::Motion::Motion()
{

}

void DeltaRobot::Motion::setup()
{
	servoA.writeMicroseconds(2000.0F);
	servoB.writeMicroseconds(2000.0F);
	servoC.writeMicroseconds(2000.0F);
	servoA.attach(Pins::servoA);
	servoB.attach(Pins::servoB);
	servoC.attach(Pins::servoC);
}

void DeltaRobot::Motion::ptp(DeltaRobot::MotionData &dataA, DeltaRobot::MotionData &dataB, DeltaRobot::MotionData &dataC, float speed)
{
	if (speed < 100.0F)
	{
		speed = (4.0F - (speed / 25.0F)) + 0.005F;

		dataA.init(speed);
		dataB.init(speed);
		dataC.init(speed);

		float stepsize = 0.005F;
		float counter = 0.0F;

		while (counter <= speed)
		{
			dataA.step(counter);
			dataB.step(counter);
			dataC.step(counter);
			servoA.writeMicroseconds(2000.0F - (dataA.angle + dataA.offset)*10.5F);
			servoB.writeMicroseconds(2000.0F - (dataB.angle + dataB.offset)*10.5F);
			servoC.writeMicroseconds(2000.0F - (dataC.angle + dataC.offset)*10.5F);
			counter = counter + stepsize;
		}
	}
	else
	{
		servoA.writeMicroseconds(2000.0F - (dataA.end + dataA.offset)*10.5F);
		servoB.writeMicroseconds(2000.0F - (dataB.end + dataB.offset)*10.5F);
		servoC.writeMicroseconds(2000.0F - (dataC.end + dataC.offset)*10.5F);
	}
}

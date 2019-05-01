#include "Move.h"

DeltaRobot::Space::Space()
{
}

bool DeltaRobot::Move::checkWorkingSpace(DeltaRobot::Pos& position)
{
	for (int i = 0; i < 4; i++)
	{
		if (position.z >= levels[i].zmin && position.z < levels[i].zmax)
		{
			float radius = 0.0F;

			radius = sqrt((pow(position.x, 2.0F)) + (pow(position.y, 2.0F)));

			if (radius <= levels[i].radius)
			{
				return false;
			}
		}

	}
	return true;
}

void DeltaRobot::Move::setStandardLevels()
{
	levels[0].zmin = 70.0F;
	levels[0].zmax = 80.0F;
	levels[0].radius = 25.0F;

	levels[1].zmin = 80.0F;
	levels[1].zmax = 100.0F;
	levels[1].radius = 45.0F;

	levels[2].zmin = 100.0F;
	levels[2].zmax = 120.0F;
	levels[2].radius = 35.0F;

	levels[3].zmin = 120.0F;
	levels[3].zmax = 130.0F;
	levels[3].radius = 15.0F;

}

void DeltaRobot::Move::setWorkingSpaceLevel(int level, float zmin, float zmax, float radius)
{
	if (level > 0 && level <= 3)
	{
		levels[level - 1].radius = radius;
		levels[level - 1].zmin = zmin;
		levels[level - 1].zmax = zmax;
	}
}

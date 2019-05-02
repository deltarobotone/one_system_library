#include "Move.h"

DeltaRobot::Space::Space()
{
}

bool DeltaRobot::Move::checkWorkingSpace(DeltaRobot::Pos& position)
{
	for (int i = 0; i < 4; i++)
	{
		if (position.z >= levels[i].zmin && position.z <= levels[i].zmax)
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

void DeltaRobot::Move::setWorkingSpace(int level, float zmin, float zmax, float radius)
{
	if (level > 0 && level <= 4)
	{
		levels[level - 1].radius = radius;
		levels[level - 1].zmin = zmin;
		levels[level - 1].zmax = zmax;
	}
}

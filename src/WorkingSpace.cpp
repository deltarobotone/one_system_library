#include "Move.h"

DeltaRobot::Space::Space()
{
}

bool DeltaRobot::Move::checkWorkingSpace(DeltaRobot::Pos& position)
{
	for (int i = 0; i < 3; i++)
	{
		if (position.z >= levels[i].zmin && position.z < levels[i].zmax)
		{
			if (position.x >= levels[i].xmin && position.x <= levels[i].xmax)
			{
				if (position.y >= levels[i].ymin && position.y <= levels[i].ymax)
				{
					return false;
				}
			}
		}

	}
	return true;
}

void DeltaRobot::Move::setStandardLevels()
{
	levels[0].zmin = 70;
	levels[0].zmax = 80;
	levels[0].xmin = -25;
	levels[0].xmax = 25;
	levels[0].ymin = -25;
	levels[0].ymax = 25;

	levels[1].zmin = 80;
	levels[1].zmax = 120;
	levels[1].xmin = -32;
	levels[1].xmax = 32;
	levels[1].ymin = -32;
	levels[1].ymax = 32;

	levels[2].zmin = 120;
	levels[2].zmax = 130;
	levels[2].xmin = -10;
	levels[2].xmax = 10;
	levels[2].ymin = -10;
	levels[2].ymax = 10;
}

void DeltaRobot::Move::setWorkingSpaceLevel(int level, int xmin, int xmax, int ymin, int ymax, int zmin, int zmax)
{
	if (level > 0 && level <= 3)
	{
		levels[level - 1].xmin = xmin;
		levels[level - 1].xmax = xmax;
		levels[level - 1].ymin = ymin;
		levels[level - 1].ymax = ymax;
		levels[level - 1].zmin = zmin;
		levels[level - 1].zmax = zmax;
	}
}

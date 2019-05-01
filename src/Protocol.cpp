#include "Protocol.h"

DeltaRobot::Protocol::Protocol()
{
}

void DeltaRobot::Protocol::move(char(&rxData)[22], Pos& position, float& speed)
{
	int rxValue = 0;
	float tempValue = 0.0;
	char sign = {};

	sign = rxData[3];
	rxValue = (rxData[4] - 48) * 1000 + (rxData[5] - 48) * 100 + (rxData[6] - 48) * 10 + (rxData[7] - 48);
	tempValue = rxValue / 10.0F;
	if (sign == '-') position.x = tempValue * (-1.0F);
	if (sign == '+') position.x = tempValue;

	sign = rxData[8];
	rxValue = (rxData[9] - 48) * 1000 + (rxData[10] - 48) * 100 + (rxData[11] - 48) * 10 + (rxData[12] - 48);
	tempValue = rxValue / 10.0F;
	if (sign == '-') position.y = tempValue * (-1.0F);
	if (sign == '+') position.y = tempValue;

	sign = rxData[13];
	rxValue = (rxData[14] - 48) * 1000 + (rxData[15] - 48) * 100 + (rxData[16] - 48) * 10 + (rxData[17] - 48);
	tempValue = rxValue / 10.0F;
	if (sign == '-') position.z = tempValue * (-1.0F);
	if (sign == '+') position.z = tempValue;

	rxValue = (rxData[18] - 48) * 1000 + (rxData[19] - 48) * 100 + (rxData[20] - 48) * 10 + (rxData[21] - 48);
	tempValue = rxValue / 10.0F;
	speed = tempValue;
}

void DeltaRobot::Protocol::gripper(char(&rxData)[22], bool &status)
{
	if (rxData[9] == 'O' && rxData[10] == 'P' && rxData[11] == 'E' && rxData[12] == 'N') status = false;
	if (rxData[9] == 'C' && rxData[10] == 'L' && rxData[11] == 'O' && rxData[12] == 'S' && rxData[13] == 'E') status = true;
}

void DeltaRobot::Protocol::light(char(&rxData)[22], int &colour, int &intensity, bool &status)
{
	if (rxData[7] == 'O' && rxData[8] == 'N')status = true;
	if (rxData[7] == 'O' && rxData[8] == 'F' && rxData[9] == 'F')status = false;
	if (rxData[10] == 'R' && rxData[11] == 'E' && rxData[12] == 'D')
	{
		colour = Colour::red;
		status = true;
	}
	if (rxData[10] == 'G' && rxData[11] == 'R' && rxData[12] == 'E' && rxData[13] == 'E' && rxData[14] == 'N') {
		colour = Colour::green;
		status = true;
	}
	if (rxData[10] == 'B' && rxData[11] == 'L' && rxData[12] == 'U' && rxData[13] == 'E')
	{
		colour = Colour::blue;
		status = true;
	}
	if (rxData[10] == 'Y' && rxData[11] == 'E' && rxData[12] == 'L' && rxData[13] == 'L' && rxData[14] == 'O' && rxData[15] == 'W')
	{
		colour = Colour::yellow;
		status = true;
	}
	if (rxData[10] == 'M' && rxData[11] == 'A' && rxData[12] == 'G' && rxData[13] == 'E' && rxData[14] == 'N' && rxData[15] == 'T' && rxData[16] == 'A')
	{
		colour = Colour::magenta;
		status = true;
	}
	if (rxData[10] == 'C' && rxData[11] == 'Y' && rxData[12] == 'A' && rxData[13] == 'N')
	{
		colour = Colour::cyan;
		status = true;
	}
	if (rxData[10] == 'W' && rxData[11] == 'H' && rxData[12] == 'I' && rxData[13] == 'T' && rxData[14] == 'E')
	{
		colour = Colour::white;
		status = true;
	}

	int rxValue = 0;
	float tempValue = 0.0;
	rxValue = (rxData[18] - 48) * 1000 + (rxData[19] - 48) * 100 + (rxData[20] - 48) * 10 + (rxData[21] - 48);
	tempValue = rxValue / 10.0F;
	intensity = tempValue*2.5F;
}

void DeltaRobot::Protocol::extmotor(char(&rxData)[22], int &speed, bool &status)
{
	if (rxData[10] == 'O' && rxData[11] == 'N')status = true;
	if (rxData[10] == 'O' && rxData[11] == 'F' && rxData[12] == 'F')status = false;
	
	int rxValue = 0;
	float tempValue = 0.0;
	rxValue = (rxData[18] - 48) * 1000 + (rxData[19] - 48) * 100 + (rxData[20] - 48) * 10 + (rxData[21] - 48);
	tempValue = rxValue / 10.0F;
	speed = tempValue;
}

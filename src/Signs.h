#include "Arduino.h"

#ifndef SIGNS
#define SIGNS
namespace Signs
{
	const int full = 0;
	const int arrowLeft = 1;
	const int arrowRight = 2;

	static byte byteSignFull[8] =
	{
		B11111,
		B11111,
		B11111,
		B11111,
		B11111,
		B11111,
		B11111
	};

	static byte byteArrowRight[8] =
	{
		B00000,
		B01100,
		B00010,
		B11111,
		B00010,
		B01100,
		B00000
	};

	static byte byteArrowLeft[8] =
	{
		B00000,
		B00110,
		B01000,
		B11111,
		B01000,
		B00110,
		B00000
	};
}
#endif
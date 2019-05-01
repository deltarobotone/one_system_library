#include "Screen.h"

DeltaRobot::Screen::Screen(DeltaRobot::Display &display, DeltaRobot::Move &move):display(display),move(move)
{
}

void DeltaRobot::Screen::ready()
{
	display.clear();
	display.printLine1(F("Ready! Press any"));
	display.printLine2(F("key to continue!"));
}

void DeltaRobot::Screen::limit()
{
	display.clear();
	display.printLine1(F("Workingspace-"));
	display.printLine2(F("limit reached"));
}

void DeltaRobot::Screen::signals()
{
	display.clear();
	display.printLine1(F("Waiting for"));
	display.printLine2(F("remote signals"));
}

void DeltaRobot::Screen::info(unsigned long time)
{
	display.clear();
	display.printLine1(F("Delta Robot One"));
	display.printLine2(F("Version 1.0"));
	DeltaRobot::Functions functions;
	functions.waitFor(time);
}

void DeltaRobot::Screen::progress(unsigned long time, String text)
{
	DeltaRobot::Functions functions;
	display.clear();
	display.printLine1(text);
	for (int i = 0; i < 16; i++)
	{
		display.printSign(Signs::full, i, 1);
		functions.waitFor((time / 16));
	}
}

void DeltaRobot::Screen::angles()
{
	display.clear();

	display.printLine1(F("A"),1);
	display.printLine1(F("B"), 7);
	display.printLine1(F("C"), 13);

	DeltaRobot::ServoData angles= move.getAngles();

	display.printLine2(String(angles.a),0);
	display.printLine2(F("  "),4);
	display.printLine2(String(angles.b),6);
	display.printLine2(F("  "),10);
	display.printLine2(String(angles.c),12);
}

void DeltaRobot::Screen::position()
{
	display.clear();

	display.printLine1(F("X"), 1);
	display.printLine1(F("Y"), 7);
	display.printLine1(F("Z"), 13);

	DeltaRobot::Pos position = move.getPosition();
	
	display.printLine2(String(position.x), 0);
	display.printLine2(F("  "), 4);
	display.printLine2(String(position.y), 6);
	display.printLine2(F("  "), 10);
	display.printLine2(String(position.z), 12);
}
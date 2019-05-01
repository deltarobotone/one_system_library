#ifndef MENU
#define MENU

#include "Arduino.h"
#include "Button.h"
#include "Display.h"
#include "Encoder.h"
#include "Light.h"

namespace DeltaRobot
{
	class Menu
	{
	private:
		String items [5] = {""};
		DeltaRobot::Light &light;
		DeltaRobot::Display &display;
		DeltaRobot::Button &button;
		DeltaRobot::Encoder &encoder;
	public:
		Menu(
			DeltaRobot::Light &light,
			DeltaRobot::Display &display,
			DeltaRobot::Button &button,
			DeltaRobot::Encoder &encoder);
		void setItem(int position, String text);
		int start();
	};
}

#endif

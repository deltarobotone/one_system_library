#include "Menu.h"

DeltaRobot::Menu::Menu(
	DeltaRobot::Light & light, 
	DeltaRobot::Display & display, 
	DeltaRobot::Button & button, 
	DeltaRobot::Encoder & encoder) :
	light(light),
	display(display),
	button(button),
	encoder(encoder)
{
}

int DeltaRobot::Menu::start()
{
	int Value = 0;
	int LastValue = 1;

	encoder.reset();
	encoder.setLimitMin(0);
	encoder.setLimitMax(4);

	for (int i = 0; i < 5; i++)
	{
		if (items[i] == F(""))
		{
			if (encoder.getLimitMax() >= 1)
				encoder.setLimitMax(encoder.getLimitMax() - 1);
		}
	}

	while (true)
	{
		light.heartbeat(Colour::blue);
		Value = encoder.getValue();

		if (Value != LastValue)
		{
			display.clear();
			display.printLine1(F("Menu"));
			display.printSign(Signs::arrowLeft, 5, 0);
			display.printSign(Signs::arrowRight, 11-(4-encoder.getLimitMax()), 0);
			display.printSign(Signs::full, (Value + 6), 0);
			display.printLine2(items[Value]);
			LastValue = Value;			
		}

		if (button.clicked(ButtonID::encoder))
		{
			break;
		}	

		if (button.clicked(ButtonID::center))
		{
			return 0;
		}
	}
	display.clear();
	encoder.reset();
	return Value+1;	
}

void DeltaRobot::Menu::setItem(int position, String text)
{
	if(position>0 && position<=5)items[(position-1)] = text;
}

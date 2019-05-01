#include "Display.h"

DeltaRobot::Display::Display(uint8_t displayAdress)
{
	lcd = DisplayI2C(displayAdress, 16, 2);
}

void DeltaRobot::Display::setup()
{
	lcd.init();
	lcd.backlight();
	lcd.begin(1, 16);
	lcd.clear();
	lcd.setCursor(0, 0);
}

void DeltaRobot::Display::printLine1(String text, uint8_t position)
{
	lcd.setCursor(position, 0);
	lcd.print(text);
}

void DeltaRobot::Display::printLine2(String text, uint8_t position)
{
	lcd.setCursor(position, 1);
	lcd.print(text);
}

void DeltaRobot::Display::printText(String text, uint8_t position, uint8_t row)
{
	lcd.setCursor(position, row);
	lcd.print(text);
}

void DeltaRobot::Display::clear()
{
	lcd.clear();
	lcd.setCursor(0, 0);
}

void DeltaRobot::Display::printSign(int sign, uint8_t position, uint8_t row)
{
	switch (sign)
	{
	case 0:
	{
		lcd.createChar(0, Signs::byteSignFull);
		lcd.setCursor(position, row);
		lcd.write(byte(0));
		break;
	}
	case 1:
	{
		lcd.createChar(1, Signs::byteArrowLeft);
		lcd.setCursor(position, row);
		lcd.write(byte(1));
		break;
	}
	case 2:
	{
		lcd.createChar(2, Signs::byteArrowRight);
		lcd.setCursor(position, row);
		lcd.write(byte(2));
		break;
	}
	}
}

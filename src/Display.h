#ifndef LCD_DISPLAY
#define LCD_DISPLAY

#include "Arduino.h"
#include "DisplayI2C.h"
#include "Signs.h"
#include "Pins.h"

namespace DeltaRobot
{
	class Display
	{
	private:
		DisplayI2C lcd;
	public:
		Display(uint8_t displayAdress); // Adress Default: 0x27, Other Adress: 0x3F
		void setup();
		void clear();
		void printLine1(String text, uint8_t position = 0);
		void printLine2(String text, uint8_t position = 0);
		void printText(String text, uint8_t position = 0, uint8_t row = 0);
		void printSign(int sign, uint8_t position = 0, uint8_t row = 0);
	};
}
#endif



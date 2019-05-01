#include "DisplayI2C.h"

#define printIIC(args)	Wire.write(args)
inline size_t DisplayI2C::write(uint8_t value) 
{
	send(value, Rs);
	return 1;
}

DisplayI2C::DisplayI2C(uint8_t lcdAddress, uint8_t lcdCols, uint8_t lcdRows)
{
  adress = lcdAddress;
  cols = lcdCols;
  rows = lcdRows;
  backlightvalue = LCD_NOBACKLIGHT;
}

DisplayI2C::DisplayI2C()
{
}

void DisplayI2C::init()
{
	init_priv();
}

void DisplayI2C::init_priv()
{
	Wire.begin();
	displayfunction = LCD_4BITMODE | LCD_1LINE | LCD_5x8DOTS;
	begin(cols, rows);  
}

void DisplayI2C::begin(uint8_t cols, uint8_t lines, uint8_t dotsize) 
{
	if (lines > 1) 
	{
		displayfunction |= LCD_2LINE;
	}
	numlines = lines;

	if ((dotsize != 0) && (lines == 1)) 
	{
		displayfunction |= LCD_5x10DOTS;
	}

	delay(50);

	expanderWrite(backlightvalue);
	delay(1000);

	write4bits(0x03 << 4);
	delayMicroseconds(4500);

	write4bits(0x03 << 4);
	delayMicroseconds(4500);

	write4bits(0x03 << 4);
	delayMicroseconds(150);

	write4bits(0x02 << 4);

	command(LCD_FUNCTIONSET | displayfunction);

	displaycontrol = LCD_DISPLAYON | LCD_CURSOROFF | LCD_BLINKOFF;
	display();

	clear();

	displaymode = LCD_ENTRYLEFT | LCD_ENTRYSHIFTDECREMENT;

	command(LCD_ENTRYMODESET | displaymode);

	home();
}

void DisplayI2C::home() 
{
	command(LCD_RETURNHOME);
	delayMicroseconds(2000);
}

void DisplayI2C::display() 
{
	displaycontrol |= LCD_DISPLAYON;
	command(LCD_DISPLAYCONTROL | displaycontrol);
}

void DisplayI2C::clear() 
{
	command(LCD_CLEARDISPLAY);
	delayMicroseconds(2000);
}

void DisplayI2C::setCursor(uint8_t col, uint8_t row) 
{
	int row_offsets[] = { 0x00, 0x40, 0x14, 0x54 };
	if (row > numlines) 
	{
		row = numlines - 1;
	}
	command(LCD_SETDDRAMADDR | (col + row_offsets[row]));
}

void DisplayI2C::backlight(void) 
{
	backlightvalue=LCD_BACKLIGHT;
	expanderWrite(0);
}

inline void DisplayI2C::command(uint8_t value) 
{
	send(value, 0);
}

void DisplayI2C::send(uint8_t value, uint8_t mode) 
{
	uint8_t highnib = value & 0xf0;
	uint8_t lownib = (value << 4) & 0xf0;
	write4bits((highnib) | mode);
	write4bits((lownib) | mode);
}

void DisplayI2C::write4bits(uint8_t value) 
{
	expanderWrite(value);
	pulseEnable(value);
}

void DisplayI2C::expanderWrite(uint8_t _data)
{
	Wire.beginTransmission(adress);
	printIIC((int)(_data) | backlightvalue);
	Wire.endTransmission();   
}

void DisplayI2C::pulseEnable(uint8_t _data)
{
	expanderWrite(_data | En);
	delayMicroseconds(1);
	
	expanderWrite(_data & ~En);
	delayMicroseconds(50);
} 

void DisplayI2C::createChar(uint8_t location, uint8_t charmap[]) 
{
	location &= 0x7;
	command(LCD_SETCGRAMADDR | (location << 3));
	for (int i = 0; i<8; i++) 
	{
		write(charmap[i]);
	}
}
	

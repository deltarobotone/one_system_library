#ifndef DISPLAYI2C
#define DISPLAYI2C

#include "Arduino.h"
#include "inttypes.h"
#include "Print.h" 
#include "Wire.h"

#define LCD_CLEARDISPLAY 0x01
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80
#define LCD_RETURNHOME 0x02

#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTDECREMENT 0x00

#define LCD_DISPLAYON 0x04
#define LCD_CURSOROFF 0x00
#define LCD_BLINKOFF 0x00

#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

#define LCD_BACKLIGHT 0x08
#define LCD_NOBACKLIGHT 0x00

#define En B00000100
#define Rw B00000010
#define Rs B00000001

class DisplayI2C : public Print 
{
private:
	void init_priv();
	void send(uint8_t, uint8_t);
	void write4bits(uint8_t);
	void expanderWrite(uint8_t);
	void pulseEnable(uint8_t);
	void home();
	uint8_t adress;
	uint8_t displayfunction;
	uint8_t displaycontrol;
	uint8_t displaymode;
	uint8_t numlines;
	uint8_t cols;
	uint8_t rows;
	uint8_t backlightvalue;
public:
	DisplayI2C(uint8_t lcdAddress, uint8_t lcdCols, uint8_t lcdRows);
	DisplayI2C();
	void begin(uint8_t cols, uint8_t rows, uint8_t charsize = LCD_5x8DOTS);
	void clear();
	void setCursor(uint8_t, uint8_t);
	void command(uint8_t);
	void init();
	void backlight();
	void display();
	virtual size_t write(uint8_t);
	void createChar(uint8_t, uint8_t[]);
};

#endif

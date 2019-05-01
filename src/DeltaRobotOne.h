#ifndef DELTAROBOT
#define DELTAROBOT

// Namespace Delta Robot
namespace DeltaRobot
{
	// Prototype
	class DeltaRobotOne;
}

//Include Delta Robot One Header Files
#include "Arduino.h"
#include "Pins.h"
#include "Signs.h"
#include "Button.h"
#include "Display.h"
#include "Encoder.h"
#include "Gripper.h"
#include "Light.h"
#include "Functions.h"
#include "Screen.h"
#include "Move.h"
#include "Menu.h"
#include "Remote.h"
#include "Power.h"
#include "ExtMotor.h"
#include "LiveMode.h"
#include "ServoSetup.h"

namespace DeltaRobot
{
	//Delta Robot One Class -> Application-User-Interface (API)
	class DeltaRobotOne
	{
	private:
		char robotID = '1';
	public:
		DeltaRobotOne(int offsetServoA = 0, int offsetServoB = 0, int offsetServoC = 0, int offsetTCPX = 0, int offsetTCPY = 0, int offsetTCPZ = 0, uint8_t displayAdress = 0x27);
		void setup();
		void setID(char id);
		char getID();
		DeltaRobot::Functions functions;
		DeltaRobot::Move move;
		DeltaRobot::Light light;
		DeltaRobot::Display display;
		DeltaRobot::Button button;
		DeltaRobot::Encoder encoder;
		DeltaRobot::Power power;
		DeltaRobot::Gripper gripper;
		DeltaRobot::Remote remote;
		DeltaRobot::ExternalMotor extmotor;
		DeltaRobot::Screen screen;
		DeltaRobot::Menu menu;
		DeltaRobot::LiveMode livemode;
		DeltaRobot::ServoSetup servosetup;
	};
}
#endif

// Using Namespace Delta Robot
using namespace DeltaRobot;


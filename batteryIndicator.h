#ifndef Morse_h
#define Morse_h
#include "Arduino.h"

class battPercentage
{
	public:
	void setup();
	float getBatteryVoltage();
	void RGB(int red, int green, int blue);
};
#endif
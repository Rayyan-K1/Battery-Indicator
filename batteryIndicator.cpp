#include "Arduino.h"
#include "batteryIndicator.h"

#define ADC_AREF 3.3f
#define BATVOLT_R1 4.7f
#define BATVOLT_R2 10.0f
#define BATVOLT_PIN BAT_VOLT


	void batteryIndicator::setup() {	  
		SerialUSB.begin(57600);
	}
	
	float batteryIndicator::getBatteryVoltage() {
	uint16_t voltageNow = (uint16_t)((ADC_AREF / 1.023) * (BATVOLT_R1 + BATVOLT_R2) / BATVOLT_R2 * (float)analogRead(BATVOLT_PIN));
	int voltageBase = 4030; //Max Voltage from Test Environment
	int voltageMin = 3300;
	int voltageDiff = voltageBase - voltageMin;
	int voltageTotal = voltageBase - voltageNow;
	int batteryPercentage = (100 - (voltageTotal / (voltageDiff / 100)));

	if (batteryPercentage >= 0 && batteryPercentage < 21) { // Goes Red	
		RGB(255, 0, 0);
		delay(1000);
		pinMode(LED_RED, INPUT);
		pinMode(LED_GREEN, INPUT);
		pinMode(LED_BLUE, INPUT);
	} else if (batteryPercentage >= 21 && batteryPercentage < 51) { // Goes Yellow/Amber/Orange
		RGB(255, 128, 0);
		delay(1000);
		pinMode(LED_RED, INPUT);
		pinMode(LED_GREEN, INPUT);
		pinMode(LED_BLUE, INPUT);
	} else if (batteryPercentage >= 51 && batteryPercentage < 81) { // Goes Green
		RGB(0, 255, 0);
		delay(1000);
		pinMode(LED_RED, INPUT);
		pinMode(LED_GREEN, INPUT);
		pinMode(LED_BLUE, INPUT);
	} else if (batteryPercentage >= 81 && batteryPercentage <= 100) { // Goes Blue
		RGB(0, 0, 255);
		delay(1000);
		pinMode(LED_RED, INPUT);
		pinMode(LED_GREEN, INPUT);
		pinMode(LED_BLUE, INPUT);
	}
	else {
		if (batteryPercentage < 0) {
		RGB(255, 0, 0);
		delay(1000);
		pinMode(LED_RED, INPUT);
		pinMode(LED_GREEN, INPUT);
		pinMode(LED_BLUE, INPUT);
		} else if (batteryPercentage > 100) {
		RGB(0, 0, 255);
		delay(1000);
		pinMode(LED_RED, INPUT);
		pinMode(LED_GREEN, INPUT);
		pinMode(LED_BLUE, INPUT);
		}
	}
	return batteryPercentage;
		}
	
	
	void batteryIndicator::RGB(int red, int green, int blue) {
		analogWrite(LED_RED, 255 - red);
		analogWrite(LED_GREEN, 255 - green);
		analogWrite(LED_BLUE, 255 - blue);
	}
	


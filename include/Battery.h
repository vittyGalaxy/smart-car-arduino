/******************************************************************************/
/**
* @file: Battery.h
* @description: in this file is intended to show the amount of battery
* @author: AngeloDamante
* @author: Vittorio Tiozzo
*/
/******************************************************************************/

#ifndef SMART_CAR_ARDUINO_BATTERY_H
#define SMART_CAR_ARDUINO_BATTERY_H

#include "Arduino.h"
#include "RGBLed.h"

void voltageInit(int pin);
void Voltage_Measure(int pin);



#endif //SMART_CAR_ARDUINO_BATTERY_H

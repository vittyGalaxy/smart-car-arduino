/********************************************************************************/
/**
* @file: RGBLed.cpp
* @description: Led driver for WS2812
* @author: AngeloDamante
* @mail: angelo.damante16@gmail.com
*/
/********************************************************************************/

#include "RGBLed.h"

/********************************************************************************/
RGBLed &RGBLed::on() {
    this->bEnable = true;
    FastLED.setBrightness(20);
    return *this;
}

/********************************************************************************/
RGBLed &RGBLed::off() {
    if (!this->bEnable) { return *this; }
    this->bEnable = false;
    FastLED.clear(true);
    return *this;
}

/********************************************************************************/
RGBLed &RGBLed::show(uint8_t r, uint8_t g, uint8_t b) {
    if (!this->bEnable) {
        FastLED.clear(true);
        return *this;
    }
    FastLED.showColor(make_color(r, g, b));
    return *this;
}
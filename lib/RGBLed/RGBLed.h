/********************************************************************************/
/**
* @file: RGBLed.h
* @description: Led driver for WS2812
* @author: AngeloDamante
* @mail: angelo.damante16@gmail.com
*/
/********************************************************************************/

#ifndef RGBLED_H
#define RGBLED_H

/********************************************************************************/

#include "FastLED.h"

/********************************************************************************/
class RGBLed {
public:
    inline RGBLed() {
        CRGB leds[1];
        const int x = pin;
        FastLED.addLeds<NEOPIXEL, pin>(leds, 1);
    }

    RGBLed &on();

    RGBLed &off();

    RGBLed &show(uint8_t r, uint8_t g, uint8_t b);

    inline static uint32_t make_color(uint8_t r, uint8_t g, uint8_t b) {
        return (((uint32_t) r << 16) | ((uint32_t) g << 8) | b);
    }

private:
    static const int pin = 4;
};
/********************************************************************************/


#endif //RGBLED_H

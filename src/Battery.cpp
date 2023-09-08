/******************************************************************************/
/**
* @file: Battery.cpp
* @description: in this file is intended to show the amount of battery
* @author: AngeloDamante
* @author: Vittorio Tiozzo
*/
/******************************************************************************/

#include "Battery.h"
RGBLed led;
unsigned long pippo = 0;
void voltageInit(int pin){
    pinMode(pin, INPUT);
}

void Voltage_Measure(int pin)
{
    led.on();
    if (millis() - pippo > 1000) //Measured every 1000 milliseconds
    {
        pippo = millis();
        float voltage = (analogRead(pin) * 5 ) * ((10 + 1.5) / 1.5)/ 1024; //Read voltage value
        //float voltage = (analogRead(VOL_MEASURE_PIN) * 0.0375);
        voltage = voltage + (voltage * 0.08);
        Serial.print("Current voltage value : ");
        Serial.println(voltage);
        if(voltage>5.8){
            Serial.println("The battery is fully charged");
            led.show(0, 255, 0);
            delay(500);
        }else
            if(voltage <= 5.8 && voltage > 3.3){
                Serial.println("Medium battery");
//                led.show(255, 255, 0);
                delay(500);
            }else{
                Serial.println("Low battery");
                led.show(255, 0, 0);
                delay(500);
            }
    }
}
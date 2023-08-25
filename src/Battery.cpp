/******************************************************************************/
/**
* @file: Battery.cpp
* @description: in this file is intended to show the amount of battery
* @author: AngeloDamante
* @author: Vittorio Tiozzo
*/
/******************************************************************************/

#include "Battery.h"
unsigned long pippo = 0;
void voltageInit(int pin){
    pinMode(pin, INPUT);
}

void Voltage_Measure(int pin)
{
    if (millis() - pippo > 1000) //Measured every 1000 milliseconds
    {
        pippo = millis();
        float voltage = (analogRead(pin) * 5 ) * ((10 + 1.5) / 1.5)/ 1024; //Read voltage value
        //float voltage = (analogRead(VOL_MEASURE_PIN) * 0.0375);
        voltage = voltage + (voltage * 0.08);
        Serial.print("Current voltage value : ");
        Serial.println(voltage);
        if(voltage>7.8)
            Serial.println("The battery is fully charged");
        else
            Serial.println("Low battery");
    }
}
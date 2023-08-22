#include <Arduino.h>
#include <IRremote.h>
#include "definitions.h"
#include "MotionControl.h"
#include "Battery.h"

//int Volt = 0;

//#include "demo_libraries.h"

MotionControl aserial;
unsigned long preMillis;

const uint32_t buttonOK = 0xBF40FF00;
const uint32_t buttonUp = 0xB946FF00;
const uint32_t buttonDown = 0xEA15FF00;
const uint32_t buttonRight = 0xBC43FF00;
const uint32_t buttonLeft = 0xBB44FF00;

void setup() {
    Serial.begin(9600);
    Serial.println("Hello");
    IrReceiver.begin(PIN_IR); // Start the receiver
    voltageInit(PIN_BT);
}

__attribute__((unused)) void loop() {
    if (IrReceiver.decode()) {
        preMillis = millis();
        IrReceiver.resume(); // Receive the next value
        switch (IrReceiver.decodedIRData.decodedRawData) {
            case buttonOK:
                /* TODO */
                aserial.stop();
                Voltage_Measure(PIN_BT);
//                delay(100);
                break;

            case buttonUp:
                /* TODO */
                aserial.forward(150);
//                delay(100);
                break;

            case buttonDown:
                /* TODO */
                aserial.backward(150);
//                delay(100);
                break;

            case buttonRight:
                /* TODO */
                aserial.right(65);
//                delay(100);
                break;

            case buttonLeft:
                /* TODO */
                aserial.left(65);
//                delay(100);
                break;

            default:
                break;
        }
//        delay(100);
    }else{
        if(millis() - preMillis > 200){
            aserial.stop();
            preMillis = millis();
        }
    }
//    Serial.println(Voltage_Measure())
}
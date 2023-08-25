#include <Arduino.h>
#include <IRremote.h>
#include "definitions.h"
#include "MotionControl.h"
#include "Battery.h"
#include "UltrasonicSensor.h"

UltrasonicSensor us(PIN_TRIG, PIN_ECHO);
int distanceCm;

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
    us.init();
    distanceCm = us.computeDistance();
}

/*
 * Dobbiamo fare un test per capire esattamente il tempo di campionamento dei tasti
 * da parte del sensore ad infrarossi (diodo), così facendo potremo capire cosa succede
 */
__attribute__((unused)) void loop() {
    distanceCm = us.computeDistance();
    Serial.println(distanceCm);
    if (IrReceiver.decode()) {
        preMillis = millis();
        IrReceiver.resume(); // Receive the next value
        switch (IrReceiver.decodedIRData.decodedRawData) {
            case buttonOK:
                aserial.stop();
                Voltage_Measure(PIN_BT);
                break;

            case buttonUp:
                // FIXME
                if(distanceCm < 30){
                    Serial.println("ostacolo trovato");
                    aserial.forward(25);
                    delay(100);
                }else{
                    Serial.println("ostacolo non trovato");
                    aserial.forward(150);
                    delay(100);
                }
                break;

            case buttonDown:
                aserial.backward(150);
                break;

            case buttonRight:
                aserial.right(65);
                break;

            case buttonLeft:
                aserial.left(65);
                break;

            default:
                break;
        }
    }else{
        if(millis() - preMillis > 200){
            aserial.stop();
            preMillis = millis();
        }
    }
}
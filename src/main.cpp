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
uint32_t commandReceived = 0;

const uint32_t buttonOK = 0xBF40FF00;
const uint32_t buttonUp = 0xB946FF00;
const uint32_t buttonDown = 0xEA15FF00;
const uint32_t buttonRight = 0xBC43FF00;
const uint32_t buttonLeft = 0xBB44FF00;

uint32_t Commands[] = {buttonOK, buttonUp, buttonDown, buttonRight, buttonLeft};
bool isCommand(uint32_t command);

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
//    Serial.println(distanceCm);

    if (IrReceiver.decode()) {
        IrReceiver.resume(); // Receive the next value

        uint32_t buttonReceived = IrReceiver.decodedIRData.decodedRawData;

        if (!isCommand(buttonReceived) && commandReceived != 0) {
            buttonReceived = commandReceived;
        }

        preMillis = millis();

        switch (buttonReceived) {
            case buttonOK:
                aserial.stop();
                Serial.println("OK");

                commandReceived = buttonOK;
                Voltage_Measure(PIN_BT);
                break;

            case buttonUp:
                distanceCm = us.computeDistance();
                Serial.println("UP");

                if(distanceCm < 30){
                    aserial.forward(50);
                }else{
                    aserial.forward(150);
                }
                commandReceived = buttonUp;
//                    IrReceiver.resume(); // Receive the next value
                break;

            case buttonDown:
                Serial.println("DOWN");

                aserial.backward(150);
                commandReceived = buttonDown;
                break;

            case buttonRight:
                Serial.println("RIGHT");

                aserial.right(65);
                commandReceived = buttonRight;
                break;

            case buttonLeft:
                Serial.println("LEFT");

                aserial.left(65);
                commandReceived = buttonLeft;
                break;

            default:
                Serial.println(buttonReceived, HEX);
                break;
        }
    }else{
        if(millis() - preMillis > 200){
            aserial.stop();
            preMillis = millis();
        }
    }
}

bool isCommand(uint32_t command) {
    for (uint32_t cmd : Commands) {
        if (cmd == command) {
            return true;
        }
    }
    return false;
}
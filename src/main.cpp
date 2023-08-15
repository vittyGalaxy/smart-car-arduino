#include <Arduino.h>
#include <IRremote.h>
#include "definitions.h"
//#include "demo_libraries.h"

const uint32_t buttonOK = 0xBF40FF00;
const uint32_t buttonUp = 0xB946FF00;
const uint32_t buttonDown = 0xEA15FF00;
const uint32_t buttonRight = 0xBC43FF00;
const uint32_t buttonLeft = 0xBB44FF00;

void setup() {
    Serial.begin(9600);
    Serial.println("Hello");
    IrReceiver.begin(PIN_IR); // Start the receiver
}

__attribute__((unused)) void loop() {
    if (IrReceiver.decode()) {
        switch (IrReceiver.decodedIRData.decodedRawData) {
            case buttonOK:
                /* TODO */
                break;

            case buttonUp:
                /* TODO */
                break;

            case buttonDown:
                /* TODO */
                break;

            case buttonRight:
                /* TODO */
                break;

            case buttonLeft:
                /* TODO */
                break;

            default:
                break;
        }
        IrReceiver.resume(); // Receive the next value
    }

}
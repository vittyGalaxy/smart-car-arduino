#include <Arduino.h>
#include <IRremote.h>
#include "definitions.h"
//#include "demo_libraries.h"

void setup() {
    Serial.begin(9600);
    Serial.println("Hello");
    IrReceiver.begin(PIN_IR); // Start the receiver
}

__attribute__((unused)) void loop() {
    if (IrReceiver.decode()) {
        Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
        IrReceiver.resume();
    }
}
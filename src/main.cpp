#include <Arduino.h>
#include <Servo.h>
#include <IRremote.h>

//#include "UltrasonicSensor.h"
#include "definitions.h"
//#include "demo_libraries.h"
#include "MotionControl.h"
#include "RGBLed.h"
//#include "mission.h"
//MotionControl aserial;

//RGBLed led;
// Servo
Servo myServo;

int receiver = PIN_IR; // pin 1 of IR receiver to Arduino digital pin 11
IRrecv irrecv(receiver); // create instance of 'irrecv'
decode_results results;

void setup()
{
    Serial.begin(9600);
    Serial.println("Hello");
    irrecv.enableIRIn(); // Start the receiver
}

__attribute__((unused)) void loop()
{
    if (irrecv.decode(&results)) // have we received an IR signal?
    {
        Serial.println(results.value, HEX); // display it on serial monitor in hexadecimal
        irrecv.resume();// receive the next value
    }
}
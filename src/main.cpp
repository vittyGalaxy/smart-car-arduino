#include <Arduino.h>
#include <Servo.h>
#include "definitions.h"
#include "demo_libraries.h"

// Servo
Servo myServo;

// US;
int distanceCm;
UltrasonicSensor us(PIN_TRIG, PIN_ECHO);

// Motors
MotorDriver md(PIN_IN_RIGHT, PIN_IN_LEFT, PIN_PWM_RIGHT, PIN_PWM_LEFT, PIN_STBY);

void setup()
{
    Serial.begin(9600);
    Serial.println("Hello");

    demo_led();
}

__attribute__((unused)) void loop()
{
    // code in forever loop
}
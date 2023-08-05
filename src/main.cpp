#include <Arduino.h>
#include <Servo.h>
#include "UltrasonicSensor.h"
#include "MotorDriver.h"
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

    // init servo
    myServo.attach(PIN_SERVO);
    myServo.write(0);

//    demo_motors();
}

__attribute__((unused)) void loop()
{
    // code in forever loop
}
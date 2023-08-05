#include <Arduino.h>
#include <Servo.h>
#include "UltrasonicSensor.h"
#include "MotorDriver.h"
#include "demo_motors.h"

// Servo
Servo myServo;
const int PIN_SERVO = 9;

// US
const int PIN_ECHO = 12;
const int PIN_TRIG = 13;

int distanceCm;
UltrasonicSensor us(PIN_TRIG, PIN_ECHO);

// Motors
const int PIN_PWM_RIGHT = 5;
const int PIN_PWM_LEFT = 6;
const int PIN_IN_RIGHT = 7;
const int PIN_IN_LEFT = 8;
const int PIN_STBY = 3;
MotorDriver md(PIN_IN_RIGHT, PIN_IN_LEFT, PIN_PWM_RIGHT, PIN_PWM_LEFT, PIN_STBY);

void setup()
{
    myServo.attach(PIN_SERVO);
    myServo.write(0);

    Serial.begin(9600);
    Serial.println("Hello");
//    us.init();

    demo_motors();
}

__attribute__((unused)) void loop()
{
    // US
    distanceCm = us.computeDistance();
    Serial.println(distanceCm);
    delay(100);
}
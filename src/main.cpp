#include <Arduino.h>
#include <Servo.h>
#include "UltrasonicSensor.h"
#include "MotorDriver.h"
#include "definitions.h"
#include "demo_libraries.h"

extern UltrasonicSensor us;
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

    us.init();


    //init Motor
    md.init();
    md.on();

    // init servo
    myServo.attach(10);
    myServo.write(0);

//    demo_motors();
}

__attribute__((unused)) void loop()
{
    // code in forever loop
    distanceCm = us.computeDistance();
    Serial.println(distanceCm);
    for (int i = 0; i < 180; i += 10){
        myServo.write(i);
        delay(2000);
    }
    md.go(Motor::RIGHT, 150);
    delay(3000);
    md.stop(Motor::RIGHT);
    md.go(Motor::LEFT, 150);
    delay(3000);
    md.stop(Motor::LEFT);
    delay(2000);
    md.go(Motor::LEFT, 150);
    md.go(Motor::RIGHT, 150);
    delay(4000);
    myServo.write(0);
    md.stop(Motor::RIGHT);
    md.stop(Motor::LEFT);
}



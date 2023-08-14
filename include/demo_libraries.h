/********************************************************************************/
/**
* @file: demo_motors.cpp
* @details: This is a simple tutorial file
* @description: Demo for us and motors
*                   1. create an object
*                   2. init this object
*                   3. use object
* @author: AngeloDamante
* @mail: angelo.damante16@gmail.com
*/
/********************************************************************************/

#ifndef DEMO_LIBRARIES_H
#define DEMO_LIBRARIES_H

/********************************************************************************/
#include "definitions.h"
#include "MotorDriver.h"
#include "UltrasonicSensor.h"
#include "RGBLed.h"
#include "IRremote.h"

/*****************************************************************************/
// 1. create an object
MotorDriver oMd(PIN_IN_RIGHT, PIN_IN_LEFT, PIN_PWM_RIGHT, PIN_PWM_LEFT, PIN_STBY);

/***
 * Demo for motors
 * This function is a simple tutorial for motors
 */
void demo_motors() {

    // 2. initialize
    oMd.init();
    oMd.on();

    // 3. use object
    // right
    oMd.go(Motor::RIGHT, 150);
    delay(10000);
    oMd.stop(Motor::RIGHT);

    // left
    oMd.go(Motor::LEFT, 150);
    delay(10000);
    oMd.stop(Motor::LEFT);

    // right and left
    oMd.go(Motor::RIGHT, 150);
    oMd.go(Motor::LEFT, 150);
    delay(10000);
    oMd.stop(Motor::LEFT);
    oMd.stop(Motor::RIGHT);
}

/*****************************************************************************/
// 1. create an object
UltrasonicSensor oUs(PIN_TRIG, PIN_ECHO);

/***
 * Demo for ultrasonic sensor
 * This function is a simple tutorial for ultrasonic sensor
 */
void demo_ultrasonicSensor() {
    oUs.init(); // 2.init
    int distanceCm = oUs.computeDistance(); // 3. use
    Serial.println(distanceCm);
}

/*****************************************************************************/
RGBLed oLed;

/***
 * Demo for RGB Led
 * This function is a simple tutorial for RGB Led
 */
void demo_led() {
    oLed.on();
    oLed.show(255, 0, 0);
    delay(2000);
    oLed.show(0, 255, 0);
    delay(2000);
    oLed.show(0, 0, 255);
    delay(2000);
    oLed.off();
}

/*****************************************************************************/
/***
 * Demo for IR
 * This function is a simple tutorial for IRremote
 */
void demo_IR() {
    if (IrReceiver.decode()) {
        Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
        IrReceiver.resume();
    }
}

#endif // DEMO_LIBRARIES_H
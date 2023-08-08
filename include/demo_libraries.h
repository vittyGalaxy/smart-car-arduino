/********************************************************************************/
/**
* @file: demo_motors.cpp
* @description: Demo for us and motors
*                   1. create an object
*                   2. init this object
*                   3. use object
* @author: Vittorio
* @mail:
*/
/********************************************************************************/

#ifndef DEMO_MOTORS_H
#define DEMO_MOTORS_H

/********************************************************************************/

#include "MotorDriver.h"
#include "UltrasonicSensor.h"
#include "RGBLed.h"

/*****************************************************************************/
//extern MotorDriver md;

// 1. create an object
MotorDriver oMd(PIN_IN_RIGHT, PIN_IN_LEFT, PIN_PWM_RIGHT, PIN_PWM_LEFT, PIN_STBY);

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
//extern UltrasonicSensor us;

// 1. create an object
UltrasonicSensor oUs(PIN_TRIG, PIN_ECHO);

void demo_ultrasonicSensor() {
    oUs.init(); // 2.init
    int distanceCm = oUs.computeDistance(); // 3. use
    Serial.println(distanceCm);
}

#endif // DEMO_MOTORS_H

/*****************************************************************************/
RGBLed oLed;

void demo_led(){
    oLed.on();
    int r=255,g=0,b=0;
    for(int i=0;i<255;i++)
    {
        oLed.show(r,g,b);
        r-=1;
        g+=1;
        delay(10);
    }

    r=0,g=0,b=255;
    for(int i=0;i<255;i++)
    {
        oLed.show(r,g,b);
        r+=1;
        b-=1;
        delay(10);
    }

    r=0,g=255,b=0;
    for(int i=0;i<255;i++)
    {
        oLed.show(r,g,b);
        g-=1;
        b+=1;
        delay(10);
    }
    r=0,g=0,b=0;
}
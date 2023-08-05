/********************************************************************************/
/**
* @file: MotorDriver.cpp
* @description: MotorDriver class for TB6612 definition
* @author: AngeloDamante
* @mail: angelo.damante16@gmail.com
*/
/********************************************************************************/

#include "MotorDriver.h"

/********************************************************************************/
MotorDriver &MotorDriver::init() {
    pinMode(static_cast<uint8_t>(pwmAPin), OUTPUT);
    pinMode(static_cast<uint8_t>(pwmBPin), OUTPUT);
    pinMode(static_cast<uint8_t>(in1Pin), OUTPUT);
    pinMode(static_cast<uint8_t>(in2Pin), OUTPUT);
    pinMode(static_cast<uint8_t>(stbyPin), OUTPUT);
    return *this;
}

/********************************************************************************/
MotorDriver &MotorDriver::on() {
    digitalWrite(static_cast<uint8_t>(stbyPin), HIGH);
    return *this;
}

/********************************************************************************/
MotorDriver &MotorDriver::off() {
    digitalWrite(static_cast<uint8_t>(stbyPin), LOW);
    return *this;
}

/********************************************************************************/
MotorDriver &MotorDriver::go(Motor oMotor, uint8_t speed) {
    switch (oMotor) {
        case RIGHT:
            digitalWrite(static_cast<uint8_t>(in1Pin), HIGH);
            analogWrite(static_cast<uint8_t>(pwmAPin), speed);
            break;
        case LEFT:
            digitalWrite(static_cast<uint8_t>(in2Pin), HIGH);
            analogWrite(static_cast<uint8_t>(pwmBPin), speed);
    }
    return *this;
}

/********************************************************************************/
MotorDriver &MotorDriver::back(Motor oMotor, uint8_t speed) {
    switch (oMotor) {
        case RIGHT:
            digitalWrite(static_cast<uint8_t>(in1Pin), LOW);
            analogWrite(static_cast<uint8_t>(pwmAPin), speed);
            break;
        case LEFT:
            digitalWrite(static_cast<uint8_t>(in2Pin), LOW);
            analogWrite(static_cast<uint8_t>(pwmBPin), speed);
    }
    return *this;
}

/********************************************************************************/
MotorDriver &MotorDriver::stop(Motor oMotor) {
    switch (oMotor) {
        case RIGHT:
            digitalWrite(static_cast<uint8_t>(in1Pin), LOW);
            analogWrite(static_cast<uint8_t>(pwmAPin), 0);
            break;
        case LEFT:
            digitalWrite(static_cast<uint8_t>(in2Pin), LOW);
            analogWrite(static_cast<uint8_t>(pwmBPin), 0);
    }
    return *this;
}
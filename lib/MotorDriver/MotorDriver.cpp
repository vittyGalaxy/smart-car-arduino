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
    this->bOn = true;
    return *this;
}

/********************************************************************************/
MotorDriver &MotorDriver::off() {
    if (!this->bOn) { return *this; }
    digitalWrite(static_cast<uint8_t>(stbyPin), LOW);
    this->bOn = false;
    return *this;
}

/********************************************************************************/
MotorDriver &MotorDriver::go(Motor oMotor, int speed) {
    if (!this->bOn) { return *this; }
    int _speed = speed > MAX_SPEED ? MAX_SPEED : speed;
    switch (oMotor) {
        case Motor::RIGHT:
            digitalWrite(static_cast<uint8_t>(in1Pin), HIGH);
            analogWrite(static_cast<uint8_t>(pwmAPin), _speed);
            break;
        case Motor::LEFT:
            digitalWrite(static_cast<uint8_t>(in2Pin), HIGH);
            analogWrite(static_cast<uint8_t>(pwmBPin), _speed);
    }
    return *this;
}

/********************************************************************************/
MotorDriver &MotorDriver::back(Motor oMotor, int speed) {
    if (!this->bOn) { return *this; }
    int _speed = speed > MAX_SPEED ? MAX_SPEED : speed;
    switch (oMotor) {
        case Motor::RIGHT:
            digitalWrite(static_cast<uint8_t>(in1Pin), LOW);
            analogWrite(static_cast<uint8_t>(pwmAPin), _speed);
            break;
        case Motor::LEFT:
            digitalWrite(static_cast<uint8_t>(in2Pin), LOW);
            analogWrite(static_cast<uint8_t>(pwmBPin), _speed);
    }
    return *this;
}

/********************************************************************************/
MotorDriver &MotorDriver::stop(Motor oMotor) {
    if (!this->bOn) { return *this; }
    switch (oMotor) {
        case Motor::RIGHT:
            digitalWrite(static_cast<uint8_t>(in1Pin), LOW);
            analogWrite(static_cast<uint8_t>(pwmAPin), 0);
            break;
        case Motor::LEFT:
            digitalWrite(static_cast<uint8_t>(in2Pin), LOW);
            analogWrite(static_cast<uint8_t>(pwmBPin), 0);
    }
    return *this;
}
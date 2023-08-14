/********************************************************************************/
/**
* @file: moves.cpp
* @description: Smart Car moves declaration
* @author: AngeloDamante
* @author: Vittorio Tiozzo
*/
/********************************************************************************/

#include "MotionControl.h"

void MotionControl::forward(int speed) {
    md.go(Motor::RIGHT, speed);
    md.go(Motor::LEFT, speed);
    led.show(0, 255, 0);
}

void MotionControl::backward(int speed) {
    md.back(Motor::RIGHT, speed);
    md.back(Motor::LEFT, speed);
    led.show(255, 0, 0);
}

void MotionControl::left(int speed) {
    md.go(Motor::RIGHT, speed);
    md.back(Motor::LEFT, speed);
    led.show(247, 152, 27);
}

void MotionControl::right(int speed) {
    md.go(Motor::LEFT, speed);
    md.back(Motor::RIGHT, speed);
    led.show(152, 27, 247);
}

void MotionControl::leftForward(int speed) {
    md.go(Motor::RIGHT, speed);
    md.stop(Motor::LEFT);
    led.show(247, 233, 27);
}

void MotionControl::leftBackward(int speed) {
    md.back(Motor::RIGHT, speed);
    md.stop(Motor::LEFT);
    led.show(11, 252, 252);
}

void MotionControl::rightForward(int speed) {
    md.go(Motor::LEFT, speed);
    md.stop(Motor::RIGHT);
    led.show(131, 11, 252);
}

void MotionControl::rightBackward(int speed) {
    md.back(Motor::LEFT, speed);
    md.stop(Motor::RIGHT);
    led.show(252, 11, 156);
}

void MotionControl::stop() {
    md.stop(Motor::RIGHT);
    md.stop(Motor::LEFT);
    led.show(0, 0, 255);
}
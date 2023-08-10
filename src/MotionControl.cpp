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
}

void MotionControl::backward(int speed) {
    md.back(Motor::RIGHT, speed);
    md.back(Motor::LEFT, speed);
}

void MotionControl::left(int speed) {
    md.go(Motor::RIGHT, speed);
    md.back(Motor::LEFT, speed);
}

void MotionControl::right(int speed) {
    md.go(Motor::LEFT, speed);
    md.back(Motor::RIGHT, speed);
}

void MotionControl::leftForward(int speed) {
    md.go(Motor::RIGHT, speed);
    md.stop(Motor::LEFT);
}

void MotionControl::leftBackward(int speed) {
    md.back(Motor::RIGHT, speed);
    md.stop(Motor::LEFT);
}

void MotionControl::rightForward(int speed) {
    md.go(Motor::LEFT, speed);
    md.stop(Motor::RIGHT);
}

void MotionControl::rightBackward(int speed) {
    md.back(Motor::LEFT, speed);
    md.stop(Motor::RIGHT);
}

void MotionControl::stop() {
    md.stop(Motor::RIGHT);
    md.stop(Motor::LEFT);
}
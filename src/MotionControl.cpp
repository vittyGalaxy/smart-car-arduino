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
    //TODO
    md.go(Motor::RIGHT, speed);
    md.go(Motor::LEFT, speed);
}

void MotionControl::backward(int speed) {
    //TODO
    md.back(Motor::RIGHT, speed);
    md.back(Motor::LEFT, speed);
}

void MotionControl::left(int speed) {
    //TODO
    md.go(Motor::RIGHT, speed);
    md.back(Motor::LEFT, speed);
}

void MotionControl::right(int speed) {
    //TODO
    md.go(Motor::LEFT, speed);
    md.back(Motor::RIGHT, speed);
}

void MotionControl::leftForward(int speed) {
    //TODO
    md.go(Motor::RIGHT, speed);
    md.stop(Motor::LEFT);
}

void MotionControl::leftBackward(int speed) {
    //TODO
    md.back(Motor::RIGHT, speed);
    md.stop(Motor::LEFT);
}

void MotionControl::rightForward(int speed) {
    //TODO
}

void MotionControl::rightBackward(int speed) {
    //TODO
}

void MotionControl::stop() {
    //TODO
}
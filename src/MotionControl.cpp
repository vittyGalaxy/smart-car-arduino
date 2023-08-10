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
}

void MotionControl::right(int speed) {
    //TODO
}

void MotionControl::leftForward(int speed) {
    //TODO
}

void MotionControl::leftBackward(int speed) {
    //TODO
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
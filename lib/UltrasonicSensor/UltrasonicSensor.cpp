/********************************************************************************/
/**
* @file: UltrasonicSensor.h
* @description: UltrasonicSensor declaration
* @author: AngeloDamante
* @mail: angelo.damante16@gmail.com
*/
/********************************************************************************/

#include "UltrasonicSensor.h"

/********************************************************************************/
UltrasonicSensor &UltrasonicSensor::setEchoPin(const int _echoPin) {
    this->echoPin = _echoPin;
    return *this;
}

/********************************************************************************/
UltrasonicSensor &UltrasonicSensor::setTrigPin(const int _trigPin) {
    this->trigPin = _trigPin;
    return *this;
}

/********************************************************************************/
int UltrasonicSensor::getTrigPin() const {
    return this->trigPin;
}

/********************************************************************************/
int UltrasonicSensor::getEchoPin() const {
    return this->echoPin;
}

/********************************************************************************/
int UltrasonicSensor::computeDistance() const {
    delay(50);
    digitalWrite(static_cast<uint8_t>(this->trigPin), LOW);
    delayMicroseconds(2);
    digitalWrite(static_cast<uint8_t>(this->trigPin), HIGH);
    delayMicroseconds(10);
    digitalWrite(static_cast<uint8_t>(this->trigPin), LOW);
    unsigned long duration = pulseIn(static_cast<uint8_t>(this->echoPin), HIGH);

    return static_cast<int>(min(
            this->maxDistance,
            static_cast<int>(static_cast<double>(duration) * 0.034 / 2)));
}
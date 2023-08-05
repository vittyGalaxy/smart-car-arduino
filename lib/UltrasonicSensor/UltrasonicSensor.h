/********************************************************************************/
/**
* @file: UltrasonicSensor.h
* @description: UltrasonicSensor declaration
* @author: AngeloDamante
* @mail: angelo.damante16@gmail.com
*/
/********************************************************************************/

#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

#include "Arduino.h"

#endif //ULTRASONICSENSOR_H


/********************************************************************************/
/**
 * UltrasonicSensor class for HC=SR04 sensor
 *
 * @attribute: echoPin
 * @attribute: trigPin
 * @attribute: maxDistance
 */
class UltrasonicSensor {
public:
    UltrasonicSensor() = delete;

    inline UltrasonicSensor(int trigPin, int echoPin, double maxDistance = 100.0)
            : trigPin(trigPin), echoPin(echoPin), maxDistance(maxDistance) {
    }

    inline UltrasonicSensor &init() {
        pinMode(static_cast<uint8_t>(echoPin), INPUT);
        pinMode(static_cast<uint8_t>(trigPin), OUTPUT);
        return *this;
    }

    /**
     * Setter for echoPin
     *
     * @param echoPin
     */
    UltrasonicSensor &setEchoPin(int _echoPin);

    /**
     * Setter for trigPin
     *
     * @param trigPin
     */
    UltrasonicSensor &setTrigPin(int _trigPin);

    /**
    * Getter for echoPin
    */
    int getTrigPin() const;

    /**
    * Getter for trigPin
    */
    int getEchoPin() const;

    /**
     * Compute distance from hc-sr04 sensor
     */
    int computeDistance() const;


private:
    int trigPin;
    int echoPin;
    double maxDistance;  //cm
};

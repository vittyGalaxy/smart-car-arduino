/********************************************************************************/
/**
* @file: MotorDriver.h
* @description: MotorDriver class for TB6612 declaration
* @author: AngeloDamante
* @mail: angelo.damante16@gmail.com
*/
/********************************************************************************/

#ifndef MOTORDRIVER_H
#define MOTORDRIVER_H

/********************************************************************************/

#include <Arduino.h>

/********************************************************************************/
const int MAX_SPEED = 255;
enum Motor {
    LEFT = 0,
    RIGHT = 1
};
/********************************************************************************/
/**
 * MotorDriver class
 *
 * @attribute: in1Pin
 * @attribute: in2Pin
 * @attribute: pwmAPin
 * @attribute: pwmBPin
 * @attribute: stbyPin
 * */
class MotorDriver {
public:
    MotorDriver() = delete;

    inline MotorDriver(int in1Pin, int in2Pin, int pwmAPin, int pwmBPin, int stbyPin)
            : in1Pin(in1Pin),
              in2Pin(in2Pin),
              pwmAPin(pwmAPin),
              pwmBPin(pwmBPin),
              stbyPin(stbyPin) {}

    /**
     * Initialize Driver
     */
    MotorDriver &init();

    /**
     * Power On
     */
    MotorDriver &on();

    /**
     * Power Off
     */
    MotorDriver &off();

    /**
     * Forward Direction for selected motor with desired speed
     *
     * @param: oMotor
     * @param: speed
     */
    MotorDriver &go(Motor oMotor, uint8_t speed);

    /**
     * Backward Direction for selected motor with desired speed
     *
     * @param: oMotor
     * @param: speed
     */
    MotorDriver &back(Motor oMotor, uint8_t speed);

    /**
     * Stop desired motor
     *
     * @param: oMotor
     */
    MotorDriver &stop(Motor oMotor);


private:
    int in1Pin;
    int in2Pin;
    int pwmAPin;
    int pwmBPin;
    int stbyPin;
    bool bOn = false;
};


#endif //MOTORDRIVER_H

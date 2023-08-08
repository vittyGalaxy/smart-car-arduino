/********************************************************************************/
/**
* @file: moves.h
* @description: Smart Car moves declaration
* @author: AngeloDamante
* @author: Vittorio Tiozzo
*/
/********************************************************************************/

#ifndef SMART_CAR_ARDUINO_MOTIONCONTROL_H
#define SMART_CAR_ARDUINO_MOTIONCONTROL_H

#include "MotorDriver.h"
#include "definitions.h"

/********************************************************************************/
class MotionControl {
public:
    inline explicit MotionControl(
            int in1Pin = PIN_IN_RIGHT,
            int in2Pin = PIN_IN_LEFT,
            int pwmAPin = PIN_PWM_RIGHT,
            int pwmBPin = PIN_PWM_LEFT,
            int stbyPin = PIN_STBY) : md(in1Pin, in2Pin, pwmAPin, pwmBPin, stbyPin) {

        // code that running once time
        md.init();
        md.on();
    };

    /***
     * The car goes on
     * @param speed
     */
    void forward(int speed);

    /***
     * The car goes backward
     * @param speed
     */
    void backward(int speed);

    /***
     * The car goes left
     * @param speed
     */
    void left(int speed);

    /***
     * The car goes right
     * @param speed
     */
    void right(int speed);

    /***
     * The car goes left but in forward configuration
     * @param speed
     */
    void leftForward(int speed);

    /***
     * The car goes left but in backward configuration
     * @param speed
     */
    void leftBackward(int speed);

    /***
     * The car goes right but in forward configuration
     * @param speed
     */
    void rightForward(int speed);

    /***
     * The car goes right but in backward configuration
     * @param speed
     */
    void rightBackward(int speed);

    /***
     * The car stops
     */
    void stop();

private:
    MotorDriver md;
};


#endif //SMART_CAR_ARDUINO_MOTIONCONTROL_H

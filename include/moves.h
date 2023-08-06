/********************************************************************************/
/**
* @file: moves.h
* @description: Smart Car moves declaration
* @author: AngeloDamante
* @author: Vittorio Tiozzo
*/
/********************************************************************************/

#ifndef SMART_CAR_ARDUINO_MOVES_H
#define SMART_CAR_ARDUINO_MOVES_H

namespace MOVES {
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
};

#endif //SMART_CAR_ARDUINO_MOVES_H

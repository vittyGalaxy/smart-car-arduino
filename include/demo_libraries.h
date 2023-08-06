/********************************************************************************/
/**
* @file: demo_motors.cpp
* @description: Demo for us and motors
* @author: Vittorio
* @mail:
*/
/********************************************************************************/

#ifndef DEMO_MOTORS_H
#define DEMO_MOTORS_H

/*****************************************************************************/
extern MotorDriver md;

void demo_motors() {
    md.init();
    md.on();

    // right
    md.go(Motor::RIGHT, 150);
    delay(10000);
    md.stop(Motor::RIGHT);

    // left
    md.go(Motor::LEFT, 150);
    delay(10000);
    md.stop(Motor::LEFT);

    // right and left
    md.go(Motor::RIGHT, 150);
    md.go(Motor::LEFT, 150);
    delay(10000);
    md.stop(Motor::LEFT);
    md.stop(Motor::RIGHT);
}

/*****************************************************************************/
extern UltrasonicSensor us;

void demo_ultrasonicSensor() {
    us.init();
    int distanceCm = us.computeDistance();
    Serial.println(distanceCm);
}

#endif // DEMO_MOTORS_H
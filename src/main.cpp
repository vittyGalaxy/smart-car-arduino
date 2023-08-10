#include <Arduino.h>
#include <Servo.h>
#include "UltrasonicSensor.h"
#include "definitions.h"
//#include "demo_libraries.h"
#include "MotionControl.h"
#include "RGBLed.h"

MotionControl aserial;
RGBLed led;
// Servo
Servo myServo;

// US;
int distanceCm;
UltrasonicSensor us(PIN_TRIG, PIN_ECHO);

// Motors
MotorDriver md(PIN_IN_RIGHT, PIN_IN_LEFT, PIN_PWM_RIGHT, PIN_PWM_LEFT, PIN_STBY);

void setup()
{
    Serial.begin(9600);
    Serial.println("Hello");

    us.init();
    md.init();
    led.on();

//    demo_led();
}

__attribute__((unused)) void loop()
{
    // code in forever loop
    aserial.forward(150);
    led.show(0, 255, 0);
    distanceCm = us.computeDistance();
    Serial.println(distanceCm);
    if(distanceCm < 50){
        aserial.stop();
        led.show(152, 27, 247);
        delay(3000);
        aserial.backward(150);
        led.show(255, 0, 0);
        delay(2000);
        aserial.leftBackward(50);
        led.show(0, 0, 255);
        delay(2000);
        aserial.forward(150);
        led.show(0, 255, 0);
        delay(1000);
        aserial.leftForward(50);
        led.show(247, 233, 27);
        delay(2000);
        aserial.forward(150);
        led.show(0, 255, 0);
        delay(2000);
        aserial.left(50);
        led.show(247, 152, 27);
        delay(2000);
        aserial.forward(150);
        led.show(0, 255, 0);
        delay(2000);
        if(distanceCm < 50){
            aserial.backward(150);
            led.show(255, 0, 0);
            delay(2000);
            aserial.leftBackward(50);
            led.show(0, 0, 255);
            delay(2000);
            aserial.forward(150);
            led.show(0, 255, 0);
            delay(2000);
        }
        aserial.right(50);
        led.show(11, 252, 252);
        delay(2000);
        aserial.backward(150);
        led.show(255, 0, 0);
        delay(1000);
        aserial.rightBackward(50);
        led.show(252, 11, 156);
        delay(2000);
        aserial.forward(150);
        led.show(0, 255, 0);
        delay(1000);
        aserial.rightForward(50);
        led.show(131, 11, 252);
        delay(2000);
        aserial.forward(150);
        led.show(0, 255, 0);
        delay(3000);
        aserial.stop();
        led.show(152, 27, 247);
        delay(5000);
    }
}
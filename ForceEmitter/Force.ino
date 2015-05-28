/**
 * Force Actuator
 */

#define SERVO_PIN 4

/* --------------------------------------------------- */

#include <Servo.h>

Servo servo;

void force_setup() {
  servo.attach(SERVO_PIN);
}

void force_set(float value) {
  int val = map(value, 0, 100, 47, 32);
  servo.write(val);
}

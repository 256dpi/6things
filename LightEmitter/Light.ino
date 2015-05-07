/**
 * Light Actuator
 */

#define LIGHT_PIN 5

/* --------------------------------------------------- */

void light_setup() {
  pinMode(LIGHT_PIN, OUTPUT);
}

void light_set(float value) {
  int val = map(value, 0, 100, 0, 160);
  if(val < 2) {
    digitalWrite(LIGHT_PIN, LOW);
  } else {
    analogWrite(LIGHT_PIN, val);
  } 
}

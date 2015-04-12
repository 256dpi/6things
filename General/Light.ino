/**
 * Light
 */
 
#define LIGHT_PIN 7

/* --------------------------------------------------- */

void light_setup() {
  pinMode(LIGHT_PIN, OUTPUT);
}

void light_on() {
  digitalWrite(LIGHT_PIN, HIGH);
}

void light_off() {
  digitalWrite(LIGHT_PIN, LOW); 
}

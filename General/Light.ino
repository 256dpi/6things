/**
 * Light
 */
 
#define LIGHT_PIN 7
#define LIGHT_TIME 1000

/* --------------------------------------------------- */

long long light_last = 0;

void light_setup() {
  pinMode(LIGHT_PIN, OUTPUT);
}

void light_loop() {
  if(light_last > 0 && millis() - LIGHT_TIME > light_last) {
    light_last = 0;
    digitalWrite(LIGHT_PIN, LOW); 
  }
}

void light_on() {
  digitalWrite(LIGHT_PIN, HIGH);
  light_last = millis();
}

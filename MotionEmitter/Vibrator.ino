/**
 * Vibrator
 */

#define VIBRATOR_VCC 4
#define VIBRATOR_PIN 5

/* --------------------------------------------------- */

void vibrator_setup() {
  digitalWrite(VIBRATOR_VCC , HIGH);
}

void vibrator_set(float val) {
  analogWrite(VIBRATOR_PIN, map(val, 0, 100, 60, 255));
}

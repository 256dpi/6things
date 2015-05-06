/**
 * Vibrator
 */

#define VIBRATOR_PIN 6

/* --------------------------------------------------- */

void vibrator_set(float val) {
  analogWrite(VIBRATOR_PIN, map(val, 0, 100, 825, 1024));
}

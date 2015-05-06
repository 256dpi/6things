/**
 * Vibrator
 */

#define VIBRATOR_PIN 6

/* --------------------------------------------------- */

void vibrator_set(float val) {
  tone(VIBRATOR_PIN, map(val, 0, 100, 675, 1024));
}

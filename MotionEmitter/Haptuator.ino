/**
 * Haptuator
 */

#define HAPTUATOR_PIN 6

/* --------------------------------------------------- */

void haptuator_set(float val) {
  Serial.println(map(val, 0, 100, 0, 120));
  tone(HAPTUATOR_PIN, map(val, 0, 100, 0, 120));
}


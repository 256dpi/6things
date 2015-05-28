/**
 * Force Sensor
 *
 * Callbacks:
 * - force_change(float percent)
 */

#define FORCE_PIN 0
#define FORCE_INTERVAL 100

/* --------------------------------------------------- */

float force_history = 0;
long long force_last_read = 0;

void force_loop() {
  if(millis() - FORCE_INTERVAL > force_last_read) {
    force_read();
    force_last_read = millis();
  }
}

void force_read() {
  float v = constrain(map(analogRead(FORCE_PIN), 0, 200, 0, 100), 0, 100);
  
  if(v != force_history) {
    force_change(v);
    force_history = v;
  }
}

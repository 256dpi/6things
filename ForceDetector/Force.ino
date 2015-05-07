/**
 * Force Sensor
 *
 * Callbacks:
 * - force_change(float percent)
 */

#define FORCE_PIN 0
#define FORCE_INTERVAL 100

/* --------------------------------------------------- */

int force_history = 0;
long long force_last_read = 0;

void force_loop() {
  if(millis() - FORCE_INTERVAL > force_last_read) {
    force_read();
    force_last_read = millis();
  }
}

void force_read() {
  int v = analogRead(FORCE_PIN);
  
  if(v != force_history) {
    force_change(constrain(map(v, 900, 1000, 0, 100), 0, 100));
    force_history = v;
  }
}

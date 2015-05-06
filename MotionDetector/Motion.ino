/**
 * Motion Sensor
 *
 * Callbacks:
 * - motion_change(float percent)
 */

#define MOTION_PIN 0
#define MOTION_INTERVAL 100

/* --------------------------------------------------- */

int motion_history = 0;
long long motion_last_read = 0;

void motion_loop() {
  if(millis() - MOTION_INTERVAL > motion_last_read) {
    motion_read();
    motion_last_read = millis();
  }
}

void motion_read() {
  int v = analogRead(MOTION_PIN);
  
  if(v != motion_history) {
    motion_change(v / 1023.0 * 100.0);
    motion_history = v;
  }
}

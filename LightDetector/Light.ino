/**
 * Light Sensor
 *
 * Callbacks:
 * - light_change(float percent)
 */

#define LIGHT_PIN 0
#define LIGHT_INTERVAL 500

/* --------------------------------------------------- */

int light_history = 0;
long long light_last_read = 0;

void light_loop() {
  if(millis() - LIGHT_INTERVAL > light_last_read) {
    light_read();
    light_last_read = millis();
  }
}

void light_read() {
  int v = analogRead(LIGHT_PIN);
  
  if(v != light_history) {
    light_change(map(v, 50, 950, 0, 100));
    light_history = v;
  }
}

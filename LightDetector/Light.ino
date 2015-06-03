/**
 * Light Sensor
 *
 * Callbacks:
 * - light_change(float percent)
 */

#define LIGHT_PIN 0
#define LIGHT_INTERVAL 500

/* --------------------------------------------------- */

float light_history = 0;
long long light_last_read = 0;

void light_loop() {
  if(millis() - LIGHT_INTERVAL > light_last_read) {
    light_read();
    light_last_read = millis();
  }
}

void light_read() {
  int v = analogRead(LIGHT_PIN);
  float f = constrain(map(v, 900, 1000, 0, 100), 0, 100);
  
  if(f != light_history) {
    light_change(f);
    light_history = f;
  }
}

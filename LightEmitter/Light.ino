/**
 * Light Actuator
 */

#define LIGHT_PIN 7

/* --------------------------------------------------- */

#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel light_pixels = Adafruit_NeoPixel(16, LIGHT_PIN);

void light_setup() {
  light_pixels.begin(); 
}

void light_set(float value) {
  for(int i=0; i<16; i++) {
    int shade = value / 100 * 255;
    Serial.println(shade);
    light_pixels.setPixelColor(i, light_pixels.Color(shade, shade, shade));
  }
  light_pixels.show();
}

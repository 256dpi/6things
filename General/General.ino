/**
 * Pyolon - General
 *
 * Pylon Project: Events, logics and actions.
 */

#define ID "g1"
#define KEY "d70579f150265bcd"
#define SECRET "cb710bde99160e0a71119f51663b775b"

/* --------------------------------------------------- */

#include <Bridge.h>
#include <YunMQTTClient.h>

const char * pot_id = ID;
const char * pot_key = KEY;
const char * pot_secret = SECRET;

String current_channel = String("channel/0");

YunMQTTClient client("connect.shiftr.io", 1883);

unsigned long lastMillis = 0;

void setup() {
  Bridge.begin();
  digitalWrite(13, LOW);
  
  selector_setup();
  button_setup();
  light_setup();

  if (client.connect(pot_id, pot_key, pot_secret)) {
    digitalWrite(13, HIGH);
    client.subscribe("/another/topic");
  }
}

void loop() {
  client.loop();
  selector_loop();
  button_loop();
  light_loop();
}

void messageReceived(String topic, String payload, char * bytes, unsigned int length) {
  light_on();
}

/* Selector */

void selector_change(int channel) {
  client.unsubscribe(current_channel);
  current_channel = String("channel/") + String(channel);
  client.subscribe(current_channel);
}

/* Button */

void button_pressed() {
  client.publish(current_channel);
}

/**
 * 6things - Motion Detector
 *
 * 6things Project: Events, logics and actions.
 */

#define ID "motion-detector"
#define KEY "0c90c3f09b4fa34c"
#define SECRET "8125de517a549ceb426765d4ceb12414"

/* --------------------------------------------------- */

#include <Bridge.h>
#include <YunMQTTClient.h>

const char * thing_id = ID;
const char * thing_key = KEY;
const char * thing_secret = SECRET;

String channel;
boolean selected = false;

YunMQTTClient client("connect.shiftr.io", 1883);

unsigned long lastMillis = 0;

void setup() {
  Bridge.begin();
  digitalWrite(13, LOW);
  
  client.installBridge(false);
  selector_setup();

  if (client.connect(thing_id, thing_key, thing_secret)) {
    digitalWrite(13, HIGH);
  }
}

void loop() {
  client.loop();
  selector_loop();
  motion_loop();
}

void messageReceived(String topic, String payload, char * bytes, unsigned int length) {}

/* Selector */

void selector_change(int c) {  
  channel = String("channel/") + String(c);
  if(!selected) {
    selected = true;
  }
}

/* Motion */

void motion_change(float val) {
  if(selected) {
    client.publish(channel, String(val));
  }
}

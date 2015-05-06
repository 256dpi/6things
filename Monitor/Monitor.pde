/**
 * 6things - Monitor
 *
 * 6things Project: Events, logics and actions.
 */

import processing.mqtt.*;

MQTTClient client;

float channel1 = 0;
float channel2 = 0;
float channel3 = 0;


void setup() {
  size(600, 600);
  
  client = new MQTTClient(this);
  client.connect("mqtt://0c90c3f09b4fa34c:8125de517a549ceb426765d4ceb12414@connect.shiftr.io", "monitor");
  client.subscribe("channel/+");
  
  fill(0);
}

void draw() {  
  background(255);
  
  drawRect(0, 0, 200, int(channel1 / 100 * 600));
  drawRect(200, 0, 200, int(channel2 / 100 * 600));
  drawRect(400, 0, 200, int(channel3 / 100 * 600));
}

void messageReceived(String topic, byte[] payload) {
  String[] segments = topic.split("/");
  
  if(segments[1].equals("1")) {
    channel1 = Float.parseFloat(new String(payload));
  } else if(segments[1].equals("2")) {
    channel2 = Float.parseFloat(new String(payload));
  } else if(segments[1].equals("3")) {
    channel3 = Float.parseFloat(new String(payload));
  }
}

void drawRect(int x, int y, int w, int h) {
  rect(x, height - h + y, w, h);
}


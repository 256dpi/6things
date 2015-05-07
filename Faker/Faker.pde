/**
 * 6things - Faker
 *
 * 6things Project: Events, logics and actions.
 */

import processing.mqtt.*;

MQTTClient client;

int channel = 1;
int oldValue = 0;
int lastFrame = 0;

void setup() {
  size(200, 600);
  
  client = new MQTTClient(this);
  client.connect("mqtt://0c90c3f09b4fa34c:8125de517a549ceb426765d4ceb12414@connect.shiftr.io", "faker");
  
  fill(0);
}

void draw() {  
  if(mousePressed && frameCount > lastFrame + 10) {
    background(255);
    text("Channel " + channel, 20, 30);
    lastFrame = frameCount;
    if(mouseY != oldValue) {
      oldValue = mouseY;
      float value = constrain((height - mouseY) / float(height) * 100.0, 0, 100);
      client.publish("channel/" + channel, Float.toString(value));
    }
    drawRect(0, 0, 200, height - mouseY);
  }
}

void messageReceived(String topic, byte[] payload) {}

void drawRect(int x, int y, int w, int h) {
  rect(x, height - h + y, w, h);
}

void keyPressed() {
  if(key == '1') {
    channel = 1;
  } else if(key == '2') {
    channel = 2;
  } else if(key == '3') {
    channel = 3;
  }
}

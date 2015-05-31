/**
 * Selector
 *
 * Callbacks
 * - selector_change(channel)
 */
 
#define SELECTOR_ONE 3
#define SELECTOR_TWO 2

/* --------------------------------------------------- */

int selector_history = 0;

void selector_setup() {
  pinMode(SELECTOR_ONE, INPUT_PULLUP);
  pinMode(SELECTOR_TWO, INPUT_PULLUP);
}

void selector_loop() {
  int one = digitalRead(SELECTOR_ONE);
  int two = digitalRead(SELECTOR_TWO);
  
  int channel = 0;
  
  if(one == HIGH && two == HIGH) {
    channel = 2;
  } else if(one == HIGH && two == LOW) {
    channel = 1;
  } else if(one == LOW && two == HIGH) {
    channel = 3;
  }
  
  if(channel != selector_history) {
    selector_change(channel);
    selector_history = channel;
  }
}

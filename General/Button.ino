/**
 * Button
 *
 * Callbacks
 * - button_pressed()
 */
 
#define BUTTON_PIN 5

/* --------------------------------------------------- */

int button_history = 0;

void button_setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void button_loop() {
  int btn = digitalRead(BUTTON_PIN);
  
  if(btn != button_history) {
    if(btn == LOW) {
      button_pressed();
    }
    
    button_history = btn;
  }
}

/**
 * Motion Sensor
 *
 * Callbacks:
 * - motion_change(float percent)
 */

#define MOTION_X 0
#define MOTION_Y 1
#define MOTION_Z 2
#define MOTION_INTERVAL 100

/* --------------------------------------------------- */

int motion_x_history = 0;
int motion_y_history = 0;
int motion_z_history = 0;
int motion_d_history = 0;
long long motion_last_read = 0;

void motion_loop() {
  if(millis() - MOTION_INTERVAL > motion_last_read) {
    motion_read();
    motion_last_read = millis();
  }
}

void motion_read() {
  int x = analogRead(MOTION_X);
  int y = analogRead(MOTION_Y);
  int z = analogRead(MOTION_Z);
  
  if(motion_last_read > 0) {
    int dx = abs(motion_x_history - x);
    int dy = abs(motion_y_history - y);
    int dz = abs(motion_z_history - z);
    int d = dx + dy + dz;
    
    if(motion_d_history != d) {
      motion_change(constrain(map(d, 0, 500, 0, 100), 0, 100));
    }
    
    motion_d_history = d;
  }
  
  motion_x_history = x;
  motion_y_history = y;
  motion_z_history = z;
  motion_last_read = millis();
}

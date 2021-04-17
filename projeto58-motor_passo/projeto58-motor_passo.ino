#include <Stepper.h>

#define e1 8
#define e2 9
#define e3 10
#define e4 11

const int steps = 64;

Stepper mp(steps, e1, e3, e2, e4);  

void setup() {
  mp.setSpeed(500);
}

void loop() {
  for(int i=0; i<32;i++){
    mp.step(steps);
  } 
  delay(1000);

  for(int i=0; i<32;i++){
    mp.step(-steps);
  }
  delay(1000);
  
}

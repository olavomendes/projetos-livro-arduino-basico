#include <Servo.h>

Servo servo1;



void setup(){
  servo1.attach(5);
}

void loop(){
  int angulo = analogRead(0);
  
  angulo = map(angulo, 0, 1023, 0, 180);
  
  servo1.write(angulo);
  delay(15);
}
#include <IRremote.h>
#define IR_GO 0x00ff629d 
#define IR_BACK 0x00ffa857 
#define IR_LEFT 0x00ff22dd 
#define IR_RIGHT 0x00ffc23d 
#define IR_STOP 0x00ff02fd 
#define VEL_A 200
#define VEL_B 150

int ENA = 5;
int ENB = 6;
int IN1 = 2;
int IN2 = 4;
int IN3 = 7;
int IN4 = 8;

int RECV_PIN = 12;
IRrecv irrecv(RECV_PIN);
decode_results results;

int i = 2;


void config(void) {
  for (i; i<9; i++) {
    pinMode(i, OUTPUT);
  }

  digitalWrite(ENA, VEL_A);
  digitalWrite(ENB, VEL_B); 

  Serial.begin(9600);
  irrecv.enableIRIn();
}

void advance() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void back() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void left() {
  digitalWrite(ENA, 50);
  digitalWrite(ENB, 50); 
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void right() {
  digitalWrite(ENA, 50);
  digitalWrite(ENB, 50); 
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void stopp(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH); 
}

void control(void) {
  if (irrecv.decode(&results)) {
    unsigned long key = (results.value);
    
    switch(key) {
      case IR_GO: advance(); break;
      case IR_BACK: back(); break;
      case IR_STOP: stopp(); break;
      case IR_LEFT: left(); break;
      case IR_RIGHT: right(); break;
      default: break;
    }
    irrecv.resume();
  }
}

void setup() {
  config();
  stopp();  
}

void loop() {
  control();
}
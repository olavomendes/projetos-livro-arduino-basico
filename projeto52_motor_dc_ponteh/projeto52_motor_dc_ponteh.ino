#define vel_m1 3
#define m1_A 2
#define m1_B 4

#define vel_m2 11
#define m2_A 12
#define m2_B 13

#define tmp 5000


int vel = 255;



void setup(){
  // Motor 1
  pinMode(vel_m1, OUTPUT);
  pinMode(m1_A, OUTPUT);
  pinMode(m1_B, OUTPUT);
  
  // Motor 2
  pinMode(vel_m2, OUTPUT);
  pinMode(m2_A, OUTPUT);
  pinMode(m2_B, OUTPUT); 
  
  //Motor 1
  analogWrite(vel_m1, 0);
  digitalWrite(m1_A, LOW);
  digitalWrite(m1_B, LOW);

  
  // Motor 2
  analogWrite(vel_m2, 0);
  digitalWrite(m2_A, LOW);
  digitalWrite(m2_B, LOW); 
}

void loop(){
  // Motor 1
  analogWrite(vel_m1, vel);
  digitalWrite(m1_A, HIGH);
  digitalWrite(m1_B, LOW);
  
  // Motor 2
  analogWrite(vel_m2, vel);
  digitalWrite(m2_A, LOW);
  digitalWrite(m2_B, HIGH); 
  
  delay(tmp);
  
  // Motor 1
  digitalWrite(m1_A, LOW);
  digitalWrite(m1_B, HIGH);

  // Motor 2
  digitalWrite(m2_A, HIGH);
  digitalWrite(m2_B, LOW); 
  
  delay(tmp);
}
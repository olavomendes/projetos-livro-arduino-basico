int pinos_led[] = {9, 10, 11};


void setup() {
     for (int x=0; x<3; x++) {
          pinMode(pinos_led[x], OUTPUT); 
     }
}

void loop() {
     analogWrite(pinos_led[0], random(120) + 136);
     analogWrite(pinos_led[1], random(120) + 136);
     analogWrite(pinos_led[2], random(120) + 136);
     delay(random(100));
}

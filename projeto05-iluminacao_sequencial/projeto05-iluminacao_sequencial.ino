byte pinos_led[] = {9, 10, 11, 12, 13};

int delay_led(65);
int direcao = 1;
int led_atual = 0;
unsigned long mudanca_tempo;


void setup() {
    for (int x=0; x<5; x++) {
        pinMode(pinos_led[x], OUTPUT);  
    }
    mudanca_tempo = millis();
}

void loop() {
    if ((millis() - mudanca_tempo) > delay_led) {
      muda_led();
      mudanca_tempo = millis();  
    }
}

void muda_led(){
    for (int x=0; x<5; x++) {
        digitalWrite(pinos_led[x], LOW);  
    }  

    digitalWrite(pinos_led[led_atual], HIGH);
    led_atual += direcao;

    if (led_atual == 4) {direcao = - 1;}
    if (led_atual == 0) {direcao = 1;}
}

int carro_vermelho = 13;
int carro_amarelo = 12;
int carro_verde = 11;

int ped_vermelho = 9;
int ped_verde = 8;

int botao = 2;
int tempo_cruzamento = 5000; // tempo para o pedestre atravessar

unsigned long tempo_mudanca; // tempo desde a conclusão do último ciclo de pedestres

void setup() {
    pinMode(carro_vermelho, OUTPUT);
    pinMode(carro_amarelo, OUTPUT);
    pinMode(carro_verde, OUTPUT);
    
    pinMode(ped_vermelho, OUTPUT);
    pinMode(ped_verde, OUTPUT);
    
    pinMode(botao, INPUT);
  
    digitalWrite(carro_verde, HIGH);
    digitalWrite(ped_vermelho, HIGH);
}

void loop() {
    int estado_botao = digitalRead(botao);
  
    if (estado_botao == HIGH && (millis() - tempo_mudanca) > 5000) {
        muda_leds();
    }
}

void muda_leds() {
    digitalWrite(carro_verde, LOW);
    digitalWrite(carro_amarelo, HIGH);
    delay(2000);

    digitalWrite(carro_amarelo, LOW);
    digitalWrite(carro_vermelho, HIGH);
    delay(1000);

    digitalWrite(ped_vermelho, LOW);
    digitalWrite(ped_verde, HIGH);
    delay(tempo_cruzamento);

    // pisca o verde dos pedestres
    for (int x=0; x<10; x++) {
        digitalWrite(ped_verde, HIGH);
        delay(250);
        digitalWrite(ped_verde, LOW);
        delay(250);  
    }

    // acende o vermelho dos pedestres
    digitalWrite(ped_vermelho, HIGH);
    delay(500);

    digitalWrite(carro_amarelo, HIGH);
    digitalWrite(carro_vermelho, LOW);
    delay(1000);
    digitalWrite(carro_verde, HIGH);
    digitalWrite(carro_amarelo, LOW);

    tempo_mudanca = millis();
    
}

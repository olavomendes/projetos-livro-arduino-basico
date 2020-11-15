int pino_led = 9;
int pino_piezo = 5;
int limiar = 120; // valor do sensor a ser atingido antes da ativação
int valor_sensor = 0;
float valor_led = 0;


void setup() {
     pinMode(pino_led, OUTPUT);
     // pisca o LED duas vezes para sinalizar que o programa iniciou
     digitalWrite(pino_led, HIGH); delay(150); digitalWrite(pino_led, LOW); delay(150);
     digitalWrite(pino_led, HIGH); delay(150); digitalWrite(pino_led, LOW); delay(150);
}

void loop() {
     valor_sensor = analogRead(pino_piezo);

     if (valor_sensor >= limiar) {
         valor_led = 255; 
     }

     analogWrite(pino_led, int(valor_led)); // escreve o valor do brilho no LED
     valor_led -= 0.05;
     
     if (valor_led <= 0) { valor_led = 0;} // o valor não vai ficar abaixo de 0
}

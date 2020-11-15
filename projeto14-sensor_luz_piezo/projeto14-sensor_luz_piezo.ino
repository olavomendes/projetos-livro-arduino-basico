int pino_piezo = 8;
int pino_ldr = A0;

int valor_ldr = 0;


void setup() {
  Serial.begin(9600);
  pinMode(pino_ldr, INPUT);
}

void loop() {

     valor_ldr = analogRead(pino_ldr);
     Serial.println(valor_ldr);
     delay(1000);
     tone(pino_piezo, 1000);
     delay(25);
     noTone(pino_piezo);
     delay(valor_ldr);
}

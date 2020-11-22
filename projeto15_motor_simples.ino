int pino_pot = 0; // pino do potenciômetro
int pino_transistor = 9; // pino do transistor
int valor_pot = 0;


void setup(){
  pinMode(pino_transistor, OUTPUT);
}

void loop(){
  	valor_pot = analogRead(pino_pot) / 4;
    analogWrite(pino_transistor, valor_pot);
}
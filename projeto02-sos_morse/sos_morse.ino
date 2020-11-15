int led = 7;

void setup() {
  pinMode(led,OUTPUT);
}

void loop() {
  // 3 pontos
  for (int x=0; x<3; x++) {
      digitalWrite(led, HIGH);
      delay(150);
      digitalWrite(led, LOW);
      delay(150);  
  }

  // 100 ms de intervalo entre as letras
  delay(100);

  // 3 traços
  for (int x=0; x<3; x++){
      digitalWrite(led, HIGH);
      delay(400);
      digitalWrite(led, LOW);
      delay(400);  
  }

  delay(100);

   // 3 pontos
  for (int x=0; x<3; x++) {
      digitalWrite(led, HIGH);
      delay(150);
      digitalWrite(led, LOW);
      delay(150);  
  }

  // espera 5 segundos para repetir
  delay(5000);
}

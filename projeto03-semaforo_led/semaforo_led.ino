int delay_led = 1000;
int led_vermelho = 7;
int led_amarelo = 6;
int led_verde = 5;

void setup() {
  pinMode(led_vermelho, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_verde, OUTPUT);
}

void loop() {
  digitalWrite(led_vermelho, HIGH);
  delay(delay_led);
  digitalWrite(led_amarelo, HIGH);
  delay(2000);

  digitalWrite(led_verde, HIGH);
  digitalWrite(led_vermelho, LOW);
  digitalWrite(led_amarelo, LOW);
  delay(delay_led);

  digitalWrite(led_amarelo, HIGH);
  digitalWrite(led_verde, LOW);
  delay(2000);

  digitalWrite(led_amarelo, LOW);
}

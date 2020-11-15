int led = 11;
float valor_seno;
int valor_led;



void setup() {
    pinMode(led, OUTPUT);
}

void loop() {
    for (int x=0; x<180; x++) {
         // converte graus em radianos e, então obtém o valor do seno
         // não devemos passar do ângulo de 180º
         valor_seno = (sin(x*(3.1416/180)));
         valor_led = int(valor_seno * 255); // o brilho deve estar entre 0 e 255

         analogWrite(led, valor_led);
         delay(25);
    }
}

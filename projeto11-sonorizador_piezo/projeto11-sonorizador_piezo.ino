int piezo = 8;
float valor_seno;
int valor_tom;


void setup() {
     pinMode(piezo, OUTPUT);
}

void loop() {
     for (int x=0; x<180; x++) {
          valor_seno = (sin(x*(3.1416/180)));
          valor_tom = 2000 + int(valor_seno*1000);
          // gera uma frequência a partir do valor do seno
          tone(piezo, valor_tom);
          delay(2); 
     }
}

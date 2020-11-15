#define buzzer 7
#define ldr A0

void setup() {
    pinMode(buzzer, OUTPUT);
    pinMode(ldr, INPUT);
    Serial.begin(9600);
};

void loop() {
    float luminosidade = analogRead(ldr);
    Serial.println(luminosidade);
    delay(1000);

    if (luminosidade > 800.0) {
        tone(buzzer, 1000);
    }else{
      noTone(buzzer);
    };
};

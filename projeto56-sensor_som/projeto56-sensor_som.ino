bool som;
int pino_sensor = 2;


void setup() {
    Serial.begin(9600);
    pinMode(pino_sensor, OUTPUT);

}

void loop() {
    som = digitalRead(pino_sensor);
    Serial.print(som);

    delay(500);
}

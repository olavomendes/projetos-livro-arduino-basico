#include <IRremote.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

#define pino_sensor 11
#define pino_led 7

IRrecv sensor_IR(pino_sensor);
decode_results comando;

void setup() {
    Serial.begin(9600);
    sensor_IR.enableIRIn(); // inicialização do receptor infravermelho
    Serial.println("Sensor IR habilitado");
}

void loop() {

  if(sensor_IR.decode(&comando)){
        Serial.print("Comando: ");
        Serial.println(comando.value, HEX);
        sensor_IR.resume();

        if(comando.value == 1 or comando.value == 10001){
            digitalWrite(pino_led, HIGH);  
            delay(3000);
            digitalWrite(pino_led, LOW);
        }
  }
}

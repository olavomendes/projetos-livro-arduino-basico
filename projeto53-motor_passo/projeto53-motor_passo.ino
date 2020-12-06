#include <Stepper.h>
#define entrada_1 8
#define entrada_2 9
#define entrada_3 10
#define entrada_4 11
# define led 13

const int passos_giro = 64;

Stepper motor_passo(passos_giro, entrada_1, entrada_3, entrada_2, entrada_4);

void setup() {
    pinMode(led, OUTPUT);
}

void loop() {
    digitalWrite(led, LOW);
    // sentido horário
    motor(500, 1, 2, 1000);
    digitalWrite(led, HIGH);

    delay(3000);

    digitalWrite(led, LOW);
    // sentido anti-horário
    motor(500, -1, 2, 1000);
    motor(500, 1, 2, 1000);
    digitalWrite(led, HIGH);

    delay(3000);
} 

void motor(int velocidade, int sentido, int voltas, int tmp){

    motor_passo.setSpeed(velocidade);  // RPM

    for (int i = 0; i < (32 * voltas); i++){
      motor_passo.step(passos_giro * sentido);
    }
    delay(tmp);
}

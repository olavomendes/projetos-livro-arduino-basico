#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int maxC=0, minC=100, maxF=0, minF=212;
int escala = 1;
int pino_botao = 8;



void setup(){
  lcd.begin(16, 2);
  analogReference(INTERNAL);
  pinMode(pino_botao, INPUT);
  
  lcd.clear();
}


void loop() {
  	lcd.setCursor(0,0); 
  	int sensor = analogRead(0); 
  	int estado_botao = digitalRead(pino_botao); 
  
  	switch (estado_botao) { 
  		case HIGH:
    			escala=-escala; 
    			lcd.clear();
  	}

  	switch (escala) { 
  		case 1:
               celsius(sensor);
               break;
  		case -1:
               fahrenheit(sensor);
  	}
  	delay(250);
}

void celsius(int sensor){
  lcd.setCursor(0, 0);
  int temp = sensor * 0.1074188; // converte em C
  lcd.print(temp);
  lcd.write(B11011111); // símbolo de grau
  lcd.print("C");
  if (temp > maxC) {maxC = temp;}
  if (temp < minC) {minC = temp;}
  lcd.setCursor(0, 1);
  lcd.print("H=");
  lcd.print(maxC);
  lcd.write(B11011111);
  lcd.print("C L=");
  lcd.print(minC);
  lcd.write(B11011111);
  lcd.print("C ");
}

void fahrenheit(int sensor) {
  	lcd.setCursor(0,0);
  	float temp = ((sensor * 0.1074188) * 1.8)+32; 
  	lcd.print(int(temp));
  	lcd.write(B11011111); /
  	lcd.print("F ");
  	if (temp>maxF) {maxF=temp;}
  	if (temp<minF) {minF=temp;}
  	lcd.setCursor(0,1);
  	lcd.print("H=");
  	lcd.print(maxF);
  	lcd.write(B11011111);
  	lcd.print("F L=");
  	lcd.print(minF);
  	lcd.write(B11011111);
  	lcd.print("F ");
}



#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);



void setup(){
  lcd.begin(16, 2);
}


void loop(){
  basicPrintDemo();
  displayOnOffDemo();
  setCursorDemo();
  scrollLeftDemo();
  scrollRightDemo();
  cursorDemo();
  createGlyphDemo();
  meusDeusQueTristezaDemo();
}


void basicPrintDemo(){
  lcd.clear();
  lcd.print("Print basico");
  delay(2000);
}   

void displayOnOffDemo(){
  lcd.clear();
  lcd.print("Mostra on/off");
  
  for (int x=0; x<3; x++){
  	lcd.noDisplay();
    delay(1000);
    lcd.display();
    delay(1000);
  }
}

void setCursorDemo(){
  lcd.clear();
  lcd.print("Controlar cursor");
  delay(1000);
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("5,0");
  delay(2000);
  lcd.setCursor(10, 1);
  lcd.print("10,1");
  delay(2000);
  lcd.setCursor(3, 1);
  lcd.print("3,1");
  delay(1000);

}

void scrollLeftDemo(){
  lcd.clear();
  lcd.print("Mover esquerda");
  delay(1000);
  lcd.clear();
  lcd.setCursor(7,0);
  lcd.print("Inicio");
  lcd.setCursor(9,1);
  lcd.print("Arduino");
  delay(1000);
  
  for (int x=0; x<16; x++){
  	lcd.scrollDisplayLeft();
    delay(250);
  }
}

void scrollRightDemo(){
  lcd.clear();
  lcd.print("Mover direita");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Inicio");
  lcd.setCursor(1, 1);
  lcd.print("Arduino");
  delay(1000);
  
  for (int x=0; x<16; x++){
  	lcd.scrollDisplayRight();
    delay(250);
  }
}


void cursorDemo(){
  lcd.clear();
  lcd.cursor();
  lcd.print("Cursor on");
  delay(3000);
  lcd.clear();
  lcd.clear();
  lcd.noCursor();
  lcd.print("Cursor off");
  delay(3000);
  lcd.clear();
  lcd.cursor();
  lcd.blink();
  lcd.print("Blink on");
  delay(3000);
  lcd.noCursor();
  lcd.noBlink();
}

void createGlyphDemo(){
  lcd.clear();
  
  	//carinha feliz
  	byte happy[8] = { 
  	B00000,
  	B00000,
  	B10001,
  	B00000,
  	B10001,
  	B01110,
  	B00000,
  	B00000};
  
  	//carinha triste
  	byte sad[8] = { 
  	B00000,
  	B00000,
  	B10001,
  	B00000,
  	B01110,
  	B10001,
  	B00000,
  	B00000};
  
  lcd.createChar(0, happy);
  lcd.createChar(1, sad);
  
  for (int x=0; x<5; x++){
  	lcd.setCursor(8,0);
    lcd.write((byte)0);
    delay(1000);
    lcd.setCursor(8,0);
    lcd.write(1);
    delay(1000);
  }

}


void meusDeusQueTristezaDemo(){
  lcd.clear();
  lcd.setCursor(0, 0);
  delay(1000);
  lcd.print("Meu Deus");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("Que tristeza");
  delay(1000);
}































// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int buttonState1,buttonState2,buttonState3,buttonState4 = 0; 
void setup() {  
  pinMode(BT1, INPUT);
  pinMode(BT2, INPUT);
  pinMode(BT3, INPUT);
  pinMode(BT4, INPUT);
  // set up the LCD's number of columns and rows:  
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("2020 Hello World!");
  lcd.setCursor(0, 1);
  lcd.print("Welcome to Andes!");
}
 void loop() {
  buttonState1 = digitalRead(BT1);
  buttonState2 = digitalRead(BT2);
  buttonState3 = digitalRead(BT3);
  buttonState4 = digitalRead(BT4);
  if (buttonState1 == LOW) {
    lcd.clear();
    lcd.print("BT1");
  }else if (buttonState2 == LOW){
    lcd.clear();
    lcd.print("BT2");
  }else if (buttonState3 == LOW){
    lcd.clear();
    lcd.print("BT3");
  }else if (buttonState4 == LOW){
    lcd.clear();
    lcd.print("BT4");
  }
}

#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
String Line1 = "NTTU";
String Line2 = "11111240";

void setup() {
  lcd.begin(16, 2);
}
void loop() {
  char i;
  lcd.clear();
  lcd.setCursor(1, 0);
  for (i = 0; i < Line1.length(); i++) {
    lcd.print(Line1[i]);
    delay(200);
  }
  lcd.setCursor(5, 1);
  for (i = 0; i < Line2.length(); i++) {
    lcd.print(Line2[i]);
    delay(200);
  }
}

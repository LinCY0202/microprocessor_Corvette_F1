#include <LiquidCrystal.h>
#include <RTC.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
const byte seconds = 0;
const byte minutes = 36;
const byte hours = 13;
const byte day = 10;
void setup() {
  lcd.begin(16, 2);     // set the time and start counting
  RTC.settime(day, hours, minutes, seconds);
  RTC.startcounting();
}
void loop() {     
  lcd.clear();
  lcd.print("Start Counting...");
  lcd.setCursor(0, 1);
  lcd.print("20/3/");
  lcd.print(RTC.getday());
  lcd.print(",");
  lcd.print(RTC.gethours());
  lcd.print(":");
  lcd.print(RTC.getminutes());
  lcd.print(":");
  lcd.print(RTC.getseconds());
  delay(1000);
}

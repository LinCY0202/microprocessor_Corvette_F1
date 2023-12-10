#include <FlexiTimer2.h> // 引入計時中斷函式庫
#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

static unsigned int num;

void timer_isr_routine() { // 計時中斷函數
  lcd.setCursor(0, 1);
  lcd.print(++num);
}

void setup() {
  Serial.begin(9600);
  FlexiTimer2::set(1000, timer_isr_routine); // 每1000ms產生中斷，進入中斷服務常式
  FlexiTimer2::start(); // 啟動開始計時
  lcd.begin(16, 2);
  lcd.print("Timer");
  num = 0;
}

void loop() { // 主程式無作用，或執行其它程式
   Serial.print("===========================\n");
}

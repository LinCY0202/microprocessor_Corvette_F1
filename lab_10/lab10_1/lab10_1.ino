#define NUM 14 
int leds[NUM] = {D0, D2, D4, D5, D6, D7, D8, D9, D10, D11, D12, D13, D14, D15};
//int leds[NUM] = {D0, D1, D2, D4, D5, D6, D7, D8, D9, D10, D11, D12, D13, D14, D15};

int count = 0; // 外部中斷次數
void setup(){
  for(int i = 0; i < NUM; i++){
        pinMode(leds[i], OUTPUT);
        digitalWrite(leds[i], HIGH);
  }
  Serial.begin(9600); // 啟動串列埠
  pinMode(BT1, INPUT_PULLUP); // 設定D1(INT0)為輸入有提升電阻
  attachInterrupt(BT1, disp_count, FALLING); // 致能外部中斷腳、函數及負緣
}
void loop(){
  for(int i = 0; i < NUM; i++){
        digitalWrite(leds[i], LOW);
        delay(300);
        digitalWrite(leds[i], HIGH);
        delay(300); 
  }
}

void disp_count() // INT0中斷服務程式
{  
  unsigned int dly;
  noInterrupts(); // 停止中斷
  dly = 5000;
  while (dly--); // 延時，防止機械彈跳
  while (!digitalRead(BT1)); // 等待放開鍵
  dly = 5000;
  while (dly--); // 延時，防止機械彈跳
  Serial.println(count++); // 中斷次數遞加送到串列埠顯示
  interrupts(); // 恢復中斷
}

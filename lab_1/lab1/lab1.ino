#define NUM 15 
int leds[NUM] = {D0, D1, D2, D4, D5, D6, D7, D8, D9, D10, D11, D12, D13, D14, D15};

// 將每個腳位模式設為OUTPUT
void setup() {               
  for(int i = 0; i < NUM; i++){
    pinMode(leds[i], OUTPUT);
  }    
}
void loop() {
  int case1 = 0x0000;
  int case2 = 0xAAAA;
  int case3 = 0x5555;
  for(int i = 0; i < NUM ; i++){
    digitalWrite(leds[i], bitRead(case1, i));
  }
  delay(300);
  for(int i = 0; i < NUM ; i++){
    digitalWrite(leds[i], bitRead(case2, i));
  }
  delay(300);
  for(int i = 0; i < NUM ; i++){
    digitalWrite(leds[i], bitRead(case3, i));
  }
  delay(300);
}

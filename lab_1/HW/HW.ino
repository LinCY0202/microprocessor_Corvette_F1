#define NUM 14 
int leds[NUM] = {D0, D1, D2, D4, D5, D6, D7, D8, D9, D10, D11, D13, D14, D15};

// 將每個腳位模式設為OUTPUT
void setup() {               
  for(int i = 0; i < NUM; i++){
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], HIGH);//初始化
  }    
}
void loop() {

  for(int i = 0; i < NUM/2 ; i++){
    digitalWrite(leds[i], LOW);
    digitalWrite(leds[NUM-i-1], LOW);
    delay(300);
    digitalWrite(leds[i], HIGH);
    digitalWrite(leds[NUM-i-1], HIGH);
    delay(300);
  }
  delay(300);
}

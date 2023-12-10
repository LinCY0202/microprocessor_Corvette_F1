#define NUM 23 
int leds[NUM] = {D0, D1, D2, D4, D5, D6, D7, D8, D9, D10, D11, D12, D13, D14, D15, A0, A1, A2, A3, LED1, LED2, LED3, LED4};

void setup() {               
  for(int i = 0; i < NUM; i++){
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], HIGH);
  }    
}
void loop() {
  for(int i = 0; i < NUM-4; i++){
    digitalWrite(leds[i], LOW);
    delay(300);
    digitalWrite(leds[i], HIGH);
    delay(300);    
  }
  for(int i = NUM-4; i < NUM; i++){
    digitalWrite(leds[i], HIGH);
    delay(300);
    digitalWrite(leds[i], LOW);
    delay(300);    
  }
}

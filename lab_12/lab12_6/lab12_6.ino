//#define counterclockwise
#define servoPin D7
#define NUM 4
char leds[NUM] = {D8, D9, D10, D11};
char start = 0;
char level = 1;

void LED_cnt(char cnt){
  int i;
  for(i=0; i<cnt ; i++)
    digitalWrite(leds[i], LOW);
  for(i=cnt; i< cnt+(NUM-cnt); i++)
    digitalWrite(leds[i], HIGH);  
}
void BT1_isr_routine(){
  int i;
  unsigned int dly;
  noInterrupts(); // 停止中斷
  dly = 5000;
  while (dly--); // 延時，防止機械彈跳
  while (!digitalRead(BT1)); // 等待放開鍵
  dly = 5000;
  while (dly--); // 延時，防止機械彈跳
  start = !start;
  if(start)
    digitalWrite(LED1, HIGH);
  else{
    digitalWrite(LED1, LOW);
    for(i = 0; i < NUM; i++){
      pinMode(leds[i], OUTPUT);
      digitalWrite(leds[i], HIGH);
    }  
  }  
  interrupts(); // 恢復中斷
}
void BT2_isr_routine(){
  unsigned int dly;
  noInterrupts(); // 停止中斷
  dly = 5000;
  while (dly--); // 延時，防止機械彈跳
  while (!digitalRead(BT2)); // 等待放開鍵
  dly = 5000;
  while (dly--); // 延時，防止機械彈跳
  if(start){
    level++;
    if(level == 5)
      level = 4;
  }
  interrupts(); // 恢復中斷
}
void BT3_isr_routine(){
  unsigned int dly;
  noInterrupts(); // 停止中斷
  dly = 5000;
  while (dly--); // 延時，防止機械彈跳
  while (!digitalRead(BT3)); // 等待放開鍵
  dly = 5000;
  while (dly--); // 延時，防止機械彈跳
  if(start){
    level--;
    if(level == 0)
      level = 1;
  }
  interrupts(); // 恢復中斷
}
void rotate(int pulse){
  int i;
  noInterrupts(); // 停止中斷
  for(i=0; i<50; i++){
    digitalWrite(servoPin, HIGH);
    delayMicroseconds(pulse);
    digitalWrite(servoPin, LOW);
    delay(20);
  }
  interrupts(); // 恢復中斷
}
void rotation_rate(char level){
#ifdef counterclockwise
    switch(level){  //  slow-> fast 1600 ~ 2400
      case 1: rotate(1700); break;
      case 2: rotate(1900); break;
      case 3: rotate(2100); break;
      case 4: rotate(2300); break;
      default: break;
    }
#else //clockwise
    switch(level){ // fast-> slow 500 ~ 1400
      case 1: rotate(1300); break;
      case 2: rotate(1100); break;
      case 3: rotate(900); break;
      case 4: rotate(800); break;
      default: break;  
  }
#endif    
}
void setup() {
  int i = 0;
  pinMode(servoPin, OUTPUT);
  digitalWrite(servoPin, LOW);
  delay(1000);
  pinMode(BT1, INPUT_PULLUP);
  attachInterrupt(BT1, BT1_isr_routine, FALLING);
  pinMode(BT2, INPUT_PULLUP);
  attachInterrupt(BT2, BT2_isr_routine, FALLING);
  pinMode(BT3, INPUT_PULLUP);
  attachInterrupt(BT3, BT3_isr_routine, FALLING);
  pinMode(LED1, OUTPUT);
  for(i = 0; i < NUM; i++){
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], HIGH);
  }  
}
void loop() {
  if(start){
    LED_cnt(level);
    rotation_rate(level);
  }
}

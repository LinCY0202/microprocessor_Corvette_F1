#include <FlexiTimer2.h> // 引入計時中斷函式庫
#define usedDigitalPin D7 

unsigned int bitPattern=0, newKey=0;
unsigned char timerValue;
unsigned char msCount=0;
char pulseCount=0;
 
void timer_isr_routine() { // 計時中斷函數
   FlexiTimer2::timer_stop();
   if(msCount<50)
    msCount++;
   FlexiTimer2::SetPeriod(1);
   FlexiTimer2::start(); 
}
void exIR_int0() // INT0中斷服務程式
{  
  noInterrupts(); // 停止中斷
  FlexiTimer2::timer_stop();
  timerValue = msCount;
  msCount = 0;
  FlexiTimer2::SetPeriod(1);
  pulseCount++;
  if(timerValue>=50){
    pulseCount = -2;
    bitPattern = 0;
  }
  else if((pulseCount>=0)&&(pulseCount<32)){
    if(timerValue>=2)
      bitPattern |= (unsigned int)1<<(31-pulseCount);     
  }
  else if(pulseCount>=32){
    newKey = bitPattern;
    pulseCount = 0;
  }
  FlexiTimer2::start(); 
  interrupts(); // 恢復中斷
}
void setup() {
  Serial.begin(9600); 
  FlexiTimer2::set(1, timer_isr_routine);
  FlexiTimer2::start();
  pinMode(usedDigitalPin , INPUT_PULLUP);
  attachInterrupt(usedDigitalPin , exIR_int0, FALLING);
}

void loop() {
  if(newKey != 0){
    //Serial.println(newKey, HEX);
    switch(newKey){
      case 0x7FB44B: Serial.println('0'); break;
      case 0x7F9867: Serial.println('1'); break;
      case 0x7F8C73: Serial.println('2'); break;
      case 0x7FBD42: Serial.println('3'); break;
      case 0x7F8877: Serial.println('4'); break;
      case 0x7F9C63: Serial.println('5'); break;
      case 0x7FAD52: Serial.println('6'); break;
      case 0x7FA15E: Serial.println('7'); break;
      case 0x7FA55A: Serial.println('8'); break;
      case 0x7FA956: Serial.println('9'); break; 
      default: break;
    }
    newKey = 0;  
  }
}

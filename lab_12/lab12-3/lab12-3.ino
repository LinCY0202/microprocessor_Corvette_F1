#define usedDigitalPin D7

void setup() {
  pinMode(LED1, OUTPUT);
      pinMode(usedDigitalPin, INPUT);
}

void loop() {
    if (digitalRead(usedDigitalPin) == HIGH){
            digitalWrite(LED1, HIGH);
            delay(500);
    }else
            digitalWrite(LED1, LOW);    
}

#define usedDigitalPin D7  

void setup() {
  Serial.begin(9600);
  pinMode(usedDigitalPin, INPUT);
  digitalWrite(usedDigitalPin, LOW);
}

void loop() {
  if(digitalRead(usedDigitalPin)==HIGH) 
    Serial.println("Light detected.");
  else 
    Serial.println("Nothing.");
  
  delay(1000);
}

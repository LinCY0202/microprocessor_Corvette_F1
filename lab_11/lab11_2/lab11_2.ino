void setup(){
  Serial.begin(9600); // D0 D1
  Serial1.begin(9600); // D2 D3
}

void loop(){
   if (Serial1.available())
    Serial.write(Serial1.read());
  if (Serial.available())
    Serial1.write(Serial.read());
}
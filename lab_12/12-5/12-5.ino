#define UPDATE_TIME 20
#define servoPin D7
int degree = 0;
int endcode;

int convertAngleToImp(int degree){
  float a = 2000/180;
  float b = 500;
  return int(a*degree+b);
}
void ServoControl(int degree) {
  digitalWrite(servoPin, HIGH);
  delayMicroseconds(convertAngleToImp(degree));
  digitalWrite(servoPin,LOW);
  delay(UPDATE_TIME);
}
void setup() {
  pinMode(servoPin, OUTPUT);
  Serial.begin(9600);
}
void loop() {
 if (Serial.available())
 {
    degree = Serial.parseInt();
    endcode = Serial.parseInt();
    Serial.println(degree);
 }
 ServoControl(degree);
}

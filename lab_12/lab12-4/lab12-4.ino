#define TRIG_PIN D6 
#define ECHO_PIN  D7
const unsigned int MAX_DIST = 23200;
void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  digitalWrite(TRIG_PIN, LOW);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600); 
}
void loop() {
  unsigned long t1, t2;
  unsigned long pulse_width;
  float cm;
// Hold the trigger pin high for at least 10 us
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  // Wait for pulse on echo pin
  while ( digitalRead(ECHO_PIN) == 0 );
  
   // Measure how long the echo pin was held high (pulse width)
  t1 = micros();
  while ( digitalRead(ECHO_PIN) == 1);
  t2 = micros();
  pulse_width = t2 - t1;

// Calculate distance in centimeters. This is calculated from the assumed speed of sound in air at sea level (~340 m/s).
    cm = pulse_width / 58.0;
  if ( pulse_width > MAX_DIST )
    Serial.println("Out of range");
  else{
        Serial.print(cm);
        Serial.print("cm\n");
  }
  // Wait at least 60ms before next measurement
  delay(60);
}

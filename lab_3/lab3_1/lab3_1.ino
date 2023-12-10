void setup() {
  pinMode(LED1, OUTPUT); // initialize digital pin LED1 as an output
  pinMode(LED2, OUTPUT); // initialize digital pin LED2 as an output
  pinMode(LED3, OUTPUT); // initialize digital pin LED3 as an output
  pinMode(LED4, OUTPUT); // initialize digital pin LED4 as an output

  pinMode(BT1, INPUT); // initialize digital pin BT1 as an input
  pinMode(BT2, INPUT); // initialize digital pin BT2 as an input
  pinMode(BT3, INPUT); // initialize digital pin BT3 as an input
  pinMode(BT4, INPUT); // initialize digital pin BT4 as an input
}

void loop() {
  int buttonState1 = 0; // declare integer variables
  int buttonState2 = 0; // declare integer variables
  int buttonState3 = 0; // declare integer variables
  int buttonState4 = 0; // declare integer variables
  int delay_number = 100; // declare integer variables 
  buttonState1 = digitalRead(BT1); // read the input pin of BT1
  buttonState2 = digitalRead(BT2); // read the input pin of BT2
  buttonState3 = digitalRead(BT3); // read the input pin of BT3
  buttonState4 = digitalRead(BT4); // read the input pin of BT4
  if (buttonState1 == LOW) { // determines whether buttonState1 is low
    digitalWrite(LED1, HIGH); // turn the LED1 on (HIGH is the voltage level)
    delay(delay_number); // wait for 100 ms
  } else if (buttonState2 == LOW) { // determines whether buttonState2 is low
    digitalWrite(LED2, HIGH); // turn the LED2 on (HIGH is the voltage level)
    delay(delay_number); // wait for 100 ms
  } else if (buttonState3 == LOW) { // determines whether buttonState3 is low
    digitalWrite(LED3, HIGH); // turn the LED3 on (HIGH is the voltage level)
    delay(delay_number); // wait for 100 ms
  } else if (buttonState4 == LOW) { // determines whether buttonState3 is low
  digitalWrite(LED4, HIGH); // turn the LED4 on (HIGH is the voltage level)
  delay(delay_number); // wait for 100 ms
  }
  else {
    digitalWrite(LED1, LOW); // turn the LED1 off by making the voltage LOW
    digitalWrite(LED2, LOW); // turn the LED2 off by making the voltage LOW
    digitalWrite(LED3, LOW); // turn the LED3 off by making the voltage LOW
    digitalWrite(LED4, LOW); // turn the LED4 off by making the voltage LOW
  }
}

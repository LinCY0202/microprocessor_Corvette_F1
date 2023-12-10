int speakerPin = D3;

#define NOTE_Med_DO  523
#define NOTE_Med_SO  784
int i;
void setup() {
  pinMode(speakerPin, OUTPUT);
  pinMode(BT1, INPUT);
}

void loop() {
  int buttonState1 = digitalRead(BT1); 
  if (buttonState1 == LOW){
      for(i=0;i<5;i++)
      {
          tone(speakerPin, NOTE_Med_DO);
          delay(1000);
          noTone(speakerPin);
          tone(speakerPin, NOTE_Med_SO);
          delay(1000);
          noTone(speakerPin);
      }
  }
}

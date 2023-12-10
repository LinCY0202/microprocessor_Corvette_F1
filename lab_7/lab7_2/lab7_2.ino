#define NOTE_Low_SO  392
#define NOTE_Low_LA  440
#define NOTE_Low_SI  494
#define NOTE_Med_DO  523
#define NOTE_Med_RE  587
#define NOTE_Med_MI  659
#define NOTE_Med_FA  698
#define NOTE_Med_SO  784
#define NOTE_Med_LA  880
#define NOTE_Med_SI  988
#define NOTE_High_DO  1046
#define NOTE_High_RE  1175
#define NOTE_High_MI  1318
#define NOTE_High_FA  1397
#define NOTE_High_SO  1568

int speakerPin = D3;
int note[16] = {0, NOTE_Low_SO, NOTE_Low_LA, NOTE_Low_SI, NOTE_Med_DO, NOTE_Med_RE, NOTE_Med_MI, NOTE_Med_FA, NOTE_Med_SO, NOTE_Med_LA, NOTE_Med_SI, NOTE_High_DO, NOTE_High_RE, NOTE_High_MI, NOTE_High_FA, NOTE_High_SO};
unsigned char song[] = {0x82,0x01,0x81,0x94,0x84,0xB4,0xA4,0x04,0x82,0x01,0x81,0x94,0x84,0xc4,0xB4,0x04,0x82,0x01,0x81,0xF4,0xD4,0xB4,0xA4,0x94,0xE2,0x01,0xE1,0xD4,0xB4,0xC4,0xB4,0x04,0x00};
int duration = 187; // 187 milliseconds
int i, beat, temp;

void setup() {
  Serial.begin(9600);
  pinMode(speakerPin, OUTPUT);
  pinMode(BT1, INPUT);
}

void playsong()
{
    for(i=0;i<int(sizeof(song));i++)
    {
        temp = song[i];
        beat=temp & 0x0f;
        temp=(temp>>4) & 0x0f;
        tone(speakerPin, note[temp]);
        delay(duration*beat);
        noTone(speakerPin);
        Serial.println(sizeof(song));
        Serial.println(sizeof(unsigned char));
        Serial.println(i);
    }
}
void loop() {  
    int buttonState1 = digitalRead(BT1); 
    if (buttonState1 == LOW)
          playsong();
}

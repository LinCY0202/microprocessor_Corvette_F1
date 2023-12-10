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

const byte col_pin[4]={A0,A1,A2,A3};
const byte row_pin[4]={D10,D11,D12,D13};
unsigned char keypressed;
int key;
void KeyScan(){
  unsigned char col, row, i;
  unsigned char ScanLine = 0x01;
  keypressed = 0xFF;
  for(col=0;col<4;col++){
    for(i=0;i<4;i++)
      digitalWrite(col_pin[i], bitRead(~ScanLine,i));     
    for(row=0;row<4;row++){
      pinMode(row_pin[row], INPUT);
      if(digitalRead(row_pin[row])==LOW){
        delay(100);
        if(digitalRead(row_pin[row])==LOW){
          keypressed =  (col<<4) | row;  
        }
      }
    }
    ScanLine <<= 1;    
  }
}
int gotkey(){
    KeyScan();
    switch (keypressed) {
        case 0x00: return 0; break;
        case 0x10: return 1; break;
        case 0x20: return 2; break;
        case 0x30: return 3; break;
        case 0x01: return 4; break;
        case 0x11: return 5; break;
        case 0x21: return 6; break;
        case 0x31: return 7; break;
        case 0x02: return 8; break;
        case 0x12: return 9; break;
        case 0x22: return 10; break;
        case 0x32: return 11; break;
        case 0x03: return 12; break;
        case 0x13: return 13; break;
        case 0x23: return 14; break;
        case 0x33: return 15; break;
        default:   return 16; break;
    }
}
void setup() {
  Serial.begin(9600);
  pinMode(speakerPin, OUTPUT);
  for(int i=0;i<4;i++){
    pinMode(col_pin[i], OUTPUT);
    pinMode(row_pin[i], OUTPUT);
    digitalWrite(col_pin[i],HIGH);    
    digitalWrite(row_pin[i],HIGH);    
  }
}

void loop() {  
      key = gotkey();
      tone(speakerPin, note[key]);
      delay(100);
      noTone(speakerPin);
}

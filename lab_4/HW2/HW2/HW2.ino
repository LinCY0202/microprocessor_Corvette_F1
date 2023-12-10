#define LATCH_DIO D15   
#define CLK_DIO D14
#define DATA_DIO D2
const byte SEGMENT_MAP[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
const byte SEGMENT_SELECT[] = {0xFE,0xFD,0xFB,0xF7};
const byte col_pin[4]={A0,A1,A2,A3};
const byte row_pin[4]={D10,D11,D12,D13};
unsigned char keypressed;
int tame = 0;
void WriteNumberToSegment(byte Segment, byte Value)
{
  digitalWrite(LATCH_DIO,LOW);
  shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_MAP[Value % 10]);
  shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_SELECT[Segment] );
  digitalWrite(LATCH_DIO,HIGH);
  
  if(Value >= 10){
    digitalWrite(LATCH_DIO,LOW);
    shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_MAP[1]);
    shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_SELECT[Segment - 1] );
    digitalWrite(LATCH_DIO,HIGH);
  }

}
void setup() {               
  keypressed = 0;
  pinMode(LATCH_DIO,OUTPUT);
  pinMode(CLK_DIO,OUTPUT);
  pinMode(DATA_DIO,OUTPUT);
  for(int i=0;i<4;i++){
    pinMode(col_pin[i], OUTPUT);
    pinMode(row_pin[i], OUTPUT);
    digitalWrite(col_pin[i],HIGH);    
    digitalWrite(row_pin[i],HIGH);    
  }
}
int KeyScan(){
  unsigned char col, row, i;
  unsigned char ScanLine = 0x01;
  for(col=0;col<4;col++){
    for(i=0;i<4;i++)
      digitalWrite(col_pin[i], bitRead(~ScanLine,i));     
    for(row=0;row<4;row++){
      pinMode(row_pin[row], INPUT);
      if(digitalRead(row_pin[row])==LOW){
        delay(100);
        if(digitalRead(row_pin[row])==LOW){
          keypressed =  (col<<4) | row;  
          return 1;
        }
      }
    }
    ScanLine <<= 1;    
  }
  return 0;
}
void loop() {
    if(KeyScan()){
      switch (keypressed) {
        case 0x00:
            tame = 0;
            break;
        case 0x10:
            tame = 1;
            break;
        case 0x20:
            tame = 2;
            break;
        case 0x30:
            tame = 3;
            break;
        case 0x01:
            tame = 4;
            break;
        case 0x11:
            tame = 5;
            break;
        case 0x21:
            tame = 6;
            break;
        case 0x31:
            tame = 7;
            break;
        case 0x02:
            tame = 8;
            break;
        case 0x12:
            tame = 9;
            break;
        case 0x22:
            tame = 10;
            break;
        case 0x32:
            tame = 11;
            break;
        case 0x03:
            tame = 12;
            break;
        case 0x13:
            tame = 13;
            break;
        case 0x23:
            tame = 14;
            break;
        case 0x33:
            tame = 15;
            break;
    }
  }
  WriteNumberToSegment(3 , tame);
}

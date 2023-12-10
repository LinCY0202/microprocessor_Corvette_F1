#define LATCH_DIO D15   
#define CLK_DIO D14
#define DATA_DIO D2

/* Segment byte maps for numbers 0 to 9*/
const byte SEGMENT_MAP[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0X7F,0X6F};
/* Byte maps to select digit 0 to 3 */
const byte SEGMENT_SELECT[] = {0xFE,0xFD,0xFB,0xF7};

void setup() {
  pinMode(BT1, INPUT); // initialize digital pin BT1 as an input
  pinMode(BT2, INPUT); // initialize digital pin BT2 as an input
  pinMode(BT3, INPUT); // initialize digital pin BT3 as an input
  pinMode(BT4, INPUT); // initialize digital pin BT4 as an input
  pinMode(LATCH_DIO,OUTPUT);
  pinMode(CLK_DIO,OUTPUT);
  pinMode(DATA_DIO,OUTPUT);
}
int read_btn()
{
  if (digitalRead(BT1) == LOW)
    return 1;
  else if (digitalRead(BT2) == LOW)
    return 2;
  else if (digitalRead(BT3) == LOW)
    return 3;
  else if (digitalRead(BT4) == LOW)
    return 4;
  else
    return 0;
}

void WriteNumberToSegment(byte Segment, byte Value)
{
  digitalWrite(LATCH_DIO,LOW);
  shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_MAP[Value]);
  shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_SELECT[Segment] );
  digitalWrite(LATCH_DIO,HIGH);
}
void loop() {
  int delay_number = 100; // declare integer variables
  int btn_status = read_btn();
  switch (btn_status) {
    case 1:
      WriteNumberToSegment(3 , 1);
      break;
    case 2:
      WriteNumberToSegment(2 , 2);
      break;
    case 3:
      WriteNumberToSegment(1 , 3);
      break;
    case 4:
      WriteNumberToSegment(0 , 4);
      break;
    default:
      break;
  }
  delay(delay_number);
}

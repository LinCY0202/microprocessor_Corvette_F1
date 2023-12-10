/* Define shift register pins used for seven segment display */
#define LATCH_DIO D15   
#define CLK_DIO D14
#define DATA_DIO D2

/* Segment byte maps for numbers 0 to 9*/
const byte SEGMENT_MAP[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0X7F,0X6F};
/* Byte maps to select digit 0 to 3 */
const byte SEGMENT_SELECT[] = {0xFE,0xFD,0xFB,0xF7};

void WriteNumberToSegment(byte Segment, byte Value)
{
  digitalWrite(LATCH_DIO,LOW);
  shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_MAP[Value]);
  shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_SELECT[Segment] );
  digitalWrite(LATCH_DIO,HIGH);
}
void setup ()
{
  /* Set DIO pins to outputs */
  pinMode(LATCH_DIO,OUTPUT);
  pinMode(CLK_DIO,OUTPUT);
  pinMode(DATA_DIO,OUTPUT);
}
/* Main program */
void loop()
{
/* Update the display with the current counter value */
  WriteNumberToSegment(3 , 0);
  delay(1000);
  WriteNumberToSegment(2 , 0);
  delay(1000);
  WriteNumberToSegment(1 , 0);
  delay(1000);
  WriteNumberToSegment(0 , 0);
  delay(1000);
}

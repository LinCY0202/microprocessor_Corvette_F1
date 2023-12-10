char ch;
byte no;
String a;
char flag;
void setup() {                
    Serial.begin(9600);
    pinMode(BT1, INPUT);
    flag = 1;
}
void loop() 
{
  int buttonState1 = digitalRead(BT1); 
  if (buttonState1 == LOW){
    delay(500);
    if (buttonState1 == LOW){
        flag = !flag;
        if(flag)
            Serial.print("===== Number =====\n");
        else
            Serial.print("===== String =====\n");    
        }
  }
 if(flag)
  {
      if (Serial.available())
       {
            ch = Serial.read();
            if (ch >= '1' && ch <= '9')
            {
                no = ch - '0';
                Serial.print(no);
                Serial.print(" ");
                for (int i = 0; i < no; i++)
                  Serial.print("*");
                Serial.println();
            }
      }
  }
 else
  {
       if (Serial.available())
         {
              a= Serial.readString();
              Serial.println(a);
        }
  }
}

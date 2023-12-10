void DRV_Printf(const char *pFmt, int val)
{
  char Buf;
  while((Buf=*(pFmt++)))
  {
    if(Buf == '%')
    {
      switch(*(pFmt++))
      {
        case 'x':
        case 'X':
            Serial.print(val, HEX);
            break;
        case 'd':
        case 'i':
            Serial.print(val, DEC);
            break;
        case 'c':
        case 'C':
            Serial.write(val);
            break;
      }
    }
    else
      Serial.write(Buf);      
  }
}
void setup() {                
    Serial.begin(9600);
}
void loop() 
{
    DRV_Printf("Dec = %d\n",0);
    DRV_Printf("Dec = %i\n",123);
    DRV_Printf("Hex = %x\n",0);
    DRV_Printf("Hex = %X\n",0xBAA);
    DRV_Printf("Character = %c\n",'a');
    DRV_Printf("Character = %C\n",'b');
}

#include <LiquidCrystal.h>
#include <RTC.h>
#include <gotkey.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

gotkey detect;
//const byte col_pin[4]={A0,A1,A2,A3};
//const byte row_pin[4]={D10,D11,D12,D13};
//unsigned char keypressed;
const byte seconds = 30;
const byte minutes = 59;
const byte hours = 21;
unsigned char set_year, set_mon, set_day, set_hours, set_minutes;

char dayofmonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
typedef struct {
    int year;
    int month;
    int day;
} date;
date today={23,10,24},tmpday;
//void KeyScan(){
//  unsigned char col, row, i;
//  unsigned char ScanLine = 0x01;
//  keypressed = 0xFF;
//  for(col=0;col<4;col++){
//    for(i=0;i<4;i++)
//      digitalWrite(col_pin[i], bitRead(~ScanLine,i));     
//    for(row=0;row<4;row++){
//      pinMode(row_pin[row], INPUT);
//      if(digitalRead(row_pin[row])==LOW){
//        delay(100);
//        if(digitalRead(row_pin[row])==LOW){
//          keypressed =  (col<<4) | row;  
//        }
//      }
//    }
//    ScanLine <<= 1;    
//  }
//}
//int gotkey(){
//      KeyScan();
//      switch (keypressed) {
//        case 0x00: return 0; break;
//        case 0x10: return 1; break;
//        case 0x20: return 2; break;
//        case 0x30: return 3; break;
//        case 0x01: return 4; break;
//        case 0x11: return 5; break;
//        case 0x21: return 6; break;
//        case 0x31: return 7; break;
//        case 0x02: return 8; break;
//        case 0x12: return 9; break;
//        case 0x22: return 10; break;
//        case 0x32: return 11; break;
//        case 0x03: return 12; break;
//        case 0x13: return 13; break;
//        case 0x23: return 14; break;
//        case 0x33: return 15; break;
//        default:   return 16; break;
//    }
//  return 16;
//}
unsigned char monthday(unsigned char year, unsigned char month)
{
  if(month==2 && year%4==0)   //潤年的2月有29天
        return(29);
  else
    return(dayofmonth[month-1]);//非閏年時的該月份天數
}
void CountDate()
{
  unsigned char tmp_day;  
  tmp_day = monthday(today.year, today.month);
  set_day = today.day + RTC.getday();
  if(set_day > tmp_day){
    set_day = set_day - tmp_day;
    set_mon = today.month + 1;
  }
  else
    set_mon = today.month;
  if(set_mon > 12){
    set_mon = set_mon - 12;
    set_year = today.year + 1;
  }
  else
    set_year = today.year;
}
void displaycnt(unsigned char num)
{
  if(num < 10){
    lcd.print('0');
    lcd.print(num);     
  }
  else
    lcd.print(num);    
}

int getdigit(unsigned char x,unsigned char y)
{
  char  keys;
  lcd.setCursor(x,y);
  lcd.print('_');
  while((keys=detect.key())>9);
  lcd.setCursor(x,y);
  lcd.print(keys,DEC);
  return(keys);
}
int getdate()
{
  char temp,days;
  lcd.setCursor(0,0);
  lcd.print("20");
  lcd.setCursor(4,0);
  lcd.print("/");
  lcd.setCursor(7,0);
  lcd.print("/");

  temp=getdigit(2,0);
  tmpday.year=temp*10+getdigit(3,0);

  do {
      while((temp=getdigit(5,0))>1);  //月的十位數不能大於1
      temp=temp*10+getdigit(6,0);
  } while (temp > 12 || temp==0);
  tmpday.month=temp;
  do {
      while((temp=getdigit(8,0))>3);  //日的十位數不能大於3
      temp=temp*10+getdigit(9,0);
      days=monthday(tmpday.year,tmpday.month);
  } while (temp > days || temp==0);//如果輸入的日期大於該月份的日期就重新輸入
    tmpday.day=temp;
    return 1;
}
int gettime()
{
  char temp;
  lcd.setCursor(2,1);
  lcd.print(':');
  lcd.setCursor(5,1);
  lcd.print(':');
  do {
        while((temp=getdigit(0,1))>2);//時的十位數不能大於2
    temp=temp*10+getdigit(1,1);
  } while (temp > 23);
  set_hours=temp;
      while((temp=getdigit(3,1))>5);
  set_minutes=temp*10+getdigit(4,1);
  return 1;
}
void setup() {
     lcd.begin(16, 2);
     for(int i=0;i<4;i++){
        pinMode(col_pin[i], OUTPUT);
        pinMode(row_pin[i], OUTPUT);
        digitalWrite(col_pin[i],HIGH);    
        digitalWrite(row_pin[i],HIGH);    
     }
     RTC.settime(0, hours, minutes, seconds);
     RTC.startcounting();
}
void loop() {
    int temp = detect.key();
    if(temp == 15){
        if (getdate())  today=tmpday;
        if (gettime()) RTC.settime(0, set_hours, set_minutes, 0);  
    }
    else{
        CountDate();   
        lcd.clear();
        lcd.print("20");
        lcd.print(set_year);
        lcd.print("/");    
        displaycnt(set_mon);      
        lcd.print("/");
        displaycnt(set_day);        
        lcd.setCursor(0, 1);
        displaycnt(RTC.gethours());          
        lcd.print(":"); 
        displaycnt(RTC.getminutes());
        lcd.print(":");
        displaycnt(RTC.getseconds());         
        delay(1000);
    }
}

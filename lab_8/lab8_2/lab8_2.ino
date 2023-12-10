#include <LiquidCrystal.h>
#include <RTC.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

const byte seconds = 30;
const byte minutes = 24;
const byte hours = 15;
unsigned char year, mon, day;

char dayofmonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
typedef struct {
    int year;
    int month;
    int day;
} date;
date today={23,10,24};

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
  day = today.day + RTC.getday();
  if(day > tmp_day){
    day = day - tmp_day;
    mon = today.month + 1;
  }
  else
    mon = today.month;
  if(mon > 12){
    mon = mon - 12;
    year = today.year + 1;
  }
  else
    year = today.year;
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
void setup() {
     lcd.begin(16, 2);
     RTC.settime(0, hours, minutes, seconds);
     RTC.startcounting();
}

void loop() {
    CountDate();   
    lcd.clear();
    lcd.print("20");
    lcd.print(year);
    lcd.print("/");    
    displaycnt(mon);      
    lcd.print("/");
    displaycnt(day);        
    lcd.setCursor(0, 1);
    displaycnt(RTC.gethours());          
    lcd.print(":"); 
    displaycnt(RTC.getminutes());
    lcd.print(":");
    displaycnt(RTC.getseconds());         
    delay(1000);
}

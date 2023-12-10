#include <LiquidCrystal.h>
#include <FlexiTimer2.h> 
#include <gotkey.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

gotkey detect;

char dayofmonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};

typedef struct {
    int hour;
    int minute;
    int second;
} ttime;

typedef struct {
    int year;
    int month;
    int day;
} tdate;

ttime now={23,59,45},tmptime;
tdate today={16,2,28},tmpday;
unsigned char monthday(unsigned char year, unsigned char month)
{
  if(month==2 && year%4==0)   //潤年的2月有29天
        return(29);
  else
    return(dayofmonth[month-1]);//非閏年時的該月份天數
}
void timer_isr_routine() { // 計時中斷函數
  now.second++;        
  if (now.second==60) {   
    now.second=0;   
    now.minute++;   
    if (now.minute==60) { 
      now.minute=0; 
      now.hour++; 
      if (now.hour==24) { 
        now.hour=0;
        today.day++;
        if (today.day>monthday(today.year,today.month)) {
          today.day=1;    
          today.month++;                
          if(today.month==13) {
              today.month=1;
              today.year++;
          }
        }
      }
    }
  }
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
  tmptime.hour=temp;
      while((temp=getdigit(3,1))>5);
  tmptime.minute=temp*10+getdigit(4,1);
  return 1;
}
void setup() {
     lcd.begin(16, 2);
     FlexiTimer2::set(1000, timer_isr_routine); // 每1000ms產生中斷，進入中斷服務常式
     FlexiTimer2::start(); // 啟動開始計時

     for(int i=0;i<4;i++){
        pinMode(col_pin[i], OUTPUT);
        pinMode(row_pin[i], OUTPUT);
        digitalWrite(col_pin[i],HIGH);    
        digitalWrite(row_pin[i],HIGH);    
     }
}
void loop() {
    int temp = detect.key();
    if(temp == 15){
        if (getdate())  today=tmpday;
        if (gettime()) now=tmptime;
    }
    else{
        //CountDate();   
        //lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("20");
        lcd.print(today.year);
        lcd.print("/");    
        displaycnt(today.month);      
        lcd.print("/");
        displaycnt(today.day);        
        lcd.setCursor(0, 1);
        displaycnt(now.hour);          
        lcd.print(":"); 
        displaycnt(now.minute);
        lcd.print(":");
        displaycnt(now.second);         
        delay(1000);
    }
}

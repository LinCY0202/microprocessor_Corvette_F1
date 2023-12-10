//gotkey.cpp
#include "gotkey.h" 

void gotkey::KeyScan(){
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
int gotkey::key(){
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
	  return 16;
}

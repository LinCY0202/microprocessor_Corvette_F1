//gotkey.h
#include "Arduino.h"

const byte col_pin[4]={A0,A1,A2,A3};
const byte row_pin[4]={D10,D11,D12,D13};

class gotkey{
	private:
		unsigned char keypressed;
	public:
		void KeyScan();
		int key();
};

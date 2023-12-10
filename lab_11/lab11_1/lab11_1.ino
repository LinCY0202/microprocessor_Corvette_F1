#include <SoftwareSerial.h>

SoftwareSerial bluetooth(D2, D3); // 設定藍芽模組的TX腳為10，RX腳為11

void setup() {
  Serial.begin(9600);           // 用於 Arduino IDE 的序列監視器
  bluetooth.begin(9600);        // 設定藍芽模組的串口速率
}
String dataToSend = "TEST";
void loop() {
  
  // 向 HC-08 發送數據
  bluetooth.println(dataToSend);
  if (Serial.available()) {
    char data = Serial.read();
    bluetooth.write(data);  // 將資料發送到藍芽模組
  }

//  if (bluetooth.available()) {
//    int data = int(bluetooth.read());
//    if(data==99)
//      dataToSend="SUF";
//    Serial.write(data);     // 顯示藍芽模組的回應到序列監視器
//  }
//    if (bluetooth.available()) {
//    String receivedData = bluetooth.readStringUntil('\n'); // 讀取一行資料，以換行符為結尾
//    int receivedInt = receivedData.toInt(); // 將字串轉換為int型別
//    Serial.println("Received Data (int): " + String(receivedInt));
//  }
if (bluetooth.available()) {
    String receivedData = bluetooth.readStringUntil('\n'); // 讀取一行資料，以換行符為結尾
    
    // 將字串轉換為 int，如果轉換失敗，則保持原樣
    int receivedInt = receivedData.toInt();
    
    // 檢查轉換是否成功
    if (receivedInt != 0 || receivedData == "0") {
      Serial.println("Received Data (int): " + String(receivedInt));
    } else {
      Serial.println("Invalid Data Received: " + receivedData);
    }
  }
}

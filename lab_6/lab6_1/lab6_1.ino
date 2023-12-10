int num=65;
void setup() {                
  Serial.begin(9600); // 設定串列埠的鮑率為 9600 bps
}
void loop() {
  Serial.write("Serial.write!\t");  // '/t' Tab，跳格
  Serial.write(num); // 顯示字元(ASCII)
  Serial.print("\n"); 
  Serial.print("Serial.print!\t");
  Serial.print(num);
  Serial.print("\n");
  Serial.println("Serial.println!\t"); // 等同於多加Serial.print("\n");
  Serial.println(num);
  Serial.print("\n");
  Serial.print(num, HEX);
  Serial.print("\t");
  Serial.println(num, HEX);
  Serial.print("====================================\n");
  delay(500);
}

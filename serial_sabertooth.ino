#include <SoftwareSerial.h>


SoftwareSerial SabertoothSerial(10, 11);

void setup() {
  SabertoothSerial.begin(9600); 
  Serial.begin(9600);           
  Serial.println("Sabertooth 2x60 Simplified Serial Control Started");
  delay(1000);
}

void loop() {
  // ======= Move Forward =======
  Serial.println("Forward...");
  SabertoothSerial.write(64);   
  SabertoothSerial.write(192);  
  delay(2000);

  // ======= Stop =======
  Serial.println("Stop");
  SabertoothSerial.write(0);    
  delay(1000);

  // ======= Move Backward =======
  Serial.println("Backward...");
  SabertoothSerial.write(128 + 64); 
  SabertoothSerial.write(255 - 64); 
  delay(2000);

  // ======= Stop =======
  Serial.println("Stop");
  SabertoothSerial.write(0);
  delay(2000);
}

#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11); // TX, RX

void setup() {
  BTSerial.begin(38400);
  Serial.begin(9600);
}

void loop() {
  float x = analogRead(A0); // Read X axis
  float y = analogRead(A1); // Read Y axis
  // Send as comma-separated values: e.g., "512,400\n"
  float x1 =0;
  float y1 = 0;
  if (x > 526){
    x1 = 95 + ((x-526)/526)*35;
  }
  else if (x == 526){
     x1 = 95;
  }
  else if (x==0){
    x1 = 60;
  }
  else {
     x1 = 60 + (x/526)*35;
  }
  if (y == 519){
     y1 = 0;
  }
  else if (y==0){
    y1 = 200;
  }
  else if (y>519){
     y1 = -200*((y-519)/519);
  }
  else{
     y1 = 200-(y/519)*200;
  }
  int x2 = round(x1);
  int y2 = round(y1);
  BTSerial.print(x2);
  BTSerial.print(',');
  BTSerial.print(y2);
  BTSerial.print('\n');
  Serial.print(x);
  Serial.print(',');
  Serial.print(y);
  Serial.print('\n');
  //Serial.print('\n');
  //BTSerial.print('a');
  //BTSerial.print('\n');
  delay(500); // Adjust as needed
}

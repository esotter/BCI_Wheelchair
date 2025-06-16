#include <PWMServo.h>
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(11, 4); // RX, TX
#define IN1 7
#define IN2 8
#define ENA 5        //  ENA pin
String inputString = "";
 
#define FRONT 90        // steering to front 
int SHARP_RIGHT=FRONT+33;
int SHARP_LEFT=FRONT-40;

#define DELAY_TIME 1200     
#define BACK_TIME 1000  
#define SPEED 190
#define HI_SPEED 220
#define SERVO_PIN 9  //servo connect to D9
 
PWMServo head;
/*motor control*/

void setup() {
 BTSerial.begin(9600);
 pinMode(ENA, OUTPUT); 
 pinMode(IN1, OUTPUT); 
 pinMode(IN2, OUTPUT); 
 //digitalWrite(IN1, HIGH);
 //digitalWrite(IN2,LOW);
 //analogWrite(ENA,);

 head.attach(SERVO_PIN);
 head.write(95);
}

 
void loop() {
 while (BTSerial.available()){
  char c = BTSerial.read();
  if (c=='!'){
    int commaIndex = inputString.indexOf(',');
    if (commaIndex > 0 && commaIndex < inputString.length() - 1) {
    int x = inputString.substring(0,commaIndex).toInt();
    int y = inputString.substring(commaIndex+1).toInt();
    if (y>0){
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,HIGH);
      analogWrite(ENA,y);
    }
    else if (y==0){
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,LOW);
      analogWrite(ENA,0);
    }
    else{
      digitalWrite(IN1,HIGH);
      digitalWrite(IN2,LOW);
      analogWrite(ENA,-y);
    }
    head.write(x);
    }
    inputString = "";
  }
  else{
    inputString += c;
  }
 }

}

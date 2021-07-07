#include "Arduino_SensorKit.h"
#include <Servo.h> 
Servo servoLeft;
Servo servoRight; 


void setup() {
  
servoLeft.attach(12);         
servoRight.attach(11);

pinMode(6, OUTPUT);
pinMode(8, OUTPUT);
  
Serial.begin(9600);
tone(5,2000,1000);

  
Oled.begin();  
Oled.setFlipMode(true);
  
Oled.setFont(u8x8_font_chroma48medium8_r);   
Oled.setCursor(0, 33);
}

void loop() {
float leftSensor = analogRead(A2);
float rightSensor = analogRead(A3);
float nShade;
digitalWrite(8, LOW);
digitalWrite(6, LOW);
fullstop();
while (leftSensor+rightSensor > 55) {
  leftSensor = analogRead(A2);
  rightSensor = analogRead(A3);
  nShade = rightSensor/(leftSensor + rightSensor) -0.5;
  if (nShade < .03 && nShade > -.03) {
    digitalWrite(8, HIGH);
    digitalWrite(6, HIGH);
  }else {
    digitalWrite(8, LOW);
    digitalWrite(6, LOW);
  }
  forward();
  if (nShade > .03) { //right
    digitalWrite(8, HIGH);
    digitalWrite(6, LOW);
    veerright();  
    Oled.print("----->");   
  } else if (nShade < -.03) { //left
    digitalWrite(8, LOW);
    digitalWrite(6, HIGH);
    veerleft();
    Oled.print("<-----");
  }
}

Serial.print("Left = ");
Serial.print(leftSensor);
Serial.print("   nshade = ");
Serial.print(nShade);
Serial.print("    Right = ");
Serial.print(rightSensor);
Serial.println();



}

void maneuver(int speedLeft, int speedRight, int msTime) {
  servoLeft.writeMicroseconds(1500 + speedLeft); // Left servo speed 
  servoRight.writeMicroseconds(1500 - speedRight); // Right servo speed 
  if(msTime==-1) // if msTime = -1
    { 
      servoLeft.detach();
      servoRight.detach();// Stop servo signals
    }
    delay(msTime);   
}
void fullstop() {
   maneuver(0,0,0);
}

void forward() {
   maneuver(200,200,0);
}
void backward() {
  maneuver(-200,-200,0);
}
void rightrotate() {
  maneuver(200,-200,0);
}
void leftrotate() {
  maneuver(-200,200,0);
}
void pivotbackleft() {
  maneuver(0,-200,0);
}
void pivotbackright() {
  maneuver(-200,0,0);
}
void forwardslow() {
  maneuver(50,50,0);
}
void forwardmedium() {
  maneuver(100,100,0);
}
void veerright() {
  maneuver(200,50,0);
}
void veerleft() {
  maneuver(50,200,0);
}

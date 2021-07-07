
  #include <Servo.h>                      // Include servo library 
  Servo servoLeft;
  Servo servoRight; 

void setup() {
  // put your setup code here, to run once:
  tone(4, 3000, 100);
  delay(100);
  
  servoLeft.attach(12);         // Attach left signal to pin 12 
  servoRight.attach(11);        // Attach right signal to pin 11    
  forward();
  delay(3000);

  fullstop();
}

void loop() {
  // put your main code here, to run repeatedly:

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

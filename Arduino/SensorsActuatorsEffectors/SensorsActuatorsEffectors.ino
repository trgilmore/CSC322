
  #include <Servo.h> 
  Servo servoLeft;
  Servo servoRight; 

void setup() {
  servoLeft.attach(12);         // Attach left signal to pin 12 
  servoRight.attach(11);        // Attach right signal to pin 11 
  pinMode(13, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(5, INPUT); // left whisker
  pinMode(7, INPUT); // right whisker

  Serial.begin(9600);
}

void loop() {
  byte left = digitalRead(5);
  byte right = digitalRead(7);

    // -- decide how to act
  if (left == 1 && right == 1) {
    // -- neither is touching
    forward();
    digitalWrite(13, LOW);      // Pin 13 = 5 V, LED emits light    
    digitalWrite(10, LOW);      // Pin 12 = 5 V, LED emits light       
  }
  else if (left == 0 && right == 1) {
    // -- left touch, right not    
    leftrotate();
    tone(2,1046,300);    
    digitalWrite(10, HIGH);      // Pin 12 = 5 V, LED emits light
  }
  else if (left == 1 && right == 0) {
    // -- left not, right touch
    rightrotate();
    tone(2,2093,300);
    digitalWrite(13, HIGH);      // Pin 13 = 5 V, LED emits light    
  }
  else if (left == 0 && right == 0) {
    // -- left touch, right touch
    fullstop();
    tone(2,4186,300);
    digitalWrite(13, HIGH);      // Pin 13 = 5 V, LED emits light    
    digitalWrite(10, HIGH);      // Pin 12 = 5 V, LED emits light 
  }

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

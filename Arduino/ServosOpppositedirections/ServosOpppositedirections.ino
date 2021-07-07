  #include <Servo.h>                      // Include servo library 
  Servo servoLeft;
  Servo servoRight;             // Declare right servo

void setup() {
  // put your setup code here, to run once:
   servoLeft.attach(12);         // Attach left signal to pin 13 
   servoRight.attach(11);        // Attach right signal to pin 12    
   servoLeft.writeMicroseconds(1500);     
   servoRight.writeMicroseconds(1500);
  
}
void loop() {
  // put your main code here, to run repeatedly:

}

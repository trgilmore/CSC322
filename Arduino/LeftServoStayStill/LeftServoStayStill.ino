  #include <Servo.h>                      // Include servo library 
  Servo servoLeft;

void setup() {
  // put your setup code here, to run once:
   servoLeft.attach(13);                 // Attach left signal to pin 13    
   servoLeft.writeMicroseconds(1500);    // 1.5 ms stay still signal
}

void loop() {
  // put your main code here, to run repeatedly:

}

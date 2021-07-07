void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
tone(5, 2000, 1000);
pinMode(6, OUTPUT);
pinMode(8, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(6, HIGH);
digitalWrite(8, HIGH);
delay(500);
digitalWrite(6, LOW);
digitalWrite(8, LOW);
delay(500);
}

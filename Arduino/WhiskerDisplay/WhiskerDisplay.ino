void setup() {
  // put your setup code here, to run once:
  
  pinMode(7, INPUT);
  pinMode(5, INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  byte wLeft = digitalRead(5);
  byte wRight = digitalRead(7);

  Serial.print(wLeft);
  Serial.println(wRight);
  if (wLeft == 0) 
  {
    tone(4,3000,300);
  }
  if (wRight == 0)
  {
    tone(4,2000,300);
  }
  delay(300);
}

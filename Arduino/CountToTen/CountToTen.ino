void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  for(int i = 1; i <= 10; i++)
  {
    Serial.println(i);
    delay(500);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}

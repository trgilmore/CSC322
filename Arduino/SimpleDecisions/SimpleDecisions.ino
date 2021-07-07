void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  int a = 89;
  int b = 42;

  if (a > b)
  {
    Serial.print("a is greater than b");
  }
  else
  {
    Serial.print("a is not greater than b");
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}

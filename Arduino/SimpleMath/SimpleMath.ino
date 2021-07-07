void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  int a = 89;
  int b = 42;
  int c = a + b;

  Serial.print("a + b = ");
  Serial.println(c);
}

void loop() {
  // put your main code here, to run repeatedly:

}

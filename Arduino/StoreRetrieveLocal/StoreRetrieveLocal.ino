  int a;
  char c;
  float root2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  a = 42;
  c = 'm';
  root2 = sqrt(2.0);


}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(a);
  Serial.println(c);
  Serial.println(root2);
  delay(1000);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  float r = 0.75;
  float c = 2.0 * PI * r;

  Serial.print("circumference = ");
  Serial.println(c);
}

void loop() {
  // put your main code here, to run repeatedly:

}

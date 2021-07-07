  double a;
  double b;
  double c;
  const double ZERO = .00000001;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  double x1;
  double x2;
  a=1;
  b=2;
  c=3;
  double discrim = b * b - 4 * a * c;
  if (discrim < 0) {
    Serial.println("No real solutions");
  }
  else if ((fabs(a) < ZERO) && fabs(b < ZERO)) {
    Serial.println("No real solutions");
  }
  else if (fabs(a) < ZERO) {
    x1 = -c / b;
    Serial.print("X = ");
    Serial.print(x1);
  }
  else if (fabs(discrim) < ZERO) {
    x1 = -b / (2 * a);
    Serial.print("X = ");
    Serial.print(x1);
  }
  else {
    x1 = (-b + sqrt(discrim))/ 2 * a;
    x2 = (-b - sqrt(discrim))/ 2 * a;
    Serial.print("X = (");
    Serial.print(x1);
    Serial.print(", ");
    Serial.print(x2);
    Serial.print(")");
  }
}
void loop() {
  // put your main code here, to run repeatedly:

}

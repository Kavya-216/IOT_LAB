const int motorPin1 = 9;
const int motorPin2 = 2;

void setup()
{
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
}

void loop()
{
 
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  delay(10000);

  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  delay(10000);

  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  delay(10000);

  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  delay(10000);
}
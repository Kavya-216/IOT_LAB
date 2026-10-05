const int LDR_PIN = A0;
const int LED_PIN = 7;

void setup()
{
  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  int LDR_DISP = analogRead(LDR_PIN);

  Serial.println(LDR_DISP);

  if (LDR_DISP > 500)
  {
    digitalWrite(LED_PIN, HIGH);
  }
  else
  {
    digitalWrite(LED_PIN, LOW);
  }

  delay(100);
}
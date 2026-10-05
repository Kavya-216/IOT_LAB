#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int smokeSensor = A0;
int threshold = 65;

void setup()
{
  Serial.begin(9600);

  lcd.begin(16, 2);

  lcd.setCursor(0, 0);
  lcd.print("SMOKE DETECTOR");

  lcd.setCursor(0, 1);
  lcd.print("Initializing...");

  delay(5000);

  lcd.clear();
}

void loop()
{
  int smokeValue = analogRead(smokeSensor);

  Serial.println(smokeValue);

  lcd.setCursor(0, 0);
  lcd.print("Smoke: ");
  lcd.print(smokeValue);
  lcd.print("   ");

  lcd.setCursor(0, 1);

  if (smokeValue >= threshold)
  {
    lcd.print("SMOKE DETECTED!");
  }
  else
  {
    lcd.print("NO SMOKE    ");
  }

  delay(500);
}
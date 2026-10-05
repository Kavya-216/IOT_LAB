#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define PH_SENSOR A0

void setup()
{
  Serial.begin(9600);

  lcd.begin(16, 2);

  lcd.setCursor(0, 0);
  lcd.print("pH Sensor");
  delay(2000);
  lcd.clear();
}

void loop()
{
  int sensorValue = analogRead(PH_SENSOR);
  float voltage = sensorValue * (5.0 / 1023.0);


  float pH = 7.0 + ((2.5 - voltage) / 0.18);

  lcd.setCursor(0, 0);
  lcd.print("pH Value:");

  lcd.setCursor(0, 1);
  lcd.print(pH, 2);
  lcd.print("       ");

  Serial.print("ADC: ");
  Serial.print(sensorValue);
  Serial.print("  Voltage: ");
  Serial.print(voltage, 2);
  Serial.print(" V  pH: ");
  Serial.println(pH, 2);

  delay(1000);
}
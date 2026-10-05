#define TRIG_PIN 9
#define ECHO_PIN 10
#define BUZZER_PIN 8

float tankDepth = 6;   

void setup() {

  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(BUZZER_PIN, LOW);
}

void loop() {

  long duration;
  float distance;
  float waterLevel;
  float percentage;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

 
  duration = pulseIn(ECHO_PIN, HIGH);


  distance = duration * 0.0343 / 2;

  waterLevel = tankDepth - distance;

  if (waterLevel < 0)
    waterLevel = 0;

  if (waterLevel > tankDepth)
    waterLevel = tankDepth;

  percentage = (waterLevel / tankDepth) * 100;


  Serial.print("Distance from sensor: ");
  Serial.print(distance);
  Serial.println(" cm");

  Serial.print("Water Level: ");
  Serial.print(waterLevel);
  Serial.println(" cm");

  Serial.print("Water Level Percentage: ");
  Serial.print(percentage);
  Serial.println("%");

  if (percentage >= 90) {

    Serial.println("Alert: Tank Almost FULL!");

    digitalWrite(BUZZER_PIN, HIGH);
  }

  else if (percentage <= 20) {

    Serial.println("Alert: Water Level LOW!");

    digitalWrite(BUZZER_PIN, HIGH);
    delay(300);

    digitalWrite(BUZZER_PIN, LOW);
    delay(300);
  }

  else {

    Serial.println("Water Level NORMAL");

    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(1000);
}
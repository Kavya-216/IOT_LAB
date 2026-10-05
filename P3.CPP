int ULTR_VAL = 0;

long readUltrasonicDistance(int triggerPin , int echoPin)
{
  pinMode(triggerPin , OUTPUT);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin , LOW);
  pinMode(echoPin , INPUT);

  return pulseIn(echoPin , HIGH);
}
void setup()
{
  Serial.begin(9600); 
  pinMode(13 , OUTPUT);
}
void loop() 
{
  ULTR_VAL = 0.01723 *  readUltrasonicDistance(7,8);

  Serial.println(ULTR_VAL);

  if(ULTR_VAL < 20){
    tone(13,523,1000);
  }else{
    noTone(13);
  }
  delay(10);
}
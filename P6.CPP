void setup() {

  pinMode(A0,INPUT);
  Serial.begin(9600);
  pinMode(7,OUTPUT);

}

void loop() {
  int MOIS_LEV=analogRead(A0);
  Serial.println(MOIS_LEV);
  if(MOIS_LEV<15){
    digitalWrite(7,HIGH);
  }
  else{
    digitalWrite(7,LOW);
  }
  delay(10);
}
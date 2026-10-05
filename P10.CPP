void setup() {
  Serial.begin(9600);
  Serial.println("Arduino Ready");
}

void loop() {
  String message = "Hello from Arduino";

  Serial.print("Message: ");
  Serial.println(message);

  delay(1000);
}
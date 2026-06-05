const int ldrPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int rawValue = analogRead(ldrPin);

  float voltage = rawValue * (5.0 / 1023.0);

  Serial.print("Raw: ");
  Serial.print(rawValue);

  Serial.print("  Voltage: ");
  Serial.println(voltage);

  delay(200);
}

const int SOIL_PIN = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int soilRaw = analogRead(SOIL_PIN);

  Serial.print("ADC = ");
  Serial.println(soilRaw);

  delay(1000);
}

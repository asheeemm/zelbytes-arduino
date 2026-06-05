const int ldrPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {

  long total = 0;

  for(int i = 0; i < 8; i++) {
    total += analogRead(ldrPin);
    delay(5);
  }

  int average = total / 8;

  Serial.println(average);

  delay(1000);
}

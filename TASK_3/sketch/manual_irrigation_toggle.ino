const int BUTTON_PIN = 2;
const int LED_PIN = 7;
const int RELAY_PIN = 8;

bool estop = false;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);
  digitalWrite(RELAY_PIN, HIGH);

  Serial.begin(9600);

  Serial.println("Manual Irrigation Controller Ready");
}

void loop() {

  if (Serial.available()) {
  char c = Serial.read();

  if (c == 'e') {
    estop = true;
    digitalWrite(LED_PIN, LOW);
    digitalWrite(RELAY_PIN, HIGH);
    Serial.println("ESTOP ACTIVATED");
  }

  if (c == 'r') {
    estop = false;
    Serial.println("ESTOP CLEARED");
  }
}

  if (estop) {
    return;
  }

  bool buttonPressed =
      digitalRead(BUTTON_PIN) == LOW;

  if (buttonPressed) {

    digitalWrite(LED_PIN, HIGH);

    digitalWrite(RELAY_PIN, LOW);

    Serial.print("Valve OPEN at ");
    Serial.print(millis());
    Serial.println(" ms");

  } else {

    digitalWrite(LED_PIN, LOW);

    digitalWrite(RELAY_PIN, HIGH);

    Serial.print("Valve CLOSED at ");
    Serial.print(millis());
    Serial.println(" ms");
  }

  delay(2000);
}

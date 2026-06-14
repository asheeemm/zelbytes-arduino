const int ENA = 9;
const int IN1 = 10;
const int IN2 = 11;
const int RELAY_PIN = 6;
const int LED_PIN = 13;
const int ESTOP_PIN = 2;

volatile bool emergencyStop = false;

unsigned long previousMillis = 0;
bool ledState = LOW;
int currentPWM = 0;
bool messagePrinted = false;

// Interrupt Service Routine
void emergencyISR() {
  emergencyStop = true;
}

void setup() {
  Serial.begin(9600);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(ESTOP_PIN, INPUT_PULLUP);

  // Set motor direction
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Valve initially closed
  digitalWrite(RELAY_PIN, LOW);

  attachInterrupt(digitalPinToInterrupt(ESTOP_PIN), emergencyISR, FALLING);

  Serial.println("System Ready");
  Serial.println("Commands:");
  Serial.println("1-9 : Motor speed");
  Serial.println("0   : Motor OFF");
  Serial.println("o   : Valve OPEN");
  Serial.println("f   : Valve CLOSE");
  Serial.println("r   : Reset after Emergency Stop");
}

void loop() {

  // Handle Emergency Stop
  if (emergencyStop) {

    analogWrite(ENA, 0);          // Stop motor
    currentPWM = 0;

    digitalWrite(RELAY_PIN, LOW); // Close valve
    digitalWrite(LED_PIN, LOW);   // Turn off LED

    // REMOVED: analogWrite(ENA, 255);

    if (!messagePrinted) {
      Serial.println("EMERGENCY STOP ACTIVATED");
      Serial.println("Send 'r' to reset system");
      messagePrinted = true;
    }

    if (Serial.available()) {
      char cmd = Serial.read();

      if (cmd == 'r') {
        emergencyStop = false;
        messagePrinted = false;
        Serial.println("SYSTEM RESET");
      }
    }

    return;
  }

  // Blink LED while motor is running
  if (currentPWM > 0) {
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= 500) {
      previousMillis = currentMillis;
      ledState = !ledState;
      digitalWrite(LED_PIN, ledState);
    }
  }
  else {
    digitalWrite(LED_PIN, LOW);
  }

  // Read Serial Commands
  if (Serial.available()) {

    char cmd = Serial.read();

    // Motor Speed Control
    if (cmd >= '1' && cmd <= '9') {

      // FIXED map() syntax
      currentPWM = map(cmd - '0', 1, 9, 80, 255);

      analogWrite(ENA, currentPWM);

      Serial.print("Motor PWM = ");
      Serial.println(currentPWM);
    }

    // Motor OFF
    else if (cmd == '0') {

      currentPWM = 0;
      analogWrite(ENA, 0);
      digitalWrite(LED_PIN, LOW);

      Serial.println("Motor OFF");
    }

    // Valve ON
    else if (cmd == 'o') {

      digitalWrite(RELAY_PIN, HIGH);
      Serial.println("Valve OPEN");
    }

    // Valve OFF
    else if (cmd == 'f') {

      digitalWrite(RELAY_PIN, LOW);
      Serial.println("Valve CLOSED");
    }
  }
}

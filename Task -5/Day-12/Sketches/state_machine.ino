#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

#define SOIL_PIN A0
#define RELAY_PIN 8

#define LED_PIN 13

DHT dht(DHTPIN, DHTTYPE);

enum State {
  IDLE,
  IRRIGATING,
  COOLDOWN,
  FAULT
};

State currentState = IDLE;

const int soilThreshold = 400;

const unsigned long irrigationTime = 5000; // 5 seconds
const unsigned long cooldownTime = 10000;  // 10 seconds

unsigned long stateStartTime = 0;

int dhtFailCount = 0;

void setup() {
  Serial.begin(9600);

  pinMode(RELAY_PIN, OUTPUT);

  // Valve closed initially
  digitalWrite(RELAY_PIN, LOW);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  dht.begin();

  Serial.println("System Started");
  Serial.println("STATE -> IDLE");
}

void loop() {

  float humidity = dht.readHumidity();

  // Check DHT status
  if (isnan(humidity)) {

    dhtFailCount++;

    Serial.print("DHT Error Count: ");
    Serial.println(dhtFailCount);

    if (dhtFailCount >= 3) {
      currentState = FAULT;
      Serial.println("STATE -> FAULT");
    }

  } else {
    dhtFailCount = 0;
  }

  int soilValue = analogRead(SOIL_PIN);

  Serial.print("Soil Moisture: ");
  Serial.println(soilValue);

  switch (currentState) {

    case IDLE:

      // Valve Closed
      digitalWrite(RELAY_PIN, LOW);
      digitalWrite(LED_PIN, LOW);

      if (soilValue < soilThreshold && dhtFailCount == 0) {

        currentState = IRRIGATING;
        stateStartTime = millis();

        Serial.println("Dry Soil Detected");
        Serial.println("STATE -> IRRIGATING");

        // Valve Open
        digitalWrite(RELAY_PIN, HIGH);
      }

      break;

    case IRRIGATING:

      // Valve Open
      digitalWrite(RELAY_PIN, HIGH);
      digitalWrite(LED_PIN, HIGH);

      if (millis() - stateStartTime >= irrigationTime) {

        // Valve Closed
        digitalWrite(RELAY_PIN, LOW);

        currentState = COOLDOWN;
        stateStartTime = millis();

        Serial.println("Watering Complete");
        Serial.println("STATE -> COOLDOWN");
      }

      break;

    case COOLDOWN:

      // Valve Closed
      digitalWrite(RELAY_PIN, LOW);
      digitalWrite(LED_PIN, LOW);

      if (millis() - stateStartTime >= cooldownTime) {

        currentState = IDLE;

        Serial.println("Cooldown Complete");
        Serial.println("STATE -> IDLE");
      }

      break;

    case FAULT:

      // Valve Closed
      digitalWrite(RELAY_PIN, LOW);

      digitalWrite(LED_PIN, HIGH);
      delay(250);
      digitalWrite(LED_PIN, LOW);
      delay(250);

      Serial.println("FAULT: DHT Sensor Failure");
      delay(2000);

      break;
  }

  delay(500);
}

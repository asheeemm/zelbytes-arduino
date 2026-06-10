#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

#define LDR_PIN A0
#define SOIL_PIN A1

#define TRIG_PIN 9
#define ECHO_PIN 10

DHT dht(DHTPIN, DHTTYPE);

// Sensor values
int lightRaw = 0;
float temperature = NAN;
float humidity = NAN;
float distanceCm = NAN;
int soilRaw = 0;
int soilPct = 0;

// Timers
unsigned long lastLdrRead = 0;
unsigned long lastDhtRead = 0;
unsigned long lastUltraRead = 0;
unsigned long lastSoilRead = 0;
unsigned long lastPrint = 0;

// Intervals (ms)
const unsigned long LDR_INTERVAL = 500;
const unsigned long DHT_INTERVAL = 2000;
const unsigned long ULTRA_INTERVAL = 500;
const unsigned long SOIL_INTERVAL = 1000;
const unsigned long PRINT_INTERVAL = 1000;

float readUltrasonic()
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  if (duration == 0)
  {
    return -1;
  }

  return duration * 0.0343 / 2.0;
}

void setup()
{
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  dht.begin();

  Serial.println("time_ms,light_raw,temp,hum,distance_cm,soil_pct");
}

void loop()
{
  unsigned long currentMillis = millis();

  // LDR
  if (currentMillis - lastLdrRead >= LDR_INTERVAL)
  {
    lastLdrRead = currentMillis;
    lightRaw = analogRead(LDR_PIN);
  }

  // DHT22
  if (currentMillis - lastDhtRead >= DHT_INTERVAL)
  {
    lastDhtRead = currentMillis;

    float h = dht.readHumidity();
    float t = dht.readTemperature();

    if (!isnan(h))
      humidity = h;

    if (!isnan(t))
      temperature = t;
  }

  // Ultrasonic
  if (currentMillis - lastUltraRead >= ULTRA_INTERVAL)
  {
    lastUltraRead = currentMillis;

    float d = readUltrasonic();

    if (d >= 0)
      distanceCm = d;
  }

  // Soil Moisture
  if (currentMillis - lastSoilRead >= SOIL_INTERVAL)
  {
    lastSoilRead = currentMillis;

    soilRaw = analogRead(SOIL_PIN);

    // Adjust these values after calibration
    soilPct = map(soilRaw, 1023, 300, 0, 100);

    if (soilPct < 0)
      soilPct = 0;

    if (soilPct > 100)
      soilPct = 100;
  }

  // CSV Output
  if (currentMillis - lastPrint >= PRINT_INTERVAL)
  {
    lastPrint = currentMillis;

    Serial.print(currentMillis);
    Serial.print(",");

    Serial.print(lightRaw);
    Serial.print(",");

    Serial.print(temperature, 1);
    Serial.print(",");

    Serial.print(humidity, 1);
    Serial.print(",");

    Serial.print(distanceCm, 1);
    Serial.print(",");

    Serial.println(soilPct);
  }
}

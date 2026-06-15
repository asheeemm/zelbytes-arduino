#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

#define SOIL_PIN A0
#define LIGHT_PIN A1

DHT dht(DHTPIN, DHTTYPE);

// Log every 30 seconds (30000 ms)
// 30 minutes = about 60 rows
const unsigned long LOG_INTERVAL = 30000;

unsigned long previousMillis = 0;

void setup()
{
  Serial.begin(9600);

  dht.begin();

  // CSV Header
  Serial.println("timestamp,temp,humidity,soil,light");
}

void loop()
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= LOG_INTERVAL)
  {
    previousMillis = currentMillis;

    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    int soil = analogRead(SOIL_PIN);
    int light = analogRead(LIGHT_PIN);

    // Skip if DHT reading failed
    if (isnan(temperature) || isnan(humidity))
    {
      Serial.println("DHT Error");
      return;
    }

    // CSV row
    Serial.print(currentMillis);
    Serial.print(",");

    Serial.print(temperature);
    Serial.print(",");

    Serial.print(humidity);
    Serial.print(",");

    Serial.print(soil);
    Serial.print(",");

    Serial.println(light);
  }
}

#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);
  dht.begin();

  Serial.println("millis,temp,humidity");
}

void loop()
{
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (!isnan(humidity) && !isnan(temperature))
  {
    Serial.print(millis());
    Serial.print(",");

    Serial.print(temperature);
    Serial.print(",");

    Serial.println(humidity);
  }

  delay(2000);
}

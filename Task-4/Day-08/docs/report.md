Objective
To interface a DHT22/AM2301 sensor with an Arduino Uno, measure ambient temperature and relative humidity, and log the readings through the Serial Monitor in both human-readable and CSV formats.

Part A: Basic Temperature & Humidity Reading
Temperature: 33.30 °C  Humidity: 94.10 %
Temperature: 33.30 °C  Humidity: 93.70 %
Temperature: 33.30 °C  Humidity: 93.20 %

Observations
Temperature remained nearly constant.
Humidity varied slightly with room conditions.
Sensor readings updated every 2 seconds.
No communication errors were observed.

Part B: CSV Data Logging
millis,temp,humidity
2008,33.20,92.40
4048,33.30,93.40
6051,33.30,97.40
8054,33.30,97.20

Observations
Data was generated at approximately 2-second intervals.
CSV format enables direct copying into spreadsheets.
Temperature remained around 33.30°C.
Breathing on the sensor increases humidity.

Result
The DHT22 sensor was successfully interfaced with the Arduino and produced stable temperature and humidity readings.

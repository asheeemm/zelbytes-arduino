# Zelbytes Arduino Foundations

## Task 7 - CSV Data Logging

### Objective

Read temperature, humidity, soil moisture, and light sensor values and log them in CSV format through the Serial Monitor.

### Components Used

* Arduino Uno
* DHT11 Sensor
* Soil Moisture Sensor
* LDR
* 10kΩ Resistor
* Breadboard
* Jumper Wires

### Connections

* DHT11 DATA → D2
* Soil Moisture AO → A0
* LDR Output → A1
* VCC → 5V
* GND → GND

### Working

The Arduino reads all sensors at a fixed logging interval and prints the readings as comma-separated values (CSV) to the Serial Monitor. The output can be saved as a CSV file for later analysis.

### Output Format

```csv
timestamp,temp,humidity,soil,light
0,29.1,68,520,410
20000,29.2,68,519,412
40000,29.3,69,518,411
```

```

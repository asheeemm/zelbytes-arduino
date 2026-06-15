# Hardware Documentation

## Board

* Arduino Uno

## Components Used

* Soil Moisture Sensor
* DHT11 Temperature & Humidity Sensor
* Relay Module (5V)
* 12V Solenoid Valve
* LED
* 220Ω Resistor
* Breadboard
* Jumper Wires
* 12V Power Supply

## Pin Connections

| Component                 | Arduino Pin |
| ------------------------- | ----------- |
| Soil Moisture Sensor (AO) | A0          |
| DHT11 DATA                | D2          |
| Relay Module IN           | D8          |
| LED                       | D13         |

## Power Connections

* Soil Moisture Sensor VCC → 5V
* Soil Moisture Sensor GND → GND
* DHT11 VCC → 5V
* DHT11 GND → GND
* Relay Module VCC → 5V
* Relay Module GND → GND

## Solenoid Valve Connection

* 12V (+) → Relay COM
* Relay NO → Solenoid Valve (+)
* Solenoid Valve (-) → 12V (−)

## Working

The Arduino continuously monitors the soil moisture sensor. When the soil becomes dry, the relay is activated to open the solenoid valve and start irrigation. After the irrigation period, the valve is turned off and the system enters a cooldown state. If the DHT11 sensor fails three consecutive times, the system enters the FAULT state and irrigation is disabled.

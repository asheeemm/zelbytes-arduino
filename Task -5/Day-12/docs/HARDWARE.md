# Hardware Documentation

## Project
Automatic Irrigation System using State Machine

## Components Used

| Component | Quantity | Purpose |
|------------|------------|------------|
| Arduino Uno | 1 | Main controller |
| Soil Moisture Sensor | 1 | Detect soil moisture level |
| DHT11 Sensor | 1 | Humidity sensing and fault monitoring |
| Single Channel Relay Module | 1 | Controls solenoid valve |
| Solenoid Valve / Water Pump | 1 | Irrigation actuator |
| LED | 1 | Status indication |
| Breadboard | 1 | Circuit prototyping |
| Jumper Wires | Several | Electrical connections |
| USB Cable | 1 | Programming and power |

## Pin Connections

| Arduino Pin | Connected Device |
|-------------|------------------|
| A0 | Soil Moisture Sensor (AO) |
| D2 | DHT11 Data Pin |
| D9 | Relay IN |
| D13 | Status LED |
| 5V | Sensor VCC, Relay VCC |
| GND | Common Ground |

## State Indications

| State | Relay | LED |
|---------|---------|---------|
| IDLE | OFF | OFF |
| IRRIGATING | ON | ON |
| COOLDOWN | OFF | OFF |
| FAULT | OFF | Blinking |

## Moisture Threshold

- Soil Threshold: 400
- Irrigation starts when soil value exceeds the threshold.
- Threshold should be calibrated according to the sensor and soil type.

## Timing Parameters

- Irrigation Time: 5 seconds
- Cooldown Time: 10 seconds
- Maximum DHT Failures: 3 consecutive failures

## Fault Protection

The system continuously monitors the DHT11 sensor. If three consecutive humidity readings fail, the controller enters the FAULT state. In this state:

- Relay is disabled.
- Irrigation is stopped.
- LED blinks to indicate an error.
- Manual intervention or reset is required.

## Wiring Summary

Soil Moisture Sensor:
- VCC → 5V
- GND → GND
- AO → A0

DHT11:
- VCC → 5V
- GND → GND
- DATA → D2

Relay Module:
- VCC → 5V
- GND → GND
- IN → D9

LED:
- Anode (+) → D13 through 220Ω resistor
- Cathode (-) → GND

## Safety Notes

- Perform testing under supervision.
- Keep electronics away from water exposure.
- Verify relay wiring before connecting a pump or valve.
- Ensure a stable 5V supply for sensors and relay.
- Do not leave the irrigation system unattended during testing.

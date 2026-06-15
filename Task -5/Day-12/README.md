## Task 5 - Threshold Logic & State Machine

### Components Used
- Arduino Uno
- Soil Moisture Sensor
- DHT11 Sensor
- Relay Module
- 12V Solenoid Valve
- LED
- Breadboard
- Jumper Wires

### Description
Implemented an automatic irrigation system using a state machine with four states: **IDLE**, **IRRIGATING**, **COOLDOWN**, and **FAULT**. The system monitors soil moisture, controls a solenoid valve through a relay, and uses the DHT11 sensor for fault detection. An LED indicates the irrigation status, and the Serial Monitor displays state transitions during operation.

### Test
Verified one complete cycle:
- IDLE → IRRIGATING → COOLDOWN → IDLE

Also verified the FAULT state when the DHT11 sensor failed three consecutive times.

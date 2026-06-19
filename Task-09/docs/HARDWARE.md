# Hardware – Automated Grow Bench (ESP32)

## Overview

The Automated Grow Bench is an ESP32-based smart irrigation system that continuously monitors soil moisture, temperature, and humidity. Based on soil conditions, the system automatically controls a solenoid valve through a relay module to provide irrigation when required. Sensor data is transmitted to the Zelbytes IoT Lab cloud platform and visualized through a custom real-time dashboard.

---

## Main Components

* ESP32 Development Board
* Resistive Soil Moisture Sensor
* DHT11 Temperature and Humidity Sensor
* Relay Module
* Solenoid Valve
* Push Button
* Zelbytes IoT Lab Cloud Platform
* Custom HTML/CSS/JavaScript Dashboard

---

## Sensor Connections

### Soil Moisture Sensor

| Sensor Pin | ESP32 Pin |
| ---------- | --------- |
| VCC        | 3.3V      |
| GND        | GND       |
| AO         | GPIO34    |

### DHT11 Sensor

| DHT11 Pin | ESP32 Pin |
| --------- | --------- |
| VCC       | 3.3V      |
| GND       | GND       |
| DATA      | GPIO4     |

### Relay Module

| Relay Pin | ESP32 Pin |
| --------- | --------- |
| IN        | GPIO26    |
| VCC       | 5V        |
| GND       | GND       |

### Push Button

| Button Pin | ESP32 Pin |
| ---------- | --------- |
| Terminal 1 | GPIO27    |
| Terminal 2 | GND       |

---

## Working Principle

1. The soil moisture sensor provides analog readings to the ESP32.
2. The DHT11 sensor measures ambient temperature and humidity.
3. The ESP32 compares soil moisture values with predefined thresholds.
4. When the soil becomes dry, the relay activates the solenoid valve and irrigation starts.
5. When sufficient moisture is detected, the relay deactivates the valve and irrigation stops.
6. Users can override automatic operation using the push button or serial commands.
7. Sensor data is periodically uploaded to the Zelbytes IoT Lab cloud using HTTPS.
8. A custom web dashboard retrieves the latest telemetry and displays real-time values and graphs.

---

## Soil Moisture Calibration

The resistive soil moisture sensor was experimentally calibrated using measured values.

| Condition               | Sensor Reading |
| ----------------------- | -------------- |
| Air (Very Dry)          | 4000+          |
| Moist Surface Contact   | ~3200          |
| Fully Immersed in Water | 2000+          |

### Threshold Values

```text
DRY_THRESHOLD = 3500
WET_THRESHOLD = 2500
```

### Irrigation Logic

```text
If Soil Value > 3500
→ Soil is Dry
→ Valve ON

If Soil Value < 2500
→ Soil is Wet
→ Valve OFF

If Soil Value is between 2500 and 3500
→ Maintain Previous State
```

---

## Moisture Percentage Calculation

For cloud visualization and dashboard monitoring, the raw sensor value is converted into a moisture percentage.

```cpp
soilPercent = map(soilRaw, 4000, 2000, 0, 100);
soilPercent = constrain(soilPercent, 0, 100);
```

### Example Values

| Raw Value | Moisture Percentage |
| --------- | ------------------- |
| 4000      | 0%                  |
| 3500      | 25%                 |
| 3000      | 50%                 |
| 2500      | 75%                 |
| 2000      | 100%                |

---

## Cloud Telemetry

The ESP32 uploads telemetry to Zelbytes IoT Lab every 5 seconds.

### Parameters Sent

* temperature_c
* humidity_pct
* soil_moisture_pct
* pump_state
* mode

Example:

```json
{
  "device_id": "esp32_irrigation",
  "temperature_c": 34.6,
  "humidity_pct": 68.6,
  "soil_moisture_pct": 75,
  "pump_state": 1,
  "mode": "AUTO"
}
```

---

## Dashboard Features

The custom dashboard provides:

* Real-Time Temperature Monitoring
* Real-Time Humidity Monitoring
* Real-Time Soil Moisture Monitoring
* Live Graphs for All Parameters
* Pump Status Indicator
* AUTO / MANUAL Mode Indicator
* Automatic Refresh Every 5 Seconds
* Zelbytes IoT Cloud Integration

---

## Manual Control

### Push Button

* Toggle between AUTO and MANUAL mode.

### Serial Commands

```text
ON      → Manual Mode, Pump ON
OFF     → Manual Mode, Pump OFF
AUTO    → Automatic Mode Enabled
STATUS  → Display System Status
```

---

## Applications

* Smart Irrigation Systems
* Polyhouse Monitoring
* Greenhouse Automation
* Home Gardening
* Precision Agriculture
* IoT-Based Environmental Monitoring

```
```

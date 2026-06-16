# Task 5 – Threshold Logic & State Machine

## Objective

Implement an irrigation state machine using soil moisture and humidity thresholds. The system automatically controls irrigation based on sensor readings while ensuring safety through cooldown periods, runtime limits, and fault detection.

---

## Components Used

- Arduino Uno
- Soil Moisture Sensor
- DHT22 Sensor
- Relay Module
- LED
- Jumper Wires
- Breadboard

---

## State Machine States

### IDLE
Initial startup state. The valve remains OFF and the system prepares for monitoring.

### MONITORING
Continuously reads soil moisture and humidity values and checks whether irrigation is required.

### IRRIGATING
The relay activates irrigation when soil moisture falls below the minimum threshold and humidity conditions are satisfied.

### COOLDOWN
The valve remains OFF for a fixed time after irrigation to prevent immediate re-triggering.

### FAULT
The system enters FAULT state when the DHT sensor fails three consecutive readings. The valve is turned OFF and the LED blinks.

---

## Threshold Values

| Parameter | Value |
|-----------|--------|
| SOIL_MIN | 25% |
| SOIL_TARGET | 40% |
| HUMIDITY_MAX | 85% |
| LOW_COUNT_REQ | 3 |
| MAX_RUN_TIME | 10000 ms |
| COOLDOWN_TIME | 5000 ms |

---

## Hysteresis Logic

Irrigation starts when soil moisture falls below 25%.

Irrigation stops when soil moisture reaches 40%.

Using separate ON and OFF thresholds prevents rapid relay switching near the threshold value.

---

## State Transition Flow

IDLE → MONITORING

MONITORING → IRRIGATING

IRRIGATING → COOLDOWN

COOLDOWN → MONITORING

ANY STATE → FAULT

---

## Features Implemented

- Soil moisture threshold detection
- Humidity threshold checking
- Hysteresis control
- Debounce logic
- Cooldown timer
- Maximum runtime protection
- DHT sensor fault detection
- Serial monitor logging

---

## Test Results

### Test 1 – Low Soil Moisture
- Soil moisture dropped below 25%
- Relay activated successfully
- State changed to IRRIGATING

Result: PASS

### Test 2 – Target Moisture Reached
- Soil moisture reached 40%
- Relay deactivated successfully
- State changed to COOLDOWN

Result: PASS

### Test 3 – Cooldown Complete
- Cooldown timer expired
- State returned to MONITORING

Result: PASS

### Test 4 – DHT Sensor Failure
- Simulated three consecutive DHT failures
- State changed to FAULT
- LED blinking observed

Result: PASS

---

## Conclusion

Successfully implemented a state-machine-based irrigation system with threshold control, hysteresis logic, cooldown protection, runtime safety, and fault detection.

---

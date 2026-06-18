# 🌱 Automated Grow-Bench System  
### ESP8266-Based Smart Irrigation System (Capstone Project)

---

## 📌 1. Objective

The objective of this project is to design and implement an IoT-based automated irrigation system using ESP8266 NodeMCU. The system monitors soil moisture and controls water flow using a solenoid valve through a relay module. It supports both automatic and manual operation modes.

---

## 🔩 2. Hardware Bill of Materials (BOM)

| Component | Description | Estimated Cost (INR) |
|-----------|-------------|----------------------|
| ESP8266 NodeMCU | Main microcontroller for IoT control | ₹250 – ₹400 |
| Soil Moisture Sensor | Measures soil water content (analog output) | ₹80 – ₹150 |
| Relay Module (1-channel) | Switches solenoid valve ON/OFF | ₹60 – ₹120 |
| Solenoid Valve | Controls water flow | ₹300 – ₹800 |
| Push Button | Manual override control | ₹10 – ₹20 |
| External 12V Supply | Powers solenoid valve | ₹200 – ₹500 |
| Jumper Wires & Breadboard | Prototyping connections | ₹100 – ₹200 |

---

## 🔌 3. Wiring Overview

### ESP8266 Connections

- Soil Sensor AO → A0  
- Relay IN → D1  
- Push Button → D2 (INPUT_PULLUP)  
- VCC → 3.3V / 5V (as required)  
- GND → Common Ground  

---

### Relay to Solenoid Valve

- COM → 12V Positive  
- NO → Solenoid Positive  
- Solenoid Negative → 12V Negative  

---

## 🖼️ 4. Wiring Diagram

![Wiring Diagram](docs/images/wiring.png)

---

## ⚙️ 5. Calibration Methodology

The soil moisture sensor was calibrated by observing analog values under different conditions:

| Condition | Sensor Value |
|----------|-------------|
| Air | ~10–20 |
| Dry Soil | ~600–900 |
| Wet Soil | ~200–500 |

Based on observations, the following thresholds were selected:

- **Dry Threshold = 750** → activates watering  
- **Wet Threshold = 500** → stops watering  

This hysteresis prevents rapid switching of the relay.

---

## 🧪 6. Test Results

### Functional Tests Performed:
- Sensor reading verification
- Relay switching test
- Solenoid ON/OFF control
- Serial command execution
- Button-based manual override

### Observations:
- System successfully switches between AUTO and MANUAL modes
- Moisture readings are stable but dependent on sensor placement
- Relay switching is responsive

---

## ⚠️ 7. Known Limitations

- Soil moisture sensor is not highly accurate and varies with soil type
- Sensor corrosion may occur over long-term usage
- ESP8266 ADC has limited resolution and noise
- Requires external stable power supply for solenoid valve

---

## 🔄 8. System Working Summary

The system continuously reads soil moisture values using ESP8266 ADC. If the value exceeds 750, the soil is considered dry and the relay activates the solenoid valve to supply water. If the value drops below 500, watering stops. The system can also be controlled manually using a push button or serial commands.

---

## 🔁 9. Instructions for Next Intern (Reflash Guide)

### Step 1: Install Arduino IDE
- Install ESP8266 board package

### Step 2: Select Board
- NodeMCU 1.0 (ESP-12E Module)

### Step 3: Select Port
- Choose correct COM port

### Step 4: Upload Code
- Open `.ino` file
- Click Upload

### Step 5: Test System
Use Serial Monitor:
- `STATUS`
- `AUTO`
- `FORCE_ON`
- `FORCE_OFF`

---

## 🚀 10. Future Improvements

- Replace resistive soil sensor with capacitive soil moisture sensor for better accuracy and durability  
- Add WiFi-based mobile app control (Blynk / MQTT dashboard)  
- Implement cloud data logging for moisture history analysis  
- Add battery backup system for uninterrupted operation  
- Introduce multiple plant zone control using multiple relays  
- Improve power management for long-term outdoor deployment  

---

## 📌 11. Project Summary

This project demonstrates an IoT-based smart irrigation system using ESP8266, capable of automatic and manual water control based on soil moisture levels. It is suitable for smart agriculture and embedded systems learning.

---

## 🏷️ Version
v1.0-capstone

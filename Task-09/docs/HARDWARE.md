#  Hardware – Automated Grow Bench (ESP8266)

##  Overview
This project uses ESP8266 to control a water valve based on soil moisture readings.

---

##  Main Components
- ESP8266 NodeMCU  
- Soil Moisture Sensor (A0)  
- Relay Module  
- Solenoid Valve  
- Push Button  

---

##  Working Principle
- Soil moisture sensor gives analog value to ESP8266.
- ESP8266 checks the value and compares it with thresholds.
- Relay controls the solenoid valve based on soil condition.

---

##  Threshold Values
- **Dry Threshold = 750** → Soil is dry → Valve ON (water ON)
- **Wet Threshold = 500** → Soil is wet → Valve OFF (water OFF)

---

##  Operation
- If moisture > 750 → system turns ON watering
- If moisture < 500 → system turns OFF watering
- Manual button and serial control can override automatic mode

---

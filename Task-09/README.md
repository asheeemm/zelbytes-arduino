#  Automated Grow Bench (ESP8266)

##  Description
This project is an automatic plant watering system using ESP8266. It reads soil moisture and controls a water valve using a relay. It also supports manual control using button and serial commands.

---

## ⚙️ Components
- ESP8266 NodeMCU  
- Soil Moisture Sensor  
- Relay Module  
- Solenoid Valve  
- Push Button  

---

##  Working
- Sensor reads soil moisture value
- If soil is dry → valve turns ON
- If soil is wet → valve turns OFF
- Manual control is also available

---

##  Commands
- STATUS → Shows moisture and system state  
- AUTO → Automatic mode  
- FORCE_ON → Turn valve ON  
- FORCE_OFF → Turn valve OFF  

---

## 🏷️ Version
v1.0-capstone

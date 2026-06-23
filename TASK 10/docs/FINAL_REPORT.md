#  Automated Grow-Bench System

## Task 10 – Technical Report

### ESP32-Based IoT Smart Irrigation System

---

# 1. Project Overview

The Automated Grow-Bench System is an IoT-enabled smart irrigation solution developed using ESP32. The system continuously monitors soil moisture levels and automatically controls irrigation through a relay-controlled solenoid valve. Sensor data is transmitted to the Zelbytes IoT Lab cloud platform and visualized through an external web dashboard featuring live monitoring and graphical analysis.

This project demonstrates the integration of embedded systems, cloud communication, API-based telemetry, and web technologies for smart agriculture applications.

---

# 2. Objectives

* Monitor soil moisture levels in real time.
* Automate irrigation using predefined moisture thresholds.
* Upload sensor data to a cloud platform using APIs.
* Display live sensor readings through an external dashboard.
* Visualize historical data using graphs.
* Provide both automatic and manual control modes.
* Demonstrate a complete IoT monitoring workflow.

---

# 3. Hardware Bill of Materials (BOM)

| Component                | Purpose            | Estimated Cost (INR) |
| ------------------------ | ------------------ | -------------------- |
| ESP32 Development Board  | Main controller    | ₹300–₹600            |
| Soil Moisture Sensor     | Soil monitoring    | ₹80–₹150             |
| Relay Module (1-Channel) | Valve control      | ₹60–₹120             |
| Solenoid Valve           | Water flow control | ₹300–₹800            |
| Push Button              | Manual override    | ₹10–₹20              |
| 12V Power Supply         | Valve power source | ₹200–₹500            |
| Jumper Wires             | Interconnections   | ₹50–₹100             |
| Breadboard               | Prototyping        | ₹50–₹100             |

### Estimated Total Cost

**₹1050 – ₹2390 (Approx.)**

---

# 4. Cloud and Dashboard Components

| Component                 | Purpose                         |
| ------------------------- | ------------------------------- |
| Zelbytes IoT Lab Platform | Cloud backend                   |
| API Key                   | Device authentication           |
| REST API Endpoints        | Data transmission and retrieval |
| External HTML Dashboard   | Monitoring interface            |
| Chart.js                  | Graph visualization             |
| Web Browser               | Dashboard access                |

---

# 5. Wiring Connections

## ESP32 Connections

| ESP32 Pin         | Connected To            |
| ----------------- | ----------------------- |
| Analog Input Pin  | Soil Moisture Sensor AO |
| Relay Control Pin | Relay IN                |
| Push Button Pin   | Push Button             |
| 3.3V              | Sensor VCC              |
| GND               | Common Ground           |

---

## Relay Connections

| Relay Terminal    | Connected To            |
| ----------------- | ----------------------- |
| COM               | +12V Supply             |
| NO                | Solenoid Valve Positive |
| Solenoid Negative | 12V Ground              |

---

# 7. Firmware Logic

The ESP32 continuously reads moisture values from the soil moisture sensor and processes the data according to predefined threshold values.

The firmware supports:

* Automatic irrigation mode
* Manual override mode
* Serial command interface
* Cloud telemetry transmission
* Dashboard integration

### Supported Commands

| Command   | Function              |
| --------- | --------------------- |
| STATUS    | Display system status |
| AUTO      | Enable automatic mode |
| ON        | Turn valve ON         |
| OFF       | Turn valve OFF        |

---

# 8. Calibration Methodology

The soil moisture sensor was tested under different soil conditions to determine suitable operating thresholds.

### Selected Thresholds

| Condition | Threshold |
| --------- | --------- |
| Dry Soil  | > 3500    |
| Wet Soil  | < 2500    |

### Irrigation Logic

#### Dry Threshold = 3500

If moisture value exceeds 3500:

* Soil is considered dry
* Relay activates
* Solenoid valve opens
* Irrigation starts

#### Wet Threshold = 2500

If moisture value drops below 2500:

* Soil is considered sufficiently wet
* Relay deactivates
* Solenoid valve closes
* Irrigation stops

The gap between thresholds provides hysteresis and prevents rapid relay switching.

---

# 9. IoT Communication Architecture

## System Architecture

```text
ESP32
  ↓
Zelbytes IoT API
  ↓
Cloud Storage
  ↓
External Dashboard
  ↓
Live Monitoring & Graphs
```

---

## Data Flow

1. Soil moisture sensor collects readings.
2. ESP32 processes sensor data.
3. Telemetry is uploaded to Zelbytes IoT Lab through authenticated API requests.
4. Cloud platform stores telemetry data.
5. Dashboard retrieves live and historical data using API endpoints.
6. Graphs and status indicators are updated automatically.

---

# 10. Dashboard Implementation

A separate external dashboard was developed for remote monitoring of system data.

### Dashboard Features

* Live sensor value display
* Real-time status monitoring
* Valve state indication
* Historical data visualization
* Graphical trend analysis
* Automatic dashboard refresh

### Technologies Used

* HTML
* CSS
* JavaScript
* Chart.js
* Zelbytes IoT Lab API

---

# 11. API Integration

The dashboard communicates with the Zelbytes IoT Lab platform using authenticated API requests.

### API Functions

* Upload telemetry from ESP32
* Retrieve latest sensor values
* Fetch historical records
* Update dashboard widgets
* Generate graphs

### Data Displayed

* Soil moisture level
* Valve status
* Operating mode
* Historical sensor trends

---

# 12. Test Results

## Hardware Tests

| Test                | Result |
| ------------------- | ------ |
| Sensor Reading      | Passed |
| Relay Switching     | Passed |
| Valve Control       | Passed |
| Push Button Control | Passed |
| Serial Commands     | Passed |

---

## IoT Tests

| Test                | Result |
| ------------------- | ------ |
| WiFi Connectivity   | Passed |
| API Communication   | Passed |
| Cloud Upload        | Passed |
| Dashboard Retrieval | Passed |
| Real-Time Updates   | Passed |

---

## Dashboard Tests

| Test                      | Result |
| ------------------------- | ------ |
| Live Data Display         | Passed |
| Historical Data Retrieval | Passed |
| Graph Rendering           | Passed |
| Status Indicators         | Passed |
| Auto Refresh              | Passed |

---

# 14. Known Limitations

* Sensor accuracy varies with soil composition.
* Long-term sensor exposure may affect calibration.
* Internet connection is required for remote monitoring.
* Cloud service availability affects dashboard functionality.
* Single-node implementation only.

---

# 15. Future Improvements

* Capacitive soil moisture sensor integration.
* Remote valve control from dashboard.
* Mobile application support.
* Notification alerts for dry soil conditions.
* Multi-node grow-bench support.
* Weather-based irrigation prediction.
* Advanced analytics and reporting.

---

# 16. Instructions for Next Intern

## Reflashing Firmware

### Step 1

Install Arduino IDE.

### Step 2

Install ESP32 Board Package.

### Step 3

Select:

**Board:** ESP32 Dev Module

### Step 4

Connect ESP32 and select the correct COM port.

### Step 5

Open the firmware file:

```text
automated_growbench.ino
```

### Step 6

Update WiFi credentials and API key if required.

### Step 7

Upload firmware to ESP32.

### Step 8

Open Serial Monitor at:

```text
115200 baud
```

### Step 9

Verify operation using:

* STATUS
* AUTO
* ON
* OFF

---

# 17. Conclusion

The Automated Grow-Bench System successfully demonstrates the integration of ESP32-based sensing, cloud communication, and web-based monitoring. The system automatically manages irrigation based on soil moisture conditions while simultaneously uploading telemetry to the Zelbytes IoT Lab platform. The external dashboard provides live monitoring and graphical visualization, making the solution suitable for smart agriculture and IoT learning applications.

---

## Version

**v1.0-capstone**

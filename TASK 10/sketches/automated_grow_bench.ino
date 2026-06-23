#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>

// =====================================
// WiFi Credentials
// =====================================
const char* ssid = "realme narzo 30";
const char* password = "12345678";

// =====================================
// Zelbytes IoT Lab
// =====================================
const char* apiKey = "MY_API_Key";
const char* server =
"https://careers.zelbytes.com/api/iot-lab/v1/telemetry";

// =====================================
// Pin Definitions
// =====================================
#define SOIL_PIN    34
#define RELAY_PIN   26
#define BUTTON_PIN  27

#define DHTPIN      4
#define DHTTYPE     DHT22

DHT dht(DHTPIN, DHTTYPE);

// =====================================
// Soil Thresholds
// =====================================
const int DRY_THRESHOLD = 3500;
const int WET_THRESHOLD = 2500;

// =====================================
// Global Variables
// =====================================
bool pumpState = false;
bool manualMode = false;
bool lastButtonState = HIGH;

unsigned long lastTelemetryTime = 0;
const unsigned long TELEMETRY_INTERVAL = 5000;

// =====================================
// WiFi Connection
// =====================================
void connectWiFi()
{
    Serial.print("Connecting to WiFi");

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println();
    Serial.println("WiFi Connected");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
}

// =====================================
// Soil Status
// =====================================
String getSoilStatus(int soilRaw)
{
    if (soilRaw > DRY_THRESHOLD)
        return "DRY";

    if (soilRaw < WET_THRESHOLD)
        return "WET";

    return "NORMAL";
}

// =====================================
// Telemetry Function
// =====================================
void sendTelemetry(int soilRaw,
                   float temperature,
                   float humidity)
{
    if (WiFi.status() != WL_CONNECTED)
        return;

    HTTPClient http;

    http.begin(server);

    http.addHeader("Content-Type", "application/json");
    http.addHeader("X-Iot-Lab-Key", apiKey);

  int soilPercent = map(soilRaw, 4095, 0, 0, 100);
soilPercent = constrain(soilPercent, 0, 100);

String payload =
"{"
"\"device_id\":\"esp32_irrigation\","
"\"temperature_c\":" + String(temperature,1) + ","
"\"humidity_pct\":" + String(humidity,1) + ","
"\"soil_moisture_pct\":" + String(soilPercent) + ","
"\"pump_state\":" + String(pumpState ? 1 : 0) + ","
"\"mode\":\"" + String(manualMode ? "MANUAL" : "AUTO") + "\""
"}";

    Serial.println("\nSending Telemetry:");
    Serial.println(payload);

    int httpCode = http.POST(payload);

    Serial.print("HTTP Response Code: ");
    Serial.println(httpCode);

    if (httpCode > 0)
    {
        String response = http.getString();
        Serial.println(response);
    }

    http.end();
}

// =====================================
// Serial Commands
// =====================================
void handleSerialCommands()
{
    if (!Serial.available())
        return;

    String command = Serial.readStringUntil('\n');

    command.trim();
    command.toUpperCase();

    if (command == "ON")
    {
        manualMode = true;
        pumpState = true;
        Serial.println("Manual Mode -> Pump ON");
    }
    else if (command == "OFF")
    {
        manualMode = true;
        pumpState = false;
        Serial.println("Manual Mode -> Pump OFF");
    }
    else if (command == "AUTO")
    {
        manualMode = false;
        Serial.println("Automatic Mode Enabled");
    }
    else if (command == "STATUS")
    {
        Serial.println("\n===== SYSTEM STATUS =====");
        Serial.print("Mode : ");
        Serial.println(manualMode ? "MANUAL" : "AUTO");

        Serial.print("Pump : ");
        Serial.println(pumpState ? "ON" : "OFF");
    }
}

// =====================================
// Setup
// =====================================
void setup()
{
    Serial.begin(115200);

    pinMode(RELAY_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);

    digitalWrite(RELAY_PIN, LOW);

    dht.begin();

    connectWiFi();

    Serial.println("\n=================================");
    Serial.println("AUTOMATED GROW BENCH READY");
    Serial.println("=================================");

    Serial.println("Available Commands:");
    Serial.println("ON");
    Serial.println("OFF");
    Serial.println("AUTO");
    Serial.println("STATUS");
}

// =====================================
// Main Loop
// =====================================
void loop()
{
    // -------------------------
    // Reconnect WiFi
    // -------------------------
    if (WiFi.status() != WL_CONNECTED)
    {
        connectWiFi();
    }

    // -------------------------
    // Read Sensors
    // -------------------------
    int soilRaw = analogRead(SOIL_PIN);

    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    if (isnan(temperature))
        temperature = 0;

    if (isnan(humidity))
        humidity = 0;

    // -------------------------
    // Button Toggle Mode
    // -------------------------
    bool buttonState = digitalRead(BUTTON_PIN);

    if (lastButtonState == HIGH &&
        buttonState == LOW)
    {
        manualMode = !manualMode;

        Serial.print("Mode Changed To: ");
        Serial.println(
            manualMode ? "MANUAL" : "AUTO");

        delay(300);
    }

    lastButtonState = buttonState;

    // -------------------------
    // Automatic Irrigation
    // -------------------------
    if (!manualMode)
    {
        if (soilRaw > DRY_THRESHOLD)
        {
            pumpState = true;
        }

        if (soilRaw < WET_THRESHOLD)
        {
            pumpState = false;
        }
    }

    // -------------------------
    // Relay Control
    // -------------------------
    digitalWrite(RELAY_PIN, pumpState);

    // If your relay is active LOW,
    // replace above line with:
    // digitalWrite(RELAY_PIN, !pumpState);

    // -------------------------
    // Serial Commands
    // -------------------------
    handleSerialCommands();

    // -------------------------
    // Display Readings
    // -------------------------
    Serial.println();
    Serial.println("--------------------------------");

    Serial.print("Soil Raw Value : ");
    Serial.println(soilRaw);

    Serial.print("Soil Status    : ");
    Serial.println(getSoilStatus(soilRaw));

    Serial.print("Temperature    : ");
    Serial.print(temperature);
    Serial.println(" °C");

    Serial.print("Humidity       : ");
    Serial.print(humidity);
    Serial.println(" %");

    Serial.print("Mode           : ");
    Serial.println(
        manualMode ? "MANUAL" : "AUTO");

    Serial.print("Pump State     : ");
    Serial.println(
        pumpState ? "ON" : "OFF");

    // -------------------------
    // Send Telemetry
    // -------------------------
    if (millis() - lastTelemetryTime >=
        TELEMETRY_INTERVAL)
    {
        sendTelemetry(
            soilRaw,
            temperature,
            humidity);

        lastTelemetryTime = millis();
    }

    delay(1000);
}

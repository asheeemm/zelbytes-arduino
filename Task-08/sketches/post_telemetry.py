import requests

API = "https://careers.zelbytes.com/api/iot-lab/v1"
KEY = "zil_YOUR_KEY"  # from IoT Lab → My Instance
headers = {"X-Iot-Lab-Key": KEY, "Content-Type": "application/json"}

payload = {
    "device_id": "uno-bench-01",
    "temperature_c": 33.50,
    "humidity_pct": 64.60,
    "soil_moisture_pct": 1023,
}
r = requests.post(f"{API}/telemetry", json=payload, headers=headers, timeout=15)
print(r.status_code, r.json())

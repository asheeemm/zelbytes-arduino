import requests
import time

API = "https://careers.zelbytes.com/api/iot-lab/v1"
KEY = "zil_YOUR_KEY"

headers = {
    "X-Iot-Lab-Key": KEY,
    "Content-Type": "application/json"
}

for i in range(10):
    payload = {
        "device_id": "uno-bench-01",
        "temperature_c": 33.50 + i * 0.1,
        "humidity_pct": 64.60,
        "soil_moisture_pct": 1023,       
        
    }

    r = requests.post(
        f"{API}/telemetry",
        json=payload,
        headers=headers,
        timeout=15
    )

    print(f"Sample {i+1}: Status {r.status_code}")
    time.sleep(2)   # Wait 2 seconds before the next sample

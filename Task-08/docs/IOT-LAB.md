# IoT Lab Documentation

## Objective

The objective of this task is to send sensor telemetry data from a Python program to the Zelbytes IoT Learning Lab.

## Working

1. The Python script creates a JSON payload containing the sensor values.
2. The request is authenticated using the IoT Lab API key.
3. The telemetry data is sent to the IoT Lab server.
4. The uploaded data is stored and can be viewed in the API Explorer or Dashboard.

## Payload Format

```json
{
  "device_id": "uno-bench-01",
  "temperature_c": 33.5,
  "humidity_pct": 64.6,
  "soil_moisture_pct": 1023
}
```

## Files Used

- `post_telemetry.py` – Sends telemetry data to the IoT Lab.
- `README.md` – Project overview and usage instructions.

## Result

The telemetry data was successfully uploaded to the IoT Lab and verified using the API Explorer, where more than 10 samples were recorded.

# Irrigation State Machine

```text
                 Dry Soil Detected
          +----------------------------+
          |                            |
          v                            |
      +--------+                  +-----------+
      |  IDLE  | ---------------->| IRRIGATING|
      +--------+                  +-----------+
          ^                            |
          |                            |
          | Cooldown Complete          | Watering Complete
          |                            v
      +----------+ <-------------------+
      | COOLDOWN |
      +----------+

DHT Failure (3 Consecutive Reads)
                 |
                 v
            +--------+
            | FAULT  |
            +--------+
```

### State Descriptions

* **IDLE**: System monitors soil moisture and sensor status.
* **IRRIGATING**: Relay activates the solenoid valve and LED turns ON.
* **COOLDOWN**: Irrigation stops and the system waits before the next cycle.
* **FAULT**: Triggered after 3 consecutive DHT sensor failures; irrigation is disabled.

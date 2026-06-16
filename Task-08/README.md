# Task 8 - IoT Lab First Cloud Post

## Objective

Send telemetry data to the Zelbytes IoT Learning Lab using a Python script.

## Requirements

- Python 3.14.6
- requests library

## Device ID

Device ID used: `uno-bench-01`

## Installation

```bash
pip install requests
```

## Running

Replace `zil_YOUR_KEY` with your IoT Lab API key and run:

```bash
py post_telemetry.py
```

The script sends sample telemetry data to the IoT Lab and prints the server response.

## Files

- `post_telemetry.py` - Python script to send telemetry
- `README.md` - Project documentation

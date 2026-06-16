# Test Log

## Test 1 - Dry Soil

Soil moisture dropped below 25%.

State transition:

IDLE → MONITORING → IRRIGATING

Relay turned ON successfully.

Result: PASS

## Test 2 - Target Moisture Reached

Soil moisture reached 40%.

State transition:

IRRIGATING → COOLDOWN

Relay turned OFF successfully.

Result: PASS

## Test 3 - Cooldown Expired

Cooldown timer completed.

State transition:

COOLDOWN → MONITORING

Result: PASS

## Test 4 - DHT Failure

Simulated 3 consecutive DHT failures.

State transition:

ANY STATE → FAULT

LED blinking observed.

Result: PASS

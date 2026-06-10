## Soil Moisture Calibration

AIR = 1023
DRY = 750
WET = 221

Moisture percentage calculated using:

map(raw, DRY_ADC, WET_ADC, 0, 100)

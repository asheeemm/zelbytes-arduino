## Soil Moisture Calibration

DRY_ADC = 850
WET_ADC = 321

Moisture percentage calculated using:

map(raw, DRY_ADC, WET_ADC, 0, 100)

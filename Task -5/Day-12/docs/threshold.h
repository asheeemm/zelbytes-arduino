#ifndef THRESHOLDS_H
#define THRESHOLDS_H

// Soil moisture threshold
const int SOIL_THRESHOLD = 400;

// Irrigation timing
const unsigned long IRRIGATION_TIME = 5000;   // 5 seconds
const unsigned long COOLDOWN_TIME = 10000;    // 10 seconds

// DHT11 fault detection
const int MAX_DHT_FAILURES = 3;

#endif

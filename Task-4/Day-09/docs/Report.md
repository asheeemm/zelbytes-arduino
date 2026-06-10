## Day 9 Ultrasonic Sensor Notes

Sensor mounted horizontally on breadboard.

Target:
- Flat surface like a smartphone

Angle:
- Approximately perpendicular to target surface.

Blind zone:
- Readings unreliable below 3 cm.

Maximum tested distance:
- 80 cm.

Expected Output

When working normally:

millis,distance_cm
1023,10.12
1524,10.08
2025,10.15
2526,29.98
3028,30.05

When unplugged or no echo:

millis,distance_cm
4020,INVALID
4521,INVALID
5022,INVALID

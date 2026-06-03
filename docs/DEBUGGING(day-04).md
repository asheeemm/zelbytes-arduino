# Debugging Notes

## Serial Port Issues
- Wrong COM port selected.
- USB cable disconnected.
- Board not detected by Arduino IDE.

## Baud Rate
- Sketch uses 9600 baud.
- Serial Monitor must also be set to 9600.

## Brownout Symptoms
- Random resets.
- Serial output restarting unexpectedly.
- LED flickering during power drops.

## Debug Mode
- DEBUG enabled using #define DEBUG 1.
- Periodic uptime messages help verify firmware execution.

#Hardware Documentation

Components Used

Arduino Uno
L298N Motor Driver Module
DC Motor
Relay Module
Push Button (Emergency Stop)
LED
Breadboard
Jumper Wires
External Power Supply (5V–12V)
Pin Mapping

Arduino Pin| Connected To D9| L298N ENA D10| L298N IN1 D11| L298N IN2 D6| Relay IN D13| Status LED D2| Emergency Stop Button

L298N Motor Driver Connections

Power Connections

External Power Supply Positive → 12V Terminal
External Power Supply Ground → GND Terminal
Arduino GND → L298N GND
Motor Connections

Motor Terminal 1 → OUT1
Motor Terminal 2 → OUT2
Control Connections

ENA → Arduino D9
IN1 → Arduino D10
IN2 → Arduino D11
Relay Module Connections

VCC → Arduino 5V
GND → Arduino GND
IN → Arduino D6
Emergency Stop Button Connections

One Terminal → Arduino D2
Other Terminal → GND
The button is configured using INPUT_PULLUP mode.

Working Principle

The Arduino generates PWM signals on pin D9 to control motor speed through the L298N motor driver. Pins D10 and D11 determine motor direction. The relay module controls the valve operation. The emergency stop push button uses an external interrupt on pin D2 to instantly stop the motor and close the valve when activated.

Safety Notes

Common ground must be connected between Arduino and L298N.
Never connect the motor directly to Arduino pins.
Verify motor voltage before applying power.
Test emergency stop operation before normal use.

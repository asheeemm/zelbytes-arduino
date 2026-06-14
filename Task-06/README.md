# Zelbytes Arduino Foundations

## Task 6 - PWM Motor & Interrupt E-Stop

### Objective

Control a DC motor using PWM and implement an interrupt-based Emergency Stop.

### Components Used

- Arduino Uno
- L298N Motor Driver
- DC Motor
- Relay Module
- Solenoid Valve
- Push Button
- LED
- Breadboard
- Jumper Wires

### Working

The Arduino generates PWM signals on pin D9 to control motor speed through the L298N motor driver. Motor direction is controlled using pins D10 and D11.

The relay module connected to pin D6 controls the valve. The user can open or close the valve using serial commands.

An emergency stop push button is connected to interrupt pin D2. When pressed, the interrupt immediately stops the motor, turns off the relay, closes the valve, and places the system in a safe state until reset.


### Result

Successfully controlled the motor speed using PWM and implemented an interrupt-driven Emergency Stop that instantly stopped the motor and closed the valve.

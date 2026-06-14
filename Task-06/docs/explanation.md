#Working Explanation

Overview

This project implements PWM-based DC motor speed control using an L298N motor driver and an interrupt-driven Emergency Stop (E-Stop) system.

The motor speed is controlled through serial commands, while a relay module is used to control a valve. An emergency stop push button is connected to an interrupt pin to immediately stop the motor and close the valve when pressed.

Motor Control

The Arduino generates PWM signals on pin D9 and sends them to the ENA pin of the L298N motor driver.

The motor direction is controlled using pins IN1 and IN2.

PWM values range from 80 to 255 and are selected using serial commands from 1 to 9.

Command Mapping:

1 = Low Speed
5 = Medium Speed
9 = Maximum Speed
0 = Motor OFF
Valve Control

A relay module connected to pin D6 controls the valve.

Commands:

o = Open Valve
f = Close Valve
Emergency Stop System

A push button is connected to interrupt pin D2 using INPUT_PULLUP mode.

When the button is pressed:

Interrupt is triggered.
ISR sets the emergencyStop flag.
Motor PWM becomes 0.
Relay is turned OFF.
Valve closes immediately.
LED turns OFF.
The system remains in emergency mode until the user sends the reset command:

r = Reset System

LED Indication

The onboard LED connected to pin 13 blinks whenever the motor is running.

The LED remains OFF when the motor is stopped or during emergency stop conditions.

Safety Features

Interrupt-driven emergency stop.
Immediate motor shutdown.
Automatic valve closure.
No Serial.print() inside ISR.
PWM motor speed control through L298N driver.

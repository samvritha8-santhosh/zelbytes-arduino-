
# Motor and Valve Control System

## Objective

Control a DC motor using PWM, operate a relay-controlled valve, and implement an emergency stop using interrupts.

## Features

* PWM motor speed control (0–255)
* Valve OPEN/CLOSE control
* Emergency stop interrupt
* Status LED indication
* Serial command interface

## Serial Commands

| Command | Function           |
| ------- | ------------------ |
| M0–M255 | Set motor speed    |
| OPEN    | Open valve         |
| CLOSE   | Close valve        |
| RESET   | Reset after E-STOP |

## Usage

1. Upload the sketch to Arduino.
2. Open Serial Monitor at 9600 baud.
3. Send commands to control the motor and valve.
4. Press the E-STOP button to stop the system instantly.
5. Send RESET to resume operation.

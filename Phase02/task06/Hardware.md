
# Hardware Documentation

## Components Used

* Arduino Uno
* DC Motor
* Motor Driver (L298N or equivalent)
* Relay Module
* Push Button (E-STOP)
* LED
* Jumper Wires
* External Power Supply

## Pin Mapping

| Arduino Pin | Connected To  |
| ----------- | ------------- |
| D9          | Motor PWM     |
| D6          | Motor IN1     |
| D7          | Motor IN2     |
| D8          | Relay IN      |
| D13         | Status LED    |
| D2          | E-STOP Button |

## Connections

### Motor Driver

* ENA → D9
* IN1 → D6
* IN2 → D7
* OUT1/OUT2 → DC Motor
* GND → Arduino GND

### Relay Module

* VCC → 5V
* GND → GND
* IN → D8

### E-STOP Button

* One terminal → D2
* Other terminal → GND
* Configured using INPUT_PULLUP

## Working Principle

PWM on D9 controls motor speed. The relay controls valve operation. Pressing the E-STOP button triggers an interrupt that immediately stops the motor, closes the valve, and turns off the LED.

## Safety Notes

* Use a common ground between Arduino and motor driver.
* Use an external supply for the motor.
* Verify E-STOP operation before testing.
*

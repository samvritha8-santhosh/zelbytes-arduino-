# Task 5 – Irrigation State Machine

## Overview

This project implements an automatic irrigation controller using a finite state machine (FSM) on Arduino.

The system monitors soil moisture and humidity and automatically controls a solenoid valve through a relay.

States:

* IDLE
* MONITORING
* IRRIGATING
* COOLDOWN
* FAULT

Features:

* Soil moisture monitoring
* DHT22 humidity monitoring
* Debounced irrigation trigger
* Hysteresis control
* Maximum irrigation runtime protection
* Cooldown period after irrigation
* Fault detection for DHT22 sensor
* Serial logging with timestamps

## Hardware Used

* Arduino Uno
* Soil Moisture Sensor
* DHT22 Sensor
* Relay Module
* Solenoid Valve
* LED
* Breadboard
* Jumper Wires

## Repository Structure

task5_state_machine/

├── README.md

├── irrigation_state_machine.ino

├── config.h

├── thresholds.h

├── docs/

│ ├── state_machine.md

│ ├── connection_diagram.md

│ ├── test_log.md

│ └── methodology.md

├── logs/

│ └── serial_output.txt

└── images/

├── state_machine_diagram.png

├── hardware_setup.jpg

└── serial_monitor.png

## State Transition Flow

IDLE
↓
MONITORING
↓ (Soil < 25%)
IRRIGATING
↓ (Soil > 40% OR timeout)
COOLDOWN
↓
MONITORING

Any state → FAULT when DHT22 fails three consecutive times.

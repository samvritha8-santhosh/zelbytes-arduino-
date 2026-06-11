# Wiring Connections

## Soil Moisture Sensor

VCC → 5V

GND → GND

AO → A0

## DHT22

VCC → 5V

GND → GND

DATA → D4

10kΩ Pull-up:
DATA → VCC

## Relay Module

VCC → 5V

GND → GND

IN → D8

## Status LED

Anode → D13 through 220Ω resistor

Cathode → GND

## Solenoid Valve

Valve + → External Supply +

Valve - → Relay NO terminal

Relay COM → Supply Negative

Use external power supply suitable for the valve.

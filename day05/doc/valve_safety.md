# VALVE SAFETY CHECKLIST

## Hardware Safety

* Solenoid valve must never be powered directly from an Arduino pin.
* Use a relay module or approved driver circuit.
* Verify flyback protection is present.
* Check all wiring before applying power.

## Startup Safety

* Valve must be OFF during boot.
* Firmware calls valveOff() before normal operation.
* ESTOP command tested before valve operation.

## Plumbing Safety

* Manual ball valve installed upstream.
* Drip tray placed beneath test setup.
* Inspect hoses and fittings for leaks.
* Never leave energized plumbing unattended.

## Relay Testing Procedure

1. Verify relay wiring.
2. Test relay click without solenoid connected.
3. Test ESTOP command.
4. Connect solenoid.
5. Perform brief pulse test.
6. Inspect for leaks.

## Emergency Stop

Serial command:

e

Expected response:

ESTOP

Valve should immediately de-energize.

## Bench Rules

* Supervisor approval before connecting valve.
* Never bypass relay.
* Never connect bench supply directly to live plumbing.
* Disconnect power before modifying wiring.

## Photo Documentation

Save a photo showing:

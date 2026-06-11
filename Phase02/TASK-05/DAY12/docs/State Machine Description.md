# State Machine Description

## IDLE

System startup state.

Actions:

* Valve OFF
* LED OFF

Transition:

* Automatically enters MONITORING.

## MONITORING

Reads soil moisture and humidity.

Actions:

* Check soil moisture percentage.
* Count consecutive low-moisture readings.

Transition:

* To IRRIGATING when:
  Soil < 25%
  for 3 consecutive readings.

## IRRIGATING

Watering is active.

Actions:

* Valve ON
* LED ON

Transition:

* To COOLDOWN when:
  Soil >= 40%
  OR
  Runtime >= 10 seconds

## COOLDOWN

Prevents rapid cycling.

Actions:

* Valve OFF
* LED OFF

Transition:

* To MONITORING after 5 seconds.

## FAULT

Sensor failure protection.

Actions:

* Valve OFF
* LED blinking

Transition:

* Remains in FAULT until reset.

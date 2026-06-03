# DEBUGGING CHECKLIST

## Serial Monitor Issues

### No Output

* Check USB cable
* Check COM port
* Check board selection
* Press Reset button

### Garbage Characters

Cause:

* Wrong baud rate

Fix:

* Match Serial.begin() and Serial Monitor baud rate

Example:

Serial.begin(9600)

Monitor:
9600

## Nano USB Disconnects

Symptoms:

* COM port disappears
* Upload fails
* Random serial disconnects

Fix:

* Secure USB cable
* Avoid cable strain

## Brownout Symptoms

Symptoms:

* Random resets
* Startup message repeats
* LED flickers unexpectedly

Possible Causes:

* Weak power supply
* USB power drops
* Excessive current draw

## Command Testing

? = Help

l = LED ON

o = LED OFF

Unknown commands should return:
"Unknown"

## Debug Logging

DEBUG ON:
#define DEBUG 1

DEBUG OFF:
#define DEBUG 0

Check uptime messages every 2 seconds.

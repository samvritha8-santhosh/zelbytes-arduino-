# Test Log

## Test 1 - Normal Monitoring

Input:
Soil = 55%

Expected:
Remain in MONITORING

Result:
PASS

## Test 2 - Irrigation Start

Input:
Soil = 20%

Expected:
MONITORING → IRRIGATING

Result:
PASS

## Test 3 - Moisture Recovery

Input:
Soil = 45%

Expected:
IRRIGATING → COOLDOWN

Result:
PASS

## Test 4 - Cooldown Expiry

Input:
5 second cooldown completed

Expected:
COOLDOWN → MONITORING

Result:
PASS

## Test 5 - DHT Failure

Input:
Disconnect DHT22 sensor

Expected:
FAULT state

Result:
PASS

## Test 6 - Maximum Runtime

Input:
Keep soil dry

Expected:
Stop irrigation after 10 seconds

Result:
PASS

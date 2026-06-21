# Test Report

## Project
Automated Grow-Bench Prototype

## Objective

To verify correct operation of soil moisture monitoring, automatic irrigation, manual override, dashboard visualization, cloud telemetry, and safety functions.

---

## Test Environment

- ESP32 Development Board
- Soil Moisture Sensor
- Relay Module
- Push Button
- LED Indicator
- WiFi Network
- Zelbytes Telemetry API
- Dashboard Application

---

# Test Cases

| Test ID | Test Description | Expected Result | Actual Result | Status |
|----------|------------------|----------------|--------------|--------|
| T1 | ESP32 Power ON | System boots successfully | Boot successful | PASS |
| T2 | WiFi Connection | Device connects to WiFi | Connected successfully | PASS |
| T3 | Soil Moisture Reading | Sensor value displayed correctly | Reading displayed | PASS |
| T4 | Auto Irrigation ON | Relay activates when soil is dry | Relay activated | PASS |
| T5 | Auto Irrigation OFF | Relay deactivates when soil is wet | Relay deactivated | PASS |
| T6 | Manual Override Button | User can toggle pump manually | Working correctly | PASS |
| T7 | STATUS Command | System status displayed | Status displayed | PASS |
| T8 | FORCE_ON Command | Pump turns ON | Pump ON | PASS |
| T9 | FORCE_OFF Command | Pump turns OFF | Pump OFF | PASS |
| T10 | Dashboard Visualization | Moisture value displayed | Display correct | PASS |
| T11 | Historical Data Logging | Logs stored successfully | Logs available | PASS |
| T12 | Cloud Telemetry Upload | Data uploaded to server | Upload successful | PASS |

---

# Fault Injection Tests

## Fault 1 – WiFi Disconnection

### Procedure
Disconnect WiFi router while system is running.

### Expected Result
System continues local operation.

### Actual Result
Automatic irrigation continued normally.

### Status
PASS

---

## Fault 2 – Soil Sensor Removal

### Procedure
Disconnect sensor from ESP32.

### Expected Result
Invalid readings detected.

### Actual Result
Abnormal values observed.

### Status
PASS

---

## Fault 3 – Relay Output Failure

### Procedure
Disconnect relay module.

### Expected Result
Pump control unavailable.

### Actual Result
Relay inactive.

### Status
PASS

---

## Fault 4 – Dashboard Closed

### Procedure
Close dashboard application.

### Expected Result
ESP32 continues operation.

### Actual Result
System continued normally.

### Status
PASS

---

## Fault 5 – API Server Unreachable

### Procedure
Disable internet connection.

### Expected Result
Local irrigation remains operational.

### Actual Result
Telemetry stopped but irrigation continued.

### Status
PASS

---

## Fault 6 – Power Restart

### Procedure
Restart ESP32.

### Expected Result
System reconnects automatically.

### Actual Result
Successful recovery.

### Status
PASS

---

# Performance Results

| Parameter | Result |
|------------|---------|
| Boot Time | < 5 seconds |
| Sensor Update Interval | 3 seconds |
| Dashboard Refresh | Real-time |
| WiFi Reconnection | Successful |
| Telemetry Upload | Successful |
| Manual Override Response | Immediate |

---

# Known Issues

1. Sensor values may fluctuate slightly.
2. Soil moisture sensor requires periodic calibration.
3. Dashboard depends on network connectivity.
4. Water pump hardware not included in all tests.
5. Telemetry uploads depend on server availability.

---

# Conclusion

All major functionalities of the Automated Grow-Bench Prototype were tested successfully. Automatic irrigation, manual override, dashboard monitoring, telemetry upload, and recovery procedures operated as expected. The system is suitable for demonstration and educational IoT applications.
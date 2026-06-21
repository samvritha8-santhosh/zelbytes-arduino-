# **Final Firmware Report – Automated Grow-Bench Prototype**

## **Student Information**

**Name:** Anamika S S  
**KTU ID:** SCT23EC023  
**College:** Sree Chitra Thirunal College of Engineering  
**Branch:** Electronics and Communication Engineering  
**Internship:** Zelbytes Arduino Foundations Internship  
**Task:** Task 10 – Final Firmware Report

---

# **1. Project Overview**

The Automated Grow-Bench Prototype is an IoT-based irrigation system developed using an ESP32 microcontroller, soil moisture sensor, relay module, and cloud telemetry platform. The system continuously monitors soil moisture and automatically controls irrigation based on predefined thresholds.

## Objectives

- Monitor soil moisture in real time.
- Automate irrigation.
- Support manual override.
- Upload telemetry to the cloud.
- Provide dashboard monitoring and control.
- Maintain historical logs.

## Key Features

- Automatic irrigation control
- Manual relay override
- Serial command interface
- Cloud telemetry integration
- Dashboard visualization
- Historical data logging
- WiFi connectivity

---

# **2. System Architecture**

The system consists of sensing, processing, communication, and actuation layers.

## Sensor Layer

The soil moisture sensor measures soil conditions and provides analog readings to the ESP32.

## Controller Layer

The ESP32 reads sensor values, processes them, and decides whether irrigation is required.

## Communication Layer

WiFi connectivity allows data transmission to the Zelbytes IoT platform.

## Actuator Layer

A relay module controls irrigation equipment based on controller decisions.

## Dashboard Layer

A Streamlit dashboard displays sensor readings, logs, graphs, and relay status.

---

# **3. Hardware Bill of Materials**

| Component | Quantity | Purpose |
|------------|----------|----------|
| ESP32 | 1 | Main Controller |
| Soil Moisture Sensor | 1 | Soil Monitoring |
| Relay Module | 1 | Pump Control |
| Push Button | 1 | Manual Override |
| LED | 1 | Status Indication |
| Breadboard | 1 | Circuit Assembly |
| Jumper Wires | Several | Connections |
| USB Cable | 1 | Programming |

---

# **4. Wiring Diagram and Connections**

| Component | ESP32 Pin |
|------------|-----------|
| Soil Moisture Sensor | GPIO34 |
| Relay Module | GPIO26 |
| Push Button | GPIO27 |
| LED | GPIO2 |

All modules share a common ground connection.

![Hardware Setup](../images/hardware_setup.jpeg)

---

# **5. Firmware Design**

## Startup Sequence

1. Initialize serial communication.
2. Configure GPIO pins.
3. Connect to WiFi.
4. Start web server.
5. Enable telemetry services.

## Automatic Irrigation Logic

The ESP32 continuously reads moisture values.

If the soil is dry, the relay turns ON.

If moisture is sufficient, the relay turns OFF.

## Manual Override

Manual control can be performed using:

- Push button
- Dashboard controls
- Serial commands

## Serial Commands

- STATUS
- FORCE_ON
- FORCE_OFF

## Relay Control

Relay state determines irrigation status.

LED status follows relay status.

## Telemetry Upload

Sensor values are transmitted to the cloud using HTTP POST requests.

---

# **6. Sensor Calibration Methodology**

## Dry Soil Test

Observed ADC values:

- 2800 to 3500

Average value:

- 3150 ADC

## Wet Soil Test

Observed ADC values:

- 800 to 1500

Average value:

- 1150 ADC

## Selected Threshold

Threshold value:

- 2000 ADC

## Decision Logic

- ADC > 2000 → Dry Soil → Pump ON
- ADC < 2000 → Wet Soil → Pump OFF

Calibration improves reliability and reduces false triggering.

---

# **7. Dashboard Design and Visualization**

The dashboard was developed using Streamlit.

## Features

- Live moisture percentage
- Relay ON/OFF buttons
- Relay status display
- Historical logs
- Trend chart

## Benefits

- Remote monitoring
- Quick diagnostics
- User-friendly interface

![Dashboard Screenshot](../images/Dashboard.jpeg)

---

# **8. Cloud Telemetry Integration**

Telemetry data is uploaded to the Zelbytes platform.

Example payload:

```json
{
  "soil_moisture_pct": 89
}
```

Benefits:

- Centralized storage
- Historical analysis
- Dashboard synchronization

---

# **9. Testing Procedure**

## Test Case 1

Dry soil condition.

Expected Result:

Pump ON.

Result: PASS

## Test Case 2

Wet soil condition.

Expected Result:

Pump OFF.

Result: PASS

## Test Case 3

Manual override.

Expected Result:

Relay toggles.

Result: PASS

## Test Case 4

Dashboard relay control.

Expected Result:

Relay responds.

Result: PASS

## Test Case 5

Telemetry upload.

Expected Result:

Cloud receives data.

Result: PASS

---

# **10. Test Results Summary**

| Test Item | Result |
|------------|---------|
| Sensor Reading | PASS |
| Auto Irrigation | PASS |
| Relay Operation | PASS |
| Dashboard Control | PASS |
| WiFi Connection | PASS |
| Telemetry Upload | PASS |
| Manual Override | PASS |
| Serial Commands | PASS |

---

# **11. Known Limitations**

1. Single sensor support.
2. No battery backup.
3. Limited authentication.
4. WiFi dependency.
5. No weather integration.

---

# **12. Safety Considerations**

## Electrical Safety

- Disconnect power before rewiring.
- Verify wiring before operation.

## Water Safety

- Protect electronics from water.
- Use insulated connections.

## Operational Safety

- Keep manual water shutoff available.
- Monitor system during testing.

---

# **13. Reflash Instructions for Next Intern**

1. Install Arduino IDE.
2. Install ESP32 Board Package.
3. Open firmware source code.
4. Update WiFi credentials.
5. Connect ESP32.
6. Select COM port.
7. Upload firmware.
8. Open Serial Monitor.
9. Verify sensor operation.

---

# **14. Future Improvements**

- Multiple sensors
- Mobile application
- Battery backup
- Solar power
- Weather integration
- MQTT communication
- AI-based irrigation optimization

---

# **15. Conclusion**

The Automated Grow-Bench Prototype successfully demonstrates automatic irrigation using ESP32 and IoT technologies. The system integrates sensing, control, telemetry, and dashboard visualization into a unified platform. Testing confirmed reliable operation and successful completion of project objectives.

# Retrospective Notes

## Project Summary

The Automated Grow-Bench Prototype was developed as the final capstone project of the Zelbytes Arduino Foundations Internship. The project integrates soil moisture monitoring, automatic irrigation control, cloud telemetry, and dashboard visualization using an ESP32.

## What Went Well

- Successfully implemented automatic irrigation based on soil moisture threshold.
- Implemented manual override using a push button.
- Established WiFi connectivity for cloud telemetry.
- Created a dashboard for monitoring soil moisture data.
- Added serial commands for debugging and testing.
- Successfully pushed all project files to GitHub.
- Created Git tag v1.0-capstone.

## Challenges Faced

- Sensor values fluctuated during initial testing.
- WiFi connection occasionally disconnected during telemetry upload.
- Soil moisture calibration required multiple test runs.
- Relay logic needed verification because of active-low operation.
- Dashboard integration required additional testing.

## Lessons Learned

- Importance of sensor calibration before deployment.
- Benefits of modular firmware design.
- Proper Git version control practices.
- Documentation is essential for project handoff.
- Testing under different operating conditions improves reliability.

## Improvements for Future Versions

- Add water level monitoring.
- Add temperature and humidity sensors.
- Add mobile notifications.
- Implement data storage in cloud database.
- Add automatic fault detection.
- Improve dashboard visualization.

## Final Reflection

This project provided practical experience in embedded systems, IoT communication, sensor interfacing, cloud telemetry, Git workflows, and technical documentation. The final system successfully demonstrates automated irrigation with monitoring and manual control capabilities.
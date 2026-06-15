# Sensor Data Logger

## Objective
Log temperature, humidity, soil moisture, and light sensor data to CSV format using Arduino and serial capture.

## Components
- Arduino UNO
- DHT11 Sensor
- Soil Moisture Sensor
- LDR + 10kΩ Resistor
- Breadboard & Jumper Wires

## Connections

### DHT11
| Pin | Arduino |
|------|---------|
| VCC | 5V |
| GND | GND |
| DATA | D2 |

### Soil Moisture Sensor
| Pin | Arduino |
|------|---------|
| VCC | 5V |
| GND | GND |
| AO | A0 |

### LDR
- One leg → 5V
- Other leg → A1
- 10kΩ resistor between A1 and GND

## CSV Format

```csv
timestamp,temp,humidity,soil,light
0,27.3,49.9,9,100
30,27.4,50.0,8,99
```

## How to Run
1. Connect the sensors as shown above.
2. Upload `sensor_logger.ino` to the Arduino UNO.
3. Open Serial Monitor at **9600 baud**.
4. Record data for the required duration.
5. Save the serial output as `task7/sample_log.csv`.

## Files Submitted
- `task7/sensor_logger.ino`
- `task7/sample_log.csv`
- `README.md`

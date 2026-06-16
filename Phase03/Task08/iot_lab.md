# IoT Lab Integration

## Objective
Post bench telemetry data (temperature, humidity, soil moisture, CO2) from
Arduino Uno to the Zelbytes IoT Learning Lab dashboard using a host Python
script, since the Uno has no native WiFi capability.

## Device Information
- **Device ID:** samvritha_01
- **Endpoint:** https://careers.zelbytes.com/api/iot-lab/v1/telemetry
- **Telemetry Topic:** zelbytes/lab/65/telemetry

## Architecture
Arduino Uno reads sensor values and prints them as CSV over Serial.
A Python script running on the host laptop reads this Serial CSV data,
converts it to JSON, and POSTs it to the IoT Lab telemetry endpoint
using the API key stored in `secrets.h` (gitignored, never committed).

## Field Mapping (CSV → JSON)

| CSV Column (Day 11) | JSON Field         | Type  | Description                   |
|----------------------|--------------------|-------|--------------------------------|
| temp                 | temperature_c       | float | Temperature in Celsius        |
| humidity             | humidity_pct        | int   | Relative humidity percentage  |
| soil                 | soil_moisture_pct   | int   | Soil moisture percentage      |
| co2                  | co2_ppm             | int   | CO2 concentration in ppm      |

## Sample JSON Payload
```json
{
  "device_id": "krishnaas_bench01",
  "temperature_c": 29.7,
  "humidity_pct": 87,
  "soil_moisture_pct": 32,
  "co2_ppm": 911
}
```

## Security
- API key is stored in `secrets.h`, excluded from version control via `.gitignore`.
- Only `secrets.h.example` (with placeholder values) is committed to the repository.
- API key is never logged, printed in screenshots, or included in commit messages.

## Verification
- 10 sample readings were successfully posted under device_id `krishnaas_bench01`, each returning HTTP status **202**.
- Data was confirmed visible via **IoT Lab → API Explorer**, with the `temperature_c` series showing multiple recorded data points across all samples sent.

## Notes
- ESP8266 WiFi bridge integration is planned for Day 17, removing the need for a host Python relay script.

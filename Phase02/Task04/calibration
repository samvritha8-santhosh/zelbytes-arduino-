# Sensor Calibration Table

## LDR Calibration

| Condition | Raw ADC Range |
| --------- | ------------- |
| DARK      | < 200         |
| AMBIENT   | 200–700       |
| BRIGHT    | > 700         |

Observed values:

* DARK: 41–90
* AMBIENT: 593–634
* BRIGHT: 781–782

---

## DHT22 Calibration

| Parameter   | Value    |
| ----------- | -------- |
| Temperature | 33.5 °C  |
| Humidity    | 74.1 %RH |

---

## HC-SR04 Calibration

| Parameter | Value               |
| --------- | ------------------- |
| Unit      | Centimeters         |
| Accuracy  | Approximately ±1 cm |

Sample distances:

* 4.3 cm
* 4.4 cm
* 9.2 cm
* 10.8 cm

---

## Soil Moisture Calibration

| Parameter | Value |
| --------- | ----- |
| DRY_ADC   | 820   |
| WET_ADC   | 380   |

Typical readings:

* Raw ADC: 508–631
* Moisture Percentage: 42–80%

## Conversion Formula

moisturePercent = map(rawADC, 820, 380, 0, 100)

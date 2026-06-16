import requests
import random
import time

API = "https://careers.zelbytes.com/api/iot-lab/v1"
KEY = "zil_......"

headers = {
    "Content-Type": "application/json",
    "X-Iot-Lab-Key": KEY
}

for i in range(10):

    payload = {
        "device_id": "samvritha_bench01",
        "temperature_c": round(random.uniform(24, 32), 1),
        "humidity_pct": random.randint(50, 90),
        "soil_moisture_pct": random.randint(30, 70),
        "co2_ppm": random.randint(700, 1200)
    }

    r = requests.post(
        f"{API}/telemetry",
        json=payload,
        headers=headers
    )

    print(f"Sample {i+1}: {r.status_code}")
    print(payload)

    time.sleep(1)

print("Finished sending 10 samples")

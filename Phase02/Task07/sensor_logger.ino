#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

#define SOIL_PIN A0
#define LIGHT_PIN A1

DHT dht(DHTPIN, DHTTYPE);

unsigned long startTime;
const unsigned long LOG_INTERVAL = 30000; // 30 sec

void setup() {
  Serial.begin(9600);

  dht.begin();

  startTime = millis();

  Serial.println("timestamp,temp,humidity,soil,light");
}

void loop() {

  static unsigned long lastLog = 0;

  if (millis() - lastLog >= LOG_INTERVAL) {

    lastLog = millis();

    float temp = dht.readTemperature();
    float humidity = dht.readHumidity();

    int soil = analogRead(SOIL_PIN);
    int light = analogRead(LIGHT_PIN);

    unsigned long timestamp =
      (millis() - startTime) / 1000;

    Serial.print(timestamp);
    Serial.print(",");

    Serial.print(temp);
    Serial.print(",");

    Serial.print(humidity);
    Serial.print(",");

    Serial.print(soil);
    Serial.print(",");

    Serial.println(light);
  }
}

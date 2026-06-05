#include <DHT.h>

#define DHT_PIN 4
#define DHT_TYPE DHT22

DHT dht(DHT_PIN, DHT_TYPE);

unsigned long lastRead = 0;

void setup() {
  Serial.begin(9600);
  dht.begin();

  Serial.println("ms,temp_c,humidity_pct");
}

void loop() {

  if (millis() - lastRead < 2000)
    return;

  lastRead = millis();

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("ERR,NaN,NaN");
    return;
  }

  Serial.print(lastRead);
  Serial.print(",");

  Serial.print(temperature, 1);
  Serial.print(",");

  Serial.println(humidity, 1);
}

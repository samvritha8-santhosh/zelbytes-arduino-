#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

#define SOIL_PIN A0
#define LDR_PIN A1
#define RELAY_PIN 8

DHT dht(DHTPIN, DHTTYPE);

// Calibration values
const int DRY_SOIL = 300;
const int WET_SOIL = 800;
const int SOIL_THRESHOLD = 50; // % moisture threshold

void setup() {
  Serial.begin(9600);

  dht.begin();

  pinMode(RELAY_PIN, OUTPUT);

  // Active LOW relay
  digitalWrite(RELAY_PIN, HIGH);

  Serial.println("Smart Grow Bench Started");
}

void loop() {

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  int soilRaw = analogRead(SOIL_PIN);
  int ldrValue = analogRead(LDR_PIN);

  int soilPercent = map(
    soilRaw,
    DRY_SOIL,
    WET_SOIL,
    0,
    100
  );

  soilPercent = constrain(soilPercent, 0, 100);

  bool irrigationRequired = soilPercent < SOIL_THRESHOLD;

  if (irrigationRequired) {
    digitalWrite(RELAY_PIN, LOW);   // Relay ON
  } else {
    digitalWrite(RELAY_PIN, HIGH);  // Relay OFF
  }

  Serial.println("--------------------------------");

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("DHT11 Read Failed");
  } else {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" C");

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
  }

  Serial.print("Soil Raw: ");
  Serial.println(soilRaw);

  Serial.print("Soil Moisture: ");
  Serial.print(soilPercent);
  Serial.println(" %");

  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  Serial.print("Valve State: ");

  if (irrigationRequired) {
    Serial.println("ON");
  } else {
    Serial.println("OFF");
  }

  delay(2000);
}

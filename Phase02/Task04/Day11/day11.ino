#include <DHT.h>

// Pin Definitions
#define LDR_PIN A0

#define SOIL_PIN A1
#define SOIL_PWR 7

#define DHT_PIN 4
#define DHT_TYPE DHT22

#define TRIG_PIN 9
#define ECHO_PIN 10

// Calibration Values
#define DRY_ADC 820
#define WET_ADC 380

DHT dht(DHT_PIN, DHT_TYPE);

int ldrValue = 0;
float temperature = 0;
float humidity = 0;
float distanceCm = 0;
int soilPercent = 0;

// Timers
unsigned long nextLdr = 0;
unsigned long nextDht = 0;
unsigned long nextUltra = 0;
unsigned long nextSoil = 0;
unsigned long nextCsv = 0;

// LDR
void readLdr() {
  long sum = 0;

  for (int i = 0; i < 8; i++) {
    sum += analogRead(LDR_PIN);
  }

  ldrValue = sum / 8;
}

// DHT22
void readDht() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (!isnan(h) && !isnan(t)) {
    humidity = h;
    temperature = t;
  }
}

// HC-SR04
float readCmOnce() {

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  unsigned long us =
      pulseIn(ECHO_PIN, HIGH, 30000);

  if (us == 0)
    return -1;

  return (us * 0.0343) / 2.0;
}

void readUltra() {

  float a = readCmOnce();
  float b = readCmOnce();
  float c = readCmOnce();

  if (a < 0 || b < 0 || c < 0)
    return;

  if ((a <= b && b <= c) || (c <= b && b <= a))
    distanceCm = b;
  else if ((b <= a && a <= c) || (c <= a && a <= b))
    distanceCm = a;
  else
    distanceCm = c;
}

// Soil Moisture
void readSoil() {

  digitalWrite(SOIL_PWR, HIGH);
  delay(10);

  int raw = analogRead(SOIL_PIN);

  digitalWrite(SOIL_PWR, LOW);

  soilPercent =
      constrain(map(raw, DRY_ADC, WET_ADC, 0, 100),
                0,
                100);
}

// Setup
void setup() {

  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(SOIL_PWR, OUTPUT);
  digitalWrite(SOIL_PWR, LOW);

  dht.begin();

  Serial.println("ms,ldr,dht_t,dht_h,cm,soil_pct");
}

// Loop
void loop() {

  unsigned long now = millis();

  if (now >= nextLdr) {
    nextLdr = now + 500;
    readLdr();
  }

  if (now >= nextDht) {
    nextDht = now + 2000;
    readDht();
  }

  if (now >= nextUltra) {
    nextUltra = now + 300;
    readUltra();
  }

  if (now >= nextSoil) {
    nextSoil = now + 1000;
    readSoil();
  }

  if (now >= nextCsv) {

    nextCsv = now + 2000;

    Serial.print(now);
    Serial.print(",");

    Serial.print(ldrValue);
    Serial.print(",");

    Serial.print(temperature, 1);
    Serial.print(",");

    Serial.print(humidity, 1);
    Serial.print(",");

    Serial.print(distanceCm, 1);
    Serial.print(",");

    Serial.println(soilPercent);
  }
}

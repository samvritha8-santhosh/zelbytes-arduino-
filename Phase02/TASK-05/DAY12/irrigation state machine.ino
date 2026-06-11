#include <DHT.h>

// =====================
// Pin Definitions
// =====================
#define SOIL_PIN    A0
#define DHT_PIN     4
#define RELAY_PIN   8
#define LED_PIN     13

#define DHT_TYPE DHT22

// =====================
// Soil Calibration
// Adjust after testing
// =====================
const int DRY_VALUE = 850;
const int WET_VALUE = 250;

// =====================
// Thresholds (thresholds.h)
// =====================
const int SOIL_MIN = 25;       // Turn ON irrigation
const int SOIL_TARGET = 40;    // Turn OFF irrigation

const int LOW_COUNT_REQ = 3;   // Debounce count
const int HUMIDITY_MAX = 85;

const unsigned long MAX_RUN_TIME = 10000UL;
const unsigned long COOLDOWN_TIME = 5000UL;

// =====================
// State Machine
// =====================
enum State
{
  IDLE,
  MONITORING,
  IRRIGATING,
  COOLDOWN,
  FAULT
};

State state = IDLE;

DHT dht(DHT_PIN, DHT_TYPE);

unsigned long irrigateStart = 0;
unsigned long cooldownStart = 0;

int lowCount = 0;
int dhtFailCount = 0;

// =====================
// Relay Control
// Active LOW Relay
// =====================
void setValve(bool open)
{
  digitalWrite(RELAY_PIN, open ? LOW : HIGH);
}

// =====================
// Log State Changes
// =====================
void logTransition(const char* fromState,
                   const char* toState)
{
  Serial.print("[");
  Serial.print(millis());
  Serial.print(" ms] ");

  Serial.print(fromState);
  Serial.print(" -> ");
  Serial.println(toState);
}

// =====================
// Setup
// =====================
void setup()
{
  Serial.begin(9600);

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  setValve(false);
  digitalWrite(LED_PIN, LOW);

  dht.begin();

  Serial.println("=================================");
  Serial.println("TASK 5 STATE MACHINE");
  Serial.println("=================================");

  logTransition("STARTUP", "IDLE");
}

// =====================
// Main Loop
// =====================
void loop()
{
  int rawSoil = analogRead(SOIL_PIN);

  int moisturePercent =
      map(rawSoil, DRY_VALUE, WET_VALUE, 0, 100);

  moisturePercent =
      constrain(moisturePercent, 0, 100);

  float humidity = dht.readHumidity();

  // =====================
  // DHT Fault Detection
  // =====================
  if (isnan(humidity))
  {
    dhtFailCount++;

    Serial.print("[");
    Serial.print(millis());
    Serial.print(" ms] DHT Failure Count = ");
    Serial.println(dhtFailCount);

    if (dhtFailCount >= 3)
    {
      logTransition("ANY STATE", "FAULT");
      state = FAULT;
    }
  }
  else
  {
    dhtFailCount = 0;
  }

  // =====================
  // State Machine
  // =====================
  switch (state)
  {
    // -----------------
    case IDLE:
    // -----------------
      setValve(false);
      digitalWrite(LED_PIN, LOW);

      logTransition("IDLE", "MONITORING");

      state = MONITORING;

      break;

    // -----------------
    case MONITORING:
    // -----------------

      if (moisturePercent < SOIL_MIN)
      {
        lowCount++;

        Serial.print("Low Moisture Count = ");
        Serial.println(lowCount);
      }
      else
      {
        lowCount = 0;
      }

      if (lowCount >= LOW_COUNT_REQ &&
          humidity < HUMIDITY_MAX)
      {
        logTransition("MONITORING", "IRRIGATING");

        state = IRRIGATING;

        irrigateStart = millis();

        setValve(true);
        digitalWrite(LED_PIN, HIGH);

        lowCount = 0;
      }

      break;

    // -----------------
    case IRRIGATING:
    // -----------------

      setValve(true);
      digitalWrite(LED_PIN, HIGH);

      // Hysteresis stop condition
      if (moisturePercent >= SOIL_TARGET)
      {
        logTransition("IRRIGATING", "COOLDOWN");

        setValve(false);

        cooldownStart = millis();

        state = COOLDOWN;
      }

      // Max Runtime Safety
      else if (millis() - irrigateStart >= MAX_RUN_TIME)
      {
        Serial.println("MAX RUN TIME REACHED");

        logTransition("IRRIGATING", "COOLDOWN");

        setValve(false);

        cooldownStart = millis();

        state = COOLDOWN;
      }

      break;

    // -----------------
    case COOLDOWN:
    // -----------------

      setValve(false);
      digitalWrite(LED_PIN, LOW);

      if (millis() - cooldownStart >= COOLDOWN_TIME)
      {
        logTransition("COOLDOWN", "MONITORING");

        state = MONITORING;
      }

      break;

    // -----------------
    case FAULT:
    // -----------------

      setValve(false);

      // Blink LED
      digitalWrite(LED_PIN,
                   (millis() / 250) % 2);

      Serial.println(
        "FAULT STATE - DHT SENSOR ERROR");

      delay(1000);

      break;
  }

  // =====================
  // Status Log
  // =====================
  Serial.print("[");
  Serial.print(millis());
  Serial.print(" ms] ");

  Serial.print("State=");

  switch (state)
  {
    case IDLE:
      Serial.print("IDLE");
      break;

    case MONITORING:
      Serial.print("MONITORING");
      break;

    case IRRIGATING:
      Serial.print("IRRIGATING");
      break;

    case COOLDOWN:
      Serial.print("COOLDOWN");
      break;

    case FAULT:
      Serial.print("FAULT");
      break;
  }

  Serial.print(" | Soil=");
  Serial.print(moisturePercent);
  Serial.print("%");

  Serial.print(" | Humidity=");
  Serial.print(humidity);
  Serial.println("%");

  delay(1000);
}

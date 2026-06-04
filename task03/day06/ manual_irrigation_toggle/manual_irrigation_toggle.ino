/*
  manual_irrigation_v0_1.ino

  Single button press starts irrigation.
  Valve opens for IRRIGATION_SECONDS.
  Serial logs every irrigation event.
*/

#define IRRIGATION_SECONDS 5

const uint8_t BTN_PIN   = 2;
const uint8_t LED_PIN   = 13;
const uint8_t RELAY_PIN = 8;

const bool RELAY_ACTIVE_LOW = true;

bool irrigationRunning = false;
unsigned long irrigationStartMs = 0;

// ------------------------------------------------
// Relay / Valve Control
// ------------------------------------------------
void setValve(bool open) {

  if (RELAY_ACTIVE_LOW) {
    digitalWrite(RELAY_PIN, open ? LOW : HIGH);
  } else {
    digitalWrite(RELAY_PIN, open ? HIGH : LOW);
  }
}

// ------------------------------------------------
// Setup
// ------------------------------------------------
void setup() {

  pinMode(BTN_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);

  // Safe startup
  setValve(false);
  digitalWrite(LED_PIN, LOW);

  Serial.begin(9600);

  Serial.println(F("================================"));
  Serial.println(F("Manual Irrigation Controller"));
  Serial.println(F("Firmware v0.1-manual"));
  Serial.print(F("Irrigation Duration = "));
  Serial.print(IRRIGATION_SECONDS);
  Serial.println(F(" sec"));
  Serial.println(F("Press button to irrigate"));
  Serial.println(F("================================"));
}

// ------------------------------------------------
// Main Loop
// ------------------------------------------------
void loop() {

  static bool lastButtonState = HIGH;

  bool buttonState = digitalRead(BTN_PIN);

  // Detect button press (HIGH -> LOW)
  if (lastButtonState == HIGH &&
      buttonState == LOW &&
      !irrigationRunning) {

    irrigationRunning = true;
    irrigationStartMs = millis();

    setValve(true);
    digitalWrite(LED_PIN, HIGH);

    Serial.print(F("IRRIGATION START | t="));
    Serial.print(millis() / 1000);
    Serial.println(F(" sec"));
  }

  // Stop after configured duration
  if (irrigationRunning &&
      (millis() - irrigationStartMs >=
       (unsigned long)IRRIGATION_SECONDS * 1000UL)) {

    irrigationRunning = false;

    setValve(false);
    digitalWrite(LED_PIN, LOW);

    Serial.print(F("IRRIGATION STOP  | t="));
    Serial.print(millis() / 1000);
    Serial.println(F(" sec"));
  }

  lastButtonState = buttonState;
}

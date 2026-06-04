#include "config.h"

unsigned long lastEventMs = 0;

bool debouncePressed(uint8_t pin) {
  static bool lastStable = HIGH;
  static bool lastRead = HIGH;
  static unsigned long lastChange = 0;

  bool reading = digitalRead(pin);

  if (reading != lastRead) {
    lastChange = millis();
    lastRead = reading;
  }

  if ((millis() - lastChange) > 30) {
    lastStable = reading;
  }

  return lastStable == LOW;
}

void setValve(bool open) {

  if (RELAY_ACTIVE_LOW) {
    digitalWrite(RELAY_VALVE, open ? LOW : HIGH);
  } else {
    digitalWrite(RELAY_VALVE, open ? HIGH : LOW);
  }
}

void setup() {

  pinMode(LED_STATUS, OUTPUT);
  pinMode(BTN_MANUAL, INPUT_PULLUP);
  pinMode(RELAY_VALVE, OUTPUT);

  setValve(false);

  Serial.begin(9600);

  Serial.println(F("Manual Irrigation Ready"));
  Serial.println(F("s=status, e=ESTOP"));
}

void loop() {

  bool pressed = debouncePressed(BTN_MANUAL);

  setValve(pressed);

  digitalWrite(
    LED_STATUS,
    pressed ? HIGH : LOW
  );

  if (pressed) {
    lastEventMs = millis();
  }

  if (Serial.available()) {

    char c = Serial.read();

    if (c == 'e') {

      setValve(false);

      digitalWrite(
        LED_STATUS,
        LOW
      );

      Serial.println(F("ESTOP"));
    }

    if (c == 's') {

      Serial.print(F("Valve="));
      Serial.println(
        pressed ?
        F("OPEN") :
        F("CLOSED")
      );

      Serial.print(F("UptimeMs="));
      Serial.println(millis());

      Serial.print(F("LastEventMs="));
      Serial.println(lastEventMs);
    }
  }
}

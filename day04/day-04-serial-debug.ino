#define DEBUG 1
const uint8_t LED_PIN = 13;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println(F("Commands: ? help, l on, o off"));
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    switch (c) {
      case '?': Serial.println(F("l=LED on, o=off")); break;
      case 'l': digitalWrite(LED_PIN, HIGH); Serial.println(F("ON")); break;
      case 'o': digitalWrite(LED_PIN, LOW);  Serial.println(F("OFF")); break;
      default:  Serial.println(F("Unknown")); break;
    }
  }
#if DEBUG
  static unsigned long last = 0;
  if (millis() - last > 2000) {
    last = millis();
    Serial.print(F("uptime_ms=")); Serial.println(millis());
  }
#endif
}

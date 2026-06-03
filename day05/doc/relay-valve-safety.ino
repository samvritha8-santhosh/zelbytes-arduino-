const uint8_t RELAY_PIN = 8;  // IN on relay board
const bool RELAY_ACTIVE_LOW = true;

void setValve(bool open) {
  bool energize = open;
  if (RELAY_ACTIVE_LOW) energize = !energize;
  digitalWrite(RELAY_PIN, energize ? LOW : HIGH);
}

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  setValve(false);  // OFF at boot
  Serial.begin(9600);
  Serial.println(F("Valve OFF. Commands: v=toggle, e=estop"));
}

void loop() {
  if (!Serial.available()) return;
  char c = Serial.read();
  if (c == 'e') { setValve(false); Serial.println(F("ESTOP")); }
  if (c == 'v') { /* demo only — supervisor present */ setValve(true); delay(2000); setValve(false); }
}

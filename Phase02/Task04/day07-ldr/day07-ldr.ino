const uint8_t LDR_PIN = A0;
const float VREF = 5.0;

int readAveraged(uint8_t pin, uint8_t samples = 8) {
  long sum = 0;
  for (uint8_t i = 0; i < samples; i++) sum += analogRead(pin);
  return (int)(sum / samples);
}

void setup() {
  Serial.begin(9600);
  Serial.println(F("raw,voltage"));
}

void loop() {
  int raw = readAveraged(LDR_PIN);
  float v = raw * (VREF / 1023.0);
  Serial.print(raw); Serial.print(','); Serial.println(v, 3);
  delay(500);
}

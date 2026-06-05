const uint8_t LDR_PIN = A0;
const float VREF = 5.0;

// Update these after calibration
const int LDR_DARK = 300;
const int LDR_BRIGHT = 700;

int readAveraged(uint8_t pin, uint8_t samples = 8) {
  long sum = 0;

  for (uint8_t i = 0; i < samples; i++) {
    sum += analogRead(pin);
  }

  return sum / samples;
}

void setup() {
  Serial.begin(9600);
  Serial.println(F("raw,voltage,level"));
}

void loop() {

  int raw = readAveraged(LDR_PIN);

  float voltage = raw * (VREF / 1023.0);

  String level;

  if (raw < LDR_DARK)
    level = "DARK";
  else if (raw < LDR_BRIGHT)
    level = "AMBIENT";
  else
    level = "BRIGHT";

  Serial.print(raw);
  Serial.print(',');

  Serial.print(voltage, 3);
  Serial.print(',');

  Serial.println(level);

  delay(500);
}

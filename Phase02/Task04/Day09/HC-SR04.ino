#define TRIG_PIN 9
#define ECHO_PIN 10

void setup() {
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.println("ms,distance_cm");
}

void loop() {

  // Clear trigger
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Send 10 us pulse
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo with 30 ms timeout
  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  if (duration == 0) {
    Serial.print(millis());
    Serial.println(",No Echo");
    delay(1000);
    return;
  }

  float distance = duration * 0.0343 / 2.0;

  Serial.print(millis());
  Serial.print(",");
  Serial.println(distance, 2);

  delay(1000);
}

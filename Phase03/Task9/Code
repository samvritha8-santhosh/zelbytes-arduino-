/*
  Firmware v1.0 - Auto Irrigation System

  Features:
  - Automatic irrigation based on soil moisture threshold
  - Manual override button
  - Serial commands:
      STATUS
      FORCE_ON
      FORCE_OFF

  Hardware:
  Soil Sensor AO -> A0
  Relay IN       -> D7
  Push Button    -> D2
*/

#define SOIL_PIN A0
#define RELAY_PIN 7
#define BUTTON_PIN 2

const int SOIL_THRESHOLD = 600;

bool manualMode = false;
bool pumpState = false;

unsigned long lastButtonTime = 0;
const unsigned long debounceDelay = 300;

void setup()
{
  Serial.begin(9600);

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  digitalWrite(RELAY_PIN, HIGH);

  Serial.println("=== Auto Irrigation Firmware v1.0 ===");
  Serial.println("Commands:");
  Serial.println("STATUS");
  Serial.println("FORCE_ON");
  Serial.println("FORCE_OFF");
}

void loop()
{
  handleButton();
  handleSerial();

  int soilValue = analogRead(SOIL_PIN);

  if (!manualMode)
  {
    autoIrrigation(soilValue);
  }

  delay(100);
}

void autoIrrigation(int soilValue)
{
  if (soilValue > SOIL_THRESHOLD)
  {
    pumpOn();
  }
  else
  {
    pumpOff();
  }
}

void handleButton()
{
  if (millis() - lastButtonTime < debounceDelay)
    return;

  if (digitalRead(BUTTON_PIN) == LOW)
  {
    manualMode = !manualMode;

    Serial.println();

    if (manualMode)
    {
      Serial.println("MANUAL OVERRIDE ENABLED");
      Serial.println("Use FORCE_ON or FORCE_OFF");
    }
    else
    {
      Serial.println("AUTO MODE ENABLED");
    }

    lastButtonTime = millis();
  }
}

void handleSerial()
{
  if (!Serial.available())
    return;

  String cmd = Serial.readStringUntil('\n');
  cmd.trim();

  cmd.toUpperCase();

  if (cmd == "STATUS")
  {
    printStatus();
  }
  else if (cmd == "FORCE_ON")
  {
    manualMode = true;
    pumpOn();

    Serial.println("Pump Forced ON");
  }
  else if (cmd == "FORCE_OFF")
  {
    manualMode = true;
    pumpOff();

    Serial.println("Pump Forced OFF");
  }
  else
  {
    Serial.println("Unknown Command");
  }
}

void printStatus()
{
  int soilValue = analogRead(SOIL_PIN);

  Serial.println("------ STATUS ------");

  Serial.print("Mode: ");

  if (manualMode)
    Serial.println("MANUAL");
  else
    Serial.println("AUTO");

  Serial.print("Soil Reading: ");
  Serial.println(soilValue);

  Serial.print("Threshold: ");
  Serial.println(SOIL_THRESHOLD);

  Serial.print("Pump State: ");

  if (pumpState)
    Serial.println("ON");
  else
    Serial.println("OFF");

  Serial.println("--------------------");
}

void pumpOn()
{
  digitalWrite(RELAY_PIN, LOW);
  pumpState = true;
}

void pumpOff()
{
  digitalWrite(RELAY_PIN, HIGH);
  pumpState = false;
}

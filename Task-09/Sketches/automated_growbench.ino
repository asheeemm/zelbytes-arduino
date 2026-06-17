#define RELAY_PIN D1
#define BUTTON_PIN D2
#define MOISTURE_PIN A0

bool autoMode = true;
bool valveState = false;

bool lastButtonState = HIGH;

int dryThreshold = 750;
int wetThreshold = 500;

char cmd[20];
byte cmdIndex = 0;

void setup()
{
  Serial.begin(115200);

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  digitalWrite(RELAY_PIN, LOW);

  Serial.println("\nGrow Bench v1.0");
  Serial.println("Commands: STATUS, FORCE_ON, FORCE_OFF, AUTO");
}

void loop()
{
  int moisture = analogRead(MOISTURE_PIN);

  handleButton();
  handleSerial(moisture);

  if(autoMode)
    autoControl(moisture);

  delay(100);
}

void autoControl(int moisture)
{
  if(moisture > dryThreshold)
    valveOn();
  else if(moisture < wetThreshold)
    valveOff();
}

void valveOn()
{
  digitalWrite(RELAY_PIN, HIGH);
  valveState = true;
}

void valveOff()
{
  digitalWrite(RELAY_PIN, LOW);
  valveState = false;
}

void handleButton()
{
  bool currentButtonState = digitalRead(BUTTON_PIN);

  if(lastButtonState == HIGH && currentButtonState == LOW)
  {
    autoMode = false;

    if(valveState)
      valveOff();
    else
      valveOn();

    Serial.println("Manual Override");
  }

  lastButtonState = currentButtonState;
}

void handleSerial(int moisture)
{
  while (Serial.available())
  {
    char c = Serial.read();

    if (c == '\n')
    {
      cmd[cmdIndex] = '\0';
      processCommand(moisture);
      cmdIndex = 0;
    }
    else if (cmdIndex < sizeof(cmd) - 1)
    {
      cmd[cmdIndex++] = c;
    }
  }
}

void processCommand(int moisture)
{
  if (strcmp(cmd, "STATUS") == 0)
  {
    Serial.println("STATUS");
    Serial.print("Mode: ");
    Serial.println(autoMode ? "AUTO" : "MANUAL");

    Serial.print("Moisture: ");
    Serial.println(moisture);

    Serial.print("Valve: ");
    Serial.println(valveState ? "ON" : "OFF");
  }
  else if (strcmp(cmd, "FORCE_ON") == 0)
  {
    autoMode = false;
    valveOn();
    Serial.println("Valve ON");
  }
  else if (strcmp(cmd, "FORCE_OFF") == 0)
  {
    autoMode = false;
    valveOff();
    Serial.println("Valve OFF");
  }
  else if (strcmp(cmd, "AUTO") == 0)
  {
    autoMode = true;
    Serial.println("AUTO MODE");
  }
}

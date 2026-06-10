const int SOIL_PIN = A0;

const int DRY_ADC = 850;  // replace with yours
const int WET_ADC = 321;  // replace with yours

void setup() {
  Serial.begin(9600);
}

void loop() {

  int soilRaw = analogRead(SOIL_PIN);

  int soilPercent = map(
    soilRaw,
    DRY_ADC,
    WET_ADC,
    0,
    100
  );

  soilPercent = constrain(
    soilPercent,
    0,
    100
  );

  Serial.print("Raw=");
  Serial.print(soilRaw);

  Serial.print("  Moisture=");
  Serial.print(soilPercent);

  Serial.println("%");

  delay(1000);
}

const int trigPin = 9;
const int echoPin = 10;

// Function to find median of 3 values
float median3(float a, float b, float c)
{
  if ((a >= b && a <= c) || (a >= c && a <= b))
    return a;
  else if ((b >= a && b <= c) || (b >= c && b <= a))
    return b;
  else
    return c;
}

// Single distance measurement
float readDistance()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000); // 30 ms timeout

  // No echo received
  if (duration == 0)
    return -1;

  float distance = duration * 0.0343 / 2.0;

  return distance;
}

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);

  // CSV Header
  Serial.println("millis,distance_cm");
}

void loop()
{
  float d1 = readDistance();
  delay(50);

  float d2 = readDistance();
  delay(50);

  float d3 = readDistance();

  // If any reading is invalid
  if (d1 < 0 || d2 < 0 || d3 < 0)
  {
    Serial.print(millis());
    Serial.println(",INVALID");
  }
  else
  {
    float filteredDistance = median3(d1, d2, d3);

    Serial.print(millis());
    Serial.print(",");
    Serial.println(filteredDistance);
  }

  delay(500);
}

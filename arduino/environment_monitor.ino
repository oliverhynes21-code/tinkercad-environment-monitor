int tempPin = A4;
int humPin = A5;

float displayTemperature()
{
  int tempSensor = analogRead(tempPin);
  float tempVoltage = tempSensor * (5.0/1023.0);
  float tempCelsius = (tempVoltage - 0.5) * 100.0;
 
  Serial.print("Temperature: ");
  Serial.print(tempCelsius);
  Serial.println(" deg C");
}

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  displayTemperature();

  delay(5000);
}

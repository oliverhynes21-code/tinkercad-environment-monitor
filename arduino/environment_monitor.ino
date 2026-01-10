int tempPin = A4;
int humPin = A5;
int lightPin = A3;

float displayTemperature()
{
  /*
     Maths used to calculate the temperature in degrees celsius
     from the raw value of the sensor and voltage calculated
     from that raw value
  */
  
  int tempSensor = analogRead(tempPin);
  float tempVoltage = tempSensor * (5.0/1023.0);
  float tempCelsius = (tempVoltage - 0.5) * 100.0;
 
  Serial.print("Temperature: ");
  Serial.print(tempCelsius);
  Serial.println(" deg C");
}

int displayHumidity()
{
  /*
     Maths used to calculate the percentage of air humidity
     by using a potentiometer as a simulated input, and then
     using the map() function to map these values from 0 to 100
  */
  
  int humSensor = analogRead(humPin);
  int humPercentage = map(humSensor, 0, 1023, 0, 100);

  Serial.print("Humidity: ");
  Serial.print(humPercentage);
  Serial.println("%");
}

float displayLightLevel()
{
  /*
     Maths used to calculate the light level in lux from the
     raw value of the sensor, the voltage calculated from this
     raw value, and then the resistance calculated from this
  */
  
  int lightSensor = analogRead(lightPin);
  float Vout = lightSensor * (5.0 / 1023.0);
  float Rldr = 10000.0 * (5.0 / Vout - 1.0);
  float lux  = pow(Rldr / 50000.0, -1.0 / 0.7);
  
  Serial.print("Light level: ");
  Serial.print(lux);
  Serial.println(" lux");
}

void setup()
{
  // Initialises the data transfer speed (baud rate) to be 9600bps and activates the serial monitor for the arduino
  Serial.begin(9600);
}

void loop()
{
  Serial.println("---------------------");
  displayTemperature();
  displayHumidity();
  displayLightLevel();

  delay(2000); // Waits 2 seconds to prevent overwhelming outputs and increase simulation performance
}

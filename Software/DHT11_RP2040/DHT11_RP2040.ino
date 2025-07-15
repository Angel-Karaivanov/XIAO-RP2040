#include <dht11.h>  // Include the DHT library
#define DHT11PIN 1  // Digital pin connected to the DHT sensor

dht11 DHT11;  

void  setup() 
{
  Serial.begin(9600); // Initialize serial communication for debugging
 
}

void loop()
{
  Serial.println();

  int chk = DHT11.read(DHT11PIN); //check the input from the sensor

  Serial.print("Humidity (%): "); //print the Humidity value
  Serial.print((float)DHT11.humidity, 2);

  Serial.print(", Temperature  (C): "); //print the Temperature value
  Serial.println((float)DHT11.temperature, 2);

  delay(2000); // Wait a few seconds between measurements
}
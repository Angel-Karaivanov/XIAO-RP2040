#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 1

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature sensor
DallasTemperature sensors(&oneWire);

DeviceAddress Sensor1 ;

void setup() 
{
  Serial.begin(115200);   // Begin serial communication for output
  delay(5000); 
  Serial.println("SYSSTART!");  
  
  sensors.begin(); // Start up the library
  
  Serial.print("Found ");
  Serial.print(sensors.getDeviceCount(), DEC); //Get the device count 
  Serial.println(" devices."); 

  if (!sensors.getAddress(Sensor1, 0))
  {
    Serial.println("Unable to find address for Device 1");
  }

}

void loop() 
{
  printDataIndex(Sensor1,0); //Print the data of the devices by index

}
void printAddress(DeviceAddress Sensor1)    // function to print a device address 
{
  Serial.print("Device Address ");
  Serial.print(" :");
  for (uint8_t i = 0; i < 8; i++)
  {
    if (Sensor1[i] < 16) Serial.print("0"); // zero pad the address if necessary
    Serial.print(Sensor1[i], HEX);
  }
  Serial.print(", ");
}

void printTemperature(DeviceAddress Sensor1)
{
  sensors.requestTemperaturesByAddress(Sensor1); // Call sensors.requestTemperatures() to issue a temperature
                                                 // request to all devices on the bus

  float temperatureC = sensors.getTempC(Sensor1); //function to show error
  if (temperatureC == DEVICE_DISCONNECTED_C)
  {
    Serial.println("Error: Could not read temperature data");
    return;
  }
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.print(" C");
}

void printData(DeviceAddress Sensor1) //function to print the print the device data
{
  printAddress(Sensor1);
  Serial.print(" ");
  printTemperature(Sensor1);
  Serial.println();
  delay(1000);  
}

void printDataIndex(DeviceAddress address, int index) //function to print the device's index
{ 
  printAddress(address);
  Serial.print(" Device index: ");
  Serial.print(index);
  Serial.print(", ");
  printTemperatureByIndex(index);
  Serial.println();
  delay(1000);  
}

void printTemperatureByIndex(int index) //function to print the temp by index
                                        // Why "byIndex"? You can have more than one sensor on the same bus.
{
  sensors.requestTemperaturesByIndex(index); 
  
  float temperatureC = sensors.getTempCByIndex(index); //function to show error
  if (temperatureC == DEVICE_DISCONNECTED_C)
  {
    Serial.println("Error: Could not read temperature data");
    return;
  }
  Serial.print("Temperature: "); // Print the temperature in Celsius
  Serial.print(temperatureC);
  Serial.print(" C");
}




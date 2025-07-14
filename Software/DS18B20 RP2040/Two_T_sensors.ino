#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS A1

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature sensor
DallasTemperature sensors(&oneWire);

DeviceAddress Sensor1, Sensor2 ;

void setup() {
  // Begin serial communication for output
  Serial.begin(115200);
  delay(5000);
  Serial.println("SYSSTART!");  
  // Start up the library
  
  sensors.begin();
  
  Serial.print("Found ");
  Serial.print(sensors.getDeviceCount(), DEC);
  Serial.println(" devices."); 

  if (!sensors.getAddress(Sensor1, 0)){
    Serial.println("Unable to find address for Device 1");
  }
  if (!sensors.getAddress(Sensor2, 1)){
    Serial.println("Unable to find address for Device 2");
  }
}

void loop() 
{
  //Serial.print("Requesting temperatures...");
  //sensors.requestTemperatures();
  //Serial.println("DONE");
  // Call sensors.requestTemperatures() to issue a temperature
  // request to all devices on the bus
  printDataIndex(Sensor1,0);
  printDataIndex(Sensor2,1);

}
// function to print a device address
void printAddress(DeviceAddress Sensor1)
{
  Serial.print("Device Address ");
  Serial.print(" :");
  for (uint8_t i = 0; i < 8; i++)
  {
    // zero pad the address if necessary
    if (Sensor1[i] < 16) Serial.print("0");
    Serial.print(Sensor1[i], HEX);
  }
  Serial.print(", ");
}

void printTemperature(DeviceAddress Sensor1)
{
  sensors.requestTemperaturesByAddress(Sensor1);

  float temperatureC = sensors.getTempC(Sensor1);
  if (temperatureC == DEVICE_DISCONNECTED_C)
  {
    Serial.println("Error: Could not read temperature data");
    return;
  }
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.print(" C");
}

void printData(DeviceAddress Sensor1){
  printAddress(Sensor1);
  Serial.print(" ");
  printTemperature(Sensor1);
  Serial.println();
  delay(1000);  
}

void printDataIndex(DeviceAddress address, int index){
  printAddress(address);
  Serial.print(" Device index: ");
  Serial.print(index);
  Serial.print(", ");
  printTemperatureByIndex(index);
  Serial.println();
  delay(1000);  
}

void printTemperatureByIndex(int index)
{
  sensors.requestTemperaturesByIndex(index);
  
  float temperatureC = sensors.getTempCByIndex(index);
  if (temperatureC == DEVICE_DISCONNECTED_C)
  {
    Serial.println("Error: Could not read temperature data");
    return;
  }
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.print(" C");
}
//void DallasTemperature::setUserDataByIndex(uint8_t deviceIndex, int16_t data) {
//    DeviceAddress Sensor1;}




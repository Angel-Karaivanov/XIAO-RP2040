const int tempSensorPin = A2; // Replace A0 with your chosen analog pin

void setup() {
  Serial.begin(115200);
  pinMode(tempSensorPin, INPUT);
}

void loop() {
  int sensorValue = analogRead(tempSensorPin);  // Read the analog value from the sensor
  float voltage = sensorValue * (3.3 / 1023.0); // Assuming 3.3V reference
                                                // Convert the analog reading to voltage

  float temperature = (voltage - 0.4) / 0.0195; // Example conversion, adjust based on sensor datasheet

  Serial.print("Sensor Value: "); // Print the results to the serial monitor
  Serial.print(sensorValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage,3);
  Serial.print(" V | Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");


  delay(1000); // Delay for 1 second before taking the next reading
}
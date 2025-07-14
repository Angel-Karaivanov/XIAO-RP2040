const int tempSensorPin = A0; // Replace A0 with your chosen analog pin

void setup() {
  Serial.begin(115200);
  pinMode(tempSensorPin, INPUT);
}

void loop() {
  int sensorValue = analogRead(tempSensorPin);
  float voltage = sensorValue * (3.3 / 1023.0); // Assuming 3.3V reference

  float temperature = (voltage - 0.4) / 0.0195; // Example conversion, adjust based on sensor datasheet

  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage,3);
  Serial.print(" V | Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");


  delay(1000);
}
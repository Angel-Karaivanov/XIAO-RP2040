const int tempSensorPin = A0;
const int LedRedex=2;
const int LedGreenex=3; 
const int LedBluex=4;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(115200);
  pinMode(tempSensorPin, INPUT);
  
  pinMode(LedRedex, OUTPUT);
  pinMode(LedGreenex, OUTPUT);
  pinMode(LedBluex, OUTPUT);
  
  pinMode(LedRedin, OUTPUT);
  pinMode(LedGreenin, OUTPUT);
  pinMode(LedBluein, OUTPUT);
  
  digitalWrite(LedRedex, HIGH);
  digitalWrite(LedGreenex, HIGH);
  digitalWrite(LedBluex, HIGH);
  
  digitalWrite(LedRedin, HIGH);
  digitalWrite(LedGreenin, HIGH);
  digitalWrite(LedBluein, HIGH);
}

// the loop function runs over and over again forever
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
  if (temperature > 30) 
  {
  digitalWrite(LedRedex, LOW);
  digitalWrite(LedGreenex, HIGH);
  digitalWrite(LedBluex, HIGH);
  
  digitalWrite(LedRedin, LOW);
  digitalWrite(LedGreenin, HIGH);
  digitalWrite(LedBluein, HIGH);        // turn the LED on (HIGH is the voltage level)
  delay(10);                       // wait for a second
  }
  if (temperature >= 20&& temperature<=30 ) 
  {
  digitalWrite(LedRedex, HIGH);
  digitalWrite(LedGreenex, lOW);
  digitalWrite(LedBluex, HIGH);
  
  digitalWrite(LedRedin, HIGH);
  digitalWrite(LedGreenin, lOW);
  digitalWrite(LedBluein, HIGH);        // turn the LED on (HIGH is the voltage level)
  delay(10);                       // wait for a second
  }
  if (temperature > 30) 
  {
  digitalWrite(LedRedex, HIGH);
  digitalWrite(LedGreenex, HIGH);
  digitalWrite(LedBluex, lOW);
  
  digitalWrite(LedRedin, HIGH);
  digitalWrite(LedGreenin, HIGH);
  digitalWrite(LedBluein, lOW);;        // turn the LED on (HIGH is the voltage level)
  delay(10);                       // wait for a second
  }
}
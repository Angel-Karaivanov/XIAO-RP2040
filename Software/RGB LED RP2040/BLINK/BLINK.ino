
  const int LedRed=16;  // Define the pin the LED is connected to
  const int LedGreen=17;
  const int LedBlue=25;

void setup() // the setup function runs once when you press reset or power the board
{ 
  Serial.begin(115200); 
  pinMode(LedRed, OUTPUT);    // Initialize the ledPins as output pins
  pinMode(LedGreen, OUTPUT);
  pinMode(LedBlue, OUTPUT);
  digitalWrite(LedRed, HIGH); //Turn them off at the start
  digitalWrite(LedGreen, HIGH);
  digitalWrite(LedBlue, HIGH);
}

void loop() // the loop function runs over and over again forever
{
  Serial.print(".");
  digitalWrite(LedRed, LOW);        // turn the LED on (LOW is the voltage level)
  delay(500);                       // wait for half a second
  digitalWrite(LedRed, HIGH);       // turn the LED off by making the voltage HIGH
  delay(500);                       // wait for half a second
  digitalWrite(LedGreen, LOW);      // turn the LED on (LOW is the voltage level)
  delay(500);                       // wait for half a second
  digitalWrite(LedGreen, HIGH);     // turn the LED off by making the voltage HIGH
  delay(500);      
  digitalWrite(LedBlue, LOW);       // turn the LED on (LOW is the voltage level)
  delay(500);                       // wait for half a second
  digitalWrite(LedBlue, HIGH);      // turn the LED off by making the voltage HIGH
  delay(500);     

}
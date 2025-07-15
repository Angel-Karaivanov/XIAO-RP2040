const int LedRedin=16; //Setting the values of pins to random names
const int LedGreenin=17;
const int LedBluein=25;
const int LedRedex=2;
const int LedGreenex=3; 
const int LedBluex=4;


void setup() { // the setup function runs once when you press reset or power the board
  Serial.begin(115200); //Begin the function
  
  pinMode(LedRedex, OUTPUT); // Initialize the Led"****" as an output pin
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

void loop() // the loop function runs over and over again forever
{
                                       //This code makes sure that each LED turns on and then turns off so there are no overlappping colors
  digitalWrite(LedRedex, LOW);         // turn the LED on (LOW is the voltage level) 
  digitalWrite(LedGreenex, HIGH);      // turn the LED off (HIGH is the voltage level)
  digitalWrite(LedBluex, HIGH);        // turn the LED off (HIGH is the voltage level)
  
  digitalWrite(LedRedin, LOW);         // turn the LED on (LOW is the voltage level)
  digitalWrite(LedGreenin, HIGH);      // turn the LED off (HIGH is the voltage level)
  digitalWrite(LedBluein, HIGH);       // turn the LED off (HIGH is the voltage level)
 
  delay (1000);                        // wait for a second
 
  
  digitalWrite(LedRedex, HIGH);        // turn the LED off (HIGH is the voltage level)
  digitalWrite(LedGreenex, LOW);       // turn the LED on (LOW is the voltage level)
  digitalWrite(LedBluex, HIGH);        // turn the LED off (HIGH is the voltage level)
  
  digitalWrite(LedRedin, HIGH);         // turn the LED off (HIGH is the voltage level)
  digitalWrite(LedGreenin, LOW);        // turn the LED on (LOW is the voltage level)
  digitalWrite(LedBluein, HIGH);        // turn the LED off (HIGH is the voltage level)
 
  delay(1000);                          // wait for a second
 
  digitalWrite(LedRedex, HIGH);         // turn the LED off (HIGH is the voltage level)
  digitalWrite(LedGreenex, HIGH);       // turn the LED off (HIGH is the voltage level)
  digitalWrite(LedBluex, LOW);          // turn the LED on (LOW is the voltage level)
  
  digitalWrite(LedRedin, HIGH);         // turn the LED off (HIGH is the voltage level)
  digitalWrite(LedGreenin, HIGH);       // turn the LED off (HIGH is the voltage level)
  digitalWrite(LedBluein, LOW);;        // turn the LED on (LOW is the voltage level)
  delay(1000);                          // wait for a second
  }
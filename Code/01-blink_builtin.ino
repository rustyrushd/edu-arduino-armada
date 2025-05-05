/*
  This program continuously blinks the builtin LED of the Arduino, just below 
  pin 13, to which it is attached. Use this program to test that the Arduino 
  is properly connected to the computer. If it fails to upload, check if the 
  correct COM port (under Tools in Arduino IDE) is selected.
*/

// setup() runs once when the board is powered
void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // initialize LED_BUILTIN (pin 13) as an output
}

// loop() runs continuously until power 
void loop() {
  digitalWrite(LED_BUILTIN, HIGH); // turn the LED on by setting the voltage HIGH
  delay(1000); // wait for 1000 millisecond(s) or 1 second
  digitalWrite(LED_BUILTIN, LOW); // turn the LED off by setting the voltage LOW
  delay(1000); // again wait for 1000 millisecond(s) or 1 second
}
